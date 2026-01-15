-- ===========================================================
-- 그룹화 : Group by 그룹화_기준_컬럼명 
-- ===========================================================
-- DB 선택
use MYDB;

-- TB 선택 & 상세 설명 : desc/describe  TB_NAME
desc user;


-- ===========================================================
-- GROUP BY 컬럼명1 
-- ===========================================================
-- hometown 값 종류
select DISTINCT hometown 
from user
order by hometown;

-- hometown 기준으로 그룹화
select hometown, count(*) "cnt"
from user    
GROUP BY hometown;


-- ===========================================================
-- GROUP BY 컬럼명1 , 컬럼명2, .. : 여러 개 컬럼으로 그룹화
-- ===========================================================
-- hometown, gender 그룹화
select hometown, gender , count(*) "인원수"
from user     
GROUP BY hometown, gender
order by hometown;

-- hometown, gender  그룹화 후 성별이 남자인 그룹 데이터만 선택
select hometown, gender, count(*)
from user
group by hometown, gender
having gender='남';
