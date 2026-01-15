#__________________________________________________________________________
# 데이터분석 패키지 Pandas
#__________________________________________________________________________
# 모듈 로딩
#__________________________________________________________________________
import pandas as pd

# 기본 정보 출력
print(f"pandas v.{pd.__version__}")

# 다양한 종류의 데이터 파일 로딩
DATA_FILES = ['../Data/test.csv', 
              '../Data/test.txt', 
              '../Data/test.json']
#_____________________________________________
# 함수명: pandas.read_ 파일확장자( 파일경로 )
#_____________________________________________
# CSV => DataFrame으로 로딩
dataDF = pd.read_csv(DATA_FILES[0])
print(f"타입: {type(dataDF)}")
print(f"출력: \n{dataDF}")

# TXT => DataFrame으로 로딩
dataDF = pd.read_csv(DATA_FILES[1])
dataDF = pd.read_table(DATA_FILES[1])
print(f"타입: {type(dataDF)}")
print(f"출력: \n{dataDF}")

# JSON => DataFrame으로 로딩
dataDF = pd.read_json(DATA_FILES[2])
print(f"타입: {type(dataDF)}")
print(f"출력: \n{dataDF}")