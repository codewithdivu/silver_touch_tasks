CREATE DATABASE Market;

USE Market;

CREATE TABLE Products (
    ProductID INT PRIMARY KEY,
    ProductName NVARCHAR(100) NOT NULL,
    Description NVARCHAR(255),
    Price DECIMAL(10, 2) NOT NULL
);

CREATE TABLE Products_New (
    ProductID INT IDENTITY(1,1) PRIMARY KEY,
    ProductName NVARCHAR(100) NOT NULL,
    Description NVARCHAR(255),
    Price DECIMAL(10, 2) NOT NULL
);

SET IDENTITY_INSERT Products_New ON;
INSERT INTO Products_New (ProductID, ProductName, Description, Price)
SELECT ProductID, ProductName, Description, Price
FROM Products;
SET IDENTITY_INSERT Products_New OFF;

DROP TABLE Products;

EXEC sp_rename 'Products_New', 'Products';

select * from Products_New;




INSERT INTO Products (ProductID, ProductName, Description, Price) VALUES
(1, 'Laptop', '15-inch Laptop with Intel Core i5 Processor', 899.99),
(2, 'Smartphone', 'Latest Android Smartphone with Dual Camera', 699.99),
(3, 'Tablet', '10-inch Tablet with Retina Display', 399.99),
(4, 'Headphones', 'Wireless Noise-Canceling Headphones', 299.99),
(5, 'Smartwatch', 'Fitness Tracker with Heart Rate Monitor', 199.99);

CREATE TABLE Customers (
    CustomerID INT PRIMARY KEY,
    FirstName NVARCHAR(50) NOT NULL,
    LastName NVARCHAR(50) NOT NULL,
    Email NVARCHAR(100) NOT NULL,
    Phone NVARCHAR(20),
    Address NVARCHAR(255)
);

INSERT INTO Customers (CustomerID, FirstName, LastName, Email, Phone, Address) VALUES
(1, 'John', 'Doe', 'john@example.com', '123-456-7890', '123 Main St, Anytown, USA'),
(2, 'Alice', 'Smith', 'alice@example.com', '987-654-3210', '456 Elm St, Anycity, USA'),
(3, 'Bob', 'Johnson', 'bob@example.com', '555-123-4567', '789 Oak St, Anycity, USA'),
(4, 'Eve', 'Brown', 'eve@example.com', '777-888-9999', '321 Pine St, Anycity, USA'),
(5, 'Charlie', 'Davis', 'charlie@example.com', '111-222-3333', '555 Maple St, Anycity, USA');
