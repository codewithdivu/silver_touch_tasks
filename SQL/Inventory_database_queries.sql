
-- ---------------------ASSIGNMENT-1---------------------------


-- Creation of DB
create database Inventory;
-- Use of DB
use Inventory;

-- Creation and Insertion queries for table


-- 1.Product 

CREATE TABLE Product (
    ProductID INT IDENTITY(1,1) PRIMARY KEY,
    ProductName VARCHAR(50) NOT NULL,
    CategoryID INT FOREIGN KEY REFERENCES Category(CategoryID),
    Price DECIMAL(10, 2) NOT NULL,
    StockQuantity INT NULL
);

Insert Into Product values 
('laptop',1,18000,10),
('Phone',1,5000,50),
('Headphone',2,800,200),
('Smart Watch',1,600,100),
('Speaker',2,8000,80),
('Tablet', 1, 1200, 15),
('Camera', 1, 800, 30),
('Chair', 2, 50, 100),
('Smart Bulb', 3, 25, 50),
('Jeans', 4, 40, 80),
('Smartphone', 1, 1200, 15),
('Digital Camera', 2, 800, 30),
('Office Chair', 3, 50, 100),
('Smart Light Bulb', 1, 25, 50),
('Denim Jeans', 4, 40, 80),
('Gaming Laptop', 1, 18000, 10),
('Bluetooth Speaker', 2, 8000, 80),
('Coffee Table', 3, 120, 60),
('Microwave Oven', 3, 150, 20),
('Novel', 5, 20, 100);



select * from Product;

-- 2.Category 

CREATE TABLE Category (
    CategoryID INT IDENTITY(1,1) PRIMARY KEY,
    CategoryName NVARCHAR(50) NOT NULL,
    Description TEXT NULL,
    CreatedDate DATE NOT NULL,
    UpdatedDate DATETIME NULL
);


INSERT INTO Category (CategoryName, Description, CreatedDate, UpdatedDate) VALUES 
    ('Electronics', 'Electronic devices and gadgets', '2023-01-15', NULL),
    ('Furniture', 'Various types of furniture', '2023-02-20', '2023-03-10 08:30:00'),
    ('Appliances', 'Home appliances and kitchen tools', '2023-03-05', NULL),
    ('Clothing', 'Clothes and accessories', '2023-04-10', '2023-05-02 12:45:00'),
    ('Books', 'Books of various genres', '2023-05-20', NULL),
	('Technology', 'Cutting-edge electronic devices', '2023-06-15', NULL),
    ('Apparel', 'Clothes and accessories for all occasions', '2023-06-18', NULL);



select * from Category;


-- 3.Supplier

CREATE TABLE Supplier (
    SupplierID INT IDENTITY(1,1) PRIMARY KEY,
    SupplierName VARCHAR(50) NOT NULL,
    ContactPerson VARCHAR(50) NULL,
    Email VARCHAR(100) NULL,
    Phone VARCHAR(20) NOT NULL
);

INSERT INTO Supplier (SupplierName, ContactPerson, Email, Phone) VALUES 
    ('divu Electronics', 'Divyesh', 'divyesh@abc.com', '1234567890'),
    ('mamu Furniture', 'Mitul', 'mitul@xyz.com', '9876543210'),
    ('chachu Appliances Inc.', 'yagnink', 'yagnik@appliances.com', '5551234567'),
    ('Fashion Trends Ltd.', 'Prince', 'prince@fashiontrends.com', '7894561230'),
    ('Book Haven', 'Kalu', 'kalu@bookhaven.com', '321-654-9870');

select * from Supplier;


-- 4.Orderr 

CREATE TABLE Order (
    OrderID INT IDENTITY(1,1) PRIMARY KEY,
    CustomerID INT NOT NULL,
    OrderDate DATETIME NOT NULL,
    TotalAmount DECIMAL(10, 2) NULL,
    Status VARCHAR(20) NOT NULL
);


INSERT INTO Orderr(CustomerID, OrderDate, TotalAmount, Status) VALUES 
    (1, '2023-01-15 10:30:00', 150.99, 'Processing'),
    (2, '2023-02-20 14:45:00', 300.50, 'Shipped'),
    (3, '2023-03-05 08:15:00', 75.25, 'Delivered'),
    (4, '2023-04-10 12:00:00', 500.00, 'Processing'),
    (5, '2023-05-20 16:30:00', 200.75, 'Shipped');


select * from Orderr;


-- 5. OrderItem 

CREATE TABLE OrderItem (
    OrderItemID INT IDENTITY(1,1) PRIMARY KEY,
    OrderID INT NOT NULL,
    ProductID INT NOT NULL,
    Quantity INT NOT NULL,
    Subtotal DECIMAL(10, 2) NULL
);


