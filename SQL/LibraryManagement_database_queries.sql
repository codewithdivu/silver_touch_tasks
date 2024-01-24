
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



-- ---------------------ASSIGNMENT-3---------------------------

-- 8. Create 2 user-defined views.
	
	-- 1. BookDetailsView
		CREATE VIEW BookDetailsView AS
		SELECT
			B.BookID,
			B.Title,
			B.ISBN,
			B.PublishedDate,
			A.AuthorID,
			A.AuthorName,
			A.BirthDate,
			A.Nationality
		FROM
			Book B
		JOIN
			Author A ON B.AuthorID = A.AuthorID;

		select * from BookDetailsView;
	
	-- 1. MemberLoanHistoryView
		CREATE VIEW MemberLoanHistoryView AS
		SELECT
			M.MemberID,
			M.FirstName,
			M.LastName,
			M.Email,
			L.LoanID,
			L.BookID,
			L.LoanDate,
			L.ReturnDate
		FROM
			Member M
		LEFT JOIN
			Loan L ON M.MemberID = L.MemberID;

		select * from MemberLoanHistoryView;



-- 9. Create 2 Scalar-valued functions.	-- 1. GetAuthorAge		CREATE FUNCTION GetAuthorAge(@AuthorID INT)
		RETURNS INT
		AS
		BEGIN
			DECLARE @Age INT;

			SELECT @Age = DATEDIFF(YEAR, BirthDate, GETDATE())
			FROM Author
			WHERE AuthorID = @AuthorID;

			RETURN @Age;
		END;

		SELECT dbo.GetAuthorAge(1) AS AuthorAge;

	-- 2. CalculateLateFee		CREATE FUNCTION CalculateLateFee(@LoanID INT)
		RETURNS DECIMAL(10, 2)
		AS
		BEGIN
			DECLARE @LateFee DECIMAL(10, 2);

			SELECT @LateFee = 
				CASE
					WHEN DATEDIFF(DAY, LoanDate, GETDATE()) > 30 THEN (DATEDIFF(DAY, LoanDate, GETDATE()) - 30) * 0.50
					ELSE 0
				END
			FROM Loan
			WHERE LoanID = @LoanID;

			RETURN @LateFee;
		END;

		SELECT dbo.CalculateLateFee(1) AS LateFee;



-- 10. Create 5 store procedures (select, add, update, delete and full).

	-- 1. Select
		CREATE PROCEDURE SelectBook
			@BookID INT
		AS
		BEGIN
			SELECT *
			FROM Book
			WHERE BookID = @BookID;
		END;

		EXEC SelectBook @BookID = 2;
	
	-- 2. Create
		CREATE PROCEDURE AddBook
			@Title VARCHAR(100),
			@AuthorID INT,
			@ISBN VARCHAR(20),
			@PublishedDate DATE,
			@GenreID INT
		AS
		BEGIN
			INSERT INTO Book (Title, AuthorID, ISBN, PublishedDate, GenreID)
			VALUES (@Title, @AuthorID, @ISBN, @PublishedDate, @GenreID);
		END;

		EXEC AddBook 
		@Title = 'Prison of Azakaban',
		@AuthorID = 1,
		@ISBN = '978-1234567890',
		@PublishedDate = '2023-01-01',
		@GenreID = 1;

		select * from Book;

	-- 3. Update

		CREATE PROCEDURE UpdateBook
			@BookID INT,
			@Title VARCHAR(100),
			@AuthorID INT,
			@ISBN VARCHAR(20),
			@PublishedDate DATE,
			@GenreID INT
		AS
		BEGIN
			UPDATE Book
			SET
				Title = @Title,
				AuthorID = @AuthorID,
				ISBN = @ISBN,
				PublishedDate = @PublishedDate,
				GenreID = @GenreID
			WHERE
				BookID = @BookID;
		END;

		EXEC UpdateBook 
		@BookID = 6,
		@Title = 'goli book',
		@AuthorID = 2,
		@ISBN = '978-9876543210',
		@PublishedDate = '2022-12-01',
		@GenreID = 2;
		
	-- 4. Delete
		CREATE PROCEDURE DeleteBook
			@BookID INT
		AS
		BEGIN
			DELETE FROM Book
			WHERE BookID = @BookID;
		END;

		EXEC DeleteBook @BookID = 6;

	-- 5. Fully
		CREATE PROCEDURE FullBookOperation
			@OperationType NVARCHAR(10),
			@BookID INT = NULL,
			@Title VARCHAR(100) = NULL,
			@AuthorID INT = NULL,
			@ISBN VARCHAR(20) = NULL,
			@PublishedDate DATE = NULL,
			@GenreID INT = NULL
		AS
		BEGIN
			IF @OperationType = 'Select'
			BEGIN
				EXEC SelectBook @BookID;
			END
			ELSE IF @OperationType = 'Add'
			BEGIN
				EXEC AddBook @Title, @AuthorID, @ISBN, @PublishedDate, @GenreID;
			END
			ELSE IF @OperationType = 'Update'
			BEGIN
				EXEC UpdateBook @BookID, @Title, @AuthorID, @ISBN, @PublishedDate, @GenreID;
			END
			ELSE IF @OperationType = 'Delete'
			BEGIN
				EXEC DeleteBook @BookID;
			END
		END;

		EXEC FullBookOperation @OperationType = 'Select', @BookID = 1;

		EXEC FullBookOperation @OperationType = 'Add',
			@Title = 'Harry Potter',
			@AuthorID = 1,
			@ISBN = '978-1234567890',
			@PublishedDate = '2023-01-01',
			@GenreID = 1;

		EXEC FullBookOperation @OperationType = 'Update',
			@BookID = 1,
			@Title = 'Choota bheem',
			@AuthorID = 2,
			@ISBN = '978-9876543210',
			@PublishedDate = '2022-12-01',
			@GenreID = 2;

		EXEC FullBookOperation @OperationType = 'Delete', @BookID = 3;




