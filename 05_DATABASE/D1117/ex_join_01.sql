-- ======================================================
-- JOIN : 테이블 조합으로 원하는 데이터 추출/선택
--        종류 : 내부(INNER) / 외부(OUTER)
-- ======================================================
--  DB 선택 및 TB 생성
-- ======================================================
-- DB 선택
use mydb;

-- TB 생성
CREATE Table A (
    id INT PRIMARY KEY,
    ename CHAR(3) NOT NULL,
    mgr  CHAR(3) NOT NULL
)

CREATE Table B (
    id INT PRIMARY KEY,
    kname CHAR(3) NOT NULL
)

-- ======================================================
--  데이터 추가 
-- ======================================================
INSERT INTO A 
VALUES  (1, 'aaa','top'), (2, 'bbb','aaa'), (3, 'ccc','bbb'),
        (11, '111','top'), (22, '222','111'), (33, '333','111');

INSERT INTO B
VALUES  (1, '가'),   (2, '나'),    (3, '다'),
        (4, '라라'), (5, '마마마'), (6, '바바바');



-- ======================================================
--  데이터 조회
-- ======================================================
-- [전체 조회]
select * from A;  select * from B;
    
-- [내부 조인] : Equi Join : 두개 TB에 기준 컬럼의 같이 동일한 것만 선택
select a.id, a.ename, b.kname
from a INNER JOIN b on A.id = B.id;

-- [내부 조인] : Non-Equi Join
select *
from a INNER JOIN b on A.id >=22 ;