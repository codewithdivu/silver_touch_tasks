
-- ---------------------ASSIGNMENT-1---------------------------


-- creation of DB
create database SocialMediaApp

-- use of DB
use SocialMediaApp;


-- Creation and Insertion queries for table

-- 1.User 

CREATE TABLE [User] (
    UserID INT IDENTITY(1,1) PRIMARY KEY,
    FirstName VARCHAR(50) NOT NULL,
    LastName VARCHAR(50) NOT NULL,
    Email VARCHAR(100) NOT NULL,
    BirthDate DATE NULL
);

INSERT INTO [User] (FirstName, LastName, Email, BirthDate) VALUES 
    ('Sara', 'Khan', 'sara.khan@email.com', '1990-03-15'),
    ('Rahul', 'Sharma', 'rahul.sharma@email.com', '1985-08-20'),
    ('Preeti', 'Patel', 'preeti.patel@email.com', '1995-05-10'),
    ('Raj', 'Singh', 'raj.singh@email.com', '1980-11-25'),
    ('Anita', 'Verma', 'anita.verma@email.com', '1988-06-30');

select * from [user];

-- 2.Post 

CREATE TABLE Post (
    PostID INT IDENTITY(1,1) PRIMARY KEY,
    UserID INT FOREIGN KEY REFERENCES [User](UserID),
    Content TEXT NOT NULL,
    PostDate DATETIME NOT NULL,
    LikesCount INT NOT NULL
);

INSERT INTO Post (UserID, Content, PostDate, LikesCount) VALUES 
    (1, 'Just visited a beautiful place!', '2022-01-15 10:30:00', 25),
    (2, 'Working on a new project. Excited!', '2022-02-20 14:45:00', 10),
    (3, 'Enjoying a cup of coffee on a lazy Sunday.', '2022-03-05 08:15:00', 15),
    (4, 'Celebrating my birthday today!', '2022-04-10 12:00:00', 11150),
    (5, 'Completed a challenging workout. Feeling accomplished!', '2022-05-20 16:30:00', 30);

select * from Post;

-- 3.Comment 

CREATE TABLE Comment (
    CommentID INT IDENTITY(1,1) PRIMARY KEY,
    PostID INT NOT NULL,
    UserID INT NOT NULL,
    CommentText TEXT NOT NULL,
    CommentDate DATETIME NOT NULL
);

INSERT INTO Comment (PostID, UserID, CommentText, CommentDate) VALUES 
    (1, 2, 'Looks amazing! Where is this?', '2022-01-15 11:30:00'),
    (1, 3, 'I love that place too! Great choice.', '2022-01-15 12:00:00'),
    (2, 1, 'Cant it to see the final result! ', '2022-02-20 15:30:00'),
    (3, 4, 'Lazy Sundays are the best! ☕', '2022-03-05 09:00:00'),
    (4, 5, 'Happy Birthday! 🎉🎂', '2022-04-10 12:30:00');


select * from Comment;

-- 4. Friendship 

CREATE TABLE Friendship (
    FriendshipID INT IDENTITY(1,1) PRIMARY KEY,
    UserID1 INT NOT NULL,
    UserID2 INT NOT NULL,
    Status VARCHAR(20) NOT NULL,
    RequestDate DATETIME NOT NULL
);

INSERT INTO Friendship (UserID1, UserID2, Status, RequestDate) VALUES 
    (1, 2, 'Accepted', '2022-01-15 10:30:00'),
    (2, 3, 'Pending', '2022-02-20 14:45:00'),
    (3, 4, 'Accepted', '2022-03-05 08:15:00'),
    (4, 5, 'Pending', '2022-04-10 12:00:00'),
    (5, 1, 'Accepted', '2022-05-20 16:30:00');

select * from Friendship;

-- 5. Notification

CREATE TABLE Notification (
    NotificationID INT IDENTITY(1,1) PRIMARY KEY,
    UserID INT NOT NULL,
    NotificationText TEXT NOT NULL,
    IsRead BIT NOT NULL,
    NotificationDate DATETIME NOT NULL
);

INSERT INTO Notification (UserID, NotificationText, IsRead, NotificationDate) VALUES 
    (1, 'You have a new friend request!', 0, '2022-01-15 10:30:00'),
    (2, 'Your post has received 10 likes!', 1, '2022-02-20 14:45:00'),
    (3, 'New comment on your post: "Looks amazing!"', 0, '2022-03-05 08:15:00'),
    (4, 'Reminde Your friends birthday is tomorrow!', 0, '2022-04-10 12:00:00'),
    (5, 'You have been tagged in a photo!', 0, '2022-05-20 16:30:00');

