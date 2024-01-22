
-- ---------------------ASSIGNMENT-1---------------------------


-- creation of DB
create database LibraryManagement

-- use of DB
use LibraryManagement;

-- Creation and Insertion queries for table

-- 1.Book 

CREATE TABLE Book (
    BookID INT IDENTITY(1,1) PRIMARY KEY,
    Title VARCHAR(100) NOT NULL,
    AuthorID INT NULL,
    ISBN VARCHAR(20) NOT NULL,
    PublishedDate DATE NOT NULL,
    GenreID INT FOREIGN KEY REFERENCES Genre(GenreID),
);


INSERT INTO Book (Title, AuthorID, ISBN, PublishedDate,GenreId) VALUES 
    ('The Art of Programming', 1, '978-0123456789', '2022-03-15',1),
    ('Data Science Fundamentals', 2, '978-9876543210', '2021-08-20',2),
    ('Mystery of the Lost City', 3, '978-1111222233', '2020-05-10',3),
    ('Design Patterns in Practice', 4, '978-4444555566', '2019-11-25',4),
    ('History of the Universe', NULL, '978-7777888899', '2018-06-30',5);

select * from Book;



-- 2.Author

CREATE TABLE Author (
    AuthorID INT IDENTITY(1,1) PRIMARY KEY,
    AuthorName VARCHAR(50) NOT NULL,
    BirthDate DATE NULL,
    Nationality VARCHAR(50) NULL,
    Biography TEXT NULL
);


INSERT INTO Author (AuthorName, BirthDate, Nationality, Biography) VALUES 
    ('Amit Sharma', '1985-09-20', 'Indian', 'Amit Sharma is a bestselling Indian author known for his novels reflecting Indian culture.'),
    ('Priya Verma', '1970-12-15', 'Indian', 'Priya Verma is a prolific Hindi author, capturing the essence of Indian traditions in her works.'),
    ('Rajeev Kapoor', '1980-05-28', 'Indian', 'Rajeev Kapoor is a renowned Indian mystery writer, weaving suspense into his captivating stories.'),
    ('Anjali Khanna', '1992-03-10', 'Indian', 'Anjali Khanna, a young Indian author, brings a fresh perspective to contemporary Indian literature.'),
    ('Vikram Singh', '1965-11-25', 'Indian', 'Vikram Singh is a celebrated Indian science fiction writer, exploring futuristic themes.');

select * from Author;

-- 3.Member 

CREATE TABLE Member (
    MemberID INT IDENTITY(1,1) PRIMARY KEY,
    FirstName VARCHAR(50) NOT NULL,
    LastName VARCHAR(50) NOT NULL,
    Email VARCHAR(100) NULL,
    JoinDate DATETIME NOT NULL
);

INSERT INTO Member (FirstName, LastName, Email, JoinDate) VALUES 
    ('Amit', 'Verma', 'amit.verma@email.com', '2022-01-10 08:45:00'),
    ('Priya', 'Singh', 'priya.singh@email.com', '2022-02-15 12:30:00'),
    ('Rajesh', 'Kumar', 'rajesh.kumar@email.com', '2022-03-20 10:15:00'),
    ('Anjali', 'Gupta', 'anjali.gupta@email.com', '2022-04-25 14:00:00'),
    ('Vikas', 'Sharma', 'vikas.sharma@email.com', '2022-05-30 16:45:00');

select * from Member;

-- 4.Loan

CREATE TABLE Loan (
    LoanID INT IDENTITY(1,1) PRIMARY KEY,
    MemberID INT NOT NULL,
    BookID INT NOT NULL,
    LoanDate DATETIME NOT NULL,
    ReturnDate DATETIME NULL
);

INSERT INTO Loan (MemberID, BookID, LoanDate, ReturnDate) VALUES 
    (1, 1, '2022-01-15 10:30:00', '2022-02-10 12:00:00'),
    (2, 2, '2022-02-20 14:45:00', '2022-03-15 10:30:00'),
    (3, 3, '2022-03-05 08:15:00', NULL),
    (4, 4, '2022-04-10 12:00:00', NULL),
    (5, 5, '2022-05-20 16:30:00', '2022-06-10 14:00:00');


select * from Loan;

-- 5.Genre

CREATE TABLE Genre (
    GenreID INT IDENTITY(1,1) PRIMARY KEY,
    GenreName VARCHAR(50) NOT NULL,
    Description TEXT NULL,
    CreatedDate DATE NOT NULL,
    UpdatedDate DATETIME NULL
);


INSERT INTO Genre (GenreName, Description, CreatedDate, UpdatedDate) VALUES 
    ('Mystery', 'Books that involve solving a mystery or crime.', '2022-01-15', '2022-02-10 08:30:00'),
    ('Science Fiction', 'Books with speculative and futuristic themes.', '2022-02-20', '2022-03-15 12:45:00'),
    ('Romance', 'Books focused on romantic relationships and love stories.', '2022-03-05', NULL),
    ('Fantasy', 'Books set in fantastical worlds with magic and mythical creatures.', '2022-04-10', NULL),
    ('History', 'Books that explore historical events and periods.', '2022-05-20', '2022-06-10 14:00:00');

