create database prject_tracking_and_managment_system_ 

use prject_tracking_and_managment_system_

-- ADMIN table
CREATE TABLE ADMIN (
    admin_id VARCHAR (10) PRIMARY KEY,
    firstName VARCHAR(20) NOT NULL,
    middleName VARCHAR(20),
    lastName VARCHAR(20),
    email VARCHAR(30) UNIQUE,
    password VARCHAR(20) NOT NULL,
    status VARCHAR(10) ,
    createUserCount INT
);
drop table admin

-- HOD table
CREATE TABLE HOD (
    hod_id VARCHAR (10) PRIMARY KEY,
    firstName VARCHAR(20) NOT NULL,
    middleName VARCHAR(20),
    lastName VARCHAR(20),
    email VARCHAR(30) UNIQUE,
    password VARCHAR(20) NOT NULL,
    status VARCHAR(10),
    officeNumber VARCHAR(10)
);
drop table hod
-- ADVISOR table
CREATE TABLE ADVISOR (
    advisor_id VARCHAR (10) PRIMARY KEY,
    firstName VARCHAR(20) NOT NULL,
    middleName VARCHAR(20),
    lastName VARCHAR(20),
    email VARCHAR(30) UNIQUE,
    password VARCHAR(20) NOT NULL,
    status VARCHAR(10),
    course VARCHAR(10)
);

drop table ADVISOR
-- GROUP table
CREATE TABLE GROUPS (
    group_id INT PRIMARY KEY,
    group_name VARCHAR(20) UNIQUE,
     group_leader_id VARCHAR (10),
);
select * from GROUPS
drop table GROUPS
ALTER TABLE GROUPS
ADD CONSTRAINT FK_STUDENT_GROUP
FOREIGN KEY (group_leader_id)
REFERENCES STUDENT(student_id);
 

-- STUDENT table (without multivalued attributes)
CREATE TABLE STUDENT (
    student_id VARCHAR (10) PRIMARY KEY,
    firstName VARCHAR(20) NOT NULL,
    middleName VARCHAR(20),
    lastName VARCHAR(20),
    gender char NOT NULL,
    section char NOT NULL,
    email VARCHAR(30) UNIQUE,
    password VARCHAR(20) NOT NULL,
    status VARCHAR(10),
    group_id int,
    GPA DECIMAL(3,2),
    FOREIGN KEY (group_id) REFERENCES GROUPS(group_id)
);
drop table STUDENT

-- STUDENT multivalued attributes
CREATE TABLE STUDENT_LOCATION (
    student_id VARCHAR (10),
    location VARCHAR(20),
    PRIMARY KEY (student_id, location),
    FOREIGN KEY (student_id) REFERENCES STUDENT(student_id)
);

CREATE TABLE STUDENT_CONTRIBUTION (
    contribution_id VARCHAR (10) PRIMARY KEY,
    student_id VARCHAR (10) NOT NULL,
    contribution TEXT NOT NULL,
    FOREIGN KEY (student_id) REFERENCES STUDENT(student_id)
);

-- GROUP schedule (multivalued)
CREATE TABLE GROUP_SCHEDULE (
    group_id VARCHAR (10),
    schedule_item VARCHAR(20),
    PRIMARY KEY (group_id, schedule_item),
    FOREIGN KEY (group_id) REFERENCES GROUPS(group_id)
);

-- PROJECT table
CREATE TABLE PROJECT (
    project_id VARCHAR (10) PRIMARY KEY,
    projectName VARCHAR(30) NOT NULL,
    group_id int  UNIQUE,
    FOREIGN KEY (group_id) REFERENCES GROUPS(group_id)
);

-- TASK table
CREATE TABLE TASK (
    task_id VARCHAR (10) PRIMARY KEY,
    student_id VARCHAR (10),
    project_id VARCHAR (10),
    task_title VARCHAR(30),
    do_date DATE,
    FOREIGN KEY (student_id) REFERENCES STUDENT(student_id),
    FOREIGN KEY (project_id) REFERENCES PROJECT(project_id)
);

