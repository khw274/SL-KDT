"""
주택 가격 예측 모듈
House Price Prediction Module

Functions:
    - run_house_price_pipeline(): 전체 파이프라인 실행
    - evaluate_and_plot(): 모델 평가 및 시각화
    - analysis_outlier(): 이상치 분석 및 제거
"""

import pandas as pd
import numpy as np
import seaborn as sns
import matplotlib.pyplot as plt

try:
    import koreanize_matplotlib
except ImportError:
    pass

from sklearn.model_selection import train_test_split, cross_val_score
from sklearn.preprocessing import OneHotEncoder, OrdinalEncoder, StandardScaler
from sklearn.compose import ColumnTransformer
from sklearn.pipeline import Pipeline
from sklearn.impute import SimpleImputer
from sklearn.linear_model import Ridge
from sklearn.ensemble import RandomForestRegressor
from sklearn.metrics import r2_score, mean_squared_error

pd.set_option('mode.copy_on_write', True)


# ===================================================================================================
# 이상치 분석 함수
# ===================================================================================================

def analysis_outlier(data, remove=False, target_col=None):
    """이상치 분석 및 선택적 제거 함수

    Parameters
    ----------
    data : pandas.DataFrame
        분석할 데이터
    remove : bool, default False
        True 이면 target_col 기준으로 이상치를 제거한 DataFrame 반환
    target_col : str, optional
        제거할 열 이름 (remove=True 일 때 필수)
    """

    num_data = data.select_dtypes(include=[np.number])

    print("=== 이상치 분석 ===")
    cleanDF = data.copy()

    for col in num_data.columns:
        q1, q3 = data[col].quantile([0.25, 0.75])
        iqr = q3 - q1

        lower = q1 - 1.5 * iqr
        upper = q3 + 1.5 * iqr

        mask = (data[col] < lower) | (data[col] > upper)
        outliers = data[mask][col]

        upper_out = data[data[col] > upper][col]
        lower_out = data[data[col] < lower][col]

        print(f"【{col}】")
        print(f"  최소값: {data[col].min():.2f}, 최댓값: {data[col].max():.2f}")
        print(f"  범위: [{lower:.2f}, {upper:.2f}]")
        print(f"  이상치: {len(outliers)}개 (상한: {len(upper_out)}, 하한: {len(lower_out)})")

        if remove and col == target_col:
            before = len(cleanDF)
            cleanDF = cleanDF[(cleanDF[col] >= lower) & (cleanDF[col] <= upper)]
            after = len(cleanDF)
            print(f"  ✓ 제거됨: {before}행 → {after}행")

        print()

    return cleanDF if remove else None


# ===================================================================================================
# 모델 평가 및 시각화 함수 (교차검증 + 그래프)
# ===================================================================================================

def evaluate_and_plot(model, X_train, y_train, X_test, y_test, model_name, cv_folds=5):
    """모델을 학습하고 평가, 시각화하는 함수"""
    model.fit(X_train, y_train)
    y_pred = model.predict(X_test)

    r2 = r2_score(y_test, y_pred)
    rmse = np.sqrt(mean_squared_error(y_test, y_pred))

    cv_scores = cross_val_score(model, X_train, y_train, cv=cv_folds, scoring='r2')
    cv_rmse_scores = -cross_val_score(model, X_train, y_train, cv=cv_folds, scoring='neg_mean_squared_error')
    cv_rmse_scores = np.sqrt(cv_rmse_scores)
    
    print(f"[{model_name}] R2: {r2:.4f}, RMSE: {rmse:.2f}")
    print(f"  교차검증 R² Score: {cv_scores.mean():.4f} (+/- {cv_scores.std():.4f})")
    print(f"  교차검증 RMSE: {cv_rmse_scores.mean():.2f} (+/- {cv_rmse_scores.std():.2f})")
    print()

    # 그래프: 실제값 vs 예측값
    plt.figure(figsize=(6, 6))
    plt.scatter(y_test, y_pred, alpha=0.6)
    plt.plot([y_test.min(), y_test.max()], [y_test.min(), y_test.max()], 'r--')
    plt.title(f'{model_name} Predicted vs Actual')
    plt.xlabel('Actual Price')
    plt.ylabel('Predicted Price')
    plt.grid(True, alpha=0.3)
    plt.tight_layout()
    plt.show()

    return r2, cv_scores.mean()


# ===================================================================================================
# 전체 파이프라인 함수
# ===================================================================================================

