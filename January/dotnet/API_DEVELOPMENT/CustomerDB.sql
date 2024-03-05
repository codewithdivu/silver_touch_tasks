create database CustomerDB;

use CustomerDB;

CREATE TABLE Customers (
    CustomerID INT IDENTITY(1,1) PRIMARY KEY,
    FirstName NVARCHAR(50),
    LastName NVARCHAR(50),
    Email NVARCHAR(100)
);

select * from Customers;


INSERT INTO Customers (FirstName, LastName, Email)
VALUES 
    ('Rahul', 'Gupta', 'rahul.gupta@example.com'),
    ('Priya', 'Sharma', 'priya.sharma@example.com'),
    ('Amit', 'Patel', 'amit.patel@example.com'),
    ('Neha', 'Joshi', 'neha.joshi@example.com'),
    ('Sandeep', 'Kumar', 'sandeep.kumar@example.com');

CREATE TABLE Orders (
    OrderID INT IDENTITY(1,1) PRIMARY KEY,
    CustomerID INT,
    OrderDate DATETIME,
    TotalAmount DECIMAL(10, 2),
    FOREIGN KEY (CustomerID) REFERENCES Customers(CustomerID)
);

INSERT INTO Orders (CustomerID, OrderDate, TotalAmount)
VALUES 
    (1, '2024-02-26', 100.00),
    (2, '2024-02-25', 150.50),
    (3, '2024-02-24', 75.25),
    (4, '2024-02-23', 200.75),
    (5, '2024-02-22', 120.00);

CREATE TABLE OrderDetails (
    OrderDetailID INT IDENTITY(1,1) PRIMARY KEY,
    OrderID INT,
    ProductID INT,
    Quantity INT,
    Price DECIMAL(10, 2),
    FOREIGN KEY (OrderID) REFERENCES Orders(OrderID)
);

INSERT INTO OrderDetails (OrderID, ProductID, Quantity, Price)
VALUES 
    (1, 101, 2, 50.00),
    (1, 102, 1, 25.00),
    (2, 103, 3, 30.50),
    (3, 104, 1, 75.25),
    (4, 105, 2, 100.00),
    (5, 106, 1, 120.00);


CREATE TABLE LogEntries (
    LogEntryId INT IDENTITY(1,1) PRIMARY KEY,
    Timestamp DATETIME NOT NULL,
    LogLevel NVARCHAR(20) NOT NULL,
    Message NVARCHAR(MAX) NOT NULL,
    ExceptionMessage NVARCHAR(MAX),
    StackTrace NVARCHAR(MAX),
    AdditionalInfo NVARCHAR(MAX)
);