select * from Notification;


-- ---------------------ASSIGNMENT-2---------------------------


-- Inline Queries:

--	1. Retrieve all posts with the names of the users who created them
	SELECT Post.PostID, Post.Content, [User].FirstName, [User].LastName FROM Post
	INNER JOIN [User] ON Post.UserID = [User].UserID;

--  2. Find the total number of likes for a specific post (e.g., PostID = 1)
	SELECT SUM(LikesCount) AS TotalLikes
	FROM Post WHERE PostID = 1;

--  3. List users with more than 1000 likes 
	SELECT [User].UserID, [User].FirstName, [User].LastName
	FROM [User]
	WHERE UserID IN (SELECT UserID FROM Post WHERE Post.LikesCount > 1000);

--	Sub Queries:
 
--  1. Subquery to extract users with more than 100 likes
	SELECT
		UserID,
		FirstName,
		LastName
	FROM
		[User]
	WHERE
		UserID IN (
			SELECT UserID
			FROM Post
			GROUP BY UserID
			HAVING SUM(LikesCount) > 100
		);

--  2. Retrieve the user who made the first post
	SELECT [User].FirstName, [User].LastName FROM [User]
	WHERE UserID = (SELECT TOP 1 UserID FROM Post 	ORDER BY PostDate ASC);

--  3. Get the average number of comments per post
	SELECT AVG(CommentsPerPost) AS 	AverageCommentsPerPost
	FROM (SELECT COUNT(CommentID) AS 	CommentsPerPost FROM Comment GROUP BY PostID) AS 	SubQuery;





--  SQL Functions:

-- 1. Query using CONCAT() and UPPER():
	SELECT
		CONCAT('Post Content: ', Post.Content) AS PostDescription,
		UPPER([User].FirstName) AS UppercaseFirstName
	FROM
		Post
	INNER JOIN
		[User] ON Post.UserID = [User].UserID;

-- 2. Query using LEFT() and LEN():
	SELECT
		LEFT(CONVERT(VARCHAR(MAX), Post.Content), 50) AS ShortPostContent,
		LEN([User].LastName) AS LastNameLength
	FROM
		Post
	INNER JOIN
    [User] ON Post.UserID = [User].UserID;

-- 3. Query using REPLACE() and TRIM():
	SELECT
		REPLACE(CONVERT(VARCHAR(MAX), Post.Content), ' ', '_') AS ReplacedPostContent,
		TRIM([User].FirstName) AS TrimmedFirstName
	FROM
		Post
	INNER JOIN
    [User] ON Post.UserID = [User].UserID;

-- 4. Query using ROUND() and POWER():
	SELECT
		Post.Content,
		ROUND(Post.LikesCount / 2.0, 2) AS RoundedLikes,
		POWER(Post.LikesCount, 2) AS CommentsCountSquared
	FROM
		Post;

-- 5. Query using ABS() and RAND():
	SELECT
		Post.Content,
		ABS(Post.LikesCount - Post.LikesCount) AS LikesMinusComments,
		RAND() AS RandomValue
	FROM
		Post;

-- 6. Query using CEILING() and FLOOR():
	SELECT
		Post.Content,
		CEILING(Post.LikesCount / 1000.0) AS ThousandLikesCeiled,
		FLOOR(Post.LikesCount / 50.0) AS FiftyCommentsFloored
	FROM
		Post;

-- 7. Query using GETDATE() and DATEADD():
	SELECT
		CommentID,
		GETDATE() AS CurrentDateTime,
		DATEADD(MINUTE, 30, CommentDate) AS CommentDateAfter30Minutes
	FROM
		Comment;

-- 8. Query using MONTH() and FORMAT():
	SELECT
		Post.Content,
		MONTH(Post.PostDate) AS PostMonth,
		FORMAT(Post.PostDate, 'yyyy-MM-dd') AS FormattedPostDate
	FROM
		Post;

-- 9. Query using DATEDIFF() and EOMONTH():
	SELECT
		Comment.CommentText,
		DATEDIFF(DAY, Comment.CommentDate, GETDATE()) AS DaysSinceComment,
		EOMONTH(Comment.CommentDate) AS EndOfMonth
	FROM
		Comment;

-- 10. Query using ROW_NUMBER() and LAG():
	WITH OrderedComments AS (
		SELECT
			CommentID,
			CommentText,
			ROW_NUMBER() OVER (ORDER BY CommentDate DESC) AS RowNum,
			LAG(CommentText) OVER (ORDER BY CommentDate DESC) AS PreviousContent
		FROM
			Comment
	)
	SELECT
		CommentID,
		CommentText,
		RowNum,
		PreviousContent
	FROM
		OrderedComments
	WHERE
		RowNum <= 5;