def run_house_price_pipeline(csv_path: str = "./Data/house.csv", show_plots=True):
    """주택 가격 예측 전체 파이프라인 실행 함수.

    Parameters
    ----------
    csv_path : str, default "./train.csv"
        학습에 사용할 CSV 파일 경로
    show_plots : bool, default True
        그래프 표시 여부
        
    Returns
    -------
    dict
        결과 딕셔너리
    """

    # ===================================================================================================
    # [1-2] 데이터 로드
    # ===================================================================================================
    filename = csv_path
    dataDF = pd.read_csv(filename)

    print(f"데이터 크기: {dataDF.shape}")
    print(dataDF.head())

    houseDF = dataDF.copy()

    # ===================================================================================================
    # [2] 상관관계 분석 및 수치형 변수 선정
    # ===================================================================================================

    numeric_houseDF = houseDF.select_dtypes(include=[np.number])
    print(f"수치형 컬럼 개수: {len(numeric_houseDF.columns)}")
    print()

    corr_matrix = numeric_houseDF.corr()

    if show_plots:
        plt.figure(figsize=(20, 20))
        sns.heatmap(corr_matrix, annot=True, fmt='.2f', cmap='coolwarm')
        plt.title('전체 수치형 변수 상관계수')
        plt.tight_layout()
        plt.show()

    corr_ = corr_matrix['SalePrice'].abs().sort_values(ascending=False)
    print("SalePrice와의 상관계수 (0.6 이상):")
    print(corr_[corr_ >= 0.6])
    print()

    highCorr = corr_[corr_ >= 0.6].index.tolist()

    if 'SalePrice' in highCorr:
        highCorr.remove('SalePrice')

    print(f"선택된 수치형 피쳐 (0.6 이상): {highCorr}")
    print()

    corrDF = numeric_houseDF[highCorr]
    corr_matrix2 = corrDF.corr()

    if show_plots:
        plt.figure(figsize=(12, 10))
        sns.heatmap(corr_matrix2, annot=True, fmt='.2f', cmap='coolwarm')
        plt.title('선택된 수치형 변수들 간의 상관계수')
        plt.tight_layout()
        plt.show()

    print("[상관계수 분석 결과]")
    print("상관관계가 있는 변수들 (상관계수 >= 0.7):")
    print()

    high_corr_pairs = []
    for i in range(len(corr_matrix2.columns)):
        for j in range(i + 1, len(corr_matrix2.columns)):
            corr_value = corr_matrix2.iloc[i, j]
            if abs(corr_value) >= 0.7:
                col1 = corr_matrix2.columns[i]
                col2 = corr_matrix2.columns[j]
                high_corr_pairs.append((col1, col2, corr_value))
                print(f"  {col1} ↔ {col2}: {corr_value:.3f}")

    if len(high_corr_pairs) == 0:
        print("  (상관계수가 0.7 이상인 변수 쌍이 없습니다)")

    top_features = ['OverallQual', 'GrLivArea', 'GarageArea', '1stFlrSF']
    print(f"\n최종 선택된 수치형 피쳐: {top_features}")

    # ===================================================================================================
    # [3-1] 이상치 분석 및 처리
    # ===================================================================================================

    print(analysis_outlier(houseDF[top_features]))
    print(houseDF[top_features].info())

    outliers_idx = houseDF[(houseDF['GrLivArea'] > 4000) & (houseDF['SalePrice'] < 200000)].index
    houseDF.drop(outliers_idx, inplace=True)
    print(f"\nGrLivArea 이상치 {len(outliers_idx)}개 제거 완료\n")

    print(analysis_outlier(houseDF[top_features]))
    print(houseDF[top_features].info())

    # ===================================================================================================
    # [4] 범주형 변수 선택 및 분류
    # ===================================================================================================
    # ✓ 수정: Ordinal(순서형) 변수와 Nominal(명목형) 변수 분리

    ordinal_categorical = ['OverallCond', 'KitchenQual']  # 순서가 있는 범주형
    nominal_categorical = ['MSZoning', 'SaleCondition']   # 순서가 없는 범주형 (명목형)

    # ===================================================================================================
    # [5] 최종 데이터셋 구성 (X, y)
    # ===================================================================================================

    final_features = top_features + ordinal_categorical + nominal_categorical

    featureDF = houseDF[final_features]
    targetSR = houseDF['SalePrice']

    print(f"\n최종 데이터 shape: featureDF{featureDF.shape}, targetSR{targetSR.shape}")

    x_train, x_test, y_train, y_test = train_test_split(
        featureDF,
        targetSR,
        test_size=0.2,
        random_state=42
    )

    print(featureDF.info())

    # ===================================================================================================
    # [6] 파이프라인 구축
    # ===================================================================================================
    # ✓ 수정: OrdinalEncoder 추가로 순서형 범주형 변수 처리

    numeric_cols = x_train.select_dtypes(include=['int64', 'float64']).columns.tolist()
    ordinal_cols = ordinal_categorical  # 순서형 범주형 변수
    nominal_cols = nominal_categorical  # 명목형 범주형 변수

    # 수치형 변수 전처리
    numeric_transformer = Pipeline(steps=[
        ('scaler', StandardScaler())
    ])

    # ✓ 순서형 범주형 변수 전처리 (OrdinalEncoder)
    ordinal_transformer = Pipeline(steps=[
        ('imputer', SimpleImputer(strategy='constant', fill_value='missing')),
        ('ordinal', OrdinalEncoder(
            categories=[
                ['1', '2', '3', '4', '5', '6', '7', '8', '9'],  # OverallCond: 1~9
                ['Fa', 'TA', 'Gd', 'Ex']  # KitchenQual: Fa < TA < Gd < Ex
            ],
            handle_unknown='use_encoded_value',
            unknown_value=-1
        ))
    ])

    # ✓ 명목형 범주형 변수 전처리 (OneHotEncoder)
    nominal_transformer = Pipeline(steps=[
        ('imputer', SimpleImputer(strategy='constant', fill_value='missing')),
        ('onehot', OneHotEncoder(handle_unknown='ignore', sparse_output=False))
    ])

    # ✓ 전체 전처리 파이프라인
    preprocessor = ColumnTransformer(
        transformers=[
            ('num', numeric_transformer, numeric_cols),
            ('ord', ordinal_transformer, ordinal_cols),  # ✓ 순서형 변수 처리
            ('nom', nominal_transformer, nominal_cols)   # ✓ 명목형 변수 처리
        ])

    ridgeModel = Pipeline([
        ('preprocessor', preprocessor),
        ('regressor', Ridge(alpha=10.0))
    ])

    rfModel = Pipeline([
        ('preprocessor', preprocessor),
        ('regressor', RandomForestRegressor(n_estimators=100, random_state=42, n_jobs=-1))
    ])

    # ===================================================================================================
    # [7] 평가 및 시각화 (교차검증 + 그래프)
    # ===================================================================================================

    print("============ 모델 평가 ============")
    ridgeR2, ridge_cv_r2 = evaluate_and_plot(ridgeModel, x_train, y_train, x_test, y_test, "Ridge", cv_folds=5)
    rfR2, rf_cv_r2 = evaluate_and_plot(rfModel, x_train, y_train, x_test, y_test, "Random Forest", cv_folds=5)

    if rfR2 > ridgeR2:
        best_model = rfModel
        best_name = "Random Forest"
        best_test_r2 = rfR2
        best_cv_r2 = rf_cv_r2
    else:
        best_model = ridgeModel
        best_name = "Ridge"
        best_test_r2 = ridgeR2
        best_cv_r2 = ridge_cv_r2

    print(f"\n최적 모델 선정: {best_name} (테스트 R2: {best_test_r2:.4f}, 교차검증 R2: {best_cv_r2:.4f})")

    # ===================================================================================================
    # [8] 최종 예측 분석 + 시각화
    # ===================================================================================================

    print("\n" + "=" * 60)
    print("[최종 예측 분석]")
    print("=" * 60)

    y_pred_test = best_model.predict(x_test)

    predictionsDF = pd.DataFrame({
        '실제가격': y_test.values,
        '예측가격': y_pred_test,
        '오차': y_test.values - y_pred_test,
        '오차율(%)': np.abs(y_test.values - y_pred_test) / y_test.values * 100
    })

    print("\n[예측 통계]")
    print(f"MAE: ${predictionsDF['오차'].abs().mean():,.2f}")
    print(f"MAPE: {predictionsDF['오차율(%)'].mean():.2f}%")
    print(f"Median Absolute Error(오차의 중앙값): ${predictionsDF['오차'].abs().median():,.2f}")
    print(f"표준편차: ${predictionsDF['오차'].std():,.2f}")

    print("\n[상위 10개 예측 결과]")
    top_10_predictions = predictionsDF.head(10).copy()
    top_10_predictions['실제가격'] = top_10_predictions['실제가격'].astype(int)
    top_10_predictions['예측가격'] = top_10_predictions['예측가격'].astype(int)
    top_10_predictions['오차'] = top_10_predictions['오차'].astype(int)
    print(top_10_predictions.to_string(index=False))

    # 예측 오류 분포 시각화
    if show_plots:
        fig, axes = plt.subplots(2, 2, figsize=(14, 10))

        # 1. 실제값 vs 예측값 (산점도)
        axes[0, 0].scatter(predictionsDF['실제가격'], predictionsDF['예측가격'], alpha=0.6, s=50)
        axes[0, 0].plot([predictionsDF['실제가격'].min(), predictionsDF['실제가격'].max()],
                        [predictionsDF['실제가격'].min(), predictionsDF['실제가격'].max()], 'r--', lw=2)
        axes[0, 0].set_xlabel('실제 가격 ($)')
        axes[0, 0].set_ylabel('예측 가격 ($)')
        axes[0, 0].set_title('실제값 vs 예측값')
        axes[0, 0].grid(True, alpha=0.3)

        # 2. 오차 분포
        axes[0, 1].hist(predictionsDF['오차'], bins=30, edgecolor='black', alpha=0.7, color='skyblue')
        axes[0, 1].axvline(x=0, color='red', linestyle='--', linewidth=2, label='오차=0')
        axes[0, 1].set_xlabel('예측 오차 ($)')
        axes[0, 1].set_ylabel('빈도')
        axes[0, 1].set_title('예측 오차 분포')
        axes[0, 1].legend()
        axes[0, 1].grid(True, alpha=0.3, axis='y')

        # 3. 오차율 분포
        axes[1, 0].hist(predictionsDF['오차율(%)'], bins=30, edgecolor='black', alpha=0.7, color='lightcoral')
        axes[1, 0].axvline(x=predictionsDF['오차율(%)'].mean(), color='blue', linestyle='--', linewidth=2,
                           label=f"평균: {predictionsDF['오차율(%)'].mean():.2f}%")
        axes[1, 0].set_xlabel('오차율 (%)')
        axes[1, 0].set_ylabel('빈도')
        axes[1, 0].set_title('예측 오차율 분포')
        axes[1, 0].legend()
        axes[1, 0].grid(True, alpha=0.3, axis='y')

        # 4. 실제가격 구간별 평균 오차
        price_bins = pd.cut(predictionsDF['실제가격'], bins=5)
        mean_error_by_price = predictionsDF.groupby(price_bins)['오차'].mean()
        axes[1, 1].bar(range(len(mean_error_by_price)), mean_error_by_price.values, color='lightgreen', edgecolor='black')
        axes[1, 1].axhline(y=0, color='red', linestyle='--', linewidth=2)
        axes[1, 1].set_xlabel('실제 가격 구간')
        axes[1, 1].set_ylabel('평균 오차 ($)')
        axes[1, 1].set_title('가격대별 평균 예측 오차')
        axes[1, 1].set_xticks(range(len(mean_error_by_price)))
        axes[1, 1].set_xticklabels([
            f'${int(interval.left / 1000)}-{int(interval.right / 1000)}K'
            for interval in mean_error_by_price.index
        ], rotation=45, ha='right')
        axes[1, 1].grid(True, alpha=0.3, axis='y')

        plt.tight_layout()
        plt.show()

        # 모델 성능 비교 시각화
        fig, ax = plt.subplots(figsize=(10, 6))

        models_perf = pd.DataFrame({
            '모델': ['Ridge', 'Random Forest'],
            'R² Score': [ridgeR2, rfR2],
            'RMSE': [
                np.sqrt(mean_squared_error(y_test, ridgeModel.predict(x_test))),
                np.sqrt(mean_squared_error(y_test, rfModel.predict(x_test)))
            ]
        })

        x_pos = np.arange(len(models_perf))
        width = 0.35

        ax.bar(x_pos - width / 2, models_perf['R² Score'], width, label='R² Score', alpha=0.8)
        ax2 = ax.twinx()
        ax2.bar(x_pos + width / 2, models_perf['RMSE'], width, label='RMSE', color='orange', alpha=0.8)

        ax.set_xlabel('모델')
        ax.set_ylabel('R² Score', color='tab:blue')
        ax2.set_ylabel('RMSE ($)', color='tab:orange')
        ax.set_title(f'모델 성능 비교 (최고 성능: {best_name})')
        ax.set_xticks(x_pos)
        ax.set_xticklabels(models_perf['모델'])
        ax.tick_params(axis='y', labelcolor='tab:blue')
        ax2.tick_params(axis='y', labelcolor='tab:orange')

        lines1, labels1 = ax.get_legend_handles_labels()
        lines2, labels2 = ax2.get_legend_handles_labels()
        ax.legend(lines1 + lines2, labels1 + labels2, loc='upper left')

        plt.tight_layout()
        plt.show()

    print("\n" + "=" * 60)
    print("[모델 선정 결과]")
    print("=" * 60)
    print(f"✓ 최적 모델: {best_name}")
    print(f"✓ 테스트 R² Score: {best_test_r2:.4f}")
    print(f"✓ 교차검증 R² Score: {best_cv_r2:.4f}")
    print(f"✓ RMSE: ${np.sqrt(mean_squared_error(y_test, y_pred_test)):,.2f}")
    print(f"✓ 평균 절대 오차 (MAE): ${predictionsDF['오차'].abs().mean():,.2f}")
    print("=" * 60)
    
    return {
        'best_model': best_model,
        'best_name': best_name,
        'test_r2': best_test_r2,
        'cv_r2': best_cv_r2,
        'predictions': predictionsDF,
        'ridge_model': ridgeModel,
        'rf_model': rfModel,
        'mae': predictionsDF['오차'].abs().mean(),
        'mape': predictionsDF['오차율(%)'].mean(),
    }


