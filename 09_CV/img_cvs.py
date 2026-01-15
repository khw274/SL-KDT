"""
원본 코드를 그대로 함수화한 이미지 처리 모듈
그레이스케일 변환 옵션 추가
"""
import cv2
import os
import pandas as pd


# -------------------------------------------------------------------------
# 함수 1: 데이터 로딩 및 파일 리스트 가져오기
# -------------------------------------------------------------------------
def load_image_files(data_dir1, data_dir2):
    """
    이미지 파일 리스트 로드
    
    Parameters:
    -----------
    data_dir1 : str
        첫 번째 이미지 디렉토리 경로
    data_dir2 : str
        두 번째 이미지 디렉토리 경로
    
    Returns:
    --------
    tuple : (FILES1, FILES2)
    """
    FILES1 = os.listdir(data_dir1)
    FILES2 = os.listdir(data_dir2)
    
    return FILES1, FILES2


# -------------------------------------------------------------------------
# 함수 2: 데이터 확인 (첫 10개)
# -------------------------------------------------------------------------
def check_files(FILES1, FILES2):
    """
    파일 목록 확인 (처음 10개)
    
    Parameters:
    -----------
    FILES1 : list
        첫 번째 카테고리 파일 리스트
    FILES2 : list
        두 번째 카테고리 파일 리스트
    """
    print("# -------------------------------------------------------------------------")
    print("# 첫 번째 카테고리 데이터 확인")
    print("# -------------------------------------------------------------------------")
    for idx, filename in enumerate(FILES1):
        if idx < 10:
            print(filename)
        else:
            break
    
    print("\n# -------------------------------------------------------------------------")
    print("# 두 번째 카테고리 데이터 확인")
    print("# -------------------------------------------------------------------------")
    for idx, filename in enumerate(FILES2):
        if idx < 10:
            print(filename)
        else:
            break


# -------------------------------------------------------------------------
# 함수 3: CSV 디렉토리 설정
# -------------------------------------------------------------------------
def setup_csv_dir(CSV_DIR):
    """
    CSV 파일 저장 디렉토리 생성/확인
    
    Parameters:
    -----------
    CSV_DIR : str
        CSV 디렉토리 경로
    """
    if not os.path.exists(CSV_DIR):
        os.mkdir(CSV_DIR)
    else:
        print(f'{CSV_DIR} 경로가 이미 존재합니다.')


# -------------------------------------------------------------------------
# 함수 4: 첫 번째 카테고리 이미지 처리
# -------------------------------------------------------------------------
def process_category1_images(DATA_DIR1, FILES1, CSV_FILE, label='apple', use_grayscale=False):
    """
    첫 번째 카테고리 이미지 처리 및 CSV 저장
    (원본 코드의 사과 이미지 처리 부분)
    
    Parameters:
    -----------
    DATA_DIR1 : str
        첫 번째 이미지 디렉토리 경로
    FILES1 : list
        첫 번째 카테고리 파일 리스트
    CSV_FILE : str
        CSV 파일 경로
    label : str
        카테고리 라벨 (기본값: 'apple')
    use_grayscale : bool
        그레이스케일 변환 여부 (기본값: False)
    """
    print("\n# -------------------------------------------------------------------------")
    print(f"# {label} 이미지 처리 (그레이스케일: {use_grayscale})")
    print("# -------------------------------------------------------------------------")
    
    with open(CSV_FILE, mode='a', encoding='utf-8') as f:
        
        for file_name in FILES1:
            img_path1 = f'{DATA_DIR1}/{file_name}'
            print(img_path1)
            
            img1 = cv2.imread(img_path1)
            
            # 그레이스케일 변환
            if use_grayscale:
                img1 = cv2.cvtColor(img1, cv2.COLOR_BGR2GRAY)
            
            img1 = cv2.resize(img1,
                            (0, 0), 
                            fx=0.5, fy=0.5, 
                            interpolation=cv2.INTER_AREA)
            print('1차 :', img1.shape)
            
            
            img1 = cv2.resize(img1, 
                            (70, 70), 
                            interpolation=cv2.INTER_AREA)
            print('2차 :', img1.shape)
            
            
            img1 = img1.reshape(-1)
            print('3차(2D → 1D) :', img1.shape, '\n')
            
            
            raw = [str(i) for i in img1.tolist()]
            raw = ','.join(raw)
            
            
            f.write(f'{label},{raw}\n')


# -------------------------------------------------------------------------
# 함수 5: 두 번째 카테고리 이미지 처리
# -------------------------------------------------------------------------
def process_category2_images(DATA_DIR2, FILES2, CSV_FILE, label='banana', use_grayscale=False):
    """
    두 번째 카테고리 이미지 처리 및 CSV 저장
    (원본 코드의 바나나 이미지 처리 부분)
    
    Parameters:
    -----------
    DATA_DIR2 : str
        두 번째 이미지 디렉토리 경로
    FILES2 : list
        두 번째 카테고리 파일 리스트
    CSV_FILE : str
        CSV 파일 경로
    label : str
        카테고리 라벨 (기본값: 'banana')
    use_grayscale : bool
        그레이스케일 변환 여부 (기본값: False)
    """
    print("\n# -------------------------------------------------------------------------")
    print(f"# {label} 이미지 처리 (그레이스케일: {use_grayscale})")
    print("# -------------------------------------------------------------------------")
    
    with open(CSV_FILE, mode='a', encoding='utf-8') as f:
        
        for file_name in FILES2:
            img_path2 = f'{DATA_DIR2}/{file_name}'
            print(img_path2)
            
            img2 = cv2.imread(img_path2)
            
            # 그레이스케일 변환
            if use_grayscale:
                img2 = cv2.cvtColor(img2, cv2.COLOR_BGR2GRAY)
            
            img2 = cv2.resize(img2,
                            (0, 0), 
                            fx=0.5, fy=0.5, 
                            interpolation=cv2.INTER_AREA)
            print('1차 :', img2.shape)
            
            
            img2 = cv2.resize(img2, 
                            (70, 70), 
                            interpolation=cv2.INTER_AREA)
            print('2차 :', img2.shape)
            
            
            
            img2 = img2.reshape(-1)
            print('3차(2D → 1D) :', img2.shape, '\n')
            
            
            raw = [str(i) for i in img2.tolist()]
            raw = ','.join(raw)
            
            
            f.write(f'{label},{raw}\n')


