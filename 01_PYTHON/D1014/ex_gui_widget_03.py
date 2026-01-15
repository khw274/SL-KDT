#__________________________________________________________________________
# Python GUI Programming - TKinter
# **Label Widget: 텍스트, 이미지 출력 UI요소
#__________________________________________________________________________
# 모듈 로딩
#__________________________________________________________________________
from tkinter import *
import os                         # 이미지 경로 관련 모듈
from PIL import Image, ImageTk    # TK 미지원 이미지 처리를 위한 모듈
#__________________________________________________________________________
# 사용자 정의 함수
#__________________________________________________________________________
# - 함수기능: 이미지 데이터에서 TKinter용 이미지 추출 후 반환
# - 함수이름: get_img
# - 매개변수: imgpath       - 이미지명 포함 경로
# - 반환결과: Tkinter용 이미지 데이터
#__________________________________________________________________________

def get_img(imgpath):
    # => 지원&미지원 이미지 처리
    _ , ext = os.path.splitext(imgpath)
    if ext in ['.png','.bmp', '.gif', '.ppm', '.pgm']:
        photo = PhotoImage(file=imgpath)
    else:
        # 순수 이미지 데이터 추출
        img = Image.open(imgpath)
        # 이미지 데이터 전달
        photo = ImageTk.PhotoImage(image = img)
#__________________________________________________________________________
# 윈도우 관련
#__________________________________________________________________________
# 윈도우 창 인스턴스 생성
mainWin = Tk()

# 윈도우 창에 설정
mainWin.title("현우")
 # (width, height, x, y) -> width/height: 창 크기, x/y: 창 위치
mainWin.geometry("400x500+100+100") 
# 창 크기 조절 가능 유무 (width, height)
mainWin.resizable(True, True)  
#__________________________________________________________________________
# 윈도우에 배치될 UI 요소들 - Image Label 요소
# 지원 이미지 확장자: .png, .bpm, .gif, .ppm
# 미지원 이미지 경우: 로우 데이터 추출 필요 => conda install pillow
#__________________________________________________________________________
# 인스턴스 생성
# => 지원 이미지: png, bmp, gif, ppm, prn

IMG_FILE1 = "../Image/cat.jpg"  # jpg는 미지원 
IMG_FILE2 = "../Image/cat2.png"

# 이미지 라벨 인스턴스 생성
imgLB1 = Label(mainWin, image = get_img(IMG_FILE2))
imgLB2 = Label(mainWin, image = get_img(IMG_FILE2))
imgLB3 = Label(mainWin, image = get_img(IMG_FILE2))

# UI 인스턴스 윈도우에 배치
imgLB1.pack(side = 'left')
imgLB1.pack()
imgLB1.pack(side = 'right')
#__________________________________________________________________________
# 윈도우에서 발생하는 사용자 이벤트 수신
#__________________________________________________________________________
# 종료 전까지 동작
mainWin.mainloop()