-- 11. Query using CTE (Common Table Expression) and FORMAT():
	WITH FormattedPosts AS (
		SELECT
			PostID,
			FORMAT(PostDate, 'yyyy-MM-dd HH:mm:ss') AS FormattedPostDate
		FROM
			Post
	)
	SELECT
		PostID,
		FormattedPostDate
	FROM
		FormattedPosts;

-- 12. Query using SUM() and PARTITION BY:
	SELECT
		[User].FirstName,
		Post.Content,
		Post.LikesCount,
		SUM(Post.LikesCount) OVER (PARTITION BY [User].UserID) AS UserTotalLikes
	FROM
		Post
	INNER JOIN
		[User] ON Post.UserID = [User].UserID;



-- ---------------------ASSIGNMENT-3---------------------------
-- 8. Create 2 user-defined views.
	--1. UserPostView
		CREATE VIEW UserPostView As
		SELECT 
			U.FirstName,
			U.Email,
			P.PostDate,
			P.LikesCount,
			P.Content
		FROM 
			[User] U
		JOIN 
			Post P ON P.UserID = U.UserID;

		select * from UserPostView;

	--2.  UserCommentView
		CREATE VIEW UserCommentView AS
		SELECT
			C.CommentID,
			U.UserID,
			U.FirstName,
			U.LastName,
			U.Email,
			U.BirthDate,
			C.PostID,
			C.CommentText,
			C.CommentDate
		FROM [User] U
		INNER JOIN Comment C ON U.UserID = C.UserID;

		select * from UserCommentView;
	
-- 9. Create 2 Scalar-valued functions (e.g. split string).	-- 1. GetUserFullName		CREATE FUNCTION dbo.GetUserFullName (@UserID INT)
		RETURNS NVARCHAR(100)
		AS
		BEGIN
			DECLARE @FullName NVARCHAR(100);

			SELECT @FullName = CONCAT(FirstName, ' ', LastName)
			FROM [User]
			WHERE UserID = @UserID;
			RETURN @FullName;
		END;

		DECLARE @FullName NVARCHAR(100);
		SET @FullName = dbo.GetUserFullName(5);
		SELECT @FullName AS UserFullName;



	-- 2. GetPostLikesCount		CREATE FUNCTION dbo.GetPostLikesCount (@PostID INT)
		RETURNS INT
		AS
		BEGIN
			DECLARE @LikesCount INT;

			SELECT @LikesCount = LikesCount
			FROM Post
			WHERE PostID = @PostID;

			RETURN @LikesCount;
		END;

		DECLARE @LikesCount INT;
		SET @LikesCount = dbo.GetPostLikesCount(8);
		SELECT @LikesCount AS PostLikesCount;


-- 10. Create 5 store procedures (select, add, update, delete and full).

	-- 1. Select
		CREATE PROCEDURE SelectUser
		@UserID INT
		AS
		BEGIN
			Select * from [User] Where UserID = @userID;
		END;
		
		Exec SelectUser @UserID = 5;

	-- 2. Create
		CREATE PROCEDURE CreateUser 
			@FirstName VARCHAR(50),
			@LastName VARCHAR(50),
			@Email VARCHAR(100),
			@BirthDate DATE
		AS
		BEGIN
			INSERT INTO [User] (FirstName, LastName, Email, BirthDate)
			VALUES (@FirstName,@LastName,@Email,@BirthDate);
		END;

		select * from [User];

		Exec CreateUser @FirstName = 'Divyesh', @LastName = 'Mavadiya', @Email = 'mavadiyadivyesh56@gmail.com', @BirthDate = '2003-08-17';

	-- 3. Update
		
		CREATE PROCEDURE UpdateUser 
			@UserID INT,
			@UpdatedFirstName VARCHAR(50),
			@UpdatedLastName VARCHAR(50),
			@UpdatedEmail VARCHAR(100),
			@UpdatedBirthDate DATE
		AS
		BEGIN
			Update [User] SET
				FirstName = @UpdatedFirstName,
				LastName = @UpdatedLastName,
				Email = @UpdatedEmail,
				BirthDate = @UpdatedBirthDate WHERE UserID = @UserID;
		END;

		Exec UpdateUser @UserID = 6, @UpdatedFirstName = 'Divu', @UpdatedLastName = 'Mavadiya', @UpdatedEmail = 'Divu0017@gmail.com', @UpdatedBirthDate = '2003-08-17';

	-- 5. Fully
		CREATE PROCEDURE UserCRUD
			@Action VARCHAR(10), 
			@UserID INT = NULL,
			@FirstName VARCHAR(50) = NULL,
			@LastName VARCHAR(50) = NULL,
			@Email VARCHAR(100) = NULL,
			@BirthDate DATE = NULL
		AS
		BEGIN
			IF @Action = 'SELECT'
			BEGIN
				SELECT *
				FROM [User]
				WHERE UserID = @UserID;
			END
			ELSE IF @Action = 'INSERT'
			BEGIN
				INSERT INTO [User] (FirstName, LastName, Email, BirthDate)
				VALUES (@FirstName, @LastName, @Email, @BirthDate);
			END
			ELSE IF @Action = 'UPDATE'
			BEGIN
				UPDATE [User]
				SET FirstName = ISNULL(@FirstName, FirstName),
					LastName = ISNULL(@LastName, LastName),
					Email = ISNULL(@Email, Email),
					BirthDate = ISNULL(@BirthDate, BirthDate)
				WHERE UserID = @UserID;
			END
			ELSE IF @Action = 'DELETE'
			BEGIN
				DELETE FROM [User]
				WHERE UserID = @UserID;
			END
		END;

		EXEC UserCRUD 'INSERT', NULL, 'John', 'Doe', 'john.doe@email.com', '1990-01-01';
		EXEC UserCRUD 'UPDATE', 1, 'Updated', 'User', 'updated.user@email.com', '1995-05-05';
		EXEC UserCRUD 'DELETE', 2;
		EXEC UserCRUD 'SELECT', 3;



