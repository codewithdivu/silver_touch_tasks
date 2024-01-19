use Inventory;


Insert Into Product values 
('laptop',1,18000,10),
('Phone',1,5000,50),
('Headphone',2,800,200),
('Smart Watch',1,600,100),
('Speaker',2,8000,80);

select * from Product;


INSERT INTO Category (CategoryName, Description, CreatedDate, UpdatedDate) VALUES 
    ('Electronics', 'Electronic devices and gadgets', '2023-01-15', NULL),
    ('Furniture', 'Various types of furniture', '2023-02-20', '2023-03-10 08:30:00'),
    ('Appliances', 'Home appliances and kitchen tools', '2023-03-05', NULL),
    ('Clothing', 'Clothes and accessories', '2023-04-10', '2023-05-02 12:45:00'),
    ('Books', 'Books of various genres', '2023-05-20', NULL);

select * from Category;



INSERT INTO Supplier (SupplierName, ContactPerson, Email, Phone) VALUES 
    ('divu Electronics', 'Divyesh', 'divyesh@abc.com', '1234567890'),
    ('mamu Furniture', 'Mitul', 'mitul@xyz.com', '9876543210'),
    ('chachu Appliances Inc.', 'yagnink', 'yagnik@appliances.com', '5551234567'),
    ('Fashion Trends Ltd.', 'Prince', 'prince@fashiontrends.com', '7894561230'),
    ('Book Haven', 'Kalu', 'kalu@bookhaven.com', '321-654-9870');

select * from Supplier;


INSERT INTO Orderr(CustomerID, OrderDate, TotalAmount, Status) VALUES 
    (1, '2023-01-15 10:30:00', 150.99, 'Processing'),
    (2, '2023-02-20 14:45:00', 300.50, 'Shipped'),
    (3, '2023-03-05 08:15:00', 75.25, 'Delivered'),
    (4, '2023-04-10 12:00:00', 500.00, 'Processing'),
    (5, '2023-05-20 16:30:00', 200.75, 'Shipped');


select * from Orderr;


INSERT INTO OrderItem (OrderID, ProductID, Quantity, Subtotal) VALUES 
    (1, 1, 2, 1799.98),
    (1, 3, 1, 79.99),
    (2, 2, 3, 1499.97),
    (3, 4, 5, 199.95),
    (4, 5, 2, 299.98);


select * from OrderItem;
