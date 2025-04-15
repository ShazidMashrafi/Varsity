CREATE DATABASE TeachersrecordJKKNIU;
USE TeachersrecordJKKNIU;
CREATE TABLE Faculty 
(
  ID VARCHAR(10),
    name VARCHAR(50),
    PRIMARY KEY(ID)
);

CREATE TABLE Department
(
    ID VARCHAR(10),
    name VARCHAR(50),
    chairman VARCHAR(100),
    faculty_id VARCHAR(10),
    PRIMARY KEY (ID),
    FOREIGN KEY (faculty_id) REFERENCES Faculty(ID)
);

Create Table Teacher 
(
  ID VARCHAR(50),
    name VARCHAR(100),
    designation VARCHAR(50),
    gender VARCHAR(10),
    phone VARCHAR(15),
    email VARCHAR(50),
    dept_id VARCHAR(10),
    primary key(ID),
    FOREIGN KEY(dept_id) REFERENCES Department(ID)
);


Insert into Faculty(ID, name)
Values('1', 'Science'),
       ('2', 'Arts'),
       ('3', 'Social Science'),
       ('4', 'Business'),
       ('5','Law'),
       ('6','Fine Arts');
       
select * from Faculty;

INSERT INTO Department
(ID, name, chairman, faculty_id)
VALUES
    ('101', 'Computer Science & Engineering', 'Dr. Md. Sujan Ali', '1'),
    ('102', 'Electrical and Electronics Engineering', 'Kazi Md. Shahiduzzaman', '1'),
    ('103', 'Environmental Science and Engineering', 'MD. Rakibul Hassan', '1'),
    ('104', 'Statistics', 'Abdul Muyeed (Palash)', '1');

SELECT * FROM TeachersrecordJKKNIU.Department ;

INSERT INTO Department
(ID, name, chairman, faculty_id)
VALUES
    ('201', 'Bangla Language and Literature', 'Dr. Md. Habib-Ul-Maula (Maula Prince)', '2'),
    ('202', 'English Language and Literature', 'Raihana Akter', '2'),
    ('203', 'Music', 'Dr. Musarrat Shabnam', '2'),
    ('204', 'Theatre and Performance Studies', 'Sayed Mamun Reza', '2'),
    ('205', 'Film and Media', 'Dr. Md. Tuhinur Rahman', '2'),
    ('206', 'Philosophy', 'Md. Tariful Islam', '2');
    
INSERT INTO Department
(ID, name, chairman, faculty_id)
VALUES
    ('301', 'Economics', 'Ms. Rehnuma Ferdous', '3'),
    ('302', 'Public Administration and Governance Studies', 'Mahjabin Sultana Mitul', '3'),
    ('303', 'Folklore', 'Dr. Mohammad Mehedi Ullah', '3'),
    ('304', 'Anthropology', 'K. M. Mahmudul Haque', '3'),
    ('305', 'Population Science', 'Md. Nure Alam Siddiqi', '3'),
    ('306', 'Local Government and Urban Development', 'Tania Afrin Tonny', '3'),
    ('307', 'Sociology', 'Md. Masudur Rahman', '3');

INSERT INTO Department
(ID, name, chairman, faculty_id)
VALUES
    ('401', 'Accounting and Information Systems', 'Dr. Shakhawat Hossain Sarkar', '4'),
    ('402', 'Finance and Banking', 'Dr. Md. Tariqul Islam', '4'),
    ('403', 'Human Resource Management', 'Alvy Riasat Malik', '4'),
    ('404', 'Management', 'Razuan Ahmed Shuvro', '4'),
    ('405', 'Marketing', 'KUMAR BISWAZIT SAHA', '4');
    
INSERT INTO Department
(ID, name, chairman, faculty_id)
VALUES
    ('501', 'Law and Justice', 'Md. Ahsan Kabir', '5')
    ;
    
INSERT INTO Department
(ID, name, chairman, faculty_id)
VALUES
    ('601', 'Fine Arts', 'Dr. Mohammad Emdadur Rashed', '6')
    ;
    
ALTER TABLE teacher
DROP COLUMN Address;

