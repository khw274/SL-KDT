-- ===========================================================
-- 그룹화 : Group by 그룹화_기준_컬럼명 
--         select 절에 집계함수 사용 : max()/min()/sum()/mean()..
-- ===========================================================
-- DB 선택
use sakila;

-- TB 선택 & 상세 설명 : desc/describe  TB_NAME
desc film;


-- ===========================================================
-- GROUP BY 컬럼명1 
-- ===========================================================
-- special features  값 종류
select count( special_features) from film;
select count( DISTINCT special_features) from film;

-- special features 기준으로 그룹화
select special_features
from film
GROUP BY special_features;

-- 그룹별 행 수 
select special_features, count(special_features)
from film
GROUP BY special_features;

-- ===========================================================
-- GROUP BY 컬럼명1 , 컬럼명2, .. : 여러 개 컬럼으로 그룹화
-- ===========================================================
-- special_features, rating 
select DISTINCT rating
from film;

-- special_features, rating  그룹화
select special_features, rating 
from film    
GROUP BY special_features, rating;

-- special_features, rating  그룹별 소속된 행수
select special_features, rating , count(rating)
from film    
GROUP BY special_features, rating;

-- rating, special_features 그룹화
select rating , special_features, count(rating)
from film    
GROUP BY rating, special_features
order by rating;


-- ===========================================================
-- count() 집계함수와 정렬 order by 
-- ===========================================================
-- special features 그룹별 소속된 행 개수 파악
select  special_features, count(special_features) "CNT"   
from film
group by special_features;


-- special features 그룹별 소속된 행 개수 파악 및 정렬
select  special_features, count(special_features) "CNT"   
from film
group by special_features
order by cnt desc, special_features desc
limit 5;


-- ===========================================================
-- Having  조건  :  그룹화 후 그룹들에 대한 필터링
-- ===========================================================
-- special features로 그룹화 후 그룹이 행 수가 70개 이상인 그룹만 선택
select special_features , count(*) "CNT" 
from film
GROUP BY special_features
HAVING CNT>=70;