__all__ = ['run_house_price_pipeline', 'evaluate_and_plot', 'analysis_outlier']


if __name__ == "__main__":
    result = run_house_price_pipeline()
"""
주택 가격 예측 모듈
House Price Prediction Module

Functions:
    - run_house_price_pipeline(): 전체 파이프라인 실행
    - evaluate_and_plot(): 모델 평가 및 시각화
    - analysis_outlier(): 이상치 분석 및 제거
"""

import pandas as pd
import numpy as np
import seaborn as sns
import matplotlib.pyplot as plt

try:
    import koreanize_matplotlib
except ImportError:
    pass

from sklearn.model_selection import train_test_split, cross_val_score
from sklearn.preprocessing import OneHotEncoder, OrdinalEncoder, StandardScaler
from sklearn.compose import ColumnTransformer
from sklearn.pipeline import Pipeline
from sklearn.impute import SimpleImputer
from sklearn.linear_model import Ridge
from sklearn.ensemble import RandomForestRegressor
from sklearn.metrics import r2_score, mean_squared_error

pd.set_option('mode.copy_on_write', True)


# ===================================================================================================
# 이상치 분석 함수
# ===================================================================================================

def analysis_outlier(data, remove=False, target_col=None):
    """이상치 분석 및 선택적 제거 함수

    Parameters
    ----------
    data : pandas.DataFrame
        분석할 데이터
    remove : bool, default False
        True 이면 target_col 기준으로 이상치를 제거한 DataFrame 반환
    target_col : str, optional
        제거할 열 이름 (remove=True 일 때 필수)
    """

    num_data = data.select_dtypes(include=[np.number])

    print("=== 이상치 분석 ===")
    cleanDF = data.copy()

    for col in num_data.columns:
        q1, q3 = data[col].quantile([0.25, 0.75])
        iqr = q3 - q1

        lower = q1 - 1.5 * iqr
        upper = q3 + 1.5 * iqr

        mask = (data[col] < lower) | (data[col] > upper)
        outliers = data[mask][col]

        upper_out = data[data[col] > upper][col]
        lower_out = data[data[col] < lower][col]

        print(f"【{col}】")
        print(f"  최소값: {data[col].min():.2f}, 최댓값: {data[col].max():.2f}")
        print(f"  범위: [{lower:.2f}, {upper:.2f}]")
        print(f"  이상치: {len(outliers)}개 (상한: {len(upper_out)}, 하한: {len(lower_out)})")

        if remove and col == target_col:
            before = len(cleanDF)
            cleanDF = cleanDF[(cleanDF[col] >= lower) & (cleanDF[col] <= upper)]
            after = len(cleanDF)
            print(f"  ✓ 제거됨: {before}행 → {after}행")

        print()

    return cleanDF if remove else None


