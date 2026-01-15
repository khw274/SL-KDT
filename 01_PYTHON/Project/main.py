#__________________________________________________________________________
# 내부 패키지 활용하기
#__________________________________________________________________________
# [1] 기본 형태_____________________________________________________________
# __init__.py 빈 파일인 경우
import calcpkg.geometry as geo
import calcpkg.operation as op

# 패키지 내 모듈 함수들 사용
print(geo.rectangle_area(10, 4))
print(op.add(9, 7))

# [2] 간략화 형태______________________________________________________________
# __init__>py 내부에 모듈 import 기입
#____________________________________________________________________________
import calcpkg

# 패키지 내 모듈 함수들 사용
print(calcpkg.geometry.rectangle_area(10, 4))

from calcpkg import *

# 패키지 내 모듈 함수들 사용
print(geometry.rectangle_area(10, 4))
print(operation.add(10, 4))

# [3] 패키지 내 모듈들의 모든 것을 import_________________________________________
from calcpkg import *

# 패키지 내 모듈 함수들 사용
print(rectangle_area(10, 4))
print(add(10, 4)) 