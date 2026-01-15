import pandas as pd
import joblib
import matplotlib.pyplot as plt

# ===============================
# 회귀 모델 로드
# ===============================
REG_MODEL_PATH = "house_price_reg.pkl"
reg_model = joblib.load(REG_MODEL_PATH)

FEATURE_COLS = [
    "GrLivArea", "TotalBsmtSF", "GarageCars", "GarageArea",
    "FullBath", "TotRmsAbvGrd",
    "OverallQual", "OverallCond",
    "KitchenQual_ord", "ExterQual_ord",
    "YearBuilt", "YearRemodAdd",
    "Neighborhood"
]

def make_model_input(
    GrLivArea,
    TotalBsmtSF,
    GarageCars,
    GarageArea,
    FullBath,
    TotRmsAbvGrd,
    OverallQual,
    OverallCond,
    KitchenQual_ord,
    ExterQual_ord,
    YearBuilt,
    YearRemodAdd,
    Neighborhood
):
    df = pd.DataFrame([{
        "GrLivArea": float(GrLivArea),
        "TotalBsmtSF": float(TotalBsmtSF),
        "GarageCars": int(GarageCars),
        "GarageArea": float(GarageArea),
        "FullBath": int(FullBath),
        "TotRmsAbvGrd": int(TotRmsAbvGrd),
        "OverallQual": int(OverallQual),
        "OverallCond": int(OverallCond),
        "KitchenQual_ord": int(KitchenQual_ord),
        "ExterQual_ord": int(ExterQual_ord),
        "YearBuilt": int(YearBuilt),
        "YearRemodAdd": int(YearRemodAdd),
        "Neighborhood": str(Neighborhood).strip()
    }])
    return df[FEATURE_COLS]

def judge_price(asking_price, predicted_price, low_th=0.90, high_th=1.10):
    ratio = asking_price / predicted_price

    if ratio < low_th:
        label = "Undervalued (저평가)"
        decision = "👍 추천"
        comment = "예상 적정가격 대비 낮은 가격으로, 투자 매력도가 높습니다."
    elif ratio > high_th:
        label = "Overvalued (고평가)"
        decision = "👎 비추천"
        comment = "예상 적정가격 대비 높은 가격으로, 신중한 접근이 필요합니다."
    else:
        label = "Fair (적정가)"
        decision = "✊ 중립"
        comment = "예상 적정가격 범위 내의 매물입니다."

    return label, decision, comment, ratio

# 이 함수가 반드시 있어야 import 가능
def predict_house_with_price_ui(
    AskingPrice,
    GrLivArea,
    TotalBsmtSF,
    GarageCars,
    GarageArea,
    FullBath,
    TotRmsAbvGrd,
    OverallQual,
    OverallCond,
    KitchenQual_ord,
    ExterQual_ord,
    YearBuilt,
    YearRemodAdd,
    Neighborhood
):
    asking_price = float(AskingPrice)

    X_input = make_model_input(
        GrLivArea,
        TotalBsmtSF,
        GarageCars,
        GarageArea,
        FullBath,
        TotRmsAbvGrd,
        OverallQual,
        OverallCond,
        KitchenQual_ord,
        ExterQual_ord,
        YearBuilt,
        YearRemodAdd,
        Neighborhood
    )

    predicted_price = float(reg_model.predict(X_input)[0])

    label, decision, comment, ratio = judge_price(
        asking_price, predicted_price
    )

    price_gap = asking_price - predicted_price

    return (
        label,
        decision,
        f"{predicted_price:,.0f} $",
        f"{asking_price:,.0f} $",
        f"{price_gap:+,.0f} $",
        f"{ratio*100:.1f} %",
        comment
    )


def _make_scenario4_input(
    GrLivArea, TotalBsmtSF, GarageCars, GarageArea,
    FullBath, TotRmsAbvGrd,
    OverallQual, OverallCond,
    KitchenQual_ord, ExterQual_ord,
    YearBuilt, YearRemodAdd,
    Neighborhood
):
    return pd.DataFrame([{
        "GrLivArea": GrLivArea,
        "TotalBsmtSF": TotalBsmtSF,
        "GarageCars": GarageCars,
        "GarageArea": GarageArea,
        "FullBath": FullBath,
        "TotRmsAbvGrd": TotRmsAbvGrd,
        "OverallQual": OverallQual,
        "OverallCond": OverallCond,
        "KitchenQual_ord": KitchenQual_ord,
        "ExterQual_ord": ExterQual_ord,
        "YearBuilt": YearBuilt,
        "YearRemodAdd": YearRemodAdd,
        "Neighborhood": Neighborhood
    }])[FEATURE_COLS]

