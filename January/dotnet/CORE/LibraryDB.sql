
create database LibraryDB;
use LibraryDB;

-- Create Authors table
CREATE TABLE Authors (
    AuthorID INT PRIMARY KEY IDENTITY(1,1),
    FirstName NVARCHAR(50) NOT NULL,
    LastName NVARCHAR(50) NOT NULL,
    Email NVARCHAR(100)
);

INSERT INTO Authors (FirstName, LastName, Email) VALUES
('Ravi', 'Kumar', 'ravi.kumar@example.com'),
('Priya', 'Patel', 'priya.patel@example.com'),
('Amit', 'Sharma', 'amit.sharma@example.com'),
('Neha', 'Das', 'neha.das@example.com'),
('Siddharth', 'Gupta', 'siddharth.gupta@example.com');


-- Create Categories table
CREATE TABLE Categories (
    CategoryID INT PRIMARY KEY IDENTITY(1,1),
    CategoryName NVARCHAR(100) NOT NULL
);

INSERT INTO Categories (CategoryName) VALUES
('Fiction'),
('Non-Fiction'),
('Science Fiction'),
('Fantasy'),
('Mystery');

-- Create Books table
CREATE TABLE Books (
    BookID INT PRIMARY KEY IDENTITY(1,1),
    Title NVARCHAR(200) NOT NULL,
    AuthorID INT FOREIGN KEY REFERENCES Authors(AuthorID),
    CategoryID INT FOREIGN KEY REFERENCES Categories(CategoryID),
    PublicationYear INT,
    ISBN NVARCHAR(20) UNIQUE,
    Quantity INT NOT NULL,
    AvailableQuantity INT NOT NULL
);

INSERT INTO Books (Title, AuthorID, CategoryID, PublicationYear, ISBN, Quantity, AvailableQuantity) VALUES
('The Secret Garden', 1, 1, 1911, '978-1-1234-5678-1', 10, 5),
('The Discovery of India', 3, 2, 1946, '978-1-2345-6789-0', 15, 10),
('The Immortals of Meluha', 4, 3, 2010, '978-1-3456-7890-1', 5, 2),
('The God of Small Things', 5, 4, 1997, '978-1-4567-8901-2', 20, 15),
('The Palace of Illusions', 2, 5, 2008, '978-1-5678-9012-3', 8, 3);




-- Create Users table
CREATE TABLE Users (
    UserID INT PRIMARY KEY IDENTITY(1,1),
    FirstName NVARCHAR(50) NOT NULL,
    LastName NVARCHAR(50) NOT NULL,
    Email NVARCHAR(100)
);

INSERT INTO Users (FirstName, LastName, Email) VALUES
('Arun', 'Sinha', 'arun.sinha@example.com'),
('Meera', 'Reddy', 'meera.reddy@example.com'),
('Vivek', 'Nair', 'vivek.nair@example.com'),
('Pooja', 'Mukherjee', 'pooja.mukherjee@example.com'),
('Ananya', 'Gowda', 'ananya.gowda@example.com');

-- Create Borrowings table
CREATE TABLE Borrowings (
    BorrowingID INT PRIMARY KEY IDENTITY(1,1),
    UserID INT FOREIGN KEY REFERENCES Users(UserID),
    BookID INT FOREIGN KEY REFERENCES Books(BookID),
    BorrowDate DATE NOT NULL,
    ReturnDate DATE,
    CONSTRAINT CK_ReturnDate CHECK (ReturnDate IS NULL OR ReturnDate >= BorrowDate)
);

INSERT INTO Borrowings (UserID, BookID, BorrowDate, ReturnDate) VALUES
(1, 1, '2024-02-10', '2024-02-28'),
(2, 3, '2024-02-15', NULL),
(3, 2, '2024-02-18', NULL),
(4, 5, '2024-02-20', NULL),
(5, 4, '2024-02-05', '2024-02-25');
