#___________________________________________________________________________________
# Python 미니 프로젝트: 달력 일정 관리 프로그램
# 김현우
#___________________________________________________________________________________
# 주요 기능:
#   - 월별 달력 출력 및 날짜별 일정 관리
#   - 일정 추가 및 삭제 기능
#   - 현재 날짜 표시 및 일정 존재 시 색상 강조
#___________________________________________________________________________________
## 모듈 로딩
#___________________________________________________________________________________
import calendar                     # 달력 생성 및 요일 계산을 위한 calendar 모듈 불러오기
import tkinter as tk                # GUI 생성을 위한 tkinter 모듈 불러오기 (별칭 tk)
from datetime import datetime       # 현재 날짜/시간 처리를 위해 datetime 클래스만 임포트
from tkinter import simpledialog    # 사용자 입력창을 띄우기 위한 simpledialog 모듈 임포트

#___________________________________________________________________________________
## 전역 변수 설정
#___________________________________________________________________________________
today = datetime.now()  # datetime.now(): 현재 시스템 날짜와 시간 반환 → today 변수에 저장
events = {}             # 비어있는 딕셔너리 생성 → 날짜별 일정 저장용
                        # 형태 예시: {"2025-10-15": [{"text":"회의"}, {"text":"운동"}]}

#___________________________________________________________________________________
## 메인 윈도우 설정
#___________________________________________________________________________________
win = tk.Tk()                   
win.title("캘린더")              
win.geometry("700x500")         


# 1행 확장, 7열 균등 분할 설정 (grid 레이아웃 조정)
win.rowconfigure(1, weight=1)   # 행 1번을 확장 가능하게 설정
for i in range(7):              # 0~6까지 반복 (요일 칸 수)
    win.columnconfigure(i, weight=1)  # 각 열 동일 비율로 확장 가능 설정

#___________________________________________________________________________________
## 라벨 및 버튼 초기 설정
#___________________________________________________________________________________
month_label = tk.Label(win, font=("맑은 고딕", 16)) # 현재 월 표시용 라벨 생성
month_label.grid(row=0, column=3, columnspan=1)     # 첫 줄 중앙(3열)에 배치

calendar_frame = tk.Frame(win)  # 달력 날짜 버튼들을 담을 프레임 생성
calendar_frame.grid(row=1, column=0, columnspan=7, sticky="nsew") # 두 번째 행 전체 사용

# calendar_frame 내부 그리드 확장 설정
for r in range(7):            # 7행: 1행(요일) + 최대 6주
    calendar_frame.rowconfigure(r, weight=1)
for c in range(7):
    calendar_frame.columnconfigure(c, weight=1)
#___________________________________________________________________________________
## 달력 그리기 함수 정의
#___________________________________________________________________________________
def draw_calendar(year, month):
    """
    지정한 연도와 월에 해당하는 달력을 화면에 그리는 함수
    """
    for widget in calendar_frame.winfo_children():  # 기존에 표시된 위젯(버튼 등) 제거
        widget.destroy()                           # 새 달력으로 갱신하기 위해 프레임 초기화

    month_label.config(text=f"{year}년 {month}월") # 상단 라벨에 현재 연/월 표시

    # calendar 모듈로 월별 주차별 날짜 리스트 생성
    cal = calendar.monthcalendar(year, month)       # [[0,1,2,...], [3,4,5,...]] 형태
    days = ["일", "월", "화", "수", "목", "금", "토"]  # 요일 이름 리스트

    # 요일 헤더(라벨) 출력
    for i, day in enumerate(days):                  # enumerate로 인덱스와 요일 동시에
        lbl = tk.Label(calendar_frame, text=day, font=("맑은 고딕", 12, "bold"))
        lbl.grid(row=0, column=i, padx=5, pady=5)   # 첫 번째 행에 요일 배치

    # 날짜 버튼 출력
    for r, week in enumerate(cal):                  # 각 주(리스트)를 행 단위로
        for c, day in enumerate(week):              # 각 요일(값)을 열 단위로
            if day == 0:                            # 해당 칸에 날짜가 없으면
                continue                            # 빈 칸이므로 건너뜀
            date_str = f"{year}-{month:02d}-{day:02d}"  # 날짜를 문자열로 ('YYYY-MM-DD')
            
            # 일정이 있는 날짜면 색상 강조
            if date_str in events:
                bg_color = "#FFD966"                # 일정 있는 날 → 노란색 배경
            elif (year, month, day) == (today.year, today.month, today.day):
                bg_color = "#B6D7A8"                # 오늘 날짜 → 연두색 배경
            else:
                bg_color = "#FFFFFF"                # 기본 → 흰색

            # 날짜 버튼 생성
            btn = tk.Button(calendar_frame,
                             text=str(day),          # 버튼에 표시될 날짜 숫자
                             bg=bg_color,            # 배경색 적용
                             command=lambda d=date_str: show_events(d)) # 클릭 시 이벤트 표시 함수 호출
            btn.grid(row=r+1, column=c, padx=5, pady=5, sticky="nsew") # grid로 버튼 배치

