use SocialMediaApp;



INSERT INTO [User] (FirstName, LastName, Email, BirthDate) VALUES 
    ('Sara', 'Khan', 'sara.khan@email.com', '1990-03-15'),
    ('Rahul', 'Sharma', 'rahul.sharma@email.com', '1985-08-20'),
    ('Preeti', 'Patel', 'preeti.patel@email.com', '1995-05-10'),
    ('Raj', 'Singh', 'raj.singh@email.com', '1980-11-25'),
    ('Anita', 'Verma', 'anita.verma@email.com', '1988-06-30');

select * from [user];


INSERT INTO Post (UserID, Content, PostDate, LikesCount) VALUES 
    (1, 'Just visited a beautiful place!', '2022-01-15 10:30:00', 25),
    (2, 'Working on a new project. Excited!', '2022-02-20 14:45:00', 10),
    (3, 'Enjoying a cup of coffee on a lazy Sunday.', '2022-03-05 08:15:00', 15),
    (4, 'Celebrating my birthday today!', '2022-04-10 12:00:00', 50),
    (5, 'Completed a challenging workout. Feeling accomplished!', '2022-05-20 16:30:00', 30);

select * from Post;


INSERT INTO Comment (PostID, UserID, CommentText, CommentDate) VALUES 
    (1, 2, 'Looks amazing! Where is this?', '2022-01-15 11:30:00'),
    (1, 3, 'I love that place too! Great choice.', '2022-01-15 12:00:00'),
    (2, 1, 'Cant it to see the final result! ', '2022-02-20 15:30:00'),
    (3, 4, 'Lazy Sundays are the best! ☕', '2022-03-05 09:00:00'),
    (4, 5, 'Happy Birthday! 🎉🎂', '2022-04-10 12:30:00');


select * from Comment;


INSERT INTO Friendship (UserID1, UserID2, Status, RequestDate) VALUES 
    (1, 2, 'Accepted', '2022-01-15 10:30:00'),
    (2, 3, 'Pending', '2022-02-20 14:45:00'),
    (3, 4, 'Accepted', '2022-03-05 08:15:00'),
    (4, 5, 'Pending', '2022-04-10 12:00:00'),
    (5, 1, 'Accepted', '2022-05-20 16:30:00');

select * from Friendship;


INSERT INTO Notification (UserID, NotificationText, IsRead, NotificationDate) VALUES 
    (1, 'You have a new friend request!', 0, '2022-01-15 10:30:00'),
    (2, 'Your post has received 10 likes!', 1, '2022-02-20 14:45:00'),
    (3, 'New comment on your post: "Looks amazing!"', 0, '2022-03-05 08:15:00'),
    (4, 'Reminde Your friends birthday is tomorrow!', 0, '2022-04-10 12:00:00'),
    (5, 'You have been tagged in a photo!', 0, '2022-05-20 16:30:00');

select * from Notification;
