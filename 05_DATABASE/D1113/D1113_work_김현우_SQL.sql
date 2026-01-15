/* D1113_WORK_김현우 */

--  데이터베이스 삭제
DROP DATABASE IF EXISTS D1113;
--  데이터베이스 생성 (존재하지 않을 경우)
CREATE DATABASE IF NOT EXISTS D1113;

USE D1113;

-- 테이블 생성1 
CREATE TABLE HOSPITAL(주소 VARCHAR(10),
				      organ INT,
                      population INT);

INSERT INTO HOSPITAL VALUES("전라남도", 22, 1779599),
						   ("강원특별자치도", 18, 1509396),
                           ("경상북도",	25,	2512441),
                           ("충청북도",	12,	1592431),
                           ("제주특별자치도",	5,	665610);

-- 테이블 생성2 
CREATE TABLE CULTURE(시도명 VARCHAR(10),
					 도서관수 INT,
					 박물관수 INT);

INSERT INTO CULTURE VALUES("전라북도",	2,	42),
						  ("충청남도",	54,	64),
						  ("부산광역시", 38, 33),
						  ("서울특별시", 169, 132),
						  ("대구광역시",30,	19);
						
                           

