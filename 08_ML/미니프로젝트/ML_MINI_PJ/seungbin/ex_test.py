from seungbin_function import *
import gradio as gr
import joblib
import pandas as pd

# =========================================================
# 모델 & 인코더 로드
# =========================================================
best_model_rf, lbEncoder = joblib.load("best_model_rf.pkl")

# =========================================================
# Gradio UI
# =========================================================
with gr.Blocks() as demo:
    gr.Markdown("## 🏠 주택 상태 등급 예측 (Random Forest)")

    with gr.Row():
        with gr.Column(scale=1):
            gr.Markdown("### 입력 데이터")

            with gr.Tab("주택 상태 예측"):
                s_YearBuilt = gr.Slider(1800, 2025, 2000, label="YearBuilt")
                s_YearRemodAdd = gr.Slider(1800, 2025, 2010, label="YearRemodAdd")
                s_OverallCond = gr.Slider(1, 10, 5, label="OverallCond")
                btn_predict = gr.Button("예측 실행", variant="primary")

        with gr.Column(scale=2):
            gr.Markdown("### 📊 예측 결과")
            out_result = gr.Dataframe(
                headers=None, datatype="auto", label="Predicted Label + Probabilities"
            )

    def run_prediction(YearBuilt, YearRemodAdd, OverallCond):
        new_df = make_new_input_df(YearBuilt, YearRemodAdd, OverallCond)
        result_df = predict_new_data(best_model_rf, lbEncoder, new_df)
        return result_df

    btn_predict.click(
        run_prediction,
        inputs=[s_YearBuilt, s_YearRemodAdd, s_OverallCond],
        outputs=out_result,
    )

demo.launch(share=True, theme=gr.themes.Soft())
