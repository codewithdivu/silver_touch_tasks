use LibraryManagement;

INSERT INTO Book (Title, AuthorID, ISBN, PublishedDate) VALUES 
    ('The Art of Programming', 1, '978-0123456789', '2022-03-15'),
    ('Data Science Fundamentals', 2, '978-9876543210', '2021-08-20'),
    ('Mystery of the Lost City', 3, '978-1111222233', '2020-05-10'),
    ('Design Patterns in Practice', 4, '978-4444555566', '2019-11-25'),
    ('History of the Universe', NULL, '978-7777888899', '2018-06-30');

select * from Book;

INSERT INTO Author (AuthorName, BirthDate, Nationality, Biography) VALUES 
    ('Amit Sharma', '1985-09-20', 'Indian', 'Amit Sharma is a bestselling Indian author known for his novels reflecting Indian culture.'),
    ('Priya Verma', '1970-12-15', 'Indian', 'Priya Verma is a prolific Hindi author, capturing the essence of Indian traditions in her works.'),
    ('Rajeev Kapoor', '1980-05-28', 'Indian', 'Rajeev Kapoor is a renowned Indian mystery writer, weaving suspense into his captivating stories.'),
    ('Anjali Khanna', '1992-03-10', 'Indian', 'Anjali Khanna, a young Indian author, brings a fresh perspective to contemporary Indian literature.'),
    ('Vikram Singh', '1965-11-25', 'Indian', 'Vikram Singh is a celebrated Indian science fiction writer, exploring futuristic themes.');

select * from Author;

INSERT INTO Member (FirstName, LastName, Email, JoinDate) VALUES 
    ('Amit', 'Verma', 'amit.verma@email.com', '2022-01-10 08:45:00'),
    ('Priya', 'Singh', 'priya.singh@email.com', '2022-02-15 12:30:00'),
    ('Rajesh', 'Kumar', 'rajesh.kumar@email.com', '2022-03-20 10:15:00'),
    ('Anjali', 'Gupta', 'anjali.gupta@email.com', '2022-04-25 14:00:00'),
    ('Vikas', 'Sharma', 'vikas.sharma@email.com', '2022-05-30 16:45:00');

select * from Member;


INSERT INTO Loan (MemberID, BookID, LoanDate, ReturnDate) VALUES 
    (1, 1, '2022-01-15 10:30:00', '2022-02-10 12:00:00'),
    (2, 2, '2022-02-20 14:45:00', '2022-03-15 10:30:00'),
    (3, 3, '2022-03-05 08:15:00', NULL),
    (4, 4, '2022-04-10 12:00:00', NULL),
    (5, 5, '2022-05-20 16:30:00', '2022-06-10 14:00:00');


select * from Loan;



INSERT INTO Genre (GenreName, Description, CreatedDate, UpdatedDate) VALUES 
    ('Mystery', 'Books that involve solving a mystery or crime.', '2022-01-15', '2022-02-10 08:30:00'),
    ('Science Fiction', 'Books with speculative and futuristic themes.', '2022-02-20', '2022-03-15 12:45:00'),
    ('Romance', 'Books focused on romantic relationships and love stories.', '2022-03-05', NULL),
    ('Fantasy', 'Books set in fantastical worlds with magic and mythical creatures.', '2022-04-10', NULL),
    ('History', 'Books that explore historical events and periods.', '2022-05-20', '2022-06-10 14:00:00');

select * from Genre;
