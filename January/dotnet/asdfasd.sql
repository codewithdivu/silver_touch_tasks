create database QPManagement;
use QPManagement;

-- User Table
CREATE TABLE Users (
    UserID INT PRIMARY KEY IDENTITY,
    Username VARCHAR(50) NOT NULL UNIQUE,
    PasswordHash VARCHAR(255) NOT NULL,
    Email VARCHAR(100) NOT NULL,
    Role NVARCHAR(50) NOT NULL
);

select * from Questions;



INSERT INTO Users (Username, PasswordHash, Email, Role)
VALUES ('john_doe', 'password123', 'john@example.com', 'user');

-- Question Paper Table
CREATE TABLE QuestionPapers (
    QuestionPaperID INT PRIMARY KEY IDENTITY,
    Title NVARCHAR(100) NOT NULL,
    Description NVARCHAR(MAX),
    CreationDate DATETIME2 NOT NULL DEFAULT GETDATE(),
    Status NVARCHAR(50) NOT NULL DEFAULT 'Draft',
    CreatorID INT NOT NULL,
    FOREIGN KEY (CreatorID) REFERENCES Users(UserID)
);

-- Question Table
CREATE TABLE Questions (
    QuestionID INT PRIMARY KEY IDENTITY,
    QuestionText NVARCHAR(MAX) NOT NULL,
    Option1 NVARCHAR(MAX) NOT NULL,
	Option2 NVARCHAR(MAX) NOT NULL,
    Option3 NVARCHAR(MAX) NOT NULL,
    Option4 NVARCHAR(MAX) NOT NULL,
    CorrectAnswer NVARCHAR(MAX) NOT NULL,
    QuestionPaperID INT NOT NULL,
    FOREIGN KEY (QuestionPaperID) REFERENCES QuestionPapers(QuestionPaperID)
);

drop table Questions;


-- Answer Table
CREATE TABLE Answers (
    AnswerID INT PRIMARY KEY IDENTITY,
    UserID INT NOT NULL,
    QuestionID INT NOT NULL,
    AnswerText NVARCHAR(MAX) NOT NULL,
    SubmissionTimestamp DATETIME2 NOT NULL DEFAULT GETDATE(),
    FOREIGN KEY (UserID) REFERENCES Users(UserID),
    FOREIGN KEY (QuestionID) REFERENCES Questions(QuestionID)
);

-- Approval Table
CREATE TABLE Approvals (
    ApprovalID INT PRIMARY KEY IDENTITY,
    QuestionPaperID INT NOT NULL,
    ApproverID INT NOT NULL,
    ApprovalStatus NVARCHAR(50) NOT NULL,
    ApprovalTimestamp DATETIME2 NOT NULL DEFAULT GETDATE(),
    FOREIGN KEY (QuestionPaperID) REFERENCES QuestionPapers(QuestionPaperID),
    FOREIGN KEY (ApproverID) REFERENCES Users(UserID)
);

-- Permission Table
CREATE TABLE Permissions (
    PermissionID INT PRIMARY KEY IDENTITY,
    Role NVARCHAR(50) NOT NULL,
    CanCreateQuestionPaper BIT NOT NULL DEFAULT 0,
    CanEditQuestionPaper BIT NOT NULL DEFAULT 0,
    CanDeleteQuestionPaper BIT NOT NULL DEFAULT 0,
    CanReviewQuestionPaper BIT NOT NULL DEFAULT 0
);
