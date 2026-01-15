# =========================================================
# 모듈 로드
# =========================================================
import joblib
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import gradio as gr
import koreanize_matplotlib

# =========================================================
# 시나리오별 모듈 import
# =========================================================
# --- 시나리오 2 (seohee) ---
from seohee.seohee import (
    FinanceAccessibilityModel,
    make_finance_input_df,
    plot_input_vs_mean,
    generate_finance_explanation,
)

# --- 시나리오 3 (seungbin) ---
from seungbin.seungbin_function import (
    make_new_input_df,
    predict_new_data,
)

# --- 시나리오 5 (hyeonwoo) ---
from hyon.hyeonwoo import run_house_price_pipeline

# =========================================================
# 모델 로드
# =========================================================
# 시나리오 2
rf_pipeline = joblib.load("./seohee/finance_rf.pkl")
category_info = joblib.load("./seohee/finance_categories.pkl")

NEIGHBORHOODS = category_info["Neighborhood"]
HOUSE_STYLES = category_info["HouseStyle"]
FOUNDATIONS = category_info["Foundation"]

finance_model = FinanceAccessibilityModel(rf_pipeline)

# 시나리오 3
best_model_rf, lbEncoder = joblib.load("./seungbin/best_model_rf.pkl")

# 시나리오 2 시각화용 평균
dataDF = pd.read_csv("train.csv")
COMPARE_FEATURES = [
    "GrLivArea",
    "OverallQual",
    "YearBuilt",
    "FullBath",
    "TotRmsAbvGrd",
    "YearRemodAdd",
]
FEATURE_MEANS = dataDF[COMPARE_FEATURES].mean()


# =========================================================
# 시나리오 함수 정의
# =========================================================
##### 시나리오 2 : 금융 접근성
def run_finance_scenario(*args):
    input_df = make_finance_input_df(*args)
    label, score = finance_model.predict(input_df)
    fig = plot_input_vs_mean(input_df, FEATURE_MEANS)
    explanation = generate_finance_explanation(input_df, FEATURE_MEANS)
    return label, score, explanation, fig


##### 시나리오 3 : 주택 상태 등급
def run_house_condition_prediction(YearBuilt, YearRemodAdd, OverallCond):
    new_df = make_new_input_df(YearBuilt, YearRemodAdd, OverallCond)
    result_df = predict_new_data(best_model_rf, lbEncoder, new_df)
    return result_df


# =========================================================
# 시나리오 5 : 집값 예측 (HTML 풀 버전)
# =========================================================
_house_price_result = None


