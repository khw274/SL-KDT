import os                       
from collections import Counter # 개수 세는 함수
import string                   # 알파벳 a-z 사용

def csv_data(path, filename):   # 읽을 경로, 만들 csv파일 이름
    rows = []                   # 각 파일에서 추출한 정보 저장할 리스트
    
    for f in sorted(os.listdir(path)):  # path의 모든 파일을 정렬된 순서로 반복(알파벳 순)
                                        # f: 현재 파일의 이름
                                        # os.listdir(path) : 폴더의 모든 파일명 리스트
        if f.endswith('.txt'):          # txt 파일만 처리
            text = open(path + f, encoding='utf-8').read()      # 텍스트 파일 읽어서 내용 모두 읽기
            
            alpha = [c.lower() for c in text if c.isalpha()]    # 알파벳인지 확인한 후, 
                                                                # 텍스트에서 소문자만 추출
            count = Counter(alpha)                              # 알파벳별 개수 세기
            total = len(alpha)                                  # total 글자 수
            
            line = f'{f},{f.split("-")[0]}'                     # 파일명과 언어코드 
            for letter in string.ascii_lowercase:               # a~z 알파벳 반복
                rate = round(count[letter] / total, 4) if total > 0 else 0  # 각 알파벳의 비율 계산
                line += f',{rate}'                              # 비율 추가
            
            rows.append(line)
    
    with open(filename, 'w', encoding='utf-8') as file:         # csv 쓰기 모드로 열기
        header = 'filename,language,' + ','.join(string.ascii_lowercase)    # 첫 줄 -> 제목
        file.write(header + '\n')                               
        for row in rows:
            file.write(row + '\n')
    
    print(f'✓ {filename} 생성!')

csv_data('./dataset/train/', 'train.csv')
csv_data('./dataset/test/', 'test.csv')
