##_____________________________________________
## [실습]
##_____________________________________________
## 프로그램 : File_Explorer
## 주요기능 : Windows의 탐색기 기능
##   - 특정 폴더 아래 : 파일, 폴더 목록 출력
##   - 특정 폴더 선택 : 파일, 폴더 목록 출력
##   - 파일 선택 : 크기, 생성일자 
##   - 상위 폴더 이동 : 상위 폴더의 목록 출력
## 실행화면 : 바탕화면의 목록들
##_____________________________________________
# [모듈 로딩]
#______________________________________________
import os
import time
#______________________________________________
# [사용자 정의 함수]
#______________________________________________
# 함수이름: printList
# 함수기능: 현재 경로의 목록 출력
# 매개변수: path(현재 경로)
# 결과반환: items(현재 경로 내 파일 및 폴더 목록 리스트)

def printList(path):

    # 현재 디렉토리의 파일/폴더 리스트
    items = os.listdir(path)

    for idx, item in enumerate(items):  # 인덱스로 구분

        full_path = os.path.join(path, item)  # 현재 경로와 파일/폴더를 합춰서 표현해줌
        print(full_path)
        
        if os.path.isdir(full_path):  # 경로가 존재한다면 폴더, 아니면 파일
            mark = "📁"
        else:
            mark = "📄"
        
        print(f"[{idx}] {mark} {item}")
    
    return items
#______________________________________________
# 함수 이름: showFileInfo
# 함수 기능: 선택한 파일의 상세 정보 출력 (파일명, 크기, 생성일자)
# 매개변수: path (현재 경로), filename (파일 이름)

def showFileInfo(path, filename):
    full_path = os.path.join(path, filename)

    name = os.path.basename(full_path)
    size = os.path.getsize(full_path)
    created = os.path.getctime(full_path)

    print(f"\n파일명: {filename}")
    print(f"크기: {size} bytes")
    print(f"생성일자: {created}")
#______________________________________________
# 함수 이름: fileExplorer
# 함수 기능: 파일 탐색기 실행 및 사용자 입력 처리
# 매개변수: start_path (탐색기 시작 경로)

def fileExplorer(start_path):
    current = start_path  # 현재 경로
    while(1):
        print("\n현재 경로:", current)
        print("_" * 50)

        items = printList(current)  # 현재 경로 목록 출력
        print("\n옵션: 번호 입력, '..' (상위 폴더), 'exit' (종료)")


        choice = input("선택: ").strip()

        if choice == "exit":
            print("탐색기를 종료합니다.")
            break
        elif choice == "..":
            current = os.path.dirname(current)
        elif choice.isdigit() and 0 <= int(choice) < len(items):
            selected = items[int(choice)]
            selected_path = os.path.join(current, selected)
            if os.path.isdir(selected_path):
                current = selected_path  # 폴더 이동
            else:
                showFileInfo(current, selected)  # 파일 정보 출력
                input("\nEnter 키를 눌러 계속...")
        else:
            print("잘못된 입력입니다.")
#______________________________________________
# [프로그램 구동]
#______________________________________________
desktop_path = "C:\\Users\\khw27\\바탕 화면"

printList(desktop_path)