INSERT INTO OrderItem (OrderID, ProductID, Quantity, Subtotal) VALUES 
    (1, 1, 2, 1799.98),
    (1, 3, 1, 79.99),
    (2, 2, 3, 1499.97),
    (3, 4, 5, 199.95),
    (4, 5, 2, 299.98);


select * from OrderItem;


-- ---------------------ASSIGNMENT-2---------------------------

-- Inline Queries:

-- 1. Retrieve all products with their category names
	SELECT Product.ProductID, Product.ProductName, Category.CategoryName
	FROM Product INNER JOIN Category 
	ON Product.CategoryID = Category.CategoryID;

-- 2. Find the total stock quantity of all products
	SELECT SUM(StockQuantity) AS TotalStock
	FROM Product;

-- 3. List products with a price greater than 50
	SELECT ProductID, ProductName, Price FROM Product WHERE Price > 50;


-- Sub Queries:
--	1. Find products in a specific category (Electronics)
	SELECT ProductID, ProductName, Price
	FROM Product WHERE CategoryID = 
	(SELECT CategoryID FROM Category WHERE CategoryName = 'Electronics');

-- 2. Retrieve Products in a Specific Category ('Electronics') --
	SELECT
		ProductID,
		ProductName,
		CategoryID,
		Price,
		StockQuantity
	FROM
		Product
	WHERE
		CategoryID IN (
			SELECT CategoryID
			FROM Category
			WHERE CategoryName = 'Electronics');

-- 3. Get the average price of products
	SELECT AVG(Price) AS AveragePrice FROM Product;


--  SQL Functions:

-- 1. Query using CONCAT() and UPPER():
	SELECT
		CONCAT('Product: ', Product.ProductName) AS ProductDescription,
		UPPER(Category.CategoryName) AS UppercaseCategory
	FROM
		Product
	INNER JOIN
		Category ON Product.CategoryID = Category.CategoryID;

-- 2. Query using LEFT() and LEN():
	SELECT
		LEFT(Product.ProductName, 3) AS ShortProductName,
		LEN(CONVERT(VARCHAR(MAX), Category.Description)) AS CategoryDescriptionLength
	FROM
		Product
	INNER JOIN
    Category ON Product.CategoryID = Category.CategoryID;

-- 3. Query using REPLACE() and TRIM():
	SELECT
		REPLACE(Product.ProductName, ' ', '_') AS ReplacedProductName,
		TRIM(Category.CategoryName) AS TrimmedCategory
	FROM
		Product
	INNER JOIN
		Category ON Product.CategoryID = Category.CategoryID;

-- 4. Query using ROUND() and POWER():
	SELECT
		Product.ProductName,
		ROUND(Product.Price, 2) AS RoundedPrice,
		POWER(Product.StockQuantity, 2) AS StockQuantitySquared
	FROM
		Product;

-- 5. Query using ABS() and RAND():
	SELECT
		Product.ProductName,
		ABS(Product.Price) AS AbsolutePrice,
		RAND() AS RandomValue
	FROM
		Product;

-- 6. Query using CEILING() and FLOOR():
	SELECT
		Product.ProductName,
		CEILING(Product.Price) AS CeiledPrice,
		FLOOR(Product.Price) AS FlooredPrice
	FROM
		Product;

-- 7. Query using GETDATE() and DATEADD():
	SELECT
		OrderID,
		GETDATE() AS CurrentDateTime,
		DATEADD(DAY, 7, OrderDate) AS OrderDateAfter7Days
	FROM
		[Orderr];

-- 8. Query using MONTH() and FORMAT():
	SELECT
    OrderID,
    CustomerID,
		MONTH(OrderDate) AS OrderMonth,
		FORMAT(OrderDate, 'yyyy-MM-dd HH:mm:ss') AS FormattedOrderDate
	FROM
		[Orderr];

-- 9. Query using DATEDIFF() and EOMONTH():
	SELECT
    OrderID,
    CustomerID,
		DATEDIFF(DAY, OrderDate, GETDATE()) AS DaysSinceOrder,
		EOMONTH(OrderDate) AS EndOfMonth
	FROM
		[Orderr];

-- 10. Query using ROW_NUMBER() and LAG():
	WITH OrderedProducts AS (
		SELECT
			ProductID,
			ProductName,
			ROW_NUMBER() OVER (ORDER BY Price DESC) AS RowNum,
			LAG(ProductName) OVER (ORDER BY Price DESC) AS PreviousProduct
		FROM
			Product
	)
	SELECT
		ProductID,
		ProductName,
		RowNum,
		PreviousProduct
	FROM
		OrderedProducts
	WHERE
		RowNum <= 5;

