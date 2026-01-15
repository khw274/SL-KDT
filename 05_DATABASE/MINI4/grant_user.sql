-- ===================================================
-- 팀원 3명 계정에 권한 부여 
-- ProjectDB : 팀의 Database이름으로 변경
-- ===================================================


GRANT ALL PRIVILEGES ON EMS.* TO 'user1'@'172.30.1.93';
GRANT ALL PRIVILEGES ON EMS.* TO 'user2'@'172.30.1.36';
GRANT ALL PRIVILEGES ON EMS.* TO 'user3'@'172.30.1.94';

FLUSH PRIVILEGES;  # 권한 적용


-- GRANT ALL PRIVILEGES ON ProjectDB.* TO 'user1'@'%';
-- GRANT ALL PRIVILEGES ON ProjectDB.* TO 'user2'@'%';
-- GRANT ALL PRIVILEGES ON ProjectDB.* TO 'user3'@'%';

-- FLUSH PRIVILEGES;
