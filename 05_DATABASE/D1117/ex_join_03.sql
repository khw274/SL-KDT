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
    
-- [외부 조인] : Equi Join : 두개 TB에 기준 컬럼의 같이 동일한 것만 선택
--              customer TB, store TB 
--              고객이 등록된 상점 정보 추출

-- Left Outer join : 왼쪽 TB 모두 선택 -> 오른쪽 TB없으면 NULL
select a.address, s.store_id
from address as a LEFT OUTER JOIN store as s
on a.address_id = s.address_id;


-- Right Outer Join : 오른쪽 TB 모두 선택 ->  왼쪽 TB없으면 NULL
select a.address, s.store_id
from address as a RIGHT OUTER JOIN store as s
on a.address_id = s.address_id;


-- Full outer join : MYSQL 제공 X, LEFT OUTER JOIN + RIGHT OUTER JOIN
select a.address, s.store_id
from address as a LEFT OUTER JOIN store as s
on a.address_id = s.address_id
UNION
select a.address, s.store_id
from address as a RIGHT OUTER JOIN store as s
on a.address_id = s.address_id;


-- Full outer join : MYSQL 제공 X, LEFT OUTER JOIN + RIGHT OUTER JOIN
--                   2개 TB 교집합 제외 
select a.address, s.store_id
from address as a LEFT OUTER JOIN store as s
on a.address_id = s.address_id
where s.address_id is null 
UNION
select a.address, s.store_id
from address as a RIGHT OUTER JOIN store as s
on a.address_id = s.address_id
where a.address_id is null ;