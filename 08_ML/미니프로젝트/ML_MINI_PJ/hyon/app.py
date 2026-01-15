"""
기존 Gradio 코드에 집값 예측 통합 (HTML 스타일 + 범주형 설명 포함 + 흰색 배경)
House Price Prediction integrated with existing Gradio UI
"""

import joblib
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns
import gradio as gr


# ===================================================================================================
# 모델 로드 (기존 코드)
# ===================================================================================================

rf_pipeline = joblib.load("finance_rf.pkl")
category_info = joblib.load("finance_categories.pkl")

NEIGHBORHOODS = category_info["Neighborhood"]
HOUSE_STYLES = category_info["HouseStyle"]
FOUNDATIONS = category_info["Foundation"]

from seohee import FinanceAccessibilityModel, make_finance_input_df
from hyeonwoo import run_house_price_pipeline

finance_model = FinanceAccessibilityModel(rf_pipeline)

# 글로벌 변수로 결과 저장
_house_price_result = None

# 범주형 변수 설명
QUALITY_DICT = {
    'Ex': 'EXCELLENT (우수)',
    'Gd': 'GOOD (좋음)',
    'TA': 'TYPICAL (보통)',
    'Fa': 'FAIR (낮음)',
    'Po': 'POOR (매우 낮음)'
}

GARAGE_DICT = {
    'Attchd': 'ATTACHED (붙어있음)',
    'Detchd': 'DETACHED (분리됨)',
    'BuiltIn': 'BUILT-IN (내장)',
    'CarPort': 'CARPORT (카포트)',
    'None': 'NONE (없음)'
}

ZONE_DICT = {
    'RL': 'RESIDENTIAL LOW DENSITY (저밀도)',
    'RM': 'RESIDENTIAL MEDIUM DENSITY (중밀도)',
    'FV': 'FLOATING VILLAGE (플로팅)',
    'RH': 'RESIDENTIAL HIGH DENSITY (고밀도)'
}

SALECOND_DICT = {
    'Normal': 'NORMAL (정상)',
    'Abnorml': 'ABNORMAL (비정상)',
    'AdjLand': 'ADJACENT LAND (인접지)',
    'Alloca': 'ALLOCATION (배분)',
    'Family': 'FAMILY (가족)',
    'Partial': 'PARTIAL (부분)'
}

# ===================================================================================================
# 집값 예측 함수 (HTML 결과 반환)
# ===================================================================================================

