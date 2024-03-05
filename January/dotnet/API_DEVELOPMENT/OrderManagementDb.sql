
CREATE DATABASE OrderManagement;

USE OrderManagement;

CREATE TABLE Products (
    ProductId INT PRIMARY KEY IDENTITY(1,1),
    Name VARCHAR(100),
    Description VARCHAR(255),
    Price DECIMAL(10,2),
    StockQuantity INT
);

CREATE TABLE Customers (
    CustomerId INT PRIMARY KEY IDENTITY(1,1),
    Name VARCHAR(100),
    Email VARCHAR(100),
    Address VARCHAR(255)
);

ALTER TABLE Customers
ADD Role VARCHAR(50),
    Password VARCHAR(255);

INSERT INTO Customers (Name, Email, Address, Role, Password)
VALUES ('Divu', 'divu0017@gmail.com', 'Behind to Lohana mahajan vadi, madhavpur ghed', 'Admin', 'divu');



CREATE TABLE Orders (
    OrderId INT PRIMARY KEY IDENTITY(1,1),
    CustomerId INT FOREIGN KEY REFERENCES Customers(CustomerId),
    OrderDate DATETIME,
    TotalAmount DECIMAL(10,2),
    Status VARCHAR(50)
);

CREATE TABLE OrderItems (
    OrderItemId INT PRIMARY KEY IDENTITY(1,1),
    OrderId INT FOREIGN KEY REFERENCES Orders(OrderId),
    ProductId INT FOREIGN KEY REFERENCES Products(ProductId),
    Quantity INT,
    UnitPrice DECIMAL(10,2)
);



CREATE TABLE Cart (
    CartId INT PRIMARY KEY IDENTITY,
    CustomerId INT FOREIGN KEY REFERENCES Customers(CustomerId), 
    CreatedAt DATETIME DEFAULT GETDATE()
);

drop table cart;
drop table CartItems;

CREATE TABLE CartItems (
    CartItemId INT PRIMARY KEY IDENTITY,
    CartId INT FOREIGN KEY REFERENCES Cart(CartId),
    ProductId INT FOREIGN KEY REFERENCES Products(ProductId),
    Quantity INT,
);

select * from Cart;
