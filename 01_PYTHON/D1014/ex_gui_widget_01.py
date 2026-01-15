#__________________________________________________________________________
# Python GUI Programming - TKinter
#__________________________________________________________________________
# 모듈 로딩
#__________________________________________________________________________
from tkinter import *

# 윈도우 창 인스턴스 생성
mainWin = Tk()

# 윈도우 창에 설정
mainWin.title("현우")
mainWin.geometry("400x500+100+100")  # (width, height, x, y) -> width/height: 창 크기, x/y: 창 위치
mainWin.resizable(True, True)  # 창 크기 조절 가능 유무 (width, height)

# 윈도우에서 발생하는 사용자 이벤트 수신
# 종료 전까지 동작
mainWin.mainloop()