def predict_house_price(
    OverallQual,
    GrLivArea,
    GarageArea,
    FirstFlrSF,
    MSZoning,
    OverallCond,
    KitchenQual,
    GarageType,
    SaleCondition,
):
    global _house_price_result

    # 파이프라인 실행 (모델 + 결과)
    result = run_house_price_pipeline(show_plots=False)
    best_model = result["best_model"]
    predictions_df = result["predictions"]
    test_r2 = result["test_r2"]
    cv_r2 = result["cv_r2"]

    _house_price_result = {"predictions_df": predictions_df}

    # 입력 데이터
    new_house = pd.DataFrame(
        {
            "OverallQual": [OverallQual],
            "GrLivArea": [GrLivArea],
            "GarageArea": [GarageArea],
            "1stFlrSF": [FirstFlrSF],
            "MSZoning": [MSZoning],
            "OverallCond": [OverallCond],
            "KitchenQual": [KitchenQual],
            "GarageType": [GarageType],
            "SaleCondition": [SaleCondition],
        }
    )

    # 예측
    pred = best_model.predict(new_house)[0]

    # 성능 지표
    mae = predictions_df["오차"].abs().mean()
    rmse = np.sqrt((predictions_df["오차"] ** 2).mean())
    mape = predictions_df["오차율(%)"].mean()

    # 신뢰도 계산
    confidence = min(100, max(0, (1 - mape / 50) * 100))
    confidence_color = (
        "#27ae60" if confidence > 80 else "#f39c12" if confidence > 60 else "#e74c3c"
    )

    # ===============================
    # HTML 결과
    # ===============================
    return f"""
    <div style="
        background:#ffffff;
        border-radius:18px;
        padding:32px;
        box-shadow:0 10px 30px rgba(0,0,0,0.15);
        max-width:640px;
        font-family: 'Segoe UI', sans-serif;
    ">

        <h2 style="margin-bottom:8px;">🏠 예측 집값</h2>

        <div style="
            font-size:42px;
            font-weight:800;
            color:#2c3e50;
            margin-bottom:6px;
        ">
            ${pred:,.0f}
        </div>

        <div style="color:#555; margin-bottom:18px;">
            평균 절대 오차(MAE): ± ${mae:,.0f}
        </div>

        <hr style="margin:20px 0;">

        <h3 style="margin-bottom:10px;">📊 모델 성능</h3>
        <ul style="line-height:1.7; font-size:14px;">
            <li><b>R² (Test)</b> : {test_r2:.3f}</li>
            <li><b>R² (Cross Validation)</b> : {cv_r2:.3f}</li>
            <li><b>RMSE</b> : ${rmse:,.0f}</li>
            <li><b>MAPE</b> : {mape:.2f}%</li>
        </ul>

        <h3 style="margin-top:22px;">📈 예측 신뢰도</h3>
        <div style="
            background:#ecf0f1;
            border-radius:12px;
            height:22px;
            overflow:hidden;
            margin-bottom:6px;
        ">
            <div style="
                width:{confidence:.1f}%;
                height:100%;
                background:{confidence_color};
            "></div>
        </div>
        <div style="font-size:13px; color:#555;">
            신뢰도 점수: <b>{confidence:.1f}%</b>
        </div>

        <div style="
            margin-top:22px;
            padding:14px;
            background:#f7f9fb;
            border-radius:12px;
            font-size:13px;
            color:#333;
        ">
            ✔ 본 예측은 주택의 <b>면적, 품질, 상태, 입지 특성</b>을 기반으로  
            학습된 회귀 모델(RandomForest 등)의 결과입니다.
        </div>

    </div>
    """

# ===================================================================================================
# 그래프 생성 함수들
# ===================================================================================================


def get_actual_vs_predicted_plot():
    global _house_price_result
    if _house_price_result is None:
        return None

    predictions_df = _house_price_result["predictions_df"]

    fig, ax = plt.subplots(figsize=(9, 7))
    ax.scatter(predictions_df["실제가격"], predictions_df["예측가격"], alpha=0.6)
    ax.plot(
        [predictions_df["실제가격"].min(), predictions_df["실제가격"].max()],
        [predictions_df["실제가격"].min(), predictions_df["실제가격"].max()],
        "r--",
        label="Perfect Prediction",
    )
    ax.set_xlabel("Actual Price")
    ax.set_ylabel("Predicted Price")
    ax.set_title("Actual vs Predicted")
    ax.legend()
    ax.grid(True)
    return fig


def get_error_distribution_plot():
    global _house_price_result
    if _house_price_result is None:
        return None

    predictions_df = _house_price_result["predictions_df"]

    fig, ax = plt.subplots(figsize=(9, 7))
    ax.hist(predictions_df["오차"], bins=30)
    ax.axvline(0, color="red", linestyle="--")
    ax.set_title("Error Distribution")
    return fig


def get_error_rate_distribution_plot():
    global _house_price_result
    if _house_price_result is None:
        return None

    predictions_df = _house_price_result["predictions_df"]

    fig, ax = plt.subplots(figsize=(9, 7))
    ax.hist(predictions_df["오차율(%)"], bins=30)
    ax.set_title("Error Rate Distribution (%)")
    return fig


