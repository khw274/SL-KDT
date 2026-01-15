## =============================================
## Table 연동 연산 실습
## =============================================
## DB 선택 : use DB_NAME ;
use sakila;

## Table 정보 확인 : desc/describe Table_Name;
desc customer;

## [실습1] customer 테이블
## address_id가 2자리수인 고객 정보 추출
SELECT address_id FROM customer;
SELECT address_id FROM customer WHERE address_id >= 10 and address_id <100;

SELECT address_id FROM customer WHERE address_id BETWEEN 10 AND 99;

SELECT address_id FROM customer WHERE length(address_id) <= 2;

## [실습2] customer 테이블
## 이름이 'C' ~ 'D'로 시작하는 고객 정보만 추출
SELECT first_name FROM customer WHERE first_name LIKE 'C%' OR first_name LIKE 'D%';

## [실습3] city 테이블
## Cheju, Dallas 고객 정보만 추출
SELECT * FROM city WHERE city = 'Cheju' or city = 'Dallas';

SELECT * FROM city WHERE city in ('Cheju', 'Dallas');

## [실습4] customer 테이블
## 성은 A로 시작하고 이름은 E로 끝나는 고객 정보만 추출
SELECT * FROM customer WHERE last_name LIKE 'A%' and first_name LIKE '%E';

## [실습5] city 테이블
## 국가코드가 101인 도시들 출력
SELECT city FROM city WHERE country_id = 101;

## [실습6] city 테이블
## 국가코드가 101이 도시들 중 도시명에 사이에 h가 있는 도시
SELECT city FROM city WHERE country_id = 101 AND city LIKE '%h%';

## [실습7] address 테이블 
## address2가 입력되지 않는 주소 정보만 출력
SELECT * FROM address WHERE address2 IS NULL;

## [실습8] address 테이블 
## address2와 phone이 입력되지 않는 주소 정보만 출력
SELECT * FROM address WHERE address2 IS NULL AND phone = '';

## [실습9] payment 테이블
## 결제일이 7월인 데이터만 추출
SELECT * FROM payment;
SELECT * FROM payment WHERE payment_date LIKE '%-07-%';
SELECT * FROM payment WHERE month(payment_date) = 7;
