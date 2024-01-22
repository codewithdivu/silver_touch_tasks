USE [master]
GO
/****** Object:  Database [LibraryManagement]    Script Date: 22-01-2024 13:49:25 ******/
CREATE DATABASE [LibraryManagement]
 CONTAINMENT = NONE
 ON  PRIMARY 
( NAME = N'LibraryManagement', FILENAME = N'C:\Program Files\Microsoft SQL Server\MSSQL15.MSSQLSERVER\MSSQL\DATA\LibraryManagement.mdf' , SIZE = 8192KB , MAXSIZE = UNLIMITED, FILEGROWTH = 65536KB )
 LOG ON 
( NAME = N'LibraryManagement_log', FILENAME = N'C:\Program Files\Microsoft SQL Server\MSSQL15.MSSQLSERVER\MSSQL\DATA\LibraryManagement_log.ldf' , SIZE = 8192KB , MAXSIZE = 2048GB , FILEGROWTH = 65536KB )
 WITH CATALOG_COLLATION = DATABASE_DEFAULT
GO
ALTER DATABASE [LibraryManagement] SET COMPATIBILITY_LEVEL = 150
GO
IF (1 = FULLTEXTSERVICEPROPERTY('IsFullTextInstalled'))
begin
EXEC [LibraryManagement].[dbo].[sp_fulltext_database] @action = 'enable'
end
GO
ALTER DATABASE [LibraryManagement] SET ANSI_NULL_DEFAULT OFF 
GO
ALTER DATABASE [LibraryManagement] SET ANSI_NULLS OFF 
GO
ALTER DATABASE [LibraryManagement] SET ANSI_PADDING OFF 
GO
ALTER DATABASE [LibraryManagement] SET ANSI_WARNINGS OFF 
GO
ALTER DATABASE [LibraryManagement] SET ARITHABORT OFF 
GO
ALTER DATABASE [LibraryManagement] SET AUTO_CLOSE ON 
GO
ALTER DATABASE [LibraryManagement] SET AUTO_SHRINK OFF 
GO
ALTER DATABASE [LibraryManagement] SET AUTO_UPDATE_STATISTICS ON 
GO
ALTER DATABASE [LibraryManagement] SET CURSOR_CLOSE_ON_COMMIT OFF 
GO
ALTER DATABASE [LibraryManagement] SET CURSOR_DEFAULT  GLOBAL 
GO
ALTER DATABASE [LibraryManagement] SET CONCAT_NULL_YIELDS_NULL OFF 
GO
ALTER DATABASE [LibraryManagement] SET NUMERIC_ROUNDABORT OFF 
GO
ALTER DATABASE [LibraryManagement] SET QUOTED_IDENTIFIER OFF 
GO
ALTER DATABASE [LibraryManagement] SET RECURSIVE_TRIGGERS OFF 
GO
ALTER DATABASE [LibraryManagement] SET  ENABLE_BROKER 
GO
ALTER DATABASE [LibraryManagement] SET AUTO_UPDATE_STATISTICS_ASYNC OFF 
GO
ALTER DATABASE [LibraryManagement] SET DATE_CORRELATION_OPTIMIZATION OFF 
GO
ALTER DATABASE [LibraryManagement] SET TRUSTWORTHY OFF 
GO
ALTER DATABASE [LibraryManagement] SET ALLOW_SNAPSHOT_ISOLATION OFF 
GO
ALTER DATABASE [LibraryManagement] SET PARAMETERIZATION SIMPLE 
GO
ALTER DATABASE [LibraryManagement] SET READ_COMMITTED_SNAPSHOT OFF 
GO
ALTER DATABASE [LibraryManagement] SET HONOR_BROKER_PRIORITY OFF 
GO
ALTER DATABASE [LibraryManagement] SET RECOVERY SIMPLE 
GO
ALTER DATABASE [LibraryManagement] SET  MULTI_USER 
GO
ALTER DATABASE [LibraryManagement] SET PAGE_VERIFY CHECKSUM  
GO
ALTER DATABASE [LibraryManagement] SET DB_CHAINING OFF 
GO
ALTER DATABASE [LibraryManagement] SET FILESTREAM( NON_TRANSACTED_ACCESS = OFF ) 
GO
ALTER DATABASE [LibraryManagement] SET TARGET_RECOVERY_TIME = 60 SECONDS 
GO
ALTER DATABASE [LibraryManagement] SET DELAYED_DURABILITY = DISABLED 
GO
ALTER DATABASE [LibraryManagement] SET ACCELERATED_DATABASE_RECOVERY = OFF  
GO
ALTER DATABASE [LibraryManagement] SET QUERY_STORE = OFF
GO
USE [LibraryManagement]
GO
/****** Object:  Table [dbo].[Author]    Script Date: 22-01-2024 13:49:25 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Author](
	[AuthorID] [int] IDENTITY(1,1) NOT NULL,
	[AuthorName] [varchar](50) NOT NULL,
	[BirthDate] [date] NULL,
	[Nationality] [varchar](50) NULL,
	[Biography] [text] NULL,
PRIMARY KEY CLUSTERED 
(
	[AuthorID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY] TEXTIMAGE_ON [PRIMARY]
GO
/****** Object:  Table [dbo].[Book]    Script Date: 22-01-2024 13:49:25 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Book](
	[BookID] [int] IDENTITY(1,1) NOT NULL,
	[Title] [varchar](100) NOT NULL,
	[AuthorID] [int] NULL,
	[ISBN] [varchar](20) NOT NULL,
	[PublishedDate] [date] NOT NULL,
	[GenreID] [int] NULL,
PRIMARY KEY CLUSTERED 
(
	[BookID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[Genre]    Script Date: 22-01-2024 13:49:25 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Genre](
	[GenreID] [int] IDENTITY(1,1) NOT NULL,
	[GenreName] [varchar](50) NOT NULL,
	[Description] [text] NULL,
	[CreatedDate] [date] NOT NULL,
	[UpdatedDate] [datetime] NULL,
PRIMARY KEY CLUSTERED 
(
	[GenreID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY] TEXTIMAGE_ON [PRIMARY]
GO
/****** Object:  Table [dbo].[Loan]    Script Date: 22-01-2024 13:49:25 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Loan](
	[LoanID] [int] IDENTITY(1,1) NOT NULL,
	[MemberID] [int] NOT NULL,
	[BookID] [int] NOT NULL,
	[LoanDate] [datetime] NOT NULL,
	[ReturnDate] [datetime] NULL,
PRIMARY KEY CLUSTERED 
(
	[LoanID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[Member]    Script Date: 22-01-2024 13:49:25 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Member](
	[MemberID] [int] IDENTITY(1,1) NOT NULL,
	[FirstName] [varchar](50) NOT NULL,
	[LastName] [varchar](50) NOT NULL,
	[Email] [varchar](100) NULL,
	[JoinDate] [datetime] NOT NULL,
PRIMARY KEY CLUSTERED 
(
	[MemberID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
SET IDENTITY_INSERT [dbo].[Author] ON 

INSERT [dbo].[Author] ([AuthorID], [AuthorName], [BirthDate], [Nationality], [Biography]) VALUES (1, N'Amit Sharma', CAST(N'1985-09-20' AS Date), N'Indian', N'Amit Sharma is a bestselling Indian author known for his novels reflecting Indian culture.')
INSERT [dbo].[Author] ([AuthorID], [AuthorName], [BirthDate], [Nationality], [Biography]) VALUES (2, N'Priya Verma', CAST(N'1970-12-15' AS Date), N'Indian', N'Priya Verma is a prolific Hindi author, capturing the essence of Indian traditions in her works.')
INSERT [dbo].[Author] ([AuthorID], [AuthorName], [BirthDate], [Nationality], [Biography]) VALUES (3, N'Rajeev Kapoor', CAST(N'1980-05-28' AS Date), N'Indian', N'Rajeev Kapoor is a renowned Indian mystery writer, weaving suspense into his captivating stories.')
INSERT [dbo].[Author] ([AuthorID], [AuthorName], [BirthDate], [Nationality], [Biography]) VALUES (4, N'Anjali Khanna', CAST(N'1992-03-10' AS Date), N'Indian', N'Anjali Khanna, a young Indian author, brings a fresh perspective to contemporary Indian literature.')
INSERT [dbo].[Author] ([AuthorID], [AuthorName], [BirthDate], [Nationality], [Biography]) VALUES (5, N'Vikram Singh', CAST(N'1965-11-25' AS Date), N'Indian', N'Vikram Singh is a celebrated Indian science fiction writer, exploring futuristic themes.')
SET IDENTITY_INSERT [dbo].[Author] OFF
GO
SET IDENTITY_INSERT [dbo].[Book] ON 

INSERT [dbo].[Book] ([BookID], [Title], [AuthorID], [ISBN], [PublishedDate], [GenreID]) VALUES (1, N'The Art of Programming', 1, N'978-0123456789', CAST(N'2022-03-15' AS Date), 1)
INSERT [dbo].[Book] ([BookID], [Title], [AuthorID], [ISBN], [PublishedDate], [GenreID]) VALUES (2, N'Data Science Fundamentals', 2, N'978-9876543210', CAST(N'2021-08-20' AS Date), 2)
INSERT [dbo].[Book] ([BookID], [Title], [AuthorID], [ISBN], [PublishedDate], [GenreID]) VALUES (3, N'Mystery of the Lost City', 3, N'978-1111222233', CAST(N'2020-05-10' AS Date), 3)
INSERT [dbo].[Book] ([BookID], [Title], [AuthorID], [ISBN], [PublishedDate], [GenreID]) VALUES (4, N'Design Patterns in Practice', 4, N'978-4444555566', CAST(N'2019-11-25' AS Date), 4)
INSERT [dbo].[Book] ([BookID], [Title], [AuthorID], [ISBN], [PublishedDate], [GenreID]) VALUES (5, N'History of the Universe', NULL, N'978-7777888899', CAST(N'2018-06-30' AS Date), 5)
SET IDENTITY_INSERT [dbo].[Book] OFF
GO
SET IDENTITY_INSERT [dbo].[Genre] ON 

INSERT [dbo].[Genre] ([GenreID], [GenreName], [Description], [CreatedDate], [UpdatedDate]) VALUES (1, N'Mystery', N'Books that involve solving a mystery or crime.', CAST(N'2022-01-15' AS Date), CAST(N'2022-02-10T08:30:00.000' AS DateTime))
INSERT [dbo].[Genre] ([GenreID], [GenreName], [Description], [CreatedDate], [UpdatedDate]) VALUES (2, N'Science Fiction', N'Books with speculative and futuristic themes.', CAST(N'2022-02-20' AS Date), CAST(N'2022-03-15T12:45:00.000' AS DateTime))
INSERT [dbo].[Genre] ([GenreID], [GenreName], [Description], [CreatedDate], [UpdatedDate]) VALUES (3, N'Romance', N'Books focused on romantic relationships and love stories.', CAST(N'2022-03-05' AS Date), NULL)
INSERT [dbo].[Genre] ([GenreID], [GenreName], [Description], [CreatedDate], [UpdatedDate]) VALUES (4, N'Fantasy', N'Books set in fantastical worlds with magic and mythical creatures.', CAST(N'2022-04-10' AS Date), NULL)
INSERT [dbo].[Genre] ([GenreID], [GenreName], [Description], [CreatedDate], [UpdatedDate]) VALUES (5, N'History', N'Books that explore historical events and periods.', CAST(N'2022-05-20' AS Date), CAST(N'2022-06-10T14:00:00.000' AS DateTime))
SET IDENTITY_INSERT [dbo].[Genre] OFF
GO
SET IDENTITY_INSERT [dbo].[Loan] ON 

INSERT [dbo].[Loan] ([LoanID], [MemberID], [BookID], [LoanDate], [ReturnDate]) VALUES (1, 1, 1, CAST(N'2022-01-15T10:30:00.000' AS DateTime), CAST(N'2022-02-10T12:00:00.000' AS DateTime))
INSERT [dbo].[Loan] ([LoanID], [MemberID], [BookID], [LoanDate], [ReturnDate]) VALUES (2, 2, 2, CAST(N'2022-02-20T14:45:00.000' AS DateTime), CAST(N'2022-03-15T10:30:00.000' AS DateTime))
INSERT [dbo].[Loan] ([LoanID], [MemberID], [BookID], [LoanDate], [ReturnDate]) VALUES (3, 3, 3, CAST(N'2022-03-05T08:15:00.000' AS DateTime), NULL)
INSERT [dbo].[Loan] ([LoanID], [MemberID], [BookID], [LoanDate], [ReturnDate]) VALUES (4, 4, 4, CAST(N'2022-04-10T12:00:00.000' AS DateTime), NULL)
INSERT [dbo].[Loan] ([LoanID], [MemberID], [BookID], [LoanDate], [ReturnDate]) VALUES (5, 5, 5, CAST(N'2022-05-20T16:30:00.000' AS DateTime), CAST(N'2022-06-10T14:00:00.000' AS DateTime))
SET IDENTITY_INSERT [dbo].[Loan] OFF
GO
SET IDENTITY_INSERT [dbo].[Member] ON 

INSERT [dbo].[Member] ([MemberID], [FirstName], [LastName], [Email], [JoinDate]) VALUES (1, N'Amit', N'Verma', N'amit.verma@email.com', CAST(N'2022-01-10T08:45:00.000' AS DateTime))
INSERT [dbo].[Member] ([MemberID], [FirstName], [LastName], [Email], [JoinDate]) VALUES (2, N'Priya', N'Singh', N'priya.singh@email.com', CAST(N'2022-02-15T12:30:00.000' AS DateTime))
INSERT [dbo].[Member] ([MemberID], [FirstName], [LastName], [Email], [JoinDate]) VALUES (3, N'Rajesh', N'Kumar', N'rajesh.kumar@email.com', CAST(N'2022-03-20T10:15:00.000' AS DateTime))
INSERT [dbo].[Member] ([MemberID], [FirstName], [LastName], [Email], [JoinDate]) VALUES (4, N'Anjali', N'Gupta', N'anjali.gupta@email.com', CAST(N'2022-04-25T14:00:00.000' AS DateTime))
INSERT [dbo].[Member] ([MemberID], [FirstName], [LastName], [Email], [JoinDate]) VALUES (5, N'Vikas', N'Sharma', N'vikas.sharma@email.com', CAST(N'2022-05-30T16:45:00.000' AS DateTime))
SET IDENTITY_INSERT [dbo].[Member] OFF
GO
ALTER TABLE [dbo].[Book]  WITH CHECK ADD FOREIGN KEY([GenreID])
REFERENCES [dbo].[Genre] ([GenreID])
GO
USE [master]
GO
ALTER DATABASE [LibraryManagement] SET  READ_WRITE 
GO