# ===================================================================================================
# 모델 평가 및 시각화 함수 (교차검증 + 그래프)
# ===================================================================================================

def evaluate_and_plot(model, X_train, y_train, X_test, y_test, model_name, cv_folds=5):
    """모델을 학습하고 평가, 시각화하는 함수"""
    model.fit(X_train, y_train)
    y_pred = model.predict(X_test)

    r2 = r2_score(y_test, y_pred)
    rmse = np.sqrt(mean_squared_error(y_test, y_pred))

    cv_scores = cross_val_score(model, X_train, y_train, cv=cv_folds, scoring='r2')
    cv_rmse_scores = -cross_val_score(model, X_train, y_train, cv=cv_folds, scoring='neg_mean_squared_error')
    cv_rmse_scores = np.sqrt(cv_rmse_scores)
    
    print(f"[{model_name}] R2: {r2:.4f}, RMSE: {rmse:.2f}")
    print(f"  교차검증 R² Score: {cv_scores.mean():.4f} (+/- {cv_scores.std():.4f})")
    print(f"  교차검증 RMSE: {cv_rmse_scores.mean():.2f} (+/- {cv_rmse_scores.std():.2f})")
    print()

    # 그래프: 실제값 vs 예측값
    plt.figure(figsize=(6, 6))
    plt.scatter(y_test, y_pred, alpha=0.6)
    plt.plot([y_test.min(), y_test.max()], [y_test.min(), y_test.max()], 'r--')
    plt.title(f'{model_name} Predicted vs Actual')
    plt.xlabel('Actual Price')
    plt.ylabel('Predicted Price')
    plt.grid(True, alpha=0.3)
    plt.tight_layout()
    plt.show()

    return r2, cv_scores.mean()


