-- ======================================================
-- 실습용 DB : MYDB
--       TB : User 
-- ======================================================
CREATE DATABASE IF NOT EXISTS doitsql;

USE doitsql;

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

-- DB내의 TB 확인
SHOW TABLES;

-- TB의 구조 확인
DESC doit_tb;

-- 데이터 추가 
INSERT INTO data_tb VALUES
("TEST", 10, 'T'), ("HAPPY", 10, 'H'), ("LOVE", 10, 'L'),
("ABC", 10, 'A'), ("SKY", 10, 'S'), ("TEST", 10, 'Z'),
("GOOD", 10, 'G'), ("DOG", 10, 'D'), ("CAT", 10, 'C');

-- AUTO_INCREMENT 자동증가 COMMENT
INSERT INTO doit_tb(col_2, col_3)
VALUES ('OK', 100);

INSERT INTO doit_tb(col_2, col_3)
VALUES ('OK', 100), 
       ('YES', 90), 
       ("Good", 1);

-- AE 컬럼도 값 지정
INSERT INTO doit_tb(col_2, col_3)
VALUES ('TEST', 10); 

-- ================================================
-- SELECT => INSERT
-- data_tb ==> doit_tb로 데이터 추가
-- =================================================
INSERT INTO doit_tb(col_2, col_3)
SELECT col_2, col_3 FROM data_tb;

-- ================================================
-- SELECT => CREATE
-- ================================================
CREATE TABLE CopyTB AS (SELECT * FROM data_tb);

-- 전체 데이터 조회
SELECT * FROM doit_tb;

-- AE 설정값 변경 
SET @@AUTO_INCREMENT_increment = 5;

-- 현재 마지막 AE 값 확인
SELECT LAST_INSERT_ID() '마지막 AE 번호';