-- 11. Query using CTE (Common Table Expression) and FORMAT():
	WITH FormattedOrders AS (
		SELECT
			OrderID,
			FORMAT(OrderDate, 'yyyy-MM-dd') AS FormattedOrderDate
		FROM
			[Orderr]
	)
	SELECT
		OrderID,
		FormattedOrderDate
	FROM
		FormattedOrders;

-- 12. Query using SUM() and PARTITION BY:
	SELECT
		Category.CategoryName,
		Product.ProductName,
		Product.Price,
		SUM(Product.Price) OVER (PARTITION BY Category.CategoryID) AS CategoryTotalPrice
	FROM
		Product
	INNER JOIN
		Category ON Product.CategoryID = Category.CategoryID;


-- ---------------------ASSIGNMENT-3---------------------------

-- 8. Create 2 user-defined views.

		CREATE VIEW ProductView AS
		SELECT
			p.ProductID,
			p.ProductName,
			c.CategoryName,
			p.Price,
			p.StockQuantity
		FROM
			Product p
		JOIN
			Category c ON p.CategoryID = c.CategoryID;

		SELECT * FROM ProductView;


		CREATE VIEW OrderDetailsView AS
		SELECT
			o.OrderID,
			o.CustomerID,
			o.OrderDate,
			o.TotalAmount,
			o.Status,
			oi.ProductID,
			oi.Quantity,
			oi.Subtotal
		FROM
			Orderr o
		JOIN
			OrderItem oi ON o.OrderID = oi.OrderID;

		SELECT * FROM OrderDetailsView;

-- 9. Create 2 Scalar-valued functions (e.g. split string).	-- 1. GetProductStockValue
		CREATE FUNCTION dbo.GetProductStockValue
		(
			@ProductID INT
		)
		RETURNS DECIMAL(10, 2)
		AS
		BEGIN
			DECLARE @StockValue DECIMAL(10, 2);

			SELECT @StockValue = Price * StockQuantity
			FROM Product
			WHERE ProductID = @ProductID;

			RETURN @StockValue;
		END;
		GO

		DECLARE @StockValue DECIMAL(10, 2);
		SET @StockValue = dbo.GetProductStockValue(1);
		PRINT 'Stock Value for ProductID 1: ' + COALESCE(CAST(@StockValue AS VARCHAR), 'NULL');




	-- 2. CalculateOrderTotal
		CREATE FUNCTION dbo.CalculateOrderTotal
		(
			@OrderID INT
		)
		RETURNS DECIMAL(10, 2)
		AS
		BEGIN
			DECLARE @TotalAmount DECIMAL(10, 2);

			SELECT @TotalAmount = SUM(Subtotal)
			FROM OrderItem
			WHERE OrderID = @OrderID;

			RETURN @TotalAmount;
		END;

		DECLARE @OrderTotal DECIMAL(10, 2);
		SET @OrderTotal = dbo.CalculateOrderTotal(1);
		PRINT 'Total Amount for OrderID 1: ' + CAST(@OrderTotal AS VARCHAR);


-- 10. Create 5 store procedures (select, add, update, delete and full).

	-- 1. Select
		CREATE PROCEDURE SelectProduct
			@ProductID INT
		AS
		BEGIN
			SELECT *
			FROM Product
			WHERE ProductID = @ProductID;
		END;

		Exec SelectProduct @ProductID = 7;
	    select * from Product;

	
	-- 2. Create
		CREATE PROCEDURE AddProduct
			@ProductName VARCHAR(50),
			@CategoryID INT,
			@Price DECIMAL(10, 2),
			@StockQuantity INT
		AS
		BEGIN
			INSERT INTO Product (ProductName, CategoryID, Price, StockQuantity)
			VALUES (@ProductName, @CategoryID, @Price, @StockQuantity);
		END;

		Exec AddProduct  @ProductName = 'Divyesh', @CategoryID = 3,@Price = 300, @StockQuantity = 99;
		select * from Product;

	-- 3. Update
		CREATE PROCEDURE UpdateProduct
			@ProductID INT,
			@ProductName VARCHAR(50),
			@CategoryID INT,
			@Price DECIMAL(10, 2),
			@StockQuantity INT
		AS
		BEGIN
			UPDATE Product
			SET
				ProductName = @ProductName,
				CategoryID = @CategoryID,
				Price = @Price,
				StockQuantity = @StockQuantity
			WHERE
				ProductID = @ProductID;
		END;

		Exec UpdateProduct @ProductId = 23, @ProductName = 'Divu', @CategoryID = 2, @Price = 299, @StockQuantity = 97;
		select * from Product;

	-- 4. Delete
		CREATE PROCEDURE DeleteProduct
			@ProductID INT
		AS
		BEGIN
			DELETE FROM Product
			WHERE ProductID = @ProductID;
		END;

		Exec DeleteProduct @ProductId = 23;
		
	-- 5. Fully
		CREATE PROCEDURE FullProductManagement
			@NewProductName VARCHAR(50),
			@NewCategoryID INT,
			@NewPrice DECIMAL(10, 2),
			@NewStockQuantity INT,
			@UpdateProductID INT,
			@UpdateProductName VARCHAR(50),
			@UpdateCategoryID INT,
			@UpdatePrice DECIMAL(10, 2),
			@UpdateStockQuantity INT,
			@DeleteProductID INT
		AS
		BEGIN
			-- Select all products
			SELECT * FROM Product;

			-- Add a new product
			INSERT INTO Product (ProductName, CategoryID, Price, StockQuantity)
			VALUES (@NewProductName, @NewCategoryID, @NewPrice, @NewStockQuantity);

			-- Update an existing product
			UPDATE Product
			SET
				ProductName = @UpdateProductName,
				CategoryID = @UpdateCategoryID,
				Price = @UpdatePrice,
				StockQuantity = @UpdateStockQuantity
			WHERE
				ProductID = @UpdateProductID;

			-- Delete a product
			DELETE FROM Product
			WHERE ProductID = @DeleteProductID;
		END;

		Exec FullProductManagement;



