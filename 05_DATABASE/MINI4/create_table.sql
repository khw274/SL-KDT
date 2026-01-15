CREATE DATABASE EMS;

USE EMS;



CREATE TABLE employees (
    emp_id INT PRIMARY KEY,                             -- 사원번호[기본키]
    emp_pw VARCHAR(255),                                -- 비밀번호
    name VARCHAR(100),                                  -- 이름
    position VARCHAR(50),                               -- 직급 
    basic_salary INT                                    -- 기본급
    annual_leave INT                                    -- 연차수 
    department VARCHAR(100)                             -- [개발, 영업, 생산, 관리, 구매]
);

CREATE TABLE monthly_salary (
    emp_id INT,                                         -- 사원번호[외래키]
    year INT, month INT,                                -- 급여날짜(연, 월)
    basic_salary INT,                                   -- 기본급
    national_pension INT,                               -- 국민연금    
    health_insurance INT,                               -- 건강보험
    long_term_care INT,                                 -- 장기요양
    employment_insurance INT,                           -- 고용보험
    income_tax INT,                                     -- 소득세    
    local_income_tax INT,                               -- 지방소득세    
    net_salary INT,                                     -- 실지급액
);

CREATE TABLE attendance (
    att_id INT PRIMARY KEY AUTO_INCREMENT,              -- 출석 기록 고유번호
    emp_id INT,                                         -- 직원번호 (외래키)
    att_date DATE,                                      -- 출석 날짜
    check_in TIME,                                      -- 출근 시간
    check_out TIME,                                     -- 퇴근 시간
    status varchar(10)                                  -- 출근현황('정상', '지각', '결근', '조퇴', '휴가, 야근')
);


