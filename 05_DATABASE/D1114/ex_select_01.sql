# -------------------------------------------------------------
# SELECT 문법
# -------------------------------------------------------------
# - 1. 테이블에서 데이터 조회
# 	   from DB_NAME.Table -> 이런 방식도 가능
SELECT countrycode from world.city;

# - 2. 단순 계산 결과 출력
SELECT 5+2, 5-2, 5*2, 5/2, 5%2;

# - 별칭 지정: 컬럼명을 다른 이름으로 지정
SELECT 5+2 AS 'ADD', 5*2;

# - 3. 날짜/문자열/수학 등 함수 결과 확인용
SELECT now();
SELECT CONCAT('Hello', ' ', 'MySQL'), LENGTH('한글'); # 여기서 LENGTH는 바이트 기준

# - 4. 시스템/환경 정보 확인용
SELECT VERSION();		# MYSQL 버전
SELECT DATABASE();		# 현재 사용 중인 DB
SELECT USER();			# 현재 접속 사용자

# - 5. 변수에 값을 넣거나, 변수값을 확인할 때
# 	@변수명 := 값[권장]		@변수명 = 값[비교연산자와 혼동 가능성] 
SELECT @x := 10, @y := 20, @z = 9;
SELECT @x + @y AS sum;