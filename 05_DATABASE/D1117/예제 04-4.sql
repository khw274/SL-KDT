# --------------------------------------------------
# 04-4. 와일드카드로 문자열 조회하기
# --------------------------------------------------
-- 첫 번째 글자가 A로 시작하는 데이터 조회
SELECT * FROM customer WHERE first_name LIKE 'A%';

-- 첫 번째 글자가 AA로 시작하는 데이터 조회
SELECT * FROM customer WHERE first_name LIKE 'AA%';

-- A로 끝나는 모든 데이터 조회
SELECT * FROM customer WHERE first_name LIKE '%A';

-- RA로 끝나는 모든 데이터 조회
SELECT * FROM customer WHERE first_name LIKE '%RA';

-- A를 포함한 모든 데이터 조회
SELECT * FROM customer WHERE first_name LIKE '%A%';

-- 첫 번째 글자가 A로 시작하지 않는 데이터만 조회
SELECT * FROM customer WHERE first_name NOT LIKE 'A%';

-- 특수 문자를 포함한 임의의 테이블 생성

-- 특수 문자 %를 포함한 데이터 조회

-- ESCAPE로 특수 문자 %를 포함한 데이터 조회

-- ESCAPE와 !로 특수 문자 %를 포함한 데이터 조회

-- A로 시작하면서 문자열 길이가 2인 데이터 조회

-- A로 시작하면서 문자열 길이가 3인 데이터 조회

-- A로 끝나면서 문자열 길이가 3인 데이터 조회

-- A로 시작하고 A로 끝나면서 문자열 길이가 4인 데이터 조회

-- 문자열 길이가 5인 데이터 조회

-- A_R로 시작하는 문자열 조회

-- __R로 시작하는 문자열 조회

-- A로 시작하면서 R_로 끝나는 문자열 조회

-- ^, |, $를 사용해 데이터 조회

-- […]를 사용해 데이터 조회

-- [^…]를 사용해 데이터 조회

-- %와 […]을 사용해 데이터 조회

-- 와일드카드 조합으로 데이터 조회