#___________________________________________________________________________________
## 일정 표시 함수
#___________________________________________________________________________________
def show_events(date_str):
    """
    특정 날짜를 클릭하면 해당 날짜의 일정 목록을 표시하는 함수
    """
    for widget in calendar_frame.winfo_children():  # 기존 달력 위젯 제거
        widget.destroy()
    # 날짜 표시
    tk.Label(calendar_frame, text=f"{date_str} 일정", font=("맑은 고딕", 14, "bold")).grid(row=0, column=0, columnspan=7)

    # 일정 목록 표시
    if date_str in events and events[date_str]:     # 해당 날짜에 일정이 있으면
        for i, event in enumerate(events[date_str]):# 각 일정 항목 순회
            lbl = tk.Label(calendar_frame, text=f"- {event['text']}", anchor="w")
            lbl.grid(row=i+1, column=0, columnspan=6, sticky="w", padx=10, pady=2)
            del_btn = tk.Button(calendar_frame, text="삭제", command=lambda i=i: delete_event(date_str, i))
            del_btn.grid(row=i+1, column=6)         # 일정 오른쪽에 삭제 버튼 배치
    else:
        tk.Label(calendar_frame, text="등록된 일정이 없습니다.", font=("맑은 고딕", 12)).grid(row=1, column=0, columnspan=7)

    # 추가 버튼
    add_btn = tk.Button(calendar_frame, text="일정 추가", command=lambda: add_event(date_str))
    add_btn.grid(row=10, column=2, columnspan=3, pady=10)
    # 돌아가기 버튼
    back_btn = tk.Button(calendar_frame, text="← 돌아가기", command=lambda: draw_calendar(today.year, today.month))
    back_btn.grid(row=11, column=2, columnspan=3, pady=5)

#___________________________________________________________________________________
## 일정 추가 함수
#___________________________________________________________________________________
def add_event(date_str):
    """
    사용자가 입력한 일정 내용을 해당 날짜에 추가하는 함수
    """
    text = simpledialog.askstring("일정 추가", f"{date_str} 일정 내용을 입력하세요:") # 입력창 표시
    if text:                                        # 사용자가 입력값을 주면
        if date_str not in events:                  # 해당 날짜 키가 없으면
            events[date_str] = []                   # 새 리스트 생성
        events[date_str].append({"text": text})     # 일정 항목 추가
    show_events(date_str)                           # 화면 갱신 (새 일정 반영)

#___________________________________________________________________________________
## 일정 삭제 함수
#___________________________________________________________________________________
def delete_event(date_str, index):
    """
    해당 날짜의 일정 중 인덱스로 지정된 항목을 삭제하는 함수
    """
    if date_str in events:                          # 해당 날짜가 존재하면
        del events[date_str][index]                 # 해당 인덱스의 일정 삭제
        if not events[date_str]:                    # 삭제 후 일정이 없으면
            del events[date_str]                    # 해당 날짜 키 자체 삭제
    show_events(date_str)                           # 변경 후 다시 화면 갱신

#___________________________________________________________________________________
## 프로그램 실행
#___________________________________________________________________________________
draw_calendar(today.year, today.month)  # 현재 날짜 기준으로 달력 표시 함수 최초 호출
win.mainloop()                          # Tkinter 이벤트 루프 실행 (창 유지)
