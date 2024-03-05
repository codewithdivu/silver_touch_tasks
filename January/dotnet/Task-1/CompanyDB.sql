create database CompanyDB;

use CompanyDB;


-- Create Department Table
CREATE TABLE Department (
    DepartmentID INT PRIMARY KEY,
    DepartmentName VARCHAR(100),
    Location VARCHAR(100),
    ManagerID INT,
    Budget DECIMAL(18, 2)
);


ALTER TABLE Department
ALTER COLUMN DepartmentID INT IDENTITY(1,1);

use CompanyDB;
select * from Department;

INSERT INTO Department (DepartmentID, DepartmentName, Location, ManagerID, Budget)
VALUES 
(1, 'IT', 'New York', 3, 100000),
(2, 'Marketing', 'Los Angeles', 2, 80000),
(3, 'Finance', 'Chicago', 1, 120000),
(4, 'HR', 'Houston', 5, 90000),
(5, 'Operations', 'San Francisco', 4, 110000);





-- Create Employee Table
CREATE TABLE Employee (
    EmployeeID INT PRIMARY KEY,
    Name VARCHAR(100),
    DepartmentID INT,
    Gender VARCHAR(10),
    Email VARCHAR(255),
    FOREIGN KEY (DepartmentID) REFERENCES Department(DepartmentID)
);

select * from Employee;

INSERT INTO Employee (EmployeeID, Name, DepartmentID, Gender, Email)
VALUES 
(1, 'John Doe', 1, 'Male', 'johndoe@gmail.com'),
(2, 'Jane Smith', 2, 'Female', 'janesmith@gmail.com'),
(3, 'Mike Johnson', 1, 'Male', 'mikejohnson@gmail.com'),
(4, 'Emily Brown', 3, 'Female', 'emilybrown@gmail.com'),
(5, 'David Lee', 2, 'Male', 'davidlee@gmail.com');



-- Create Project Table
CREATE TABLE Project (
    ProjectID INT PRIMARY KEY,
    ProjectName VARCHAR(100),
    StartDate DATE,
    EndDate DATE,
    Status VARCHAR(20)
);



INSERT INTO Project (ProjectID, ProjectName, StartDate, EndDate, Status)
VALUES 
(1, 'Website Redesign', '2023-01-10', '2023-06-30', 'Active'),
(2, 'Product Launch', '2023-03-15', '2023-09-30', 'Active'),
(3, 'Financial Analysis', '2023-02-05', '2023-05-20', 'Completed'),
(4, 'Marketing Campaign', '2023-04-20', '2023-08-10', 'Active'),
(5, 'Employee Training', '2023-06-01', '2023-07-15', 'Inactive');


-- Create Task Table
CREATE TABLE Task (
    TaskID INT PRIMARY KEY,
    TaskName VARCHAR(100),
    ProjectID INT,
    AssignedTo INT,
    Priority VARCHAR(20),
    FOREIGN KEY (ProjectID) REFERENCES Project(ProjectID),
    FOREIGN KEY (AssignedTo) REFERENCES Employee(EmployeeID)
);

INSERT INTO Task (TaskID, TaskName, ProjectID, AssignedTo, Priority)
VALUES 
(1, 'Design Mockups', 1, 1, 'High'),
(2, 'Content Creation', 1, 2, 'Medium'),
(3, 'Market Research', 2, 3, 'High'),
(4, 'Budget Planning', 3, 4, 'Medium'),
(5, 'Training Material Creation', 5, 5, 'Low');


-- Create Salary Table
CREATE TABLE Salary (
    SalaryID INT PRIMARY KEY,
    EmployeeID INT,
    SalaryAmount DECIMAL(18, 2),
    PaymentDate DATE,
    PaymentMethod VARCHAR(20),
    FOREIGN KEY (EmployeeID) REFERENCES Employee(EmployeeID)
);


INSERT INTO Salary (SalaryID, EmployeeID, SalaryAmount, PaymentDate, PaymentMethod)
VALUES 
(1, 1, 60000, '2024-01-31', 'Direct Deposit'),
(2, 2, 70000, '2024-01-31', 'Cheque'),
(3, 3, 80000, '2024-01-31', 'Cash'),
(4, 4, 75000, '2024-01-31', 'Direct Deposit'),
(5, 5, 65000, '2024-01-31', 'Cheque');
