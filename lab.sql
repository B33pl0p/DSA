 --###############################
 --lab day 1
 --###############################
CREATE TABLE student(id int , name varchar(50) , rn int , batch int);
CREATE TABLE teacher(t_id int, name varchar(50), faculty varchar(10));


SELECT * FROM student; 
SELECT * FROM teacher;


INSERT INTO student (id, name, rn, batch) values
(1,'ram',12,077),
(2,'shyam',13,077),
(3,'hari',14,077),
(4,'krishna',15,077),
(5,'radha',16,077);


INSERT INTO teacher (t_id, name,faculty)VALUES
(1,'einstein','bei'),
(2,'newton','bei'),
(3,'rutherford','bei'),
(4,'openheimmer','bei'),
(5,'tonystark','bei');


SELECT name,batch FROM student;
SELECT id , name INTO student_info
from student


select * from student_info;
ALTER TABLE student drop column rn;


select * from student;
ALTER TABLE teacher ADD salary int;

select * from teacher;

 --###############################
 --lab day 2
 --###############################

ALTER TABLE student 
ALTER COLUMN id INT NOT NULL;
ALTER TABLE student
ADD PRIMARY KEY(id);
SELECT * FROM student;

select * from student_info;

INSERT INTO student (id, name, rn, batch) values
(6,'rahari',20,077);


CREATE TABLE employe(e_id int , e_name varchar(20), date_of_emp date,salary int
PRIMARY KEY(e_id))
CREATE TABLE booklist(isbn varchar(20),name varchar(20), publication varchar(20) ) ;
CREATE TABLE book(b_id int , b_name varchar(20) ,author varchar(20) , price int);
CREATE TABLE issues(i_id int , name varchar(20), date_of_issue date);




INSERT INTO employe ( e_id , e_name , date_of_emp ,salary ) values 
(001, 'Anirudrea dahal' ,'2022-3-22' , 100),
(002, 'Darwin Acharya ' ,'2022-3-23' , 1000),
(003, 'Aashik kr mahato' ,'2022-3-22' , 10),
(004, 'Biplop Giri' ,'2022-3-24' , 1000000),
(005, 'Ajay Shrestha ' ,'2022-3-19' , 100);

ALTER TABLE employe 
ALTER COLUMN e_id INT NOT NULL;
ALTER TABLE employe
ADD PRIMARY KEY(e_id);



INSERT INTO booklist ( isbn ,name , publication) values 
('111', 'physics' ,'readmore'),
('112', 'chemistry' ,'buddha'),
('113', 'maths' ,'sajha'),
('114', 'english' ,'asmita'),
('115', 'health' ,'mcgrawhill');

ALTER TABLE booklist

ALTER COLUMN isbn INT NOT NULL;
ALTER TABLE booklist
ADD PRIMARY KEY(isbn);

INSERT INTO book ( b_id , b_name , author , price) values 
(001, 'physics' ,'fenyman', 150),
(002, 'chemistry' ,'dalton', 250),
(003, 'maths' ,'bcbajr', 350),
(004, 'optmas' ,'drsimkh', 150),
(005, 'english' ,'shakese', 150);

ALTER TABLE book
ALTER COLUMN b_id INT NOT NULL;
ALTER TABLE book
ADD PRIMARY KEY(b_id);

INSERT INTO issues (i_id , name , date_of_issue) values 
(0001 , 'issue1', '2023-3-13'),
(0002 , 'issue2', '2023-4-13'),
(0003 , 'issue3', '2023-3-14'),
(0004 , 'issue4', '2023-2-16'),
(0005 , 'issue5', '2022-3-10');

ALTER TABLE issues

ALTER COLUMN i_id INT NOT NULL;
ALTER TABLE issues
ADD PRIMARY KEY(i_id);

SELECT * FROM employe
SELECT * FROM booklist
SELECT * FROM book
SELECT * FROM issues

--for foreign key



ALTER TABLE teacher  ALTER column t_id INT NOT NULL
ALTER TABLE teacher ADD PRIMARY KEY(t_id);

CREATE TABLE parent(pid int,t_id int, name varchar(20), address varchar(20)
PRIMARY KEY(pid)
FOREIGN KEY(t_id) REFERENCES teacher(t_id) );
INSERT INTO parent(pid,t_id,name,address) values(001,1,'hello', 'there');
SELECT * FROM book

--############################
-- LAB DAY 3
-- ########################

--foreign key
ALTER TABLE issues ADD CONSTRAINT FK_issues_book FOREIGN KEY (i_id)   REFERENCES book(b_id);
ALTER TABLE book ADD CONSTRAINT FK_book_issues FOREIGN KEY (b_id) REFERENCES issues(i_id);


--default value of date
--ALTER TABLE employe ALTER COLUMN date_of_emp SET DEFAULT '2010-01-01';
ALTER TABLE employe ADD CONSTRAINT d_fk DEFAULT '2010-01-01' FOR date_of_emp;
--check
INSERT INTO employe ( e_id , e_name ,salary ) values 
(008, 'Anil' , 100);
SELECT * from employe

--eid and ename having salary less than 1000
SELECT e_id, e_name FROM employe WHERE salary<1000;

--display books with price from 2500 to 5000
select * FROM book WHERE price>250 and price < 500;

--publication name starting with e
select * from booklist where publication like 'e%'

--employe names wnding with ta
select * from employe where e_name like '%ta'

--price of books must be less than 5000
ALTER TABLE book
ADD CONSTRAINT check_price CHECK(price <5000);

--checking for values >5000
--drop foreign key to insert
ALTER TABLE book DROP CONSTRAINT FK_book_issues
INSERT INTO book ( b_id , b_name , author , price) values 
(008, 'physicaloptics' ,'fenyman1', 150);