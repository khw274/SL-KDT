from seungbin_function import *
import gradio as gr
import joblib
import pandas as pd

# ===========================================================
# 모델과 LabelEncoder 불러오기
# ===========================================================
best_model_rf, lbEncoder = joblib.load("best_model_rf.pkl")  # 튜플 언패킹

# ===========================================================
# Gradio UI
# ===========================================================
with gr.Blocks(theme=gr.themes.Soft()) as demo:
    gr.Markdown("## 🚗 SL Corporation · 5조")

    with gr.Row():
        # ===============================
        # 입력 영역
        # ===============================
        with gr.Column(scale=1):
            gr.Markdown("### 입력 데이터")

            # ---------- 시나리오 3 ----------
            with gr.Tab("이상 이벤트"):
                s_YearBuilt    = gr.Slider(1800, 2025, 2000, label="YearBuilt")
                s_YearRemodAdd = gr.Slider(1800, 2025, 2010, label="YearRemodAdd")
                s_OverallCond  = gr.Slider(1, 10, 5, label="OverallCond")
                btn_predict    = gr.Button("예측 실행", variant="primary")

        # ===============================
        # 결과 영역
        # ===============================
        with gr.Column(scale=2):
            gr.Markdown("### 📊 예측 결과")
            out_result = gr.Dataframe(label="Predicted Label + Probabilities")

    # 버튼 클릭 시 예측 함수 실행
    def run_prediction(YearBuilt, YearRemodAdd, OverallCond):
        new_data  = make_new_input_df(YearBuilt, YearRemodAdd, OverallCond)
        result_df = predict_new_data(best_model_rf, lbEncoder, new_df=new_data)
        return result_df

    btn_predict.click(
        run_prediction,
        inputs=[s_YearBuilt, s_YearRemodAdd, s_OverallCond],
        outputs=out_result
    )

demo.launch(share=True)