INSERT INTO Teacher
(ID, name, designation,gender,phone, email,dept_id)
VALUES
    ('10101', 'Dr. A. H. M. Kamal', ' Professor', 'Male','017-32226-402','kamal@jkkniu.edu.bd','101'),
    ('10102', 'Md. Mijanur Rahman, Ph. D.', ' Professor', 'Male','0123456789','mijan@jkkniu.edu.bdh','101'),
    ('10103', 'Professor Dr. Md. Sujan Ali (Sheikh Sujan Ali)', 'Professor & Head of the Department', 'Male','01919817351','sujan_cse@jkkniu.edu.bd','101'),
    ('10104', 'Professor Dr. Md. Saiful Islam', 'Professor', 'Male','01552-637446','saifulmath@yahoo.com','101'),
    ('10105', 'Mst. Jannatul Ferdous, PhD', 'Professor', 'Female ',' 01710695925',' mjferdous_cse@jkkniu.edu.bd','101'),
    ('10106', 'Dr. Tushar Kanti Saha', 'Professor', 'Male ',' 0123456789',' tusharcsebd@gmail.com','101');
    
    select * from Teacher;
    ALTER TABLE Teacher MODIFY email VARCHAR(50);

INSERT INTO Teacher
(ID, name, designation,gender,phone, email,dept_id)
VALUES
    ('10201', 'Bijoy Kumer Karmaker', 'Associate Professor', 'Male',' 01712480823',' bijoy_ice@jkkniu.edu.bd','102'),
    ('10202', 'Kazi Md. Shahiduzzaman', 'Associate Professor & Head of the Department', 'Male','0123456789','kazi_eee05@yahoo.com','102'),
    ('10203', '.Md. Ali Asgar', 'Assistant Professor', 'Male','01712842874','papillon27@jkkniu.edu.bd','102'),
    ('10204', 'Dr. Md. Mahbubur Rahman', 'Associate Professor', 'Male','0123456789','DNbG8YcvxS@jkkniu.edu.bd','102');

INSERT INTO Teacher
(ID, name, designation,gender,phone, email,dept_id)
VALUES
    ('10301', 'Dr. Ashraf Ali Seddique', 'Professor', 'Male',' 0123456789',' ashraf.ali@jkkniu.edu.bd','103'),
    ('10302', 'MD. Rakibul Hassan', 'Assistant Professor and Head of the Dept.', 'Male','01914808782',' rakib.esrm@gmail.com','103'),
    ('10303', 'Rtn. MD. Nakibul Hasan Khan', 'Assistant Professor', 'Male','01730040566','hasannakibk@gmail.com','103'),
    ('10304', 'Bipulendu Basak', 'Assistant Professor', 'Male','01717506669','bbasak.gm@gmail.com','103');
   
INSERT INTO Teacher
(ID, name, designation,gender,phone, email,dept_id)
VALUES
    ('10401', 'Abdul Muyeed (Palash)', 'Assistant Professor, Department of Statistics', 'Male',' 01725912378','amuyeed@isrt.ac.bd','104'),
    ('10402', 'Most. Tawabunnahar', 'Lecturer ', 'Female','01740156575',' tnrupa@jkkniu.edu.bd','104'),
    ('10403', 'Taj-E-Jannat Mim', 'Assistant Professor', 'Female','0123456789','tjannat1@isrt.ac.bd','104'),
    ('10404', 'Md. Merajul Islam', 'Lecturer', 'Male','01762819351','merajul.stat4811@gmail.com','104');
    
INSERT INTO Teacher
(ID, name, designation,gender,phone, email,dept_id)
VALUES
    ('50101', 'Md. Ahsan Kabir', 'Assistant Professor and Head of the Department', 'Male','01717749755','ahsan.law.ru@gmail.com','501'),
    ('50102', 'Mohammad Irfan Aziz', 'Assistant Professor', 'Male','01816373239',' irfandu07@gmail.com','501'),
    ('50103', 'Md. Asaduzzaman', 'Assistant Professor', 'Male','01735235168','asaduzzamanlaw@gmail.com','501'),
    ('50104', 'Kazi Iqramul Haq', 'Lecturer', 'Male','01762781216','kazi7812@gmail.com','501');
    
INSERT INTO Teacher
(ID, name, designation,gender,phone, email,dept_id)
VALUES
    ('60101', '.Dr. Mohammad Emdadur Rashed', 'Professor & Head of the Department', 'Male','01716487686','sukhon.fa@gmail.com','601'),
    ('60102', 'Tapon Kumer Sarker', 'Professor', 'Male','0123456789','sarker_tk@yahoo.com','601'),
    ('60103', 'Nagarbasi Barman', 'Associate Professor', 'Male','01715-122402','nb.barman@gmail.com','601'),
    ('60104', 'Masum Hawlader', 'Assistant Professor', 'Male','0123456789','okrRp3rRxv@jkkniu.edu.bd','601');
    
