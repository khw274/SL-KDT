# ============================================================
# 3. 주택 상태 등급 분류(다중 분류) 관련 함수
# ============================================================
# seungbin_model.py

import pandas as pd
from sklearn.preprocessing import LabelEncoder, StandardScaler, OneHotEncoder
from sklearn.compose import ColumnTransformer
from sklearn.pipeline import Pipeline
from sklearn.ensemble import RandomForestClassifier
from sklearn.tree import DecisionTreeClassifier
from sklearn.model_selection import train_test_split, GridSearchCV, StratifiedKFold, cross_val_score
from sklearn.metrics import classification_report

import joblib
from pathlib import Path

BASE_DIR = Path(__file__).resolve().parent
MODEL_PATH = BASE_DIR / "best_model_rf.pkl"

best_model_rf, lbEncoder = joblib.load(MODEL_PATH)

CURRENT_YEAR = 2000


# ============================================================
# 훈련 모델 생성 함수
# ============================================================
def train_best_model(df, model_type='rf'):
    """
    df: 원본 데이터프레임(train.csv)
    model_type: 'rf' 또는 'dt'
    
    반환: best_model, lbEncoder
    """
    # 1️⃣ 파생 변수 생성
    df['HouseAge'] = CURRENT_YEAR - df['YearBuilt']
    df['Remodeled'] = (df['YearRemodAdd'] != df['YearBuilt']).astype(int)
    
    # 2️⃣ 타겟 생성
    def house_condition_label(row):
        if (row['HouseAge'] <= 15) and (row['OverallCond'] >= 7):
            return 'Good'
        elif (row['HouseAge'] >= 50) and (row['OverallCond'] <= 4):
            return 'Poor'
        else:
            return 'Normal'
    df['ConditionLabel'] = df.apply(house_condition_label, axis=1)
    
    # 3️⃣ 피쳐/타겟 분리
    featureDF = df[['HouseAge', 'Remodeled', 'OverallCond']]
    targetSR = df['ConditionLabel']
    
    # 4️⃣ 학습용/테스트용 분리
    x_train, x_test, y_train, y_test = train_test_split(
        featureDF, targetSR, test_size=0.2, random_state=42, stratify=targetSR
    )
    
    # 5️⃣ 타겟 인코딩
    lbEncoder = LabelEncoder()
    en_y_train = lbEncoder.fit_transform(y_train)
    en_y_test = lbEncoder.transform(y_test)
    
    # 6️⃣ Pipeline 설정
    numeric_features = ['HouseAge', 'Remodeled', 'OverallCond']
    preprocessor = ColumnTransformer(
        transformers=[
            ('num', StandardScaler(), numeric_features)
        ]
    )
    
    if model_type=='rf':
        pipeline = Pipeline([
            ('preprocessor', preprocessor),
            ('rf', RandomForestClassifier(random_state=42))
        ])
        param_grid = {
            'rf__n_estimators': [100, 200],
            'rf__max_depth': [None, 5, 10],
            'rf__min_samples_split': [2, 5],
            'rf__min_samples_leaf': [1, 2],
            'rf__max_features': ['auto', 'sqrt']
        }
    elif model_type=='dt':
        pipeline = Pipeline([
            ('preprocessor', preprocessor),
            ('dt', DecisionTreeClassifier(random_state=42))
        ])
        param_grid = {
            'dt__max_depth': [None, 5, 10],
            'dt__min_samples_split': [2, 5],
            'dt__min_samples_leaf': [1, 2],
            'dt__max_features': ['auto', 'sqrt']
        }
    else:
        raise ValueError("model_type must be 'rf' or 'dt'")
    
    # 7️⃣ GridSearchCV 학습
    grid_search = GridSearchCV(
        estimator=pipeline,
        param_grid=param_grid,
        cv=5,
        scoring='f1_macro',
        n_jobs=-1
    )
    
    grid_search.fit(x_train, y_train)
    best_model = grid_search.best_estimator_
    
    # 8️⃣ 테스트 데이터 평가
    y_pred = best_model.predict(x_test)
    print(f"\n[{model_type.upper()}] 테스트 데이터 평가")
    print(classification_report(y_test, y_pred))
    
    # 9️⃣ Cross-validation F1
    skf = StratifiedKFold(n_splits=5, shuffle=True, random_state=42)
    cv_f1 = cross_val_score(best_model, x_train, y_train, cv=skf, scoring='f1_macro', n_jobs=-1)
    print(f"[{model_type.upper()}] Cross-validation F1 macro 평균: {cv_f1.mean():.4f}")
    
    return best_model, lbEncoder

# ============================================================
# 예측 함수
# ============================================================
columns = ['YearBuilt', 'YearRemodAdd', 'OverallCond']

# # 한 줄 입력 받기
# raw_input = input("데이터 입력 (YearBuilt YearRemodAdd OverallCond): ")
# values = list(map(int, raw_input.split()))

# # 1행짜리 DataFrame 생성
# new_data = pd.DataFrame([dict(zip(columns, values))])

def predict_new_data(model, lbEncoder, new_df):
    """
    model: 학습된 pipeline 모델
    lbEncoder: 학습 시 사용된 LabelEncoder
    new_df: 최소 컬럼 ['YearBuilt', 'YearRemodAdd', 'OverallCond']
    
    반환: 예측 결과 DataFrame (PredictedLabel + 클래스별 확률)
    """
    df = new_df.copy()
    df['HouseAge'] = CURRENT_YEAR - df['YearBuilt']
    df['Remodeled'] = (df['YearRemodAdd'] != df['YearBuilt']).astype(int)
    
    x_features = df[['HouseAge', 'Remodeled', 'OverallCond']]
    
    pred_encoded = model.predict(x_features)
    pred_proba = model.predict_proba(x_features)
    
    result_df = df.copy()
    result_df['PredictedLabel'] = pred_encoded
    
    for i, class_name in enumerate(lbEncoder.classes_):
        result_df[f'Prob_{class_name}'] = pred_proba[:, i]
    
    return result_df


def make_new_input_df(
    YearBuilt,
    YearRemodAdd,
    OverallCond,
):
    """
    Gradio / API 입력값 → 모델 입력용 DataFrame 변환
    """

    return pd.DataFrame(
        [
            {
                "YearBuilt": YearBuilt,
                "YearRemodAdd": YearRemodAdd,
                "OverallCond": OverallCond,
            }
        ]
    )
