## ====================================================================
##              Python GUI Programming - TKinter 
## ====================================================================
## LogIn 화면 구성
## - 사용 Widget
##   * Label  - 타이틀/아이디/비밀번호 3개
##   * Entry  - 아이디/비밀번호       2개
##   * Button - 확인/취소            2개
## - 배치 Layout
## * 표 형식의 Grid
## - 행/열별 여백 설정
##   * padx   - 왼쪽, 오른쪽 바깥여백 설정
##   * pady   - 위쪽, 아래쪽 바깥여백 설정
## ====================================================================

## --------------------------------------------------------------------
## 모듈 로딩 
## --------------------------------------------------------------------
import tkinter 

## --------------------------------------------------------------------
## - 윈도우 관련 
## --------------------------------------------------------------------
## - 윈도우 창 인스턴스 생성 및 설정
window = tkinter.Tk()
window.title("LOGIN")
window.geometry("400x220+300+200")
window.resizable(False, False)


## --------------------------------------------------------------------
## - 윈도우에 배치될 UI요소들 - Button 요소
## --------------------------------------------------------------------
# 인스턴스 생성
# - 0번행: 타이틀
msgLB1 = tkinter.Label(window, text = "LOGIN")

# 타이틀
msgLB1 = tkinter.Label(window, text="LOGIN", font=("Arial", 16))
msgLB1.grid(row=0, column=0, columnspan=2, pady=15)

# 아이디 라벨/입력란
id_label = tkinter.Label(window, text="아이디", width=10, anchor="e")
id_label.grid(row=1, column=0, padx=10, pady=5)

inputID = tkinter.Entry(window, width=30)
inputID.grid(row=1, column=1, padx=10, pady=5)

# 비밀번호 라벨/입력란
pwd_label = tkinter.Label(window, text="비밀번호", width=10, anchor="e")
pwd_label.grid(row=2, column=0, padx=10, pady=5)

inputPWD = tkinter.Entry(window, show="*", width=30)
inputPWD.grid(row=2, column=1, padx=10, pady=5)

# 버튼 (확인/취소)
login_btn = tkinter.Button(window, text="확인", width=12)
login_btn.grid(row=3, column=0, padx=(30, 5), pady=15)

cancel_btn = tkinter.Button(window, text="취소", width=12)
cancel_btn.grid(row=3, column=1, padx=(5, 30), pady=15)

# - 종료 전까지 동작
window.mainloop()
