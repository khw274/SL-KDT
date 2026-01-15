-- ===========================================================
-- 1. GROUP BY 문제
-- ===========================================================

use employees;
-- ----------------------------------------------------------
-- G1. 성별별 직원 수
-- 테이블: employees.employees
-- ----------------------------------------------------------
SELECT * FROM employees.employees;

SELECT count(emp_no) FROM employees.employees GROUP BY gender;


-- ----------------------------------------------------------
-- G2. 부서별 현재 직원 수
-- 테이블: employees.employees
-- ----------------------------------------------------------
SELECT * FROM employees.dept_emp;

SELECT dept_no, count(emp_no) FROM employees.dept_emp GROUP BY dept_no;

-- ----------------------------------------------------------
-- G3.직급별 직원 수 (전체 이력 기준)
-- 테이블: employees.title
-- ----------------------------------------------------------
SELECT * FROM employees.titles;

SELECT title, count(emp_no) FROM employees.titles GROUP BY title;

-- ----------------------------------------------------------
-- G4. 직급별 “현재” 직원 수
-- 테이블: employees.title
-- ----------------------------------------------------------
SELECT emp_no, count(emp_no) FROM employees.titles GROUP BY emp_no;

SELECT title, count(emp_no) FROM employees.titles GROUP BY title;


-- ----------------------------------------------------------
-- G5.부서별 평균 급여 (현재 기준)
-- 테이블: employees.title
-- ----------------------------------------------------------
SELECT a.salary, a.emp_no, b.dept_no FROM employees.salaries as a INNER JOIN employees.dept_emp as b ON a.emp_no = b.emp_no; 


-- ----------------------------------------------------------
-- G6.입사 연도별 직원 수
-- 테이블: employees.employees
-- ----------------------------------------------------------
SELECT YEAR(hire_date) "입사 연도", count(emp_no) "직원 수" FROM employees.employees GROUP BY YEAR(hire_date);


-- ----------------------------------------------------------
-- G7.부서별 남녀 인원수
-- 테이블: employees.employees
-- ----------------------------------------------------------
SELECT gender "성별", count(emp_no) "인원 수" FROM employees.employees GROUP BY gender;


-- ----------------------------------------------------------
-- G8.부서별 평균 재직 일수
-- 테이블: employees.employees
-- ----------------------------------------------------------
SELECT avg(a.hire_date-a.birth_date), b.dept_no FROM employees.employees as a INNER JOIN employees.dept_emp as b GROUP BY dept_no;


-- ----------------------------------------------------------
-- G9.직급별 평균 급여 (현재 직급 + 현재 급여)
-- 테이블: employees.employees
-- ----------------------------------------------------------
SELECT 



-- ----------------------------------------------------------
-- G10.부서별 직원 수 + 전체 합계 
-- 테이블: employees.employees
-- ----------------------------------------------------------
-- 이건 안 풀어도 됨