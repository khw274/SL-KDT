-- ======================================================
-- JOIN : 테이블 조합으로 원하는 데이터 추출/선택
--        종류 : 내부(INNER) / 외부(OUTER)
-- ======================================================
--  DB 선택 및 TB 생성
-- ======================================================
-- DB 선택
use sakila;

-- ======================================================
--  데이터 조회
-- ======================================================
    
-- [내부 조인] : Equi Join : 두개 TB에 기준 컬럼의 같이 동일한 것만 선택
--              customer TB, address TB 
--              고객정보에 상세 주소 정보 선택
select customer.first_name, customer.last_name, address.address
from customer INNER JOIN address
on customer.address_id = address.address_id

select c.first_name, c.last_name, a.address
from customer as c INNER JOIN address  as a
on c.address_id = a.address_id


-- [내부 조인] : Equi Join : 두개 TB에 기준 컬럼의 같이 동일한 것만 선택
--              customer TB => cu, address TB  => ad, city => ci TB
--              고객정보에 도시명, 상세 주소 정보 선택
select cu.first_name, cu.last_name, ci.city, ad.address, ad.address2
from customer as cu 
INNER JOIN address as ad on cu.address_id = ad.address_id
INNER JOIN city as ci on ci.city_id = ad.city_id;