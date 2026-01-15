#__________________________________________________________________________
# 내장 모듈 random 활용
# - random -> 난수 생성하거나 무작위 선택할 때 사용
#__________________________________________________________________________
# [실습 1] 로또 프로그램을 구현하세요.
#         - 숫자 범위 : 1 ~ 45
#         - 추출 숫자 : 6개 중복 X
#         - 조    건 : randint 사용
#__________________________________________________________________________
import random  # from random import randint

# [방법 1]
lotto = []

while 1:
    if len(lotto) == 6: break
    
    num = random.randint(1, 45)

    if num not in lotto:
        lotto.append(num)

print(f"이번주 로또 번호 : {lotto}")

# [방법 2]
# set 타입 : 중복 불허
lotto = set()

while 1:
    if len(lotto) == 6: break
    
    lotto.add(random.randint(1, 45))

print(f"이번주 로또 번호 : {lotto}")

# [방법 3]
print(f"이번주 로또 번호 : {random.sample(range(1, 46), 6)}")
