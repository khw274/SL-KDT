# -------------------------------------------------------------
# 모듈 로딩
# -------------------------------------------------------------
# 데이터 전처리
import pandas as pd
import numpy as np

# 시각화
import matplotlib.pyplot as plt
import koreanize_matplotlib
import seaborn as sns

# 머신러닝 
from sklearn.model_selection import GridSearchCV, RandomizedSearchCV    # 튜닝 관련
from sklearn.neighbors import KNeighborsClassifier                      # 학습 알고리즘
from sklearn.model_selection import train_test_split                    # 데이터셋 관련
from sklearn.preprocessing import StandardScaler

# -------------------------------------------------------------
# 데이터 확인 함수
# -------------------------------------------------------------
def check_data(data):
    
    '''데이터 확인 함수'''
    display(data.head(3))
    display(data.info())

# -------------------------------------------------------------
# 컬럼별 기술 통계 확인 함수
# -------------------------------------------------------------
def descriptive_statistics(data):
    
    '''컬럼별 기술 통계 확인 함수'''
    display(data.describe())

    # 숫자 데이터만 가져옴(error 방지)
    num_data = data.select_dtypes(include=[np.number])
    
    print(f"왜도 :\n{num_data.skew()}\n")
    print(f"첨도 :\n{num_data.kurtosis()}\n")
    print(f"상관계수 :\n{num_data.corr()}")

# -------------------------------------------------------------
# 결측치/이상치/중복값 확인 함수
# -------------------------------------------------------------
def check_data_quality(data):

    '''결측치/이상치/중복값 확인 함수'''
    # 결측치
    print(f"=== 결측치 확인 ===\n{data.isnull().sum()}\n")           

    # 중복값
    print(f"=== 중복값 확인 ===\n{data.duplicated().sum()}\n")      
    print(f"=== 중복 데이터 확인 === \n{data[data.duplicated(keep=False)]}\n")  

    # 이상치(boxplot)
    print("=== 이상치 데이터 확인 ===")
    sns.boxplot(data=data)   
    plt.tight_layout()
    plt.show() 
    
    print()

# -------------------------------------------------------------
# 이상치 분석 및 선택적 제거
# -------------------------------------------------------------
def analysis_outlier(data, remove=False, target_col=None):
    
    '''
    이상치 분석 및 선택적 제거 함수
    
    data       : DataFrame - 분석할 데이터
    remove     : bool - True: 제거, False: 분석만
    target_col : str - 제거할 열 이름 (remove=True일 때 필수)
    '''
    # 숫자 데이터만 가져옴(error 방지)
    num_data = data.select_dtypes(include=[np.number])
    
    print("=== 이상치 분석 ===")
    for col in num_data.columns:
        
        # 사분위수
        q1, q3 = data[col].quantile([0.25, 0.75])
        iqr = q3 - q1

        # 하한/상한
        lower = q1 - 1.5*iqr
        upper = q3 + 1.5*iqr
        
        # 이상치
        mask = (data[col] < lower) | (data[col] > upper)
        outliers = data[mask][col]
        
        upper_out = data[data[col] > upper][col]
        lower_out = data[data[col] < lower][col]
        
        # 출력
        print(f"【{col}】 범위: [{lower:.2f}, {upper:.2f}]")
        print(f"  이상치: {len(outliers)}개 (상한: {len(upper_out)}, 하한: {len(lower_out)})")
        # if len(outliers) > 0:
        #     print(f"  값: {sorted(outliers.values)}")

        # 제거
        if remove and col == target_col:
            before = len(data)
            cleanDF = data[(data[col] >= lower) & (data[col] <= upper)]
            after = len(cleanDF)
            print(f"  ✓ 제거됨: {before}행 → {after}행")

        print()

    return cleanDF if remove else None