-- 11.  Create 2 non-clustered indexes.

	-- 1. Non-Clustered Index on Product Table (ProductName)
		CREATE NONCLUSTERED INDEX IX_Product_ProductName
		ON Product (ProductName);

	--2. Non-Clustered Index on OrderItem Table (OrderID)
		CREATE NONCLUSTERED INDEX IX_OrderItem_OrderID
		ON OrderItem (OrderID);



-- 12.  Create Before and After triggers for insert, update and delete operations.

	--1 Before Insert
		CREATE TRIGGER tr_Product_BeforeInsert
		ON Product
		FOR INSERT
		AS
		BEGIN
			PRINT 'BEFORE INSERT trigger on Product table';
		END;


	--2 After Insert
		CREATE TRIGGER tr_Product_AfterInsert
		ON Product
		AFTER INSERT
		AS
		BEGIN
			PRINT 'AFTER INSERT trigger on Product table';
		END;

	--3 Before Update
		CREATE TRIGGER tr_Product_BeforeUpdate
		ON Product
		FOR UPDATE
		AS
		BEGIN
			PRINT 'BEFORE UPDATE trigger on Product table';
		END;

	--4 After Update
		CREATE TRIGGER tr_Product_AfterUpdate
		ON Product
		AFTER UPDATE
		AS
		BEGIN
			PRINT 'AFTER UPDATE trigger on Product table';
		END;

	--5 After Delete
		CREATE TRIGGER tr_Product_AfterDelete
		ON Product
		AFTER DELETE
		AS
		BEGIN
			PRINT 'AFTER DELETE trigger on Product table';
		END;

	--6 Before Delete
		CREATE TRIGGER tr_Product_BeforeDelete
		ON Product
		FOR DELETE
		AS
		BEGIN
			PRINT 'BEFORE DELETE trigger on Product table';
		END;


-- 13. Write SQL queries for Union and Union All.

	-- 1. UNION
		SELECT CategoryID FROM Product
		UNION
		SELECT OrderID FROM OrderItem;

	--2; UNION ALL
		SELECT CategoryID FROM Product
		UNION ALL
		SELECT OrderID FROM OrderItem;


-- JOINS
	
	-- 1. Inner Join
		SELECT
			Product.ProductID,
			Product.ProductName,
			Product.Price,
			Product.StockQuantity,
			Category.CategoryName
		FROM
			Product
		INNER JOIN
			Category ON Product.CategoryID = Category.CategoryID;

	-- 2. Left Outer Join
		SELECT
			Product.ProductID,
			Product.ProductName,
			Product.Price,
			Product.StockQuantity,
			Category.CategoryName
		FROM
			Product
		LEFT JOIN
			Category ON Product.CategoryID = Category.CategoryID;

	-- 3. Right Outer Join
		SELECT
			Product.ProductID,
			Product.ProductName,
			Product.Price,
			Product.StockQuantity,
			Category.CategoryName
		FROM
			Product
		RIGHT JOIN
			Category ON Product.CategoryID = Category.CategoryID;

	-- 4. Full Outer Join
		SELECT
			Product.ProductID,
			Product.ProductName,
			Product.Price,
			Product.StockQuantity,
			Category.CategoryName
		FROM
			Product
		FULL JOIN
			Category ON Product.CategoryID = Category.CategoryID;

	-- 5. Cross Join
		SELECT
			Product.ProductID,
			Product.ProductName,
			Product.Price,
			Product.StockQuantity,
			Category.CategoryID,
			Category.CategoryName
		FROM
			Product
		CROSS JOIN
			Category;



-- Data Dictionary


	use Inventory;


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