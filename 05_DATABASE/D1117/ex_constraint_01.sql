-- ===========================================================
-- 제약조건 : 컬럼 데이터 추가에 대한 다양한 조건들 
--          (1) PK & FK : 테이블 간의 관계 설정
--              PK - 부모테이블      FK - 자식테이블
-- ===========================================================

-- ===========================================================
-- DB 선택  및 TB 생성
-- ===========================================================
-- DB 선택
use doitsql;

-- TB 생성
CREATE TABLE parent ( col_1 Int  PRIMARY KEY);
CREATE TABLE child ( col_1 int,
                     FOREIGN KEY(col_1) REFERENCES parent(col_1)); 

-- ===========================================================
-- 데이터 추가 : Parent에 존재하지 않는 FK는 Child에 추가 X
-- ===========================================================     
-- Parent TB에 데이터 추가
INSERT INTO parent VALUES (1), (2), (12);

-- Child TB에 데이터 추가
INSERT INTO child VALUES (1);
-- INSERT INTO child VALUES (11);  ERROR 데이터 11이 parent에 없음!


-- ===========================================================
-- 데이터 삭제 : FK 테이블에 데이터 삭제 후 PK 테이블 삭제 가능
-- ===========================================================     
-- Parent에서 삭제 : Delete From 테이블이름 Where 조건;
DELETE FROM parent where col_1 = 2;
-- DELETE FROM parent where col_1 = 1;  ERROR child_TB에 참조 중임!

-- Child에서 삭제
DELETE FROM child WHERE col_1=1;
DELETE FROM parent where col_1 = 1; 


-- ===========================================================
-- 데이터 조회
-- ===========================================================  
SELECT * FROM parent;
SELECT * FROM child;



select * from mydb.stock_data;