CREATE TABLE EMPLOYEE(
Fname 			VARCHAR(20),
Minit 			CHAR(1),
Lname 			VARCHAR(20),
Ssn 			INT PRIMARY KEY,
Bdate 			DATE,
Address 		VARCHAR(30),
Sex 			CHAR(1),
Salary 			INT,
Super_ssn	 	INT,
Dno 			INT
);

CREATE TABLE DEPARTMENT(
Dname 			VARCHAR(20),
Dnumber 		INT PRIMARY KEY,
Mger_ssn 		INT,
Mgr_start_date 	INT
);

CREATE TABLE DEPT_LOCATIONS(
Dnumber 			INT,
Dlocation string	VARCHAR(10),

PRIMARY KEY (Dnumber, Dlocation)
);

CREATE TABLE PROJECT(
Pname 			VARCHAR(20),
Pnumber 		INT PRIMARY KEY,
Plocation 		VARCHAR(20),
Dnum 			INT
);

CREATE TABLE WORKS_ON(
Essn 			INT,
Pno 			INT,
Hours 			FLOAT,

PRIMARY KEY (Essn, Pno)
);

CREATE TABLE DEPENDENT(
Essn 			INT,
Dependent_name 	VARCHAR(20),
Sex 			CHAR(1),
Bdate 			INT,
Relationship 	VARCHAR(20),

PRIMARY KEY (Essn, Dependent_name)
);
	
Insert Into EMPLOYEE
	Values ('John', 'B', 'Smith', 123456789, '1965-01-09', '731 Fondren, Houston, TX', 'M', 30000, 333445555, 5);
	
Insert Into EMPLOYEE
	Values ('Franklin', 'T', 'Wong', 333445555, '1955-12-08', '638 Voss, Houston, TX', 'M', 40000, 888665555, 5);	
	
Insert Into EMPLOYEE
	Values ('Alicia', 'J', 'Zelaya', 999887777, '1968-01-19', '3321 Castle, Spring, TX', 'F', 25000, 987654321, 4);

Insert Into EMPLOYEE
	Values ('Jennifer', 'S', 'Wallace', 987654321, '1941-06-20', '291 Berry, Bellaie, TX', 'F', 43000, 888665555, 4);

Insert Into EMPLOYEE
	Values ('Ramesh', 'N', 'Narayan', 666884444, '1962-09-15', '975 Fire Oak, Humble, TX', 'M', 38000, 333445555, 5);

Insert Into EMPLOYEE
	Values ('Joyce', 'A', 'English', 453453453, '1972-07-31', '5631 Rice, Houston, TX', 'F', 25000, 333445555,5);

Insert Into EMPLOYEE
	Values ('Ahmad', 'V', 'Jabbar', 987987987, '1969-03-29', '980 Dallas, Houston, TX', 'M', 25000, 987654321, 4);

Insert Into EMPLOYEE
	Values ('James', 'E', 'Borg', 888665555, '1937-11-10', '450 Stone, Houston, TX', 'M', 55000, NULL, 1);	
	
Insert Into PROJECT
	Values ('ProductX', 1, 'Bellaire', 5);
	Values ('ProductY', 2, 'Sugarland', 5);
	Values ('ProductZ', 3, 'Houston', 5);
	Values ('Computerization', 10, 'Stafford', 4);
	Values ('Reorganization', 20, 'Houston', 1);
	Values ('Newbenefits', 30, 'Stafford', 4);
	
Insert Into WORKS_ON
	Values (123456789, 1, 32.5);
	Values (123456789, 2, 7.5);
	Values (666884444, 3, 40.0);
	Values (453453453, 1, 20.0);
	Values (453453453, 2, 20.0);
	Values (333445555, 2, 10.0);
	Values (333445555, 3, 10.0);
	Values (333445555, 10, 10.0);
	Values (333445555, 20, 10.0);
	Values (999887777, 30, 30.0);
	Values (999887777, 10, 10.0);
	Values (987987987, 10, 35.0);
	Values (987987987, 30, 5.0);
	Values (987654321, 30, 20.0);
	Values (987654321, 20, 15.0);
	Values (888665555, 20, NULL);
	
Insert Into DEPENDENT
	Values (333445555, 'Alice', 'F', 1986-04-05, 'Daughter');
	Values (333445555, 'Theodore', 'M', 1983-10-25, 'Son');
	Values (333445555, 'Joy', 'F', 1958-05-03, Spouse);
	Values (987654321, 'Abner', 'M', 1942-02-28, Spouse);
	Values (123456789, 'Michael', 'M', 1988-01-04, Son);
	Values (123456789, 'Alice', 'F', 1988-12-30, Daughter);
	Values (123456789, 'Elizabeth', 'F', 1967-05-05, Spouse);
	
Insert Into DEPARTMENT
	Values ('Research', 5, 333445555, 1988-05-22);
	Values ('Administration', 4, 987654321, 1995-01-01);
	Values ('Headquarters', 1, 888665555, 1981-06-19);
	
Insert Into DEPT_LOCATIONS
	Values (1, 'Houston');
	Values (4, 'Stafford');
	Values (5, 'Bellaire');
	Values (5, 'Sugarland');
	Values (5, 'Houston');
	
Select *
	From EMPLOYEE
	
Select *
	From DEPARTMENT

Select *
	From DEP_LOCATIONS

Select *
	From PROJECT

Select *
	From WORKS_ON

Select *
	From DEPENDENT	