# =========================================================
# Gradio UI
# =========================================================
with gr.Blocks(theme=gr.themes.Soft()) as demo:
    gr.Markdown("## 🚗 SL Corporation · 5조 통합 시스템")

    with gr.Row():
        # ===============================
        # 입력 영역
        # ===============================
        with gr.Column(scale=1):
            gr.Markdown("### 입력 데이터")

            # ---------- 시나리오 2 ----------
            with gr.Tab("금융 접근성"):
                s2_OverallQual = gr.Slider(1, 10, 5)
                s2_GrLivArea = gr.Slider(200, 5000, 1500)
                s2_TotRmsAbvGrd = gr.Slider(2, 15, 6)
                s2_FullBath = gr.Slider(0, 4, 2)
                s2_YearBuilt = gr.Slider(1870, 2020, 2000)
                s2_YearRemodAdd = gr.Slider(1950, 2020, 2010)

                s2_KitchenQual = gr.Dropdown(["Ex", "Gd", "TA", "Fa", "Po"], value="TA")
                s2_ExterQual = gr.Dropdown(["Ex", "Gd", "TA", "Fa", "Po"], value="TA")
                s2_HeatingQC = gr.Dropdown(["Ex", "Gd", "TA", "Fa", "Po"], value="TA")

                s2_Neighborhood = gr.Dropdown(NEIGHBORHOODS)
                s2_HouseStyle = gr.Dropdown(HOUSE_STYLES)
                s2_Foundation = gr.Dropdown(FOUNDATIONS)

                btn2 = gr.Button("시나리오 2 분석")

            # ---------- 시나리오 3 ----------
            with gr.Tab("주택 상태 등급"):
                s3_YearBuilt = gr.Slider(1800, 2025, 2000)
                s3_YearRemodAdd = gr.Slider(1800, 2025, 2010)
                s3_OverallCond = gr.Slider(1, 10, 5)

                btn3 = gr.Button("주택 상태 예측")

            # ---------- 시나리오 5 ----------
            with gr.Tab("집값 예측"):
                s5_qual = gr.Slider(1, 10, 7)
                s5_gr = gr.Slider(300, 5000, 2000)
                s5_gar = gr.Slider(0, 1500, 500)
                s5_flr = gr.Slider(400, 4000, 1000)
                s5_cond = gr.Slider(1, 9, 5)
                s5_zone = gr.Dropdown(["RL", "RM", "FV", "RH"], value="RL")
                s5_kitchen = gr.Dropdown(["Ex", "Gd", "TA", "Fa", "Po"], value="Gd")
                s5_garage_type = gr.Dropdown(
                    ["Attchd", "Detchd", "BuiltIn", "CarPort", "None"]
                )
                s5_sale = gr.Dropdown(
                    ["Normal", "Abnorml", "AdjLand", "Alloca", "Family", "Partial"]
                )

                btn5 = gr.Button("집값 예측")

        # ===============================
        # 결과 영역
        # ===============================
        with gr.Column(scale=2):
            with gr.Tab("금융 접근성 결과"):
                out2_label = gr.Textbox()
                out2_score = gr.Number()
                out2_explain = gr.Textbox(lines=3)
                out2_plot = gr.Plot()

            with gr.Tab("주택 상태 결과"):
                out3 = gr.Dataframe()

            with gr.Tab("집값 예측 결과"):
                out5 = gr.HTML()

                with gr.Tab("📈 실제값 vs 예측값"):
                    out5_plot1 = gr.Plot()

                with gr.Tab("📉 오차 분포"):
                    out5_plot2 = gr.Plot()

                with gr.Tab("📊 오차율 분포"):
                    out5_plot3 = gr.Plot()

    # =====================================================
    # 이벤트 연결
    # =====================================================
    btn2.click(
        run_finance_scenario,
        [
            s2_OverallQual,
            s2_GrLivArea,
            s2_TotRmsAbvGrd,
            s2_FullBath,
            s2_YearBuilt,
            s2_YearRemodAdd,
            s2_KitchenQual,
            s2_ExterQual,
            s2_HeatingQC,
            s2_Neighborhood,
            s2_HouseStyle,
            s2_Foundation,
        ],
        [out2_label, out2_score, out2_explain, out2_plot],
    )

    btn3.click(
        run_house_condition_prediction,
        [s3_YearBuilt, s3_YearRemodAdd, s3_OverallCond],
        out3,
    )

    btn5.click(
        predict_house_price,
        [
            s5_qual,
            s5_gr,
            s5_gar,
            s5_flr,
            s5_zone,
            s5_cond,
            s5_kitchen,
            s5_garage_type,
            s5_sale,
        ],
        out5,
    ).then(
        fn=get_actual_vs_predicted_plot,
        outputs=out5_plot1,
    ).then(
        fn=get_error_distribution_plot,
        outputs=out5_plot2,
    ).then(
        fn=get_error_rate_distribution_plot,
        outputs=out5_plot3,
    )

demo.launch(share=True)