INSERT INTO Teacher
(ID, name, designation,gender,phone, email,dept_id)
VALUES
    ('20101', 'Dr Md. Mahbub Hossain', 'Professor', 'Male','01712946850','mahbubborhan65@gmail.com','201'),
    ('20102', 'Md. Shahabuddin Ph.D.', 'Professor', 'Male','01712745758','badal_bll@jkkniu.edu.bd','201'),
    ('20103', 'Ahammadul Bari', 'Professor', 'Male','0123456789','ahammadul_bari@jkkniu.edu.bd','201'),
    ('20104', 'Dr. Md. Habib-Ul-Maula (Maula Prince)', ' Professor and Head of the Department', 'Male','0123456789','humprince@yahoo.com','201');
    
INSERT INTO Teacher
(ID, name, designation,gender,phone, email,dept_id)
VALUES
    ('20201', 'Prof.Dr. Mohammad Emdadul Huda', 'Professor', 'Male','0123456789','dd2894affdeb8bceab1fb596308d183f@jkkniu.edu.bd','202'),
    ('20202', 'Raihana Akter', 'Associate Professor and Head of the Department', 'Female','0123456789','raihanaakter508@gmail.com','202'),
    ('20203', 'Arpana Awwal', 'Associate Professor', 'Female','0123456789','arpana_awwal@jkkniu.edu.bd','202'),
    ('20204', 'Dr. Sheikh Mehedi Hasan', 'Associate Professor', 'Male','0123456789','mehedi_08@jkkniu.edu.bd','202');

INSERT INTO Teacher
(ID, name, designation,gender,phone, email,dept_id)
VALUES
    ('20301', 'Dr. Musarrat Shabnam', 'Professor', ' Female','0123456789','ejJ1OyUnvy@jkkniu.edu.bd','203'),
    ('20302', 'Dr. Rashidun Nabi (PRL)', 'Professor', 'Male','0123456789','rnabimusic@gmail.com','203'),
    ('20303', 'Dr. Sushanta Kumar Sarker', 'Professor', 'Male','0123456789','9-BINN2hGJ@jkkniu.edu.bd','203'),
    ('20304', 'Dr. Md. Zahidul Kabir', 'Professor & Head of the Department', 'Male','0123456789','LWKgFthZt_@jkkniu.edu.bd','203');

INSERT INTO Teacher
(ID, name, designation,gender,phone, email,dept_id)
VALUES
    ('20401', 'Sayed Mamun Reza', 'Assistant Professor', ' Male','01716356910','mamun.theatre@jkkniu.edu.bd','204'),
    ('20402', 'Ismat Ara Bhuiya Ila', 'Assistant Professor', 'Female','01717451241','ila.kotha@gmail.com','204'),
    ('20403', 'Dr. Md. Kamal Uddin', 'Associate Professor and Head of the Department', 'Male','01719254426','mkumondal@gmail.com','204'),
    ('20404', 'AL ZABIR', 'Associte Professor', 'Male','01716253627','zabirknu@gmail.com','204');


INSERT INTO Teacher
(ID, name, designation,gender,phone, email,dept_id)
VALUES
    ('20501', 'Dr. Md. Tuhinur Rahman', 'Associate Professor and Head of the Department', ' Male','0123456789','ffa8da497882a2d47430327da90190e3@jkkniu.edu.bd','205'),
    ('20502', 'Mahmuda Sikder', 'Assistant Professor', 'Female','0123456789','mahmuda.sikder01@gmail.com','205'),
    ('20503', 'Manoj Kumar Pramanik', 'Lecturer', 'Male','01716141511','pramanik_m@yahoo.com','205'),
    ('20504', 'Mashkura Rahman', 'Lecturer', 'Female','0123456789','mashkura.rhythm@gmail.com','205');

    
INSERT INTO Teacher
(ID, name, designation,gender,phone, email,dept_id)
VALUES
    ('20601', 'Md. Kaharul Islam', 'Assistant Professor', ' Male','01723981343','kaharulislam87@gmail.com','206'),
    ('20602', 'Md. Tariful Islam', 'Assistant Professor and Head of the Department', 'Male','0123456789','tarifuldu@gmai.com','206'),
    ('20603', 'khairul islam', 'Lecturer', 'Male','0123456789','khairuldu26993@gmail.com','206'),
    ('20604', 'Shaila Islam Nipa', 'Lecturer', 'Female','0123456789','shailaislamnipa98@gmail.com','206');
   
INSERT INTO Teacher
(ID, name, designation,gender,phone, email,dept_id)
VALUES
    ('30101', ' Dr. Md. Nazrul Islam ', ' Professor & Head of the Department ', 'Male','01345789643','410b39aaf75de97cc9af67176514a7e5@jkkniu.edu.bd ','301'),
    ('30102', 'Ms. Rehnuma Ferdous', 'Associate Professor', 'Female',' 01818979375 ',' ashaferdous@gmail.com ','301'),
    ('30103', ' Md Bakhtiar Uddin', 'Associate Professor', 'Male',' 01711977035 ',' bakhtiar@jkkniu.edu.bd','301'),
    ('30104', 'Shabikunnahar Bonna', 'Lecturer', 'Female',' 01712499593 ',' bonnashabikunnahar@gmail.com ','301');
    