def predict_house_price(
    OverallQual,
    GrLivArea,
    GarageArea,
    FirstFlrSF,
    MSZoning,
    OverallCond,
    KitchenQual,
    GarageType,
    SaleCondition
):
    """집값 예측 - HTML 포맷 결과 반환"""
    global _house_price_result
    
    # 파이프라인 실행 (그래프 미표시)
    result = run_house_price_pipeline(show_plots=False)
    best_model = result['best_model']
    test_r2 = result['test_r2']
    cv_r2 = result['cv_r2']
    predictions_df = result['predictions']
    
    # 결과 전역 변수에 저장
    _house_price_result = {
        'best_model': best_model,
        'test_r2': test_r2,
        'cv_r2': cv_r2,
        'predictions_df': predictions_df
    }
    
    # 입력 데이터 생성
    new_house = pd.DataFrame({
        'OverallQual': [OverallQual],
        'GrLivArea': [GrLivArea],
        'GarageArea': [GarageArea],
        '1stFlrSF': [FirstFlrSF],
        'MSZoning': [MSZoning],
        'OverallCond': [OverallCond],
        'KitchenQual': [KitchenQual],
        'GarageType': [GarageType],
        'SaleCondition': [SaleCondition]
    })
    
    # 예측
    prediction = best_model.predict(new_house)[0]
    
    # 예측 정확도 메트릭
    mae = predictions_df['오차'].abs().mean()
    mape = predictions_df['오차율(%)'].mean()
    rmse = np.sqrt((predictions_df['오차'] ** 2).mean())
    
    # 신뢰도 계산 및 색상 결정
    confidence = min(100, max(0, (1-mape/50)*100))
    confidence_color = "#27ae60" if confidence > 80 else "#f39c12" if confidence > 60 else "#e74c3c"
    confidence_text = '매우 높음 ★★★★★' if confidence > 80 else '중간 ★★★★' if confidence > 60 else '낮음 ★★★'
    
    # 범주형 변수 설명 추가
    kitchen_text = f"{KitchenQual} ({QUALITY_DICT.get(KitchenQual, '')})"
    garage_text = f"{GarageType} ({GARAGE_DICT.get(GarageType, '')})"
    zone_text = f"{MSZoning} ({ZONE_DICT.get(MSZoning, '')})"
    salecond_text = f"{SaleCondition} ({SALECOND_DICT.get(SaleCondition, '')})"
    
    # 결과 텍스트 (HTML 포맷 - 흰색 배경)
    result_html = f"""
    <div style="font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif; background: #ffffff; border-radius: 15px; padding: 30px; color: #333; box-shadow: 0 10px 30px rgba(0,0,0,0.15); border: 1px solid #e0e0e0;">
        
        <div style="text-align: center; margin-bottom: 30px;">
            <h2 style="margin: 0; font-size: 28px; font-weight: 700; color: #667eea;">주택 가격 예측 결과</h2>
            <p style="margin: 5px 0 0 0; opacity: 0.7; font-size: 14px; color: #666;">AI 기반 정확한 시세 추정</p>
        </div>
        
        <!-- 예측 가격 하이라이트 -->
        <div style="background: linear-gradient(135deg, #ff9800 0%, #ff6f00 100%); border-radius: 12px; padding: 25px; margin-bottom: 25px; text-align: center; color: white;">
            <p style="margin: 0; font-size: 14px; opacity: 0.9; margin-bottom: 10px;">예측 집값</p>
            <h1 style="margin: 0; font-size: 44px; font-weight: 700; color: #ffffff;">${prediction:,.0f}</h1>
            <p style="margin: 10px 0 0 0; font-size: 12px; opacity: 0.85;">±${mae:,.0f} 오차범위</p>
        </div>
        
        <!-- 입력 정보 -->
        <div style="background: #f8f9fa; border-radius: 12px; padding: 20px; margin-bottom: 20px; border: 1px solid #e9ecef;">
            <h3 style="margin: 0 0 15px 0; font-size: 16px; font-weight: 600; color: #333;">입력한 주택 정보</h3>
            <div style="display: grid; grid-template-columns: 1fr 1fr; gap: 12px; font-size: 13px;">
                <div><span style="opacity: 0.7; color: #666;">전체 품질 (OverallQual)</span><br/><strong style="color: #333; font-size: 14px;">{OverallQual}/10</strong></div>
                <div><span style="opacity: 0.7; color: #666;">거실 면적 (GrLivArea)</span><br/><strong style="color: #333; font-size: 14px;">{GrLivArea:,} sq ft</strong></div>
                <div><span style="opacity: 0.7; color: #666;">차고 면적 (GarageArea)</span><br/><strong style="color: #333; font-size: 14px;">{GarageArea:,} sq ft</strong></div>
                <div><span style="opacity: 0.7; color: #666;">1층 면적 (1stFlrSF)</span><br/><strong style="color: #333; font-size: 14px;">{FirstFlrSF:,} sq ft</strong></div>
                <div><span style="opacity: 0.7; color: #666;">지역 (MSZoning)</span><br/><strong style="color: #333; font-size: 14px;">{zone_text}</strong></div>
                <div><span style="opacity: 0.7; color: #666;">전체 상태 (OverallCond)</span><br/><strong style="color: #333; font-size: 14px;">{OverallCond}/9</strong></div>
                <div><span style="opacity: 0.7; color: #666;">주방 품질 (KitchenQual)</span><br/><strong style="color: #333; font-size: 14px;">{kitchen_text}</strong></div>
                <div><span style="opacity: 0.7; color: #666;">차고 유형 (GarageType)</span><br/><strong style="color: #333; font-size: 14px;">{garage_text}</strong></div>
                <div style="grid-column: 1 / -1;"><span style="opacity: 0.7; color: #666;">판매 조건 (SaleCondition)</span><br/><strong style="color: #333; font-size: 14px;">{salecond_text}</strong></div>
            </div>
        </div>
        
        <!-- 모델 성능 -->
        <div style="background: #f8f9fa; border-radius: 12px; padding: 20px; margin-bottom: 20px; border: 1px solid #e9ecef;">
            <h3 style="margin: 0 0 15px 0; font-size: 16px; font-weight: 600; color: #333;">📊 모델 성능 지표</h3>
            <div style="display: grid; grid-template-columns: 1fr 1fr; gap: 15px; font-size: 13px;">
                <div style="background: white; padding: 12px; border-radius: 8px; border-left: 3px solid #3498db;">
                    <span style="opacity: 0.7; color: #666;">R² Score (테스트)</span><br/>
                    <strong style="font-size: 16px; color: #3498db;">{test_r2:.4f}</strong>
                </div>
                <div style="background: white; padding: 12px; border-radius: 8px; border-left: 3px solid #2ecc71;">
                    <span style="opacity: 0.7; color: #666;">R² Score (교차검증)</span><br/>
                    <strong style="font-size: 16px; color: #2ecc71;">{cv_r2:.4f}</strong>
                </div>
                <div style="background: white; padding: 12px; border-radius: 8px; border-left: 3px solid #e74c3c;">
                    <span style="opacity: 0.7; color: #666;">평균 절대 오차 (MAE)</span><br/>
                    <strong style="font-size: 16px; color: #e74c3c;">${mae:,.0f}</strong>
                </div>
                <div style="background: white; padding: 12px; border-radius: 8px; border-left: 3px solid #f39c12;">
                    <span style="opacity: 0.7; color: #666;">평균 오차율 (MAPE)</span><br/>
                    <strong style="font-size: 16px; color: #f39c12;">{mape:.2f}%</strong>
                </div>
                <div style="background: white; padding: 12px; border-radius: 8px; border-left: 3px solid #9b59b6; grid-column: 1 / -1;">
                    <span style="opacity: 0.7; color: #666;">표준편차 (RMSE)</span><br/>
                    <strong style="font-size: 16px; color: #9b59b6;">${rmse:,.0f}</strong>
                </div>
            </div>
        </div>
        
        <!-- 신뢰도 게이지 -->
        <div style="background: #f8f9fa; border-radius: 12px; padding: 20px; border: 1px solid #e9ecef;">
            <div style="display: flex; justify-content: space-between; align-items: center; margin-bottom: 10px;">
                <h3 style="margin: 0; font-size: 16px; font-weight: 600; color: #333;">예측 신뢰도</h3>
                <span style="font-size: 18px; font-weight: 700; color: {confidence_color};">{confidence:.1f}%</span>
            </div>
            <div style="background: #e9ecef; border-radius: 10px; height: 25px; overflow: hidden;">
                <div style="background: linear-gradient(90deg, {confidence_color}, #ffd700); width: {confidence}%; height: 100%; transition: width 0.5s ease; border-radius: 10px;"></div>
            </div>
            <p style="margin: 12px 0 0 0; font-size: 12px; opacity: 0.85; color: #666;">
                {confidence_text}
            </p>
        </div>
    </div>
    """
    
    return result_html