-- 11.  Create 2 non-clustered indexes.

	--1. Non-Clustered Index on Post Table (UserID)
		CREATE NONCLUSTERED INDEX IX_Post_UserID
		ON Post (UserID);

	--2. Non-Clustered Index on Comment Table (PostID)
		CREATE NONCLUSTERED INDEX IX_Comment_PostID
		ON Comment (PostID);



-- 12.  Create Before and After triggers for insert, update and delete operations.

	--1 Before Insert
		CREATE TRIGGER BeforeInsertUser
		ON [User]
		INSTEAD OF INSERT
		AS
		BEGIN
			PRINT 'Before Insert User Trigger is called';
		END;

	--2 After Insert
		CREATE TRIGGER AfterInsertUser
		ON [User]
		AFTER INSERT
		AS
		BEGIN
			PRINT 'After Insert User Trigger is Called';
		END;

	--3 Before Update
		CREATE TRIGGER BeforeUpdateUser
		ON [User]
		INSTEAD OF UPDATE
		AS
		BEGIN
			PRINT 'Before Update User Trigger is Called';
		END;

	--4 After Update
		CREATE TRIGGER AfterUpdateUser
		ON [User]
		AFTER UPDATE
		AS
		BEGIN
			PRINT 'After Update User Trigger is Called';
		END;		

	--5 Before Delete
		CREATE TRIGGER BeforeDeleteUser
		ON [User]
		INSTEAD OF DELETE
		AS
		BEGIN
			PRINT 'Before Delete User Trigger is Called';
		END;

	--6 After Delete
		CREATE TRIGGER AfterDeleteUser
		ON [User]
		AFTER DELETE
		AS
		BEGIN
			PRINT 'After Delte User Trigger is Called';
		END;

-- 13. Write SQL queries for Union and Union All.

	-- 1. UNION
		
	

	--2; UNION ALL
		SELECT PostID, Content, 'Post' AS ItemType
		FROM Post
		WHERE LikesCount > 10

		UNION ALL

		SELECT CommentID, CommentText, 'Comment' AS ItemType
		FROM Comment
		WHERE DATALENGTH(CommentText) > 20;


-- JOINS
	
	-- 1. Inner Join
		SELECT Post.PostID, Post.Content, [User].FirstName, [User].LastName
		FROM Post
		INNER JOIN [User] ON Post.UserID = [User].UserID;

	-- 2. Left Join
		SELECT [User].UserID, [User].FirstName, [User].LastName, Post.Content
		FROM [User]
		LEFT JOIN Post ON [User].UserID = Post.UserID;		

	-- 3. Right Join
		SELECT [User].UserID, [User].FirstName, [User].LastName, Post.Content
		FROM Post
		RIGHT JOIN [User] ON Post.UserID = [User].UserID;

	-- 4. Full Outer Join
		SELECT [User].UserID, [User].FirstName, [User].LastName, Post.Content
		FROM [User]
		FULL OUTER JOIN Post ON [User].UserID = Post.UserID;	

	-- 5. Cross Join
		SELECT [User].UserID, [User].FirstName, [User].LastName, Post.PostID, Post.Content
		FROM [User]
		CROSS JOIN Post;
