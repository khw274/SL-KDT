#__________________________________________________________________________

# 일정관리 프로그램(10월)
# - 캘린더 시각화
# - 일정 추가
# - 일정 삭제
# - 일정 조회(특정 날짜 지정)
# - 프로그램 종료

#__________________________________________________________________________

# 사용자 정의 함수들

#__________________________________________________________________________

# 함수기능 : 캘린더 출력 기능
# 함수이름 : printCalender
# 매개변수 : 없음
# 결과반환 : 없음

def printCalender():
    # with open("./calender.txt", mode='r', encoding='utf-8') as f:
    #     print(f.read())

    print("""    October 2025
Su Mo Tu We Th Fr Sa
          1  2  3  4
 5  6  7  8  9 10 11
12 13 14 15 16 17 18
19 20 21 22 23 24 25
26 27 28 29 30 31""")

#__________________________________________________________________________

# 함수기능 : 메인메뉴 출력 기능
# 함수이름 : printMenu
# 매개변수 : 없음
# 결과반환 : 없음

def printMenu():

    print()
    print(f"{'선 택':-^20}")
    print(f"{'1. 일정 추가✅':<18}")
    print(f"{'2. 일정 삭제❌':<18}")
    print(f"{'3. 일정 조회🔍':<18}")
    print(f"{'4. 프로그램 종료':<18}")
    print(f"{'':-^22}")

#__________________________________________________________________________

# 함수기능 : 입력 데이터를 딕셔너리로 받는 기능
# 함수이름 : inputSchedule
# 매개변수 : 없음
# 결과반환 : 입력 받은 데이터

def inputSchedule():
    data = input("날짜와 일정 입력(예시: 2 산책): ").split()

    if len(data) != 2:
        return None
    
    schedule = {data[0]: data[1]}

    return schedule

#__________________________________________________________________________

# 함수기능 : 일정 추가 기능
# 함수이름 : addSchedule
# 매개변수 : 일정 딕셔너리
# 결과반환 : 입력 받은 데이터

def addSchedule(schedule):
    with open('./schedule_list.txt', mode='a', encoding='utf-8') as f:
        for k, v in schedule.items():
            f.write(f"{k}  {v}\n")
    
    print("일정이 추가되었습니다!")

#__________________________________________________________________________

# 함수기능 : 일정 삭제 기능
# 함수이름 : deleteSchedule
# 매개변수 : 없음
# 결과반환 : 없음

def deleteSchedule():
    date = input("삭제할 날짜 입력(예: 2) : ")
    found = False
    schedule = []

    with open('./schedule_list.txt', mode = 'r', encoding = 'utf_8') as f:
        lines = f.readlines()

    for line in lines:
        d, s = line.strip().split()

        # 삭제할 날짜 제외하고 모두 새로운 딕셔너리에 추가
        if d == date:
            found == True
            continue  

        schedule.append(line)  

    with open('./schedule_list.txt', mode='w', encoding='utf-8') as f:
        f.writelines(schedule)
    
    if found:
        print(f"10월 {date}일 일정은 삭제되었습니다.")
    
    else:
        print("해당 날짜에는 일정이 존재하지 않습니다.")
    
#__________________________________________________________________________

# 함수기능 : 일정 조회 기능
# 함수이름 : searchSchedule
# 매개변수 : 없음
# 결과반환 : 없음

def searchSchedule():
    date = input("조회할 날짜 입력(예: 2) : ")
    found = False

    with open('./schedule_list.txt', mode = 'r', encoding='utf-8') as f:

        for line in f:
            d, s = line.strip().split()

            if d == date:
                print(f"[🔍 검색 결과] 10월 {date}일 일정 : {s}\n")
                found = True
    if not found:
        print("해당 날짜에는 일정이 존재하지 않습니다.")

#__________________________________________________________________________

# 프로그램 구동 

#__________________________________________________________________________

print(f"{'일정 조회 프로그램':-^14}")

while(1):

    # 캘린더 출력
    printCalender()

    # 메뉴 출력
    printMenu()
    cmd = input("메뉴 선택 : ")
    
    # 프로그램 종료
    if cmd == '4': break 

    # 일정 추가
    elif cmd == '1':  
        schedule = inputSchedule()

        if schedule: addSchedule(schedule)
        else:
            print("날짜와 일정을 다시 입력해주세요(예시: 2 산책) : ")
        
     # 일정 삭제
    elif cmd == '2': 
        deleteSchedule()

    # 일정 조회
    elif cmd == '3':  
        searchSchedule()

    else:
        print("존재하지 않는 항목입니다.")

with open('./schedule_list.txt', mode='w', encoding='utf-8') as f:
    f.write("")
print("일정 관리 프로그램 종료")