# ===================================================================================================
# 그래프 생성 함수들
# ===================================================================================================

def get_actual_vs_predicted_plot():
    """실제값 vs 예측값 그래프"""
    global _house_price_result
    
    if _house_price_result is None:
        return None
    
    predictions_df = _house_price_result['predictions_df']
    
    fig, ax = plt.subplots(figsize=(9, 7))
    ax.scatter(predictions_df['실제가격'], predictions_df['예측가격'], 
               alpha=0.6, s=60, color='steelblue', edgecolors='navy', linewidth=0.5)
    ax.plot([predictions_df['실제가격'].min(), predictions_df['실제가격'].max()],
            [predictions_df['실제가격'].min(), predictions_df['실제가격'].max()], 
            'r--', lw=2.5, label='완벽한 예측')
    ax.set_xlabel('실제 가격 ($)', fontsize=13, fontweight='bold')
    ax.set_ylabel('예측 가격 ($)', fontsize=13, fontweight='bold')
    ax.set_title('실제값 vs 예측값 (테스트 셋)', fontsize=15, fontweight='bold')
    ax.grid(True, alpha=0.3, linestyle='--')
    ax.legend(fontsize=11)
    plt.tight_layout()
    
    return fig


def get_error_distribution_plot():
    """오차 분포 그래프"""
    global _house_price_result
    
    if _house_price_result is None:
        return None
    
    predictions_df = _house_price_result['predictions_df']
    
    fig, ax = plt.subplots(figsize=(9, 7))
    ax.hist(predictions_df['오차'], bins=30, edgecolor='black', alpha=0.75, color='lightcoral')
    ax.axvline(x=0, color='red', linestyle='--', linewidth=2.5, label='오차=0')
    ax.axvline(x=predictions_df['오차'].mean(), color='blue', linestyle='--', linewidth=2.5, 
               label=f"평균 오차: ${predictions_df['오차'].mean():,.0f}")
    ax.set_xlabel('예측 오차 ($)', fontsize=13, fontweight='bold')
    ax.set_ylabel('빈도', fontsize=13, fontweight='bold')
    ax.set_title('예측 오차 분포', fontsize=15, fontweight='bold')
    ax.legend(fontsize=11)
    ax.grid(True, alpha=0.3, axis='y', linestyle='--')
    plt.tight_layout()
    
    return fig