select * from Genre;


-- ---------------------ASSIGNMENT-2---------------------------


-- Inline Queries:
select * from Book

-- 1. Retrieve all books with their genres
	SELECT Book.BookID, Book.Title, Genre.GenreName
	FROM Book
	INNER JOIN Genre ON Book.GenreID = Genre.GenreID;

-- 2. Find the total number of books published before a specific date
	SELECT COUNT(BookID) AS TotalBooks
	FROM Book WHERE PublishedDate < '2022-01-01';

-- 3. List books with titles containing the word 'programming
	SELECT BookID, Title, PublishedDate
	FROM Book WHERE Title LIKE '%programming%';

--	Sub Queries:

-- 1. Find books by a specific author (e.g., AuthorID = 1):
	SELECT BookID, Title, PublishedDate
	FROM Book WHERE AuthorID = 1;

-- 2. Retrieve the genre with the highest number of books
	SELECT GenreName FROM Genre
	WHERE GenreID = (SELECT TOP 1 GenreID FROM Book GROUP BY GenreID ORDER BY COUNT(BookID) DESC);

-- 3. Get the average published year of books
	SELECT AVG(YEAR(PublishedDate)) AS 	AveragePublishedYear FROM Book;




--  SQL Functions:


-- 1. Query using CONCAT() and UPPER():
	SELECT
		CONCAT('Book Title: ', Book.Title) AS BookDescription,
		UPPER(Genre.GenreName) AS UppercaseGenre
	FROM
		Book
	INNER JOIN
		Genre ON Book.GenreID = Genre.GenreID;

-- 2. Query using LEFT() and LEN():
	SELECT
		LEFT(Book.Title, 3) AS ShortBookTitle,
		LEN(CONVERT(VARCHAR(MAX), Genre.Description)) AS GenreDescriptionLength
	FROM
		Book
	INNER JOIN
    Genre ON Book.GenreID = Genre.GenreID;

-- 3. Query using REPLACE() and TRIM():
	SELECT
		REPLACE(Book.Title, ' ', '_') AS ReplacedBookTitle,
		TRIM(Genre.GenreName) AS TrimmedGenre
	FROM
		Book
	INNER JOIN
		Genre ON Book.GenreID = Genre.GenreID;

-- 4. Query using ROUND() and POWER():
	SELECT
    Title,
    PublishedDate,
		ROUND(DATEDIFF(DAY, PublishedDate, GETDATE()) / 365.25, 2) AS YearsAgo,
		POWER(LEN(ISBN), 2) AS ISBNLengthSquared
	FROM
		Book;

-- 5. Query using ABS() and RAND():
	SELECT
    Title,
    AuthorID,
		ABS(AuthorID) AS AbsoluteAuthorID,
		RAND() AS RandomValue
	FROM
		Book;

-- 6. Query using CEILING() and FLOOR():
	SELECT
    Title,
    PublishedDate,
		CEILING(DATEDIFF(DAY, PublishedDate, GETDATE()) / 365.25) AS YearsAgoCeiled,
		FLOOR(DATEDIFF(DAY, PublishedDate, GETDATE()) / 365.25) AS YearsAgoFloored
	FROM
		Book;

-- 7. Query using GETDATE() and DATEADD():
	SELECT
		LoanID,
		GETDATE() AS CurrentDateTime,
		DATEADD(DAY, 14, LoanDate) AS DueDate
	FROM
		Loan;

-- 8. Query using MONTH() and FORMAT():
	SELECT
		Book.Title,
		MONTH(Book.PublishedDate) AS PublishedMonth,
		FORMAT(Book.PublishedDate, 'yyyy-MM-dd') AS FormattedPublishedDate
	FROM
		Book;

-- 9. Query using DATEDIFF() and EOMONTH():
	SELECT
		Book.Title,
		DATEDIFF(YEAR, Book.PublishedDate, GETDATE()) AS YearsSincePublication,
		EOMONTH(Book.PublishedDate) AS EndOfMonth
	FROM
		Book;

-- 10. Query using ROW_NUMBER() and LAG():
	WITH OrderedBooks AS (
		SELECT
			BookID,
			Title,
			ROW_NUMBER() OVER (ORDER BY PublishedDate DESC) AS RowNum,
			LAG(Title) OVER (ORDER BY PublishedDate DESC) AS PreviousTitle
		FROM
			Book
	)
	SELECT
		BookID,
		Title,
		RowNum,
		PreviousTitle
	FROM
		OrderedBooks
	WHERE
		RowNum <= 5;

-- 11. Query using CTE (Common Table Expression) and FORMAT():
	WITH FormattedLoans AS (
		SELECT
			LoanID,
			FORMAT(LoanDate, 'yyyy-MM-dd') AS FormattedLoanDate
		FROM
			Loan
	)
	SELECT
		LoanID,
		FormattedLoanDate
	FROM
		FormattedLoans;

-- 12. Query using SUM() and PARTITION BY:
	SELECT
    Title,
    GenreID,
		SUM(BookID) OVER (PARTITION BY GenreID) AS TotalBookIDInGenre
	FROM
		Book;