# finance_model.py
# ======================================================
# 금융 접근성 예측 모델 (Service Layer)
# ======================================================

import pandas as pd
import joblib
from pathlib import Path


# ======================================================
# 모델 로드
# ======================================================
BASE_DIR = Path(__file__).resolve().parent
MODEL_PATH = BASE_DIR / "finance_rf.pkl"
CATEGORY_PATH = BASE_DIR / "finance_categories.pkl"

rf_pipeline = joblib.load(MODEL_PATH)
category_info = joblib.load(CATEGORY_PATH)


COMPARE_FEATURES = [
    "GrLivArea",
    "OverallQual",
    "YearBuilt",
    "FullBath",
    "TotRmsAbvGrd",
    "YearRemodAdd",
]

# ======================================================
## 시각화 비교 그래프
# ======================================================
import matplotlib.pyplot as plt

def plot_input_vs_mean(input_df, feature_means):
    input_vals = input_df[COMPARE_FEATURES].iloc[0]
    mean_vals = feature_means

    # 평균 대비 비율
    ratio = input_vals / mean_vals

    fig, ax = plt.subplots(figsize=(7, 4))
    ax.bar(COMPARE_FEATURES, ratio, color="#ff7f0e")

    ax.axhline(1.0, color="gray", linestyle="--", alpha=0.7)
    ax.set_ylabel("평균 대비 비율")
    ax.set_title("입력 주택의 평균 대비 수준")

    plt.xticks(rotation=30)
    plt.tight_layout()
    return fig


# ======================================================
## 설명 생성
# ======================================================
def generate_finance_explanation(input_df, feature_means):
    explanations = []

    # 면적
    if input_df["GrLivArea"].iloc[0] > feature_means["GrLivArea"] * 1.2:
        explanations.append("주거 면적은 평균 대비 넓은 편이며")

    # 품질
    if input_df["OverallQual"].iloc[0] >= feature_means["OverallQual"]:
        explanations.append("전반적인 품질은 평균 이상이지만")
    else:
        explanations.append("전반적인 품질은 평균 수준이며")

    # 질적 요소
    qualitative_limits = []
    for col in ["KitchenQual", "ExterQual", "HeatingQC"]:
        if input_df[col].iloc[0] == "TA":
            qualitative_limits.append(col)

    if qualitative_limits:
        explanations.append("주방·외벽·난방 등 질적 요소는 보통 수준에 머뭅니다")

    # 방 구성
    if input_df["TotRmsAbvGrd"].iloc[0] < feature_means["TotRmsAbvGrd"]:
        explanations.append("방 구성 효율은 평균보다 다소 낮습니다")

    return " ".join(explanations)


# ======================================================
# 금융 접근성 모델 클래스
# ======================================================
class FinanceAccessibilityModel:
    """
    House Prices 기반 금융 접근성 예측 모델
    - 입력: 단일 주택 정보(DataFrame)
    - 출력: (등급, 점수)
    """

    def __init__(self, pipeline):
        self.pipeline = pipeline

    def predict(self, input_df: pd.DataFrame):
        """
        Parameters
        ----------
        input_df : pd.DataFrame
            단일 row DataFrame (모델 학습 시 사용한 컬럼과 동일)

        Returns
        -------
        label : str
            금융 접근성 등급
        score : float
            금융 접근성 점수 (0~100)
        """

        # 클래스별 확률
        prob = self.pipeline.predict_proba(input_df)[0]

        # 확률 기반 점수화
        score = round(
            prob[0] * 30 + prob[1] * 60 + prob[2] * 100,
            1,
        )

        # 점수 → 등급
        if score < 50:
            label = "금융 접근성 낮음"
        elif score < 80:
            label = "금융 접근성 보통"
        else:
            label = "금융 접근성 높음"

        return label, score


# ======================================================
# 입력 DataFrame 생성 함수 (UI / API 공용)
# ======================================================
def make_finance_input_df(
    OverallQual,
    GrLivArea,
    TotRmsAbvGrd,
    FullBath,
    YearBuilt,
    YearRemodAdd,
    KitchenQual,
    ExterQual,
    HeatingQC,
    Neighborhood,
    HouseStyle,
    Foundation,
):
    """
    Gradio / API 입력값 → 모델 입력용 DataFrame 변환
    """

    return pd.DataFrame(
        [
            {
                "OverallQual": OverallQual,
                "GrLivArea": GrLivArea,
                "TotRmsAbvGrd": TotRmsAbvGrd,
                "FullBath": FullBath,
                "YearBuilt": YearBuilt,
                "YearRemodAdd": YearRemodAdd,
                "KitchenQual": KitchenQual,
                "ExterQual": ExterQual,
                "HeatingQC": HeatingQC,
                "Neighborhood": Neighborhood,
                "HouseStyle": HouseStyle,
                "Foundation": Foundation,
            }
        ]
    )


# ======================================================
# 외부에서 바로 쓰기 위한 인스턴스
# ======================================================
finance_model = FinanceAccessibilityModel(rf_pipeline)
