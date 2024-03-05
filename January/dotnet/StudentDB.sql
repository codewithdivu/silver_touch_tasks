create database Student;

use Student;

Create Table [User](
	UserID INT IDENTITY(1,1) PRIMARY KEY,
	Username NVARCHAR(100) NOT NULL,
	Email NVARCHAR(100) NOT NULL,
	FirstName NVARCHAR(50),
	LastName NVARCHAR(50),
	Gender NVARCHAR(10),
	CountryID INT,
	StateID INT,
	CityID INT,
	Address NVARCHAR(100),
	PhoneNumber NVARCHAR(100),
	IsActive BIT DEFAULT 1,
	FOREIGN KEY (CountryID) REFERENCES Country(CountryID),
    FOREIGN KEY (StateID) REFERENCES State(StateID),
    FOREIGN KEY (CityID) REFERENCES City(CityID)
);

INSERT INTO [User] (Username, Email, FirstName, LastName, Gender, CountryID, StateID, CityID, Address, PhoneNumber)
VALUES 
('john_doe_usa', 'john@example.com', 'John', 'Doe', 'Male', 1, 1, 1, '123 Main St', '123-456-7890'),
('jane_smith_canada', 'jane@example.com', 'Jane', 'Smith', 'Female', 2, 3, 5, '456 Elm St', '987-654-3210'),
('alex_wong_uk', 'alex@example.com', 'Alex', 'Wong', 'Male', 3, 5, 9, '789 Oak St', '555-123-4567'),
('maria_garcia_india', 'maria@example.com', 'Maria', 'Garcia', 'Female', 4, 7, 11, '101 River Rd', '111-222-3333'),
('jacob_patel_india', 'jacob@example.com', 'Jacob', 'Patel', 'Male', 4, 7, 12, '202 Lake Ave', '444-555-6666');

select * from [User];
    
delete from [User] where UserId = 9;



CREATE TABLE Country (
    CountryID INT IDENTITY(1,1) PRIMARY KEY,
    CountryName NVARCHAR(50) NOT NULL
);

INSERT INTO Country (CountryName) VALUES ('United States'), ('Canada'), ('United Kingdom'), ('India');


CREATE TABLE State (
    StateID INT IDENTITY(1,1) PRIMARY KEY,
    StateName NVARCHAR(50) NOT NULL,
    CountryID INT,
    FOREIGN KEY (CountryID) REFERENCES country(CountryID)
);

INSERT INTO State (StateName, CountryID) VALUES 
('California', 1),
('New York', 1),
('Ontario', 2),
('Quebec', 2),
('England', 3),
('Scotland', 3),
('Maharashtra', 4),
('Karnataka', 4);


CREATE TABLE City (
    CityID INT IDENTITY(1,1) PRIMARY KEY,
    CityName NVARCHAR(50) NOT NULL,
    StateID INT,
    FOREIGN KEY (StateID) REFERENCES state(StateID)
);

INSERT INTO City (CityName, StateID) VALUES 
('Los Angeles', 1),
('San Francisco', 1),
('New York City', 2),
('Buffalo', 2),
('Toronto', 3),
('Ottawa', 4),
('London', 5),
('Manchester', 5),
('Glasgow', 6),
('Edinburgh', 6),
('Mumbai', 7),
('Pune', 7),
('Bangalore', 8),
('Mysore', 8);


select * from City;