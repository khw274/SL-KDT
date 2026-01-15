#__________________________________________________________________________

# [1] homework.txt, message.txt 파일 읽어서 출력

#__________________________________________________________________________

F_NAME1 = 'homework.txt'
F_NAME2 = 'message.txt'
F_NAME3 = 'data.txt'
F_NAME4 = 'data_copy.txt'

def read_file(FILE_NAME, encode):
    with open(FILE_NAME, mode = 'r', encoding=encode) as rf:
        data = rf.read()

        print(data)

read_file(F_NAME1, 'utf-8')
read_file(F_NAME2, 'ANSI')
#__________________________________________________________________________

# [2] data.txt 복사해서 data_copy.txt를 생성

#__________________________________________________________________________

# 함수기능 : 원복을 복사해서 복사본 파일을 생성
# 함수이름 : copy_file
# 매개변수 : 
# 결과반환 : 

def copy_file(originF, copyF, encode='utf-8'):

    with open(originF, mode = 'r', encoding=encode) as rf:
        
        with open(copyF, mode = 'r', encoding='utf-8') as wf:

            wf.write(rf.read())

copy_file(F_NAME3, F_NAME4)