# -------------------------------------------------------------------------
# 함수 6: 전체 파이프라인 (원본 코드 그대로 + 그레이스케일 옵션)
# -------------------------------------------------------------------------
def process_images_pipeline(DATA_DIR1, DATA_DIR2, CSV_DIR, CSV_FILE, label1='apple', label2='banana', use_grayscale=False):
    """
    전체 이미지 처리 파이프라인
    원본 코드의 모든 단계를 순차적으로 실행
    
    Parameters:
    -----------
    DATA_DIR1 : str
        첫 번째 이미지 디렉토리 경로
    DATA_DIR2 : str
        두 번째 이미지 디렉토리 경로
    CSV_DIR : str
        CSV 파일 저장 디렉토리
    CSV_FILE : str
        CSV 파일 경로
    label1 : str
        첫 번째 카테고리 라벨 (기본값: 'apple')
    label2 : str
        두 번째 카테고리 라벨 (기본값: 'banana')
    use_grayscale : bool
        그레이스케일 변환 여부 (기본값: False)
    """
    # 1-1. 모듈 로딩 (import는 파일 상단에서 실행)
    print("# -------------------------------------------------------------------------")
    print("# 1-1. 모듈 로딩")
    print("# -------------------------------------------------------------------------")
    print("cv2, os, pandas 모듈 로드 완료\n")
    
    # 1-2. 데이터 로딩
    print("# -------------------------------------------------------------------------")
    print("# 1-2. 데이터 로딩")
    print("# -------------------------------------------------------------------------")
    FILES1, FILES2 = load_image_files(DATA_DIR1, DATA_DIR2)
    print(f"첫 번째 디렉토리 로드: {len(FILES1)}개 파일")
    print(f"두 번째 디렉토리 로드: {len(FILES2)}개 파일\n")
    
    # 데이터 확인
    check_files(FILES1, FILES2)
    
    # 2-1. CSV 파일명 설정
    print("\n# -------------------------------------------------------------------------")
    print("# 2-1. csv 파일명")
    print("# -------------------------------------------------------------------------")
    setup_csv_dir(CSV_DIR)
    print(f"CSV 파일 경로: {CSV_FILE}")
    print(f"그레이스케일 사용: {use_grayscale}\n")
    
    # 2-2. 이미지 처리
    print("# -------------------------------------------------------------------------")
    print("# 2-2. 이미지 처리")
    print("# -------------------------------------------------------------------------")
    
    # 첫 번째 카테고리 처리
    process_category1_images(DATA_DIR1, FILES1, CSV_FILE, label1, use_grayscale)
    
    # 두 번째 카테고리 처리
    process_category2_images(DATA_DIR2, FILES2, CSV_FILE, label2, use_grayscale)
    
    print("\n# -------------------------------------------------------------------------")
    print("# 처리 완료")
    print("# -------------------------------------------------------------------------")
    print(f"✓ CSV 파일 생성 완료: {CSV_FILE}")


# -------------------------------------------------------------------------
# 메인 실행 부분
# -------------------------------------------------------------------------
if __name__ == "__main__":
    
    # 경로 설정
    DATA_DIR1 = './data/img/apples'
    DATA_DIR2 = './data/img/bananas'
    CSV_DIR = './data/csv'
    CSV_FILE = './data/csv/fruits.csv'
    
    # 전체 파이프라인 실행 (컬러 이미지 - 기본값)
    process_images_pipeline(
        DATA_DIR1=DATA_DIR1,
        DATA_DIR2=DATA_DIR2,
        CSV_DIR=CSV_DIR,
        CSV_FILE=CSV_FILE,
        label1='apple',
        label2='banana',
        use_grayscale=False  # False: 컬러, True: 그레이스케일
    )
    
    
    # ===== 다른 카테고리 처리 예시 (주석 해제하여 사용) =====
    
    # 예시 1: 포도 + 딸기 (그레이스케일)
    # process_images_pipeline(
    #     DATA_DIR1='./data/img/grapes',
    #     DATA_DIR2='./data/img/strawberries',
    #     CSV_DIR='./data/csv',
    #     CSV_FILE='./data/csv/berries_gray.csv',
    #     label1='grape',
    #     label2='strawberry',
    #     use_grayscale=True
    # )
    
    # 예시 2: 고양이 + 개 (컬러)
    # process_images_pipeline(
    #     DATA_DIR1='./data/img/cats',
    #     DATA_DIR2='./data/img/dogs',
    #     CSV_DIR='./data/csv',
    #     CSV_FILE='./data/csv/animals.csv',
    #     label1='cat',
    #     label2='dog',
    #     use_grayscale=False
    # )
    
    # 예시 3: 장미 + 튤립 (그레이스케일)
    # process_images_pipeline(
    #     DATA_DIR1='./data/img/roses',
    #     DATA_DIR2='./data/img/tulips',
    #     CSV_DIR='./data/csv',
    #     CSV_FILE='./data/csv/flowers_gray.csv',
    #     label1='rose',
    #     label2='tulip',
    #     use_grayscale=True
    # )