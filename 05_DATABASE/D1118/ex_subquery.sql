# ----------------------------------------------------------
# Subquery : 쿼리 결과값을 활용한 쿼리문
# ----------------------------------------------------------
# DB 선택
# ----------------------------------------------------------
USE sakila;

# ----------------------------------------------------------
# [1] WHERE절 Subquery -> 중첩 서브쿼리, 대부분의 서브쿼리 해당
# ----------------------------------------------------------
# ROSA와 동일한 customer_id의 고객정보 추출
SELECT * FROM customer
WHERE customer_id = (
    SELECT customer_id FROM customer
    WHERE first_name = 'ROSA');

SET @u_id := (SELECT customer_id FROM customer
              WHERE first_name = 'ROSA');

SELECT * FROM customer
WHERE customer_id = @u_id;

-- [다중행 결과] ANA, ROSA와 동일한 customer_id의 고객정보 추출
SELECT customer_id FROM customer
WHERE first_name IN ('ROSA', 'ANA');

SELECT * FROM customer
WHERE customer_id IN (
    SELECT customer_id FROM customer
    WHERE first_name IN ('ROSA', 'ANA')
);

-- [다중행 결과] action 장르 영화 리스트 추출 -------------------
-- 1. action 장르의 id 찾기 => category TB
SELECT category_id, name 
FROM category
WHERE name = 'Action';      # action 장르 id => 1

SELECT * FROM film_category
WHERE category_id = 1;      # 1번 id에 해당하는 영화 

# 위에는 하드코딩이고 두개 합친 버전
SELECT film_id FROM film_category
WHERE category_id = (
    SELECT category_id 
    FROM category
    WHERE name = 'Action'
);

SELECT * FROM film
WHERE film_id IN (
    SELECT film_id FROM film_category
    WHERE category_id = (
        SELECT category_id 
        FROM category
        WHERE name = 'Action'
        )
);
)
-- 2. action 장르에 해당하는 영화 id => film_category TB


-- 3. action 장르에 해당하는 영화 정보 리스트 추출