-- 11.  Create 2 non-clustered indexes.

	-- 1. Non-Clustered Index on Author Table (AuthorID)
		CREATE NONCLUSTERED INDEX IX_Book_AuthorID
		ON Book (AuthorID);


	-- 2. Non-Clustered Index on Genre Table (GenreID)
		CREATE NONCLUSTERED INDEX IX_Book_GenreID
		ON Book (GenreID);




-- 12.  Create Before and After triggers for insert, update and delete operations.

	--1 Before Insert
		CREATE TRIGGER BeforeInsertBook
		ON Book
		FOR INSERT
		AS
		BEGIN
			PRINT 'Before Insert Book Trigger is called';
		END;


	--2 After Insert
		CREATE TRIGGER AfterInsertBook
		ON Book
		AFTER INSERT
		AS
		BEGIN
			PRINT 'After Inser Book Trigger is Called';
		END;


	--3 Before Update
		CREATE TRIGGER BeforeUpdateBook
		ON Book
		FOR UPDATE
		AS
		BEGIN
			PRINT 'Before Update Book Trigger is called';
		END;


	--4 After Update
		CREATE TRIGGER AfterUpdateBook
		ON Book
		AFTER UPDATE
		AS
		BEGIN
			PRINT 'After Update Book Trigger is called';
		END;


	--5 Before Delete
		CREATE TRIGGER BeforeDeleteBook
		ON Book
		FOR DELETE
		AS
		BEGIN
			PRINT 'Before Delete Book Trigger is called';
		END;

	--6 After Delete
		CREATE TRIGGER AfterDeleteBook
		ON Book
		AFTER DELETE
		AS
		BEGIN
			PRINT 'After Delete Book Trigger is called';
		END;
	


-- 13. Write SQL queries for Union and Union All.

	-- 1. UNION
		SELECT Title AS Name FROM Book
		UNION
		SELECT FirstName AS Name FROM Member;

	--2; UNION ALL
		SELECT Title AS Name FROM Book
		UNION ALL
		SELECT FirstName AS Name FROM Member;	


-- JOINS
	
	-- 1. Inner Join
		SELECT Book.Title, Author.AuthorName
		FROM Book
		INNER JOIN Author ON Book.AuthorID = Author.AuthorID;
		

	-- 2. Left Outer Join
		SELECT Book.Title, ISNULL(Author.AuthorName, 'Unknown Author') AS AuthorName
		FROM Book
		LEFT JOIN Author ON Book.AuthorID = Author.AuthorID;
	

	-- 3. Right Outer Join
		SELECT ISNULL(Book.Title, 'No Books') AS Title, Author.AuthorName
		FROM Author
		RIGHT JOIN Book ON Author.AuthorID = Book.AuthorID;
	

	-- 4. Full Outer Join
		SELECT ISNULL(Book.Title, 'No Books') AS Title, ISNULL(Author.AuthorName, 'Unknown Author') AS AuthorName
		FROM Book
		FULL JOIN Author ON Book.AuthorID = Author.AuthorID;
	

	-- 5. Cross Join
		SELECT Book.Title, Author.AuthorName
		FROM Book
		CROSS JOIN Author;	


-- Data Dictionary

	use LibraryManagement;


	SELECT 
		t.name AS TableName,
		c.name AS ColumnName,
		ty.name AS DataType,
		c.max_length AS Size,
		c.is_nullable AS IsNullable
	FROM 
		sys.tables t
	INNER JOIN 
		sys.columns c ON t.object_id = c.object_id
	INNER JOIN 
		sys.types ty ON c.user_type_id = ty.user_type_id
	ORDER BY 
		TableName,
		ColumnName;