USE [master]
GO
/****** Object:  Database [SocialMediaApp]    Script Date: 24-01-2024 15:18:25 ******/
CREATE DATABASE [SocialMediaApp]
 CONTAINMENT = NONE
 ON  PRIMARY 
( NAME = N'SocialMediaApp', FILENAME = N'C:\Program Files\Microsoft SQL Server\MSSQL15.MSSQLSERVER\MSSQL\DATA\SocialMediaApp.mdf' , SIZE = 8192KB , MAXSIZE = UNLIMITED, FILEGROWTH = 65536KB )
 LOG ON 
( NAME = N'SocialMediaApp_log', FILENAME = N'C:\Program Files\Microsoft SQL Server\MSSQL15.MSSQLSERVER\MSSQL\DATA\SocialMediaApp_log.ldf' , SIZE = 8192KB , MAXSIZE = 2048GB , FILEGROWTH = 65536KB )
 WITH CATALOG_COLLATION = DATABASE_DEFAULT
GO
ALTER DATABASE [SocialMediaApp] SET COMPATIBILITY_LEVEL = 150
GO
IF (1 = FULLTEXTSERVICEPROPERTY('IsFullTextInstalled'))
begin
EXEC [SocialMediaApp].[dbo].[sp_fulltext_database] @action = 'enable'
end
GO
ALTER DATABASE [SocialMediaApp] SET ANSI_NULL_DEFAULT OFF 
GO
ALTER DATABASE [SocialMediaApp] SET ANSI_NULLS OFF 
GO
ALTER DATABASE [SocialMediaApp] SET ANSI_PADDING OFF 
GO
ALTER DATABASE [SocialMediaApp] SET ANSI_WARNINGS OFF 
GO
ALTER DATABASE [SocialMediaApp] SET ARITHABORT OFF 
GO
ALTER DATABASE [SocialMediaApp] SET AUTO_CLOSE ON 
GO
ALTER DATABASE [SocialMediaApp] SET AUTO_SHRINK OFF 
GO
ALTER DATABASE [SocialMediaApp] SET AUTO_UPDATE_STATISTICS ON 
GO
ALTER DATABASE [SocialMediaApp] SET CURSOR_CLOSE_ON_COMMIT OFF 
GO
ALTER DATABASE [SocialMediaApp] SET CURSOR_DEFAULT  GLOBAL 
GO
ALTER DATABASE [SocialMediaApp] SET CONCAT_NULL_YIELDS_NULL OFF 
GO
ALTER DATABASE [SocialMediaApp] SET NUMERIC_ROUNDABORT OFF 
GO
ALTER DATABASE [SocialMediaApp] SET QUOTED_IDENTIFIER OFF 
GO
ALTER DATABASE [SocialMediaApp] SET RECURSIVE_TRIGGERS OFF 
GO
ALTER DATABASE [SocialMediaApp] SET  ENABLE_BROKER 
GO
ALTER DATABASE [SocialMediaApp] SET AUTO_UPDATE_STATISTICS_ASYNC OFF 
GO
ALTER DATABASE [SocialMediaApp] SET DATE_CORRELATION_OPTIMIZATION OFF 
GO
ALTER DATABASE [SocialMediaApp] SET TRUSTWORTHY OFF 
GO
ALTER DATABASE [SocialMediaApp] SET ALLOW_SNAPSHOT_ISOLATION OFF 
GO
ALTER DATABASE [SocialMediaApp] SET PARAMETERIZATION SIMPLE 
GO
ALTER DATABASE [SocialMediaApp] SET READ_COMMITTED_SNAPSHOT OFF 
GO
ALTER DATABASE [SocialMediaApp] SET HONOR_BROKER_PRIORITY OFF 
GO
ALTER DATABASE [SocialMediaApp] SET RECOVERY SIMPLE 
GO
ALTER DATABASE [SocialMediaApp] SET  MULTI_USER 
GO
ALTER DATABASE [SocialMediaApp] SET PAGE_VERIFY CHECKSUM  
GO
ALTER DATABASE [SocialMediaApp] SET DB_CHAINING OFF 
GO
ALTER DATABASE [SocialMediaApp] SET FILESTREAM( NON_TRANSACTED_ACCESS = OFF ) 
GO
ALTER DATABASE [SocialMediaApp] SET TARGET_RECOVERY_TIME = 60 SECONDS 
GO
ALTER DATABASE [SocialMediaApp] SET DELAYED_DURABILITY = DISABLED 
GO
ALTER DATABASE [SocialMediaApp] SET ACCELERATED_DATABASE_RECOVERY = OFF  
GO
ALTER DATABASE [SocialMediaApp] SET QUERY_STORE = OFF
GO
USE [SocialMediaApp]
GO
/****** Object:  UserDefinedFunction [dbo].[GetPostLikesCount]    Script Date: 24-01-2024 15:18:25 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
		CREATE FUNCTION [dbo].[GetPostLikesCount] (@PostID INT)
		RETURNS INT
		AS
		BEGIN
			DECLARE @LikesCount INT;

			SELECT @LikesCount = LikesCount
			FROM Post
			WHERE PostID = @PostID;

			RETURN @LikesCount;
		END;
GO
/****** Object:  UserDefinedFunction [dbo].[GetUserFullName]    Script Date: 24-01-2024 15:18:25 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE FUNCTION [dbo].[GetUserFullName] (@UserID INT)
		RETURNS NVARCHAR(100)
		AS
		BEGIN
			DECLARE @FullName NVARCHAR(100);

			SELECT @FullName = CONCAT(FirstName, ' ', LastName)
			FROM [User]
			WHERE UserID = @UserID;
			RETURN @FullName;
		END;
GO
/****** Object:  Table [dbo].[User]    Script Date: 24-01-2024 15:18:25 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[User](
	[UserID] [int] IDENTITY(1,1) NOT NULL,
	[FirstName] [varchar](50) NOT NULL,
	[LastName] [varchar](50) NOT NULL,
	[Email] [varchar](100) NOT NULL,
	[BirthDate] [date] NULL,
PRIMARY KEY CLUSTERED 
(
	[UserID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[Post]    Script Date: 24-01-2024 15:18:25 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Post](
	[PostID] [int] IDENTITY(1,1) NOT NULL,
	[UserID] [int] NOT NULL,
	[Content] [text] NOT NULL,
	[PostDate] [datetime] NOT NULL,
	[LikesCount] [int] NOT NULL,
PRIMARY KEY CLUSTERED 
(
	[PostID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY] TEXTIMAGE_ON [PRIMARY]
GO
/****** Object:  View [dbo].[UserPostView]    Script Date: 24-01-2024 15:18:25 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE VIEW [dbo].[UserPostView] As
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
GO
/****** Object:  Table [dbo].[Comment]    Script Date: 24-01-2024 15:18:25 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Comment](
	[CommentID] [int] IDENTITY(1,1) NOT NULL,
	[PostID] [int] NOT NULL,
	[UserID] [int] NOT NULL,
	[CommentText] [text] NOT NULL,
	[CommentDate] [datetime] NOT NULL,
PRIMARY KEY CLUSTERED 
(
	[CommentID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY] TEXTIMAGE_ON [PRIMARY]
GO
/****** Object:  View [dbo].[UserCommentView]    Script Date: 24-01-2024 15:18:25 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
		CREATE VIEW [dbo].[UserCommentView] AS
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
GO
/****** Object:  Table [dbo].[Friendship]    Script Date: 24-01-2024 15:18:25 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Friendship](
	[FriendshipID] [int] IDENTITY(1,1) NOT NULL,
	[UserID1] [int] NOT NULL,
	[UserID2] [int] NOT NULL,
	[Status] [varchar](20) NOT NULL,
	[RequestDate] [datetime] NOT NULL,
PRIMARY KEY CLUSTERED 
(
	[FriendshipID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[Notification]    Script Date: 24-01-2024 15:18:25 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Notification](
	[NotificationID] [int] IDENTITY(1,1) NOT NULL,
	[UserID] [int] NOT NULL,
	[NotificationText] [text] NOT NULL,
	[IsRead] [bit] NOT NULL,
	[NotificationDate] [datetime] NOT NULL,
PRIMARY KEY CLUSTERED 
(
	[NotificationID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY] TEXTIMAGE_ON [PRIMARY]
GO
SET IDENTITY_INSERT [dbo].[Comment] ON 

INSERT [dbo].[Comment] ([CommentID], [PostID], [UserID], [CommentText], [CommentDate]) VALUES (1, 1, 2, N'Looks amazing! Where is this?', CAST(N'2022-01-15T11:30:00.000' AS DateTime))
INSERT [dbo].[Comment] ([CommentID], [PostID], [UserID], [CommentText], [CommentDate]) VALUES (2, 1, 3, N'I love that place too! Great choice.', CAST(N'2022-01-15T12:00:00.000' AS DateTime))
INSERT [dbo].[Comment] ([CommentID], [PostID], [UserID], [CommentText], [CommentDate]) VALUES (3, 2, 1, N'Cant it to see the final result! ', CAST(N'2022-02-20T15:30:00.000' AS DateTime))
INSERT [dbo].[Comment] ([CommentID], [PostID], [UserID], [CommentText], [CommentDate]) VALUES (4, 3, 4, N'Lazy Sundays are the best! ?', CAST(N'2022-03-05T09:00:00.000' AS DateTime))
INSERT [dbo].[Comment] ([CommentID], [PostID], [UserID], [CommentText], [CommentDate]) VALUES (5, 4, 5, N'Happy Birthday! ????', CAST(N'2022-04-10T12:30:00.000' AS DateTime))
SET IDENTITY_INSERT [dbo].[Comment] OFF
GO
SET IDENTITY_INSERT [dbo].[Friendship] ON 

INSERT [dbo].[Friendship] ([FriendshipID], [UserID1], [UserID2], [Status], [RequestDate]) VALUES (1, 1, 2, N'Accepted', CAST(N'2022-01-15T10:30:00.000' AS DateTime))
INSERT [dbo].[Friendship] ([FriendshipID], [UserID1], [UserID2], [Status], [RequestDate]) VALUES (2, 2, 3, N'Pending', CAST(N'2022-02-20T14:45:00.000' AS DateTime))
INSERT [dbo].[Friendship] ([FriendshipID], [UserID1], [UserID2], [Status], [RequestDate]) VALUES (3, 3, 4, N'Accepted', CAST(N'2022-03-05T08:15:00.000' AS DateTime))
INSERT [dbo].[Friendship] ([FriendshipID], [UserID1], [UserID2], [Status], [RequestDate]) VALUES (4, 4, 5, N'Pending', CAST(N'2022-04-10T12:00:00.000' AS DateTime))
INSERT [dbo].[Friendship] ([FriendshipID], [UserID1], [UserID2], [Status], [RequestDate]) VALUES (5, 5, 1, N'Accepted', CAST(N'2022-05-20T16:30:00.000' AS DateTime))
SET IDENTITY_INSERT [dbo].[Friendship] OFF
GO
SET IDENTITY_INSERT [dbo].[Notification] ON 

INSERT [dbo].[Notification] ([NotificationID], [UserID], [NotificationText], [IsRead], [NotificationDate]) VALUES (1, 1, N'You have a new friend request!', 0, CAST(N'2022-01-15T10:30:00.000' AS DateTime))
INSERT [dbo].[Notification] ([NotificationID], [UserID], [NotificationText], [IsRead], [NotificationDate]) VALUES (2, 2, N'Your post has received 10 likes!', 1, CAST(N'2022-02-20T14:45:00.000' AS DateTime))
INSERT [dbo].[Notification] ([NotificationID], [UserID], [NotificationText], [IsRead], [NotificationDate]) VALUES (3, 3, N'New comment on your post: "Looks amazing!"', 0, CAST(N'2022-03-05T08:15:00.000' AS DateTime))
INSERT [dbo].[Notification] ([NotificationID], [UserID], [NotificationText], [IsRead], [NotificationDate]) VALUES (4, 4, N'Reminde Your friends birthday is tomorrow!', 0, CAST(N'2022-04-10T12:00:00.000' AS DateTime))
INSERT [dbo].[Notification] ([NotificationID], [UserID], [NotificationText], [IsRead], [NotificationDate]) VALUES (5, 5, N'You have been tagged in a photo!', 0, CAST(N'2022-05-20T16:30:00.000' AS DateTime))
SET IDENTITY_INSERT [dbo].[Notification] OFF
GO
SET IDENTITY_INSERT [dbo].[Post] ON 

INSERT [dbo].[Post] ([PostID], [UserID], [Content], [PostDate], [LikesCount]) VALUES (6, 1, N'Just visited a beautiful place!', CAST(N'2022-01-15T10:30:00.000' AS DateTime), 25)
INSERT [dbo].[Post] ([PostID], [UserID], [Content], [PostDate], [LikesCount]) VALUES (7, 2, N'Working on a new project. Excited!', CAST(N'2022-02-20T14:45:00.000' AS DateTime), 10)
INSERT [dbo].[Post] ([PostID], [UserID], [Content], [PostDate], [LikesCount]) VALUES (8, 3, N'Enjoying a cup of coffee on a lazy Sunday.', CAST(N'2022-03-05T08:15:00.000' AS DateTime), 15)
INSERT [dbo].[Post] ([PostID], [UserID], [Content], [PostDate], [LikesCount]) VALUES (9, 4, N'Celebrating my birthday today!', CAST(N'2022-04-10T12:00:00.000' AS DateTime), 11150)
INSERT [dbo].[Post] ([PostID], [UserID], [Content], [PostDate], [LikesCount]) VALUES (10, 5, N'Completed a challenging workout. Feeling accomplished!', CAST(N'2022-05-20T16:30:00.000' AS DateTime), 30)
SET IDENTITY_INSERT [dbo].[Post] OFF
GO
SET IDENTITY_INSERT [dbo].[User] ON 

INSERT [dbo].[User] ([UserID], [FirstName], [LastName], [Email], [BirthDate]) VALUES (1, N'Sara', N'Khan', N'sara.khan@email.com', CAST(N'1990-03-15' AS Date))
INSERT [dbo].[User] ([UserID], [FirstName], [LastName], [Email], [BirthDate]) VALUES (2, N'Rahul', N'Sharma', N'rahul.sharma@email.com', CAST(N'1985-08-20' AS Date))
INSERT [dbo].[User] ([UserID], [FirstName], [LastName], [Email], [BirthDate]) VALUES (3, N'Preeti', N'Patel', N'preeti.patel@email.com', CAST(N'1995-05-10' AS Date))
INSERT [dbo].[User] ([UserID], [FirstName], [LastName], [Email], [BirthDate]) VALUES (4, N'Raj', N'Singh', N'raj.singh@email.com', CAST(N'1980-11-25' AS Date))
INSERT [dbo].[User] ([UserID], [FirstName], [LastName], [Email], [BirthDate]) VALUES (5, N'Anita', N'Verma', N'anita.verma@email.com', CAST(N'1988-06-30' AS Date))
INSERT [dbo].[User] ([UserID], [FirstName], [LastName], [Email], [BirthDate]) VALUES (6, N'Divu', N'Mavadiya', N'Divu0017@gmail.com', CAST(N'2003-08-17' AS Date))
SET IDENTITY_INSERT [dbo].[User] OFF
GO
/****** Object:  Index [IX_Comment_PostID]    Script Date: 24-01-2024 15:18:25 ******/
CREATE NONCLUSTERED INDEX [IX_Comment_PostID] ON [dbo].[Comment]
(
	[PostID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, SORT_IN_TEMPDB = OFF, DROP_EXISTING = OFF, ONLINE = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
GO
/****** Object:  Index [IX_Post_UserID]    Script Date: 24-01-2024 15:18:25 ******/
CREATE NONCLUSTERED INDEX [IX_Post_UserID] ON [dbo].[Post]
(
	[UserID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, SORT_IN_TEMPDB = OFF, DROP_EXISTING = OFF, ONLINE = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
GO
/****** Object:  StoredProcedure [dbo].[CreateUser]    Script Date: 24-01-2024 15:18:25 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE PROCEDURE [dbo].[CreateUser] 
			@FirstName VARCHAR(50),
			@LastName VARCHAR(50),
			@Email VARCHAR(100),
			@BirthDate DATE
		AS
		BEGIN
			INSERT INTO [User] (FirstName, LastName, Email, BirthDate)
			VALUES (@FirstName,@LastName,@Email,@BirthDate);
		END;
GO
/****** Object:  StoredProcedure [dbo].[SelectUser]    Script Date: 24-01-2024 15:18:25 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE PROCEDURE [dbo].[SelectUser]
		@UserID INT
		AS
		BEGIN
			Select * from [User] Where UserID = @userID;
		END;
GO
/****** Object:  StoredProcedure [dbo].[UpdateUser]    Script Date: 24-01-2024 15:18:25 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE PROCEDURE [dbo].[UpdateUser] 
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
GO
/****** Object:  StoredProcedure [dbo].[UserCRUD]    Script Date: 24-01-2024 15:18:25 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE PROCEDURE [dbo].[UserCRUD]
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
GO
/****** Object:  Trigger [dbo].[AfterDeleteUser]    Script Date: 24-01-2024 15:18:25 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TRIGGER [dbo].[AfterDeleteUser]
		ON [dbo].[User]
		AFTER DELETE
		AS
		BEGIN
			PRINT 'After Delte User Trigger is Called';
		END;
GO
ALTER TABLE [dbo].[User] ENABLE TRIGGER [AfterDeleteUser]
GO
/****** Object:  Trigger [dbo].[AfterInsertUser]    Script Date: 24-01-2024 15:18:25 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TRIGGER [dbo].[AfterInsertUser]
		On [dbo].[User]
		AFTER INSERT
		AS
		BEGIN
			PRINT 'After Insert User Trigger is Called';
		END;
GO
ALTER TABLE [dbo].[User] ENABLE TRIGGER [AfterInsertUser]
GO
/****** Object:  Trigger [dbo].[AfterUpdateUser]    Script Date: 24-01-2024 15:18:25 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TRIGGER [dbo].[AfterUpdateUser]
		ON [dbo].[User]
		AFTER UPDATE
		AS
		BEGIN
			PRINT 'After Update User Trigger is Called';
		END;	
GO
ALTER TABLE [dbo].[User] ENABLE TRIGGER [AfterUpdateUser]
GO
/****** Object:  Trigger [dbo].[BeforeDeleteUser]    Script Date: 24-01-2024 15:18:25 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
	CREATE TRIGGER [dbo].[BeforeDeleteUser]
		ON [dbo].[User]
		FOR DELETE
		AS
		BEGIN
			PRINT 'Before Delete User Trigger is Called';
		END;
GO
ALTER TABLE [dbo].[User] ENABLE TRIGGER [BeforeDeleteUser]
GO
/****** Object:  Trigger [dbo].[BeforeInsertUser]    Script Date: 24-01-2024 15:18:25 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TRIGGER [dbo].[BeforeInsertUser]
		ON [dbo].[User]
		FOR INSERT
		AS
		BEGIN
			PRINT 'Before Insert User Trigger is called';
		END;
GO
ALTER TABLE [dbo].[User] ENABLE TRIGGER [BeforeInsertUser]
GO
/****** Object:  Trigger [dbo].[BeforeUpdateUser]    Script Date: 24-01-2024 15:18:26 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TRIGGER [dbo].[BeforeUpdateUser]
		ON [dbo].[User]
		FOR UPDATE
		AS
		BEGIN
			PRINT 'Before Update User Trigger is Called';
		END;
GO
ALTER TABLE [dbo].[User] ENABLE TRIGGER [BeforeUpdateUser]
GO
USE [master]
GO
ALTER DATABASE [SocialMediaApp] SET  READ_WRITE 
GO