# ===================================================================================================
# 전체 파이프라인 함수
# ===================================================================================================

def run_house_price_pipeline(csv_path: str = "./Data/house.csv", show_plots=True):
    """주택 가격 예측 전체 파이프라인 실행 함수.

    Parameters
    ----------
    csv_path : str, default "./train.csv"
        학습에 사용할 CSV 파일 경로
    show_plots : bool, default True
        그래프 표시 여부
        
    Returns
    -------
    dict
        결과 딕셔너리
    """

    # ===================================================================================================
    # [1-2] 데이터 로드
    # ===================================================================================================
    filename = csv_path
    dataDF = pd.read_csv(filename)

    print(f"데이터 크기: {dataDF.shape}")
    print(dataDF.head())

    houseDF = dataDF.copy()

    # ===================================================================================================
    # [2] 상관관계 분석 및 수치형 변수 선정
    # ===================================================================================================

    numeric_houseDF = houseDF.select_dtypes(include=[np.number])
    print(f"수치형 컬럼 개수: {len(numeric_houseDF.columns)}")
    print()

    corr_matrix = numeric_houseDF.corr()

    if show_plots:
        plt.figure(figsize=(20, 20))
        sns.heatmap(corr_matrix, annot=True, fmt='.2f', cmap='coolwarm')
        plt.title('전체 수치형 변수 상관계수')
        plt.tight_layout()
        plt.show()

    corr_ = corr_matrix['SalePrice'].abs().sort_values(ascending=False)
    print("SalePrice와의 상관계수 (0.6 이상):")
    print(corr_[corr_ >= 0.6])
    print()

    highCorr = corr_[corr_ >= 0.6].index.tolist()

    if 'SalePrice' in highCorr:
        highCorr.remove('SalePrice')

    print(f"선택된 수치형 피쳐 (0.6 이상): {highCorr}")
    print()

    corrDF = numeric_houseDF[highCorr]
    corr_matrix2 = corrDF.corr()

    if show_plots:
        plt.figure(figsize=(12, 10))
        sns.heatmap(corr_matrix2, annot=True, fmt='.2f', cmap='coolwarm')
        plt.title('선택된 수치형 변수들 간의 상관계수')
        plt.tight_layout()
        plt.show()

    print("[상관계수 분석 결과]")
    print("상관관계가 있는 변수들 (상관계수 >= 0.7):")
    print()

    high_corr_pairs = []
    for i in range(len(corr_matrix2.columns)):
        for j in range(i + 1, len(corr_matrix2.columns)):
            corr_value = corr_matrix2.iloc[i, j]
            if abs(corr_value) >= 0.7:
                col1 = corr_matrix2.columns[i]
                col2 = corr_matrix2.columns[j]
                high_corr_pairs.append((col1, col2, corr_value))
                print(f"  {col1} ↔ {col2}: {corr_value:.3f}")

    if len(high_corr_pairs) == 0:
        print("  (상관계수가 0.7 이상인 변수 쌍이 없습니다)")

    top_features = ['OverallQual', 'GrLivArea', 'GarageArea', '1stFlrSF']
    print(f"\n최종 선택된 수치형 피쳐: {top_features}")

    # ===================================================================================================
    # [3-1] 이상치 분석 및 처리
    # ===================================================================================================

    print(analysis_outlier(houseDF[top_features]))
    print(houseDF[top_features].info())

    outliers_idx = houseDF[(houseDF['GrLivArea'] > 4000) & (houseDF['SalePrice'] < 200000)].index
    houseDF.drop(outliers_idx, inplace=True)
    print(f"\nGrLivArea 이상치 {len(outliers_idx)}개 제거 완료\n")

    print(analysis_outlier(houseDF[top_features]))
    print(houseDF[top_features].info())

    # ===================================================================================================
    # [4] 범주형 변수 선택 및 분류
    # ===================================================================================================
    # ✓ 수정: Ordinal(순서형) 변수와 Nominal(명목형) 변수 분리

    ordinal_categorical = ['OverallCond', 'KitchenQual']  # 순서가 있는 범주형
    nominal_categorical = ['MSZoning', 'SaleCondition']   # 순서가 없는 범주형 (명목형)

    # ===================================================================================================
    # [5] 최종 데이터셋 구성 (X, y)
    # ===================================================================================================

    final_features = top_features + ordinal_categorical + nominal_categorical

    featureDF = houseDF[final_features]
    targetSR = houseDF['SalePrice']

    print(f"\n최종 데이터 shape: featureDF{featureDF.shape}, targetSR{targetSR.shape}")

    x_train, x_test, y_train, y_test = train_test_split(
        featureDF,
        targetSR,
        test_size=0.2,
        random_state=42
    )

    print(featureDF.info())

    # ===================================================================================================
    # [6] 파이프라인 구축
    # ===================================================================================================
    # ✓ 수정: OrdinalEncoder 추가로 순서형 범주형 변수 처리

    numeric_cols = x_train.select_dtypes(include=['int64', 'float64']).columns.tolist()
    ordinal_cols = ordinal_categorical  # 순서형 범주형 변수
    nominal_cols = nominal_categorical  # 명목형 범주형 변수

    # 수치형 변수 전처리
    numeric_transformer = Pipeline(steps=[
        ('scaler', StandardScaler())
    ])

    # ✓ 순서형 범주형 변수 전처리 (OrdinalEncoder)
    ordinal_transformer = Pipeline(steps=[
        ('imputer', SimpleImputer(strategy='constant', fill_value='missing')),
        ('ordinal', OrdinalEncoder(
            categories=[
                ['1', '2', '3', '4', '5', '6', '7', '8', '9'],  # OverallCond: 1~9
                ['Fa', 'TA', 'Gd', 'Ex']  # KitchenQual: Fa < TA < Gd < Ex
            ],
            handle_unknown='use_encoded_value',
            unknown_value=-1
        ))
    ])

    # ✓ 명목형 범주형 변수 전처리 (OneHotEncoder)
    nominal_transformer = Pipeline(steps=[
        ('imputer', SimpleImputer(strategy='constant', fill_value='missing')),
        ('onehot', OneHotEncoder(handle_unknown='ignore', sparse_output=False))
    ])

    # ✓ 전체 전처리 파이프라인
    preprocessor = ColumnTransformer(
        transformers=[
            ('num', numeric_transformer, numeric_cols),
            ('ord', ordinal_transformer, ordinal_cols),  # ✓ 순서형 변수 처리
            ('nom', nominal_transformer, nominal_cols)   # ✓ 명목형 변수 처리
        ])

    ridgeModel = Pipeline([
        ('preprocessor', preprocessor),
        ('regressor', Ridge(alpha=10.0))
    ])

    rfModel = Pipeline([
        ('preprocessor', preprocessor),
        ('regressor', RandomForestRegressor(n_estimators=100, random_state=42, n_jobs=-1))
    ])

    # ===================================================================================================
    # [7] 평가 및 시각화 (교차검증 + 그래프)
    # ===================================================================================================

    print("============ 모델 평가 ============")
    ridgeR2, ridge_cv_r2 = evaluate_and_plot(ridgeModel, x_train, y_train, x_test, y_test, "Ridge", cv_folds=5)
    rfR2, rf_cv_r2 = evaluate_and_plot(rfModel, x_train, y_train, x_test, y_test, "Random Forest", cv_folds=5)

    if rfR2 > ridgeR2:
        best_model = rfModel
        best_name = "Random Forest"
        best_test_r2 = rfR2
        best_cv_r2 = rf_cv_r2
    else:
        best_model = ridgeModel
        best_name = "Ridge"
        best_test_r2 = ridgeR2
        best_cv_r2 = ridge_cv_r2

    print(f"\n최적 모델 선정: {best_name} (테스트 R2: {best_test_r2:.4f}, 교차검증 R2: {best_cv_r2:.4f})")

    # ===================================================================================================
    # [8] 최종 예측 분석 + 시각화
    # ===================================================================================================

    print("\n" + "=" * 60)
    print("[최종 예측 분석]")
    print("=" * 60)

    y_pred_test = best_model.predict(x_test)

    predictionsDF = pd.DataFrame({
        '실제가격': y_test.values,
        '예측가격': y_pred_test,
        '오차': y_test.values - y_pred_test,
        '오차율(%)': np.abs(y_test.values - y_pred_test) / y_test.values * 100
    })

    print("\n[예측 통계]")
    print(f"MAE: ${predictionsDF['오차'].abs().mean():,.2f}")
    print(f"MAPE: {predictionsDF['오차율(%)'].mean():.2f}%")
    print(f"Median Absolute Error(오차의 중앙값): ${predictionsDF['오차'].abs().median():,.2f}")
    print(f"표준편차: ${predictionsDF['오차'].std():,.2f}")

    print("\n[상위 10개 예측 결과]")
    top_10_predictions = predictionsDF.head(10).copy()
    top_10_predictions['실제가격'] = top_10_predictions['실제가격'].astype(int)
    top_10_predictions['예측가격'] = top_10_predictions['예측가격'].astype(int)
    top_10_predictions['오차'] = top_10_predictions['오차'].astype(int)
    print(top_10_predictions.to_string(index=False))

    # 예측 오류 분포 시각화
    if show_plots:
        fig, axes = plt.subplots(2, 2, figsize=(14, 10))

        # 1. 실제값 vs 예측값 (산점도)
        axes[0, 0].scatter(predictionsDF['실제가격'], predictionsDF['예측가격'], alpha=0.6, s=50)
        axes[0, 0].plot([predictionsDF['실제가격'].min(), predictionsDF['실제가격'].max()],
                        [predictionsDF['실제가격'].min(), predictionsDF['실제가격'].max()], 'r--', lw=2)
        axes[0, 0].set_xlabel('실제 가격 ($)')
        axes[0, 0].set_ylabel('예측 가격 ($)')
        axes[0, 0].set_title('실제값 vs 예측값')
        axes[0, 0].grid(True, alpha=0.3)

        # 2. 오차 분포
        axes[0, 1].hist(predictionsDF['오차'], bins=30, edgecolor='black', alpha=0.7, color='skyblue')
        axes[0, 1].axvline(x=0, color='red', linestyle='--', linewidth=2, label='오차=0')
        axes[0, 1].set_xlabel('예측 오차 ($)')
        axes[0, 1].set_ylabel('빈도')
        axes[0, 1].set_title('예측 오차 분포')
        axes[0, 1].legend()
        axes[0, 1].grid(True, alpha=0.3, axis='y')

        # 3. 오차율 분포
        axes[1, 0].hist(predictionsDF['오차율(%)'], bins=30, edgecolor='black', alpha=0.7, color='lightcoral')
        axes[1, 0].axvline(x=predictionsDF['오차율(%)'].mean(), color='blue', linestyle='--', linewidth=2,
                           label=f"평균: {predictionsDF['오차율(%)'].mean():.2f}%")
        axes[1, 0].set_xlabel('오차율 (%)')
        axes[1, 0].set_ylabel('빈도')
        axes[1, 0].set_title('예측 오차율 분포')
        axes[1, 0].legend()
        axes[1, 0].grid(True, alpha=0.3, axis='y')

        # 4. 실제가격 구간별 평균 오차
        price_bins = pd.cut(predictionsDF['실제가격'], bins=5)
        mean_error_by_price = predictionsDF.groupby(price_bins)['오차'].mean()
        axes[1, 1].bar(range(len(mean_error_by_price)), mean_error_by_price.values, color='lightgreen', edgecolor='black')
        axes[1, 1].axhline(y=0, color='red', linestyle='--', linewidth=2)
        axes[1, 1].set_xlabel('실제 가격 구간')
        axes[1, 1].set_ylabel('평균 오차 ($)')
        axes[1, 1].set_title('가격대별 평균 예측 오차')
        axes[1, 1].set_xticks(range(len(mean_error_by_price)))
        axes[1, 1].set_xticklabels([
            f'${int(interval.left / 1000)}-{int(interval.right / 1000)}K'
            for interval in mean_error_by_price.index
        ], rotation=45, ha='right')
        axes[1, 1].grid(True, alpha=0.3, axis='y')

        plt.tight_layout()
        plt.show()

        # 모델 성능 비교 시각화
        fig, ax = plt.subplots(figsize=(10, 6))

        models_perf = pd.DataFrame({
            '모델': ['Ridge', 'Random Forest'],
            'R² Score': [ridgeR2, rfR2],
            'RMSE': [
                np.sqrt(mean_squared_error(y_test, ridgeModel.predict(x_test))),
                np.sqrt(mean_squared_error(y_test, rfModel.predict(x_test)))
            ]
        })

        x_pos = np.arange(len(models_perf))
        width = 0.35

        ax.bar(x_pos - width / 2, models_perf['R² Score'], width, label='R² Score', alpha=0.8)
        ax2 = ax.twinx()
        ax2.bar(x_pos + width / 2, models_perf['RMSE'], width, label='RMSE', color='orange', alpha=0.8)

        ax.set_xlabel('모델')
        ax.set_ylabel('R² Score', color='tab:blue')
        ax2.set_ylabel('RMSE ($)', color='tab:orange')
        ax.set_title(f'모델 성능 비교 (최고 성능: {best_name})')
        ax.set_xticks(x_pos)
        ax.set_xticklabels(models_perf['모델'])
        ax.tick_params(axis='y', labelcolor='tab:blue')
        ax2.tick_params(axis='y', labelcolor='tab:orange')

        lines1, labels1 = ax.get_legend_handles_labels()
        lines2, labels2 = ax2.get_legend_handles_labels()
        ax.legend(lines1 + lines2, labels1 + labels2, loc='upper left')

        plt.tight_layout()
        plt.show()

    print("\n" + "=" * 60)
    print("[모델 선정 결과]")
    print("=" * 60)
    print(f"✓ 최적 모델: {best_name}")
    print(f"✓ 테스트 R² Score: {best_test_r2:.4f}")
    print(f"✓ 교차검증 R² Score: {best_cv_r2:.4f}")
    print(f"✓ RMSE: ${np.sqrt(mean_squared_error(y_test, y_pred_test)):,.2f}")
    print(f"✓ 평균 절대 오차 (MAE): ${predictionsDF['오차'].abs().mean():,.2f}")
    print("=" * 60)
    
    return {
        'best_model': best_model,
        'best_name': best_name,
        'test_r2': best_test_r2,
        'cv_r2': best_cv_r2,
        'predictions': predictionsDF,
        'ridge_model': ridgeModel,
        'rf_model': rfModel,
        'mae': predictionsDF['오차'].abs().mean(),
        'mape': predictionsDF['오차율(%)'].mean(),
    }


__all__ = ['run_house_price_pipeline', 'evaluate_and_plot', 'analysis_outlier']


if __name__ == "__main__":
    result = run_house_price_pipeline()