INSERT INTO Teacher
(ID, name, designation,gender,phone, email,dept_id)
VALUES
    ('30201', 'Azizur Rahman', ' Associate Professor & Head of the Department','Male','01914343888 ','abir7du@yahoo.com ','302'),
    ('30202', ' Shanjay Kumar Mukharjee', ' Associate Professor', 'Male','01715635319 ','shanjay.jkkniu@gmail.com','302'),
    ( '30203' , 'Sharmin Begum', 'Associate Professor', 'Female',' 01718613788','sharminpags15@gmail.com ','302'),
    ('30204', ' Nazmul Hasan', ' Assistant Professor', 'Male','019853264503','nazmul.pags23@gmail.com ','302');
    
INSERT INTO Teacher
(ID, name, designation,gender,phone, email,dept_id)
VALUES
    ('30301', 'Dr. Md. Saiful Islam',' Assistant Professor', 'Female','01437825032','saiful13ba@gmail.com ','303'),
    ('30302', 'Niger Sultana  ', ' Associate Professor ', 'Female','01567309254',' HOrTDQqd0n@jkkniu.edu.bd ','303'),
    ('30303', ' Dr. Atiza Dill Afrose ', ' Associate Professor','Female','01234693402','atizadillafrose@jkkniu.edu.bd ','303'),
    ('30304', 'Proditi Routh Proma ', ' Lecturer', 'Female',' 01706482600 ','proditi@jkkniu.edu.bd ','303');
    
INSERT INTO Teacher
(ID, name, designation,gender,phone, email,dept_id)VALUES
('30401', 'Asif Ekbal Arif ', ' Assistant Professor & Head of the Department ', 'Male','01515261403 ',' dm.aekbalarif@gmail.com ','304'),
    ('30402', ' JANNATUL NAIYM ', ' Assistant Professor', 'Female','01239876643','jannatulnaiym2020@gmail.com ','304'),
    ('30403', 'Swapna Papul ', ' Lecturer', 'Female','01456864004','spapul45@gmail.com ','304'),
    ('30404', ' Juwel Molla ', ' Lecturer ', 'Male',' 01335566007','juwelmollarj19@gmail.com ','304');
    
INSERT INTO Teacher
(ID, name, designation,gender,phone, email,dept_id)
VALUES
    ('30501', 'Md Nuruzzaman Khan ', ' Associate Professor', 'Male','+8801611027536 ','sumon_pops@jkkniu.edu.bd ','305'),
    ('30502', 'Md. Syful Islam ', ' Lecturer ', 'Male','01456789001',' syful111@gmail.com ','305'),
  ('30503', 'Shimlin Jahan Khanam', ' Assistant Professor', 'Female','+8801611027536 ','shimlinjahan2208@gmail.com ','305'),
    ('30504', 'MAMUNUR RASHID', ' Lecturer ', 'Male','01456789001',' ps.ru.mamun@gmail.com ','305');
    
INSERT INTO Teacher
(ID, name, designation,gender,phone, email,dept_id)
VALUES
    ('40101', ' Tania Afrin Tonny ', ' Associate Professor', 'Female','+8801611027536 ',' tania.tonny@jkkniu.edu.bd ','401'),
    ('40102', ' Uswatun Mahera Khushi ', ' Assistant Professor ', 'Female','01456789001',' khushi.lgud@jkkniu.edu.bd ','401'),
  ('40103', ' Md. Rakibul Islam', ' Assistant Professor & Head of the Dept.', 'Male','+8801611027536 ',' rakibul.shawon93@gmail.com ','401'),
    ('40104', ' Sadik Hasan', ' Assistant Professor ', 'Male','01456789001',' sadik.jkkniu@gmaiil.com ','401');
    
INSERT INTO Teacher
(ID, name, designation,gender,phone, email,dept_id)
VALUES
    ('40201', ' Md. Reazul Islam ', ' Assistant Professor', 'Male','+8801611027536 ',' reazul@jkkniu.edu.bd ','402'),
    ('40202', ' Sonya Farhana Sony ', ' Lecturer ', 'Female','01456789001',' farhana12.mars@gmail.com','402'),
  ('40203', ' Md. Masudur Rahman ', ' Assistant Professor & Head of the Dept.', 'Male','+8801611027536 ',' mrahman1masud@gmail.com ','402'),
    ('40204', ' Rashed Hossain', ' Lecturer ', 'Male','01456789001',' hossainrashed47@gmail.com  ','402');