# ===============================
# (시나리오 4) 출력 정책
# ===============================
def _judge_price(asking_price, predicted_price):
    ratio = asking_price / predicted_price

    if ratio < 0.9:
        return (
            "Undervalued (저평가)",
            "👍 추천",
            f"{predicted_price:,.0f} $",
            f"{asking_price:,.0f} $",
            f"{asking_price - predicted_price:+,.0f} $",
            f"{ratio*100:.1f} %",
            "예상 적정가 대비 낮은 가격입니다."
        )
    elif ratio > 1.1:
        return (
            "Overvalued (고평가)",
            "👎 비추천",
            f"{predicted_price:,.0f} $",
            f"{asking_price:,.0f} $",
            f"{asking_price - predicted_price:+,.0f} $",
            f"{ratio*100:.1f} %",
            "예상 적정가 대비 높은 가격입니다."
        )
    else:
        return (
            "Fair (적정가)",
            "✊ 중립",
            f"{predicted_price:,.0f} 원",
            f"{asking_price:,.0f} 원",
            f"{asking_price - predicted_price:+,.0f} 원",
            f"{ratio*100:.1f} %",
            "예상 적정가 범위 내의 매물입니다."
        )

# ===============================
# ⭐ 시나리오 4 엔트리 포인트 (공용 UI가 부르는 함수)
# ===============================
def scenario4_handler(
    AskingPrice,
    GrLivArea,
    TotalBsmtSF,
    GarageCars,
    GarageArea,
    FullBath,
    TotRmsAbvGrd,
    OverallQual,
    OverallCond,
    KitchenQual_ord,
    ExterQual_ord,
    YearBuilt,
    YearRemodAdd,
    Neighborhood
):
    """
    [시나리오 4 계약]
    입력  : 위 파라미터들
    출력  : (평가결과, 판단, 예상가, 입력가, 차이, 비율, 코멘트)
    """

    X = _make_scenario4_input(
        GrLivArea, TotalBsmtSF, GarageCars, GarageArea,
        FullBath, TotRmsAbvGrd,
        OverallQual, OverallCond,
        KitchenQual_ord, ExterQual_ord,
        YearBuilt, YearRemodAdd,
        Neighborhood
    )

    predicted_price = float(reg_model.predict(X)[0])

    return _judge_price(float(AskingPrice), predicted_price)

# def scenario4_handler(
#     AskingPrice,
#     GrLivArea,
#     TotalBsmtSF,
#     GarageCars,
#     GarageArea,
#     FullBath,
#     TotRmsAbvGrd,
#     OverallQual,
#     OverallCond,
#     KitchenQual_ord,
#     ExterQual_ord,
#     YearBuilt,
#     YearRemodAdd,
#     Neighborhood
# ):
#     X = _make_scenario4_input(
#         GrLivArea, TotalBsmtSF, GarageCars, GarageArea,
#         FullBath, TotRmsAbvGrd,
#         OverallQual, OverallCond,
#         KitchenQual_ord, ExterQual_ord,
#         YearBuilt, YearRemodAdd,
#         Neighborhood
#     )

#     asking_price = float(AskingPrice)
#     predicted_price = float(reg_model.predict(X)[0])

#     # 기존 텍스트 결과 7개
#     result = _judge_price(asking_price, predicted_price)

#     # ✅ 그래프 생성
#     fig = plot_price_comparison(predicted_price, asking_price)

#     # ✅ 반드시 8개 반환
#     return (*result, fig)


# ## 시각화 함수
# def plot_price_comparison(pred_price, input_price):
#     fig, ax = plt.subplots(figsize=(4, 3))

#     labels = ["예상 적정가", "입력 매물가"]
#     values = [pred_price, input_price]
#     colors = ["#4A90E2", "#E74C3C"]

#     ax.bar(labels, values, color=colors)
#     ax.set_title("가격 비교")
#     ax.set_ylabel("가격")

#     for i, v in enumerate(values):
#         ax.text(i, v, f"{int(v):,}원", ha="center", va="bottom")

#     return fig