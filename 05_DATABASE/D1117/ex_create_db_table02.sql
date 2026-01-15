-- ======================================================
-- 실습용 DB : DoItsql
--       TB : doit_tb 
-- ======================================================
-- DB 생성
CREATE DATABASE IF NOT EXISTS doitsql;

-- DB 선택
USE doitsql;

-- TB 생성 
CREATE TABLE IF NOT EXISTS doit_tb
(
    col_1 int PRIMARY KEY AUTO_INCREMENT,      
    col_2 VARCHAR(50),
    col_3 int
);

CREATE TABLE IF NOT EXISTS data_tb
(   
    col_2 VARCHAR(50),
    col_3 int,
    col_4 char(2)
);

-- DB내에 TB 확인
SHOW TABLES;

-- TB의 구조 확인
desc doit_tb;

-- 데이터 추가 
INSERT INTO data_tb VALUES 
("TEST", 10, 'T'),("Happy", 13, 'H'), ("Love", 8, 'L'),
("ABC", 3, 'A'),  ("SKY", 11, 'S'),   ("TEST", 10, 'Z'),
("Good", 10, 'G'),("DOG", 10, 'D'),   ("CHR", 10, 'C');


INSERT INTO doit_tb VALUES 
(1, "TEST", 10);

-- AUTO_INCREMENT 자동증가
insert into doit_tb (col_2, col_3)
VALUES ('OK', 100);

insert into doit_tb (col_2, col_3)
VALUES  ('OK', 100), 
        ('Yes', 90),
        ("Good", 1);

-- AE 컬럼도 값 지정
INSERT INTO doit_tb VALUES 
(8, "TEST", 10);

-- ========================================
-- SELECT => INSERT 
-- data_tb ==> doti_tb로 데이터 추가
-- ========================================
INSERT into doit_tb(col_2, col_3)
select col_2, col_3 from data_tb;


-- ========================================
-- SELECT 결과 => CREATE 
-- ========================================
CREATE Table CopyTB AS (select * from data_tb);


-- 전체 데이터 조회
select * from doit_tb;

-- AE 설정값 변경 
set @@AUTO_INCREMENT_increment = 5;



-- 현재 마지막 AE 값 확인
select LAST_INSERT_ID() '마지막 AE 번호';