def get_error_rate_distribution_plot():
    """오차율 분포 그래프"""
    global _house_price_result
    
    if _house_price_result is None:
        return None
    
    predictions_df = _house_price_result['predictions_df']
    mape = predictions_df['오차율(%)'].mean()
    
    fig, ax = plt.subplots(figsize=(9, 7))
    ax.hist(predictions_df['오차율(%)'], bins=30, edgecolor='black', alpha=0.75, color='lightgreen')
    ax.axvline(x=mape, color='blue', linestyle='--', linewidth=2.5, label=f"평균 오차율: {mape:.2f}%")
    ax.set_xlabel('오차율 (%)', fontsize=13, fontweight='bold')
    ax.set_ylabel('빈도', fontsize=13, fontweight='bold')
    ax.set_title('예측 오차율 분포', fontsize=15, fontweight='bold')
    ax.legend(fontsize=11)
    ax.grid(True, alpha=0.3, axis='y', linestyle='--')
    plt.tight_layout()
    
    return fig


# ===================================================================================================
# 기존 함수들 (원본 유지)
# ===================================================================================================

def run_finance_scenario(
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
    input_df = make_finance_input_df(
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
    )
    return finance_model.predict(input_df)


def predict_aggressive(speed, hard_accel, hard_brake):
    return (
        "난폭 운전자" if speed > 120 or hard_accel + hard_brake > 5 else "일반 운전자"
    )


def predict_anomaly(sensor_err, sudden_event):
    return "이상 이벤트 발생" if sensor_err + sudden_event > 3 else "정상"


def predict_lane_depart(offset, duration):
    return round(min(100, offset * duration * 10), 1)


# ===================================================================================================
# Gradio UI (개선된 버전)
# ===================================================================================================

with gr.Blocks() as demo:
    gr.Markdown("## 🚗 SL Corporation · 5조 - 통합 분석 시스템")
    
    with gr.Row():
        # ===============================
        # 입력 영역
        # ===============================
        with gr.Column(scale=1):
            gr.Markdown("### 입력 데이터")
            
            # ---------- 시나리오 1 ----------
            with gr.Tab("난폭 운전자"):
                s1_speed = gr.Slider(0, 160, 120, label="최대 속도 (km/h)")
                s1_accel = gr.Slider(0, 10, 3, label="급가속 횟수")
                s1_brake = gr.Slider(0, 10, 2, label="급감속 횟수")
                btn1 = gr.Button("시나리오 1 분석", variant="primary")
            
            # ---------- 시나리오 2 ----------
            with gr.Tab("금융 접근성"):
                s2_OverallQual = gr.Slider(1, 10, 5, label="OverallQual")
                s2_GrLivArea = gr.Slider(200, 5000, 1500, label="GrLivArea")
                s2_TotRmsAbvGrd = gr.Slider(2, 15, 6, label="전체 방 수")
                s2_FullBath = gr.Slider(0, 4, 2, label="전체 욕실 수")
                s2_YearBuilt = gr.Slider(1870, 2020, 2000, label="건축 연도")
                s2_YearRemodAdd = gr.Slider(1950, 2020, 2010, label="리모델링 연도")
                
                s2_KitchenQual = gr.Dropdown(
                    ["Ex", "Gd", "TA", "Fa", "Po"],
                    value="TA",
                    label="KitchenQual (부엌 품질)"
                )
                s2_ExterQual = gr.Dropdown(
                    ["Ex", "Gd", "TA", "Fa", "Po"],
                    value="TA",
                    label="ExterQual (외벽 품질)"
                )
                s2_HeatingQC = gr.Dropdown(
                    ["Ex", "Gd", "TA", "Fa", "Po"],
                    value="TA",
                    label="HeatingQC (난방 품질)"
                )
                
                s2_Neighborhood = gr.Dropdown(
                    NEIGHBORHOODS,
                    label="Neighborhood"
                )
                s2_HouseStyle = gr.Dropdown(
                    HOUSE_STYLES,
                    label="HouseStyle"
                )
                s2_Foundation = gr.Dropdown(
                    FOUNDATIONS,
                    label="Foundation"
                )
                
                btn2 = gr.Button("시나리오 2 분석", variant="primary")
            
            # ---------- 시나리오 3 ----------
            with gr.Tab("이상 이벤트"):
                s3_sensor = gr.Slider(0, 10, 1, label="센서 오류 횟수")
                s3_event = gr.Slider(0, 10, 1, label="급변 이벤트 횟수")
                btn3 = gr.Button("시나리오 3 분석", variant="primary")
            
            # ---------- 시나리오 4 ----------
            with gr.Tab("경로 이탈"):
                s4_offset = gr.Slider(0, 3, 0.5, label="차선 이탈 거리 (m)")
                s4_time = gr.Slider(0, 10, 2, label="이탈 지속 시간 (s)")
                btn4 = gr.Button("시나리오 4 분석", variant="primary")
            
            # ---------- 시나리오 5 (NEW) ----------
            with gr.Tab("집값 예측"):
                s5_qual = gr.Slider(
                    1, 10, 7,
                    label="OverallQual (전체 품질)",
                    info="1: 매우 낮음 ~ 10: 매우 높음",
                    step=1
                )
                s5_gr_area = gr.Slider(
                    300, 5000, 2000,
                    label="GrLivArea (거실 면적)",
                    info="단위: sq ft",
                    step=100
                )
                s5_garage_area = gr.Slider(
                    0, 1500, 500,
                    label="GarageArea (차고 면적)",
                    info="단위: sq ft",
                    step=50
                )
                s5_first_flr = gr.Slider(
                    400, 4000, 1000,
                    label="1stFlrSF (1층 면적)",
                    info="단위: sq ft",
                    step=100
                )
                s5_cond = gr.Slider(
                    1, 9, 5,
                    label="OverallCond (전체 상태)",
                    info="1: 매우 낮음 ~ 9: 매우 높음",
                    step=1
                )
                s5_zone = gr.Dropdown(
                    ['RL', 'RM', 'FV', 'RH'],
                    value='RL',
                    label="MSZoning (지역 분류)",
                    info="RL: 저밀도, RM: 중밀도, FV: 플로팅, RH: 고밀도"
                )
                s5_kitchen = gr.Dropdown(
                    ['Ex', 'Gd', 'TA', 'Fa', 'Po'],
                    value='Gd',
                    label="KitchenQual (주방 품질)",
                    info="Ex: 우수, Gd: 좋음, TA: 보통, Fa: 낮음, Po: 매우 낮음"
                )
                s5_garage_type = gr.Dropdown(
                    ['Attchd', 'Detchd', 'BuiltIn', 'CarPort', 'None'],
                    value='Attchd',
                    label="GarageType (차고 유형)",
                    info="Attchd: 붙어있음, Detchd: 분리됨, BuiltIn: 내장, CarPort: 카포트"
                )
                s5_sale_cond = gr.Dropdown(
                    ['Normal', 'Abnorml', 'AdjLand', 'Alloca', 'Family', 'Partial'],
                    value='Normal',
                    label="SaleCondition (판매 조건)",
                    info="Normal: 정상, Abnorml: 비정상, AdjLand: 인접지, Family: 가족"
                )
                btn5 = gr.Button("집값 예측", variant="primary")
        
        # ===============================
        # 결과 영역
        # ===============================
        with gr.Column(scale=2):
            gr.Markdown("### 📊 분석 결과")
            
            with gr.Tab("시나리오 1 결과"):
                out1 = gr.Textbox(label="🚨 난폭 운전자 판단")
            
            with gr.Tab("금융 접근성 결과"):
                out2_label = gr.Textbox(label="🏦 금융 접근성 등급")
                out2_score = gr.Number(label="📈 금융 접근성 점수 (0~100)")
            
            with gr.Tab("시나리오 3 결과"):
                out3 = gr.Textbox(label="⚠️ 이상 이벤트 여부")
            
            with gr.Tab("시나리오 4 결과"):
                out4 = gr.Number(label="🛣️ 경로 이탈 위험도 (%)")
            
            with gr.Tab("집값 예측 결과"):
                out5_text = gr.HTML()
                
                with gr.Tab("📈 실제값 vs 예측값"):
                    out5_plot1 = gr.Plot()
                
                with gr.Tab("📉 오차 분포"):
                    out5_plot2 = gr.Plot()
                
                with gr.Tab("📊 오차율 분포"):
                    out5_plot3 = gr.Plot()
    
    # 금융 접근성 입력 모음
    finance_inputs = [
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
    ]
    
    # 집값 예측 입력 모음 
    house_price_inputs = [
        s5_qual,
        s5_gr_area,
        s5_garage_area,
        s5_first_flr,
        s5_zone,
        s5_cond,
        s5_kitchen,
        s5_garage_type,
        s5_sale_cond,
    ]
    
    # 버튼 클릭 이벤트
    btn1.click(
        predict_aggressive,
        inputs=[s1_speed, s1_accel, s1_brake],
        outputs=out1,
    )
    
    btn2.click(
        fn=run_finance_scenario,
        inputs=finance_inputs,
        outputs=[out2_label, out2_score],
    )
    
    btn3.click(
        predict_anomaly,
        inputs=[s3_sensor, s3_event],
        outputs=out3,
    )
    
    btn4.click(
        predict_lane_depart,
        inputs=[s4_offset, s4_time],
        outputs=out4,
    )
    
    btn5.click(
        fn=predict_house_price,
        inputs=house_price_inputs,
        outputs=out5_text,
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