-- ASSIGN relationship (Advisor assigns Task to Student)
CREATE TABLE ASSIGN (
    advisor_id VARCHAR (10),
    student_id VARCHAR (10),
    task_id VARCHAR (10),
    assigned_at DATETIME,
    PRIMARY KEY (advisor_id, student_id, task_id),
    FOREIGN KEY (advisor_id) REFERENCES ADVISOR(advisor_id),
    FOREIGN KEY (student_id) REFERENCES STUDENT(student_id),
    FOREIGN KEY (task_id) REFERENCES TASK(task_id)
);

-- MESSAGE table (recursive relationship: any role can send/receive)
CREATE TABLE MESSAGE (
    message_id VARCHAR (10) PRIMARY KEY,
    sender_type VARCHAR(40),   -- 'ADMIN', 'HOD', 'ADVISOR', 'STUDENT'
    sender_id VARCHAR (10),
    receiver_type VARCHAR(40), -- same as above
    receiver_id VARCHAR (10),
    message_body TEXT,
    sent_at DATETIME

);
drop table groups 
INSERT INTO GROUPS VALUES
(1,  'Group One','WCU173784' ),
(2,  'Group Two','WCU1600272'),
(3,  'Group Three','WCU174035'),
(4,  'Group Four', 'WCU177799'),
(5,  'Group Five', 'WCU176706'),
(6,  'Group Six', 'WCU177918'),
(7,  'Group Seven','WCU170132'),
(8,  'Group Eight', 'WCU176859'),
(9,  'Group Nine', 'WCU173021')
drop database 

select*from student
INSERT INTO STUDENT
VALUES
-- Group 1 (Leader: WCU173784)
('WCU173784','Ephrem','Geletu','Alaro','M','B','ephrem@gmail.com','pass123','active',1,3.45),
('WCU170469','Dinkayehu','Petros','Gonche','M','B','dinkayehu@gmail.com','pass123','active',1,3.10),
('WCU17D7150','Tekalign','Melaku','Ayele','M','B','tekalign@gmail.com','pass123','active',1,3.25),
('WCU175268','Brikinesh','Eyob','Gaye','F','B','brikinesh@gmail.com','pass123','active',1,3.60),
('WCU17D1847','Natnael','Sintayehu','Beyene','M','B','natnael@gmail.com','pass123','active',1,3.30),

-- Group 2 (Leader: WCU1600272)
('WCU1600272','Mubarik','Detamo','Lire','M','B','mubarik@gmail.com','pass123','active',2,3.55),
('WCU170329','Elroe','Girma','Tumebo','M','B','elroe@gmail.com','pass123','active',2,3.20),
('WCU176654','Befekadu','Yacob','Affe','M','B','befekadu@gmail.com','pass123','active',2,3.15),
('WCU179663','Bezawit','Yimenu','Urmale','F','B','bezawit@gmail.com','pass123','active',2,3.40),
('WCU17D5798','Samuel','Feleke','Demamo','M','B','samuel@gmail.com','pass123','active',2,3.05),

-- Group 3 (Leader: WCU174035)
('WCU174035','Dawit','Alemu','Abose','M','B','dawit@gmail.com','pass123','active',3,3.50),
('WCU177722','Daniel','Eshete','Kebede','M','B','daniel@gmail.com','pass123','active',3,3.00),
('WCU17D2974','Yilkal','Ermako','Kefato','M','B','yilkal@gmail.com','pass123','active',3,3.10),
('WCU174952','Gelila','Anteneh','Mergia','F','B','gelila@gmail.com','pass123','active',3,3.65),
('WCU17D4784','Tesfa','Bokona','Diriba','M','B','tesfa@gmail.com','pass123','active',3,3.20),

-- Group 4 (Leader: WCU177799)
('WCU177799','Chala','Fikadu','Asefa','M','B','chala@gmail.com','pass123','active',4,3.55),
('WCU173719','Adane','Dawit','Humessa','M','B','adane@gmail.com','pass123','active',4,3.15),
('WCU173097','Mahlet','Tesfaye','Lajebo','F','B','mahlet@gmail.com','pass123','active',4,3.45),
('WCU173054','Aremoniem','Belayneh','Negash','F','B','aremoniem@gmail.com','pass123','active',4,3.25),
('WCU17D9795','Wudinesh','Dawit','Furchaka','F','B','wudinesh@gmail.com','pass123','active',4,3.00),

-- Group 5 (Leader: WCU176706)
('WCU176706','Binyam','Selamu','Daniel','M','B','binyam@gmail.com','pass123','active',5,3.60),
('WCU170962','Ashenafi','Abesha','Geze','M','B','ashenafi@gmail.com','pass123','active',5,3.10),
('WCU171844','Betelhem','Kebede','Ertiro','F','B','betelhem@gmail.com','pass123','active',5,3.35),
('WCU177120','Tinsae','Feleke','Tadesse','M','B','tinsae@gmail.com','pass123','active',5,3.05),
('WCU17D7815','Yeheyes','Tsegaye','Addise','M','B','yeheyes@gmail.com','pass123','active',5,3.20),

-- Group 6 (Leader: WCU177918)
('WCU177918','Eyasu','Addise','Ayanto','M','B','eyasu@gmail.com','pass123','active',6,3.50),
('WCU170186','Behailu','Belay','Tona','M','B','behailu@gmail.com','pass123','active',6,3.10),
('WCU174612','Abigiya','Belay','Wonje','F','B','abigiya@gmail.com','pass123','active',6,3.30),
('WCU178071','Tsinat','Nebiyu','Daniel','F','B','tsinat@gmail.com','pass123','active',6,3.40),
('WCU175410','Bekelcha','Nuredin','Aman','M','B','bekelcha@gmail.com','pass123','active',6,3.00),

-- Group 7 (Leader: WCU170132)
('WCU170132','Hikma','Mustefa','Nuri','F','B','hikma@gmail.com','pass123','active',7,3.55),
('WCU175475','Tsion','Aklilu','Legesse','F','B','tsion@gmail.com','pass123','active',7,3.35),
('WCU17D2702','Kamil','Ersido','Nurebo','M','B','kamil@gmail.com','pass123','active',7,3.10),

-- Group 8 (Leader: WCU176859)
('WCU176859','Absira','Geletu','Tadese','M','B','absira@gmail.com','pass123','active',8,3.45),
('WCU175738','Henok','Abebe','Ertiro','M','B','henok@gmail.com','pass123','active',8,3.20),
('WCU17D8797','Selam','Amare','Tafese','F','B','selam@gmail.com','pass123','active',8,3.30),
('WCU17D4260','Mariyamawit','Mideksa','Bulti','F','B','mariyam@gmail.com','pass123','active',8,3.50),

-- Group 9 (Leader: WCU173021)
('WCU173021','Etsubdink','Getachew','Abdi','F','B','etsubdink@gmail.com','pass123','active',9,3.60),
('WCU172814','Biruktawit','Areda','Fikadu','F','B','biruktawit@gmail.com','pass123','active',9,3.25),
('WCU174940','Betelihem','Zekios','Kumalo','F','B','betelihem@gmail.com','pass123','active',9,3.35);

select * from student where group_id =1;
select firstName from student where  student_id = (
select group_leader_id from groups where group_id=1)

INSERT INTO PROJECT (project_id, projectName, group_id)
VALUES
('P001', 'Akeray–Tekeray IMS', 1),
('P002', 'Hospital Appointment System', 2),
('P003', 'Hotel Management System', 3),
('P004', 'Library Management System', 4),
('P005', 'Online Car Rental System', 5),
('P006', 'Online Class Scheduling', 6),
('P007', 'Online Exam Management', 7),
('P008', 'Online Job Portal', 8),
('P009', 'Park Reservation System', 9),
('P011', 'Project Tracking System', null);

select* from PROJECT
select * from student where group_id =(
     select group_id from project where projectName='Akeray–Tekeray IMS'

)
 
 -- Insert into ADMIN table
INSERT INTO ADMIN 
VALUES 
('A001', 'Nati', 'Sita', 'Gebre', 'nati.admin@example.com', 'admin123', 'Active', 5);

-- Insert into HOD table
INSERT INTO HOD 
VALUES
('H001', 'Aelemayehu', 'Tesfaye', NULL , 'aelemayehu.hod@example.com', 'hod123', 'Active', '101');

-- Insert into ADVISOR table
INSERT INTO ADVISOR 
VALUES
('AD001', 'Fozzia', 'Aebaco', NULL, 'fozzia.advisor@example.com', 'advisor123', 'Active', 'CS101'),
('AD002', 'Sindo', 'Gebrea', NULL , 'sindo.advisor@example.com', 'advisor123', 'Active', 'FSE102');
