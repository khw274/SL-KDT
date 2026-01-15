-- ===========================================================
-- 그룹화 : Group by 그룹화_기준_컬럼명 
--         select 절에 집계함수 사용 : max()/min()/sum()/mean()..
-- ===========================================================
-- DB 선택
use sakila;

-- ===========================================================
-- GROUP BY 컬럼명1 , 컬럼명2, 
-- ===========================================================

-- 상점별 고객수 
select count(*) as 상점별_고객수 from customer
GROUP BY store_id;

select store_id as 상점코드, count(*) as 상점별_고객수 from customer
GROUP BY store_id;


-- 국가코드별 도시 수
select country_id "국가코드", count(*) "국가별_도시수" from city
GROUP BY country_id;


-- 국가코드와 상점코드가 동일한 데이터들 그룹화
select hometown, count(*) from  mydb.user
GROUP BY hometown;

select hometown, gender, count(*) "사용자수" from  mydb.user
GROUP BY hometown, gender;

-- ===========================================================
-- 중복 제거 : distinct
-- ===========================================================




-- ===========================================================
-- 정렬 : order by  ASC/DESC limit 숫자 
-- ===========================================================




