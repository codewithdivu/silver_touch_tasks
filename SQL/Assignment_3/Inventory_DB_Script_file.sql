USE [master]
GO
/****** Object:  Database [Inventory]    Script Date: 24-01-2024 15:15:05 ******/
CREATE DATABASE [Inventory]
 CONTAINMENT = NONE
 ON  PRIMARY 
( NAME = N'Inventory', FILENAME = N'C:\Program Files\Microsoft SQL Server\MSSQL15.MSSQLSERVER\MSSQL\DATA\Inventory.mdf' , SIZE = 8192KB , MAXSIZE = UNLIMITED, FILEGROWTH = 65536KB )
 LOG ON 
( NAME = N'Inventory_log', FILENAME = N'C:\Program Files\Microsoft SQL Server\MSSQL15.MSSQLSERVER\MSSQL\DATA\Inventory_log.ldf' , SIZE = 8192KB , MAXSIZE = 2048GB , FILEGROWTH = 65536KB )
 WITH CATALOG_COLLATION = DATABASE_DEFAULT
GO
ALTER DATABASE [Inventory] SET COMPATIBILITY_LEVEL = 150
GO
IF (1 = FULLTEXTSERVICEPROPERTY('IsFullTextInstalled'))
begin
EXEC [Inventory].[dbo].[sp_fulltext_database] @action = 'enable'
end
GO
ALTER DATABASE [Inventory] SET ANSI_NULL_DEFAULT OFF 
GO
ALTER DATABASE [Inventory] SET ANSI_NULLS OFF 
GO
ALTER DATABASE [Inventory] SET ANSI_PADDING OFF 
GO
ALTER DATABASE [Inventory] SET ANSI_WARNINGS OFF 
GO
ALTER DATABASE [Inventory] SET ARITHABORT OFF 
GO
ALTER DATABASE [Inventory] SET AUTO_CLOSE ON 
GO
ALTER DATABASE [Inventory] SET AUTO_SHRINK OFF 
GO
ALTER DATABASE [Inventory] SET AUTO_UPDATE_STATISTICS ON 
GO
ALTER DATABASE [Inventory] SET CURSOR_CLOSE_ON_COMMIT OFF 
GO
ALTER DATABASE [Inventory] SET CURSOR_DEFAULT  GLOBAL 
GO
ALTER DATABASE [Inventory] SET CONCAT_NULL_YIELDS_NULL OFF 
GO
ALTER DATABASE [Inventory] SET NUMERIC_ROUNDABORT OFF 
GO
ALTER DATABASE [Inventory] SET QUOTED_IDENTIFIER OFF 
GO
ALTER DATABASE [Inventory] SET RECURSIVE_TRIGGERS OFF 
GO
ALTER DATABASE [Inventory] SET  ENABLE_BROKER 
GO
ALTER DATABASE [Inventory] SET AUTO_UPDATE_STATISTICS_ASYNC OFF 
GO
ALTER DATABASE [Inventory] SET DATE_CORRELATION_OPTIMIZATION OFF 
GO
ALTER DATABASE [Inventory] SET TRUSTWORTHY OFF 
GO
ALTER DATABASE [Inventory] SET ALLOW_SNAPSHOT_ISOLATION OFF 
GO
ALTER DATABASE [Inventory] SET PARAMETERIZATION SIMPLE 
GO
ALTER DATABASE [Inventory] SET READ_COMMITTED_SNAPSHOT OFF 
GO
ALTER DATABASE [Inventory] SET HONOR_BROKER_PRIORITY OFF 
GO
ALTER DATABASE [Inventory] SET RECOVERY SIMPLE 
GO
ALTER DATABASE [Inventory] SET  MULTI_USER 
GO
ALTER DATABASE [Inventory] SET PAGE_VERIFY CHECKSUM  
GO
ALTER DATABASE [Inventory] SET DB_CHAINING OFF 
GO
ALTER DATABASE [Inventory] SET FILESTREAM( NON_TRANSACTED_ACCESS = OFF ) 
GO
ALTER DATABASE [Inventory] SET TARGET_RECOVERY_TIME = 60 SECONDS 
GO
ALTER DATABASE [Inventory] SET DELAYED_DURABILITY = DISABLED 
GO
ALTER DATABASE [Inventory] SET ACCELERATED_DATABASE_RECOVERY = OFF  
GO
ALTER DATABASE [Inventory] SET QUERY_STORE = OFF
GO
USE [Inventory]
GO
/****** Object:  UserDefinedFunction [dbo].[CalculateOrderTotal]    Script Date: 24-01-2024 15:15:05 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE FUNCTION [dbo].[CalculateOrderTotal]
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
GO
/****** Object:  UserDefinedFunction [dbo].[GetProductStockValue]    Script Date: 24-01-2024 15:15:05 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE FUNCTION [dbo].[GetProductStockValue]
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
/****** Object:  Table [dbo].[Product]    Script Date: 24-01-2024 15:15:05 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Product](
	[ProductID] [int] IDENTITY(1,1) NOT NULL,
	[ProductName] [varchar](50) NOT NULL,
	[CategoryID] [int] NULL,
	[Price] [decimal](10, 2) NOT NULL,
	[StockQuantity] [int] NULL,
PRIMARY KEY CLUSTERED 
(
	[ProductID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[Category]    Script Date: 24-01-2024 15:15:05 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Category](
	[CategoryID] [int] IDENTITY(1,1) NOT NULL,
	[CategoryName] [nvarchar](50) NOT NULL,
	[Description] [text] NULL,
	[CreatedDate] [date] NOT NULL,
	[UpdatedDate] [datetime] NULL,
PRIMARY KEY CLUSTERED 
(
	[CategoryID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY] TEXTIMAGE_ON [PRIMARY]
GO
/****** Object:  View [dbo].[ProductView]    Script Date: 24-01-2024 15:15:05 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE VIEW [dbo].[ProductView] AS
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
GO
/****** Object:  Table [dbo].[OrderItem]    Script Date: 24-01-2024 15:15:05 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[OrderItem](
	[OrderItemID] [int] IDENTITY(1,1) NOT NULL,
	[OrderID] [int] NOT NULL,
	[ProductID] [int] NOT NULL,
	[Quantity] [int] NOT NULL,
	[Subtotal] [decimal](10, 2) NULL,
PRIMARY KEY CLUSTERED 
(
	[OrderItemID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[Orderr]    Script Date: 24-01-2024 15:15:05 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Orderr](
	[OrderID] [int] IDENTITY(1,1) NOT NULL,
	[CustomerID] [int] NOT NULL,
	[OrderDate] [datetime] NOT NULL,
	[TotalAmount] [decimal](10, 2) NULL,
	[Status] [varchar](20) NOT NULL,
PRIMARY KEY CLUSTERED 
(
	[OrderID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  View [dbo].[OrderDetailsView]    Script Date: 24-01-2024 15:15:05 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE VIEW [dbo].[OrderDetailsView] AS
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
GO
/****** Object:  Table [dbo].[Supplier]    Script Date: 24-01-2024 15:15:05 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Supplier](
	[SupplierID] [int] IDENTITY(1,1) NOT NULL,
	[SupplierName] [varchar](50) NOT NULL,
	[ContactPerson] [varchar](50) NULL,
	[Email] [varchar](100) NULL,
	[Phone] [varchar](20) NOT NULL,
PRIMARY KEY CLUSTERED 
(
	[SupplierID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
SET IDENTITY_INSERT [dbo].[Category] ON 

INSERT [dbo].[Category] ([CategoryID], [CategoryName], [Description], [CreatedDate], [UpdatedDate]) VALUES (3, N'Electronics', N'Electronic devices and gadgets', CAST(N'2023-01-15' AS Date), NULL)
INSERT [dbo].[Category] ([CategoryID], [CategoryName], [Description], [CreatedDate], [UpdatedDate]) VALUES (4, N'Furniture', N'Various types of furniture', CAST(N'2023-02-20' AS Date), CAST(N'2023-03-10T08:30:00.000' AS DateTime))
INSERT [dbo].[Category] ([CategoryID], [CategoryName], [Description], [CreatedDate], [UpdatedDate]) VALUES (5, N'Appliances', N'Home appliances and kitchen tools', CAST(N'2023-03-05' AS Date), NULL)
INSERT [dbo].[Category] ([CategoryID], [CategoryName], [Description], [CreatedDate], [UpdatedDate]) VALUES (6, N'Clothing', N'Clothes and accessories', CAST(N'2023-04-10' AS Date), CAST(N'2023-05-02T12:45:00.000' AS DateTime))
INSERT [dbo].[Category] ([CategoryID], [CategoryName], [Description], [CreatedDate], [UpdatedDate]) VALUES (7, N'Books', N'Books of various genres', CAST(N'2023-05-20' AS Date), NULL)
INSERT [dbo].[Category] ([CategoryID], [CategoryName], [Description], [CreatedDate], [UpdatedDate]) VALUES (8, N'Technology', N'Cutting-edge electronic devices', CAST(N'2023-06-15' AS Date), NULL)
INSERT [dbo].[Category] ([CategoryID], [CategoryName], [Description], [CreatedDate], [UpdatedDate]) VALUES (9, N'Apparel', N'Clothes and accessories for all occasions', CAST(N'2023-06-18' AS Date), NULL)
SET IDENTITY_INSERT [dbo].[Category] OFF
GO
SET IDENTITY_INSERT [dbo].[OrderItem] ON 

INSERT [dbo].[OrderItem] ([OrderItemID], [OrderID], [ProductID], [Quantity], [Subtotal]) VALUES (1, 1, 1, 2, CAST(1799.98 AS Decimal(10, 2)))
INSERT [dbo].[OrderItem] ([OrderItemID], [OrderID], [ProductID], [Quantity], [Subtotal]) VALUES (2, 1, 3, 1, CAST(79.99 AS Decimal(10, 2)))
INSERT [dbo].[OrderItem] ([OrderItemID], [OrderID], [ProductID], [Quantity], [Subtotal]) VALUES (3, 2, 2, 3, CAST(1499.97 AS Decimal(10, 2)))
INSERT [dbo].[OrderItem] ([OrderItemID], [OrderID], [ProductID], [Quantity], [Subtotal]) VALUES (4, 3, 4, 5, CAST(199.95 AS Decimal(10, 2)))
INSERT [dbo].[OrderItem] ([OrderItemID], [OrderID], [ProductID], [Quantity], [Subtotal]) VALUES (5, 4, 5, 2, CAST(299.98 AS Decimal(10, 2)))
SET IDENTITY_INSERT [dbo].[OrderItem] OFF
GO
SET IDENTITY_INSERT [dbo].[Orderr] ON 

INSERT [dbo].[Orderr] ([OrderID], [CustomerID], [OrderDate], [TotalAmount], [Status]) VALUES (1, 1, CAST(N'2023-01-15T10:30:00.000' AS DateTime), CAST(150.99 AS Decimal(10, 2)), N'Processing')
INSERT [dbo].[Orderr] ([OrderID], [CustomerID], [OrderDate], [TotalAmount], [Status]) VALUES (2, 2, CAST(N'2023-02-20T14:45:00.000' AS DateTime), CAST(300.50 AS Decimal(10, 2)), N'Shipped')
INSERT [dbo].[Orderr] ([OrderID], [CustomerID], [OrderDate], [TotalAmount], [Status]) VALUES (3, 3, CAST(N'2023-03-05T08:15:00.000' AS DateTime), CAST(75.25 AS Decimal(10, 2)), N'Delivered')
INSERT [dbo].[Orderr] ([OrderID], [CustomerID], [OrderDate], [TotalAmount], [Status]) VALUES (4, 4, CAST(N'2023-04-10T12:00:00.000' AS DateTime), CAST(500.00 AS Decimal(10, 2)), N'Processing')
INSERT [dbo].[Orderr] ([OrderID], [CustomerID], [OrderDate], [TotalAmount], [Status]) VALUES (5, 5, CAST(N'2023-05-20T16:30:00.000' AS DateTime), CAST(200.75 AS Decimal(10, 2)), N'Shipped')
SET IDENTITY_INSERT [dbo].[Orderr] OFF
GO
SET IDENTITY_INSERT [dbo].[Product] ON 

INSERT [dbo].[Product] ([ProductID], [ProductName], [CategoryID], [Price], [StockQuantity]) VALUES (3, N'laptop', 1, CAST(18000.00 AS Decimal(10, 2)), 10)
INSERT [dbo].[Product] ([ProductID], [ProductName], [CategoryID], [Price], [StockQuantity]) VALUES (4, N'Phone', 1, CAST(5000.00 AS Decimal(10, 2)), 50)
INSERT [dbo].[Product] ([ProductID], [ProductName], [CategoryID], [Price], [StockQuantity]) VALUES (5, N'Headphone', 2, CAST(800.00 AS Decimal(10, 2)), 200)
INSERT [dbo].[Product] ([ProductID], [ProductName], [CategoryID], [Price], [StockQuantity]) VALUES (6, N'Smart Watch', 1, CAST(600.00 AS Decimal(10, 2)), 100)
INSERT [dbo].[Product] ([ProductID], [ProductName], [CategoryID], [Price], [StockQuantity]) VALUES (7, N'Speaker', 2, CAST(8000.00 AS Decimal(10, 2)), 80)
INSERT [dbo].[Product] ([ProductID], [ProductName], [CategoryID], [Price], [StockQuantity]) VALUES (8, N'Tablet', 1, CAST(1200.00 AS Decimal(10, 2)), 15)
INSERT [dbo].[Product] ([ProductID], [ProductName], [CategoryID], [Price], [StockQuantity]) VALUES (9, N'Camera', 1, CAST(800.00 AS Decimal(10, 2)), 30)
INSERT [dbo].[Product] ([ProductID], [ProductName], [CategoryID], [Price], [StockQuantity]) VALUES (10, N'Chair', 2, CAST(50.00 AS Decimal(10, 2)), 100)
INSERT [dbo].[Product] ([ProductID], [ProductName], [CategoryID], [Price], [StockQuantity]) VALUES (11, N'Smart Bulb', 3, CAST(25.00 AS Decimal(10, 2)), 50)
INSERT [dbo].[Product] ([ProductID], [ProductName], [CategoryID], [Price], [StockQuantity]) VALUES (12, N'Jeans', 4, CAST(40.00 AS Decimal(10, 2)), 80)
INSERT [dbo].[Product] ([ProductID], [ProductName], [CategoryID], [Price], [StockQuantity]) VALUES (13, N'Smartphone', 1, CAST(1200.00 AS Decimal(10, 2)), 15)
INSERT [dbo].[Product] ([ProductID], [ProductName], [CategoryID], [Price], [StockQuantity]) VALUES (14, N'Digital Camera', 2, CAST(800.00 AS Decimal(10, 2)), 30)
INSERT [dbo].[Product] ([ProductID], [ProductName], [CategoryID], [Price], [StockQuantity]) VALUES (15, N'Office Chair', 3, CAST(50.00 AS Decimal(10, 2)), 100)
INSERT [dbo].[Product] ([ProductID], [ProductName], [CategoryID], [Price], [StockQuantity]) VALUES (16, N'Smart Light Bulb', 1, CAST(25.00 AS Decimal(10, 2)), 50)
INSERT [dbo].[Product] ([ProductID], [ProductName], [CategoryID], [Price], [StockQuantity]) VALUES (17, N'Denim Jeans', 4, CAST(40.00 AS Decimal(10, 2)), 80)
INSERT [dbo].[Product] ([ProductID], [ProductName], [CategoryID], [Price], [StockQuantity]) VALUES (18, N'Gaming Laptop', 1, CAST(18000.00 AS Decimal(10, 2)), 10)
INSERT [dbo].[Product] ([ProductID], [ProductName], [CategoryID], [Price], [StockQuantity]) VALUES (19, N'Bluetooth Speaker', 2, CAST(8000.00 AS Decimal(10, 2)), 80)
INSERT [dbo].[Product] ([ProductID], [ProductName], [CategoryID], [Price], [StockQuantity]) VALUES (20, N'Coffee Table', 3, CAST(120.00 AS Decimal(10, 2)), 60)
INSERT [dbo].[Product] ([ProductID], [ProductName], [CategoryID], [Price], [StockQuantity]) VALUES (21, N'Microwave Oven', 3, CAST(150.00 AS Decimal(10, 2)), 20)
INSERT [dbo].[Product] ([ProductID], [ProductName], [CategoryID], [Price], [StockQuantity]) VALUES (22, N'Novel', 5, CAST(20.00 AS Decimal(10, 2)), 100)
SET IDENTITY_INSERT [dbo].[Product] OFF
GO
SET IDENTITY_INSERT [dbo].[Supplier] ON 

INSERT [dbo].[Supplier] ([SupplierID], [SupplierName], [ContactPerson], [Email], [Phone]) VALUES (1, N'divu Electronics', N'Divyesh', N'divyesh@abc.com', N'1234567890')
INSERT [dbo].[Supplier] ([SupplierID], [SupplierName], [ContactPerson], [Email], [Phone]) VALUES (2, N'mamu Furniture', N'Mitul', N'mitul@xyz.com', N'9876543210')
INSERT [dbo].[Supplier] ([SupplierID], [SupplierName], [ContactPerson], [Email], [Phone]) VALUES (3, N'chachu Appliances Inc.', N'yagnink', N'yagnik@appliances.com', N'5551234567')
INSERT [dbo].[Supplier] ([SupplierID], [SupplierName], [ContactPerson], [Email], [Phone]) VALUES (4, N'Fashion Trends Ltd.', N'Prince', N'prince@fashiontrends.com', N'7894561230')
INSERT [dbo].[Supplier] ([SupplierID], [SupplierName], [ContactPerson], [Email], [Phone]) VALUES (5, N'Book Haven', N'Kalu', N'kalu@bookhaven.com', N'321-654-9870')
SET IDENTITY_INSERT [dbo].[Supplier] OFF
GO
/****** Object:  Index [IX_OrderItem_OrderID]    Script Date: 24-01-2024 15:15:05 ******/
CREATE NONCLUSTERED INDEX [IX_OrderItem_OrderID] ON [dbo].[OrderItem]
(
	[OrderID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, SORT_IN_TEMPDB = OFF, DROP_EXISTING = OFF, ONLINE = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
GO
SET ANSI_PADDING ON
GO
/****** Object:  Index [IX_Product_ProductName]    Script Date: 24-01-2024 15:15:05 ******/
CREATE NONCLUSTERED INDEX [IX_Product_ProductName] ON [dbo].[Product]
(
	[ProductName] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, SORT_IN_TEMPDB = OFF, DROP_EXISTING = OFF, ONLINE = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
GO
/****** Object:  StoredProcedure [dbo].[AddProduct]    Script Date: 24-01-2024 15:15:05 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE PROCEDURE [dbo].[AddProduct]
			@ProductName VARCHAR(50),
			@CategoryID INT,
			@Price DECIMAL(10, 2),
			@StockQuantity INT
		AS
		BEGIN
			INSERT INTO Product (ProductName, CategoryID, Price, StockQuantity)
			VALUES (@ProductName, @CategoryID, @Price, @StockQuantity);
		END;
GO
/****** Object:  StoredProcedure [dbo].[DeleteProduct]    Script Date: 24-01-2024 15:15:05 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE PROCEDURE [dbo].[DeleteProduct]
			@ProductID INT
		AS
		BEGIN
			DELETE FROM Product
			WHERE ProductID = @ProductID;
		END;
GO
/****** Object:  StoredProcedure [dbo].[FullProductManagement]    Script Date: 24-01-2024 15:15:05 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE PROCEDURE [dbo].[FullProductManagement]
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
GO
/****** Object:  StoredProcedure [dbo].[SelectProduct]    Script Date: 24-01-2024 15:15:05 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE PROCEDURE [dbo].[SelectProduct]
			@ProductID INT
		AS
		BEGIN
			SELECT *
			FROM Product
			WHERE ProductID = @ProductID;
		END;
GO
/****** Object:  StoredProcedure [dbo].[UpdateProduct]    Script Date: 24-01-2024 15:15:05 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE PROCEDURE [dbo].[UpdateProduct]
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
GO
/****** Object:  Trigger [dbo].[tr_Product_AfterDelete]    Script Date: 24-01-2024 15:15:05 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TRIGGER [dbo].[tr_Product_AfterDelete]
		ON [dbo].[Product]
		AFTER DELETE
		AS
		BEGIN
			PRINT 'AFTER DELETE trigger on Product table';
		END;
GO
ALTER TABLE [dbo].[Product] ENABLE TRIGGER [tr_Product_AfterDelete]
GO
/****** Object:  Trigger [dbo].[tr_Product_AfterInsert]    Script Date: 24-01-2024 15:15:05 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TRIGGER [dbo].[tr_Product_AfterInsert]
		ON [dbo].[Product]
		AFTER INSERT
		AS
		BEGIN
			PRINT 'AFTER INSERT trigger on Product table';
		END;
GO
ALTER TABLE [dbo].[Product] ENABLE TRIGGER [tr_Product_AfterInsert]
GO
/****** Object:  Trigger [dbo].[tr_Product_AfterUpdate]    Script Date: 24-01-2024 15:15:05 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TRIGGER [dbo].[tr_Product_AfterUpdate]
		ON [dbo].[Product]
		AFTER UPDATE
		AS
		BEGIN
			PRINT 'AFTER UPDATE trigger on Product table';
		END;
GO
ALTER TABLE [dbo].[Product] ENABLE TRIGGER [tr_Product_AfterUpdate]
GO
/****** Object:  Trigger [dbo].[tr_Product_BeforeDelete]    Script Date: 24-01-2024 15:15:05 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TRIGGER [dbo].[tr_Product_BeforeDelete]
		ON [dbo].[Product]
		FOR DELETE
		AS
		BEGIN
			PRINT 'BEFORE DELETE trigger on Product table';
		END;
GO
ALTER TABLE [dbo].[Product] ENABLE TRIGGER [tr_Product_BeforeDelete]
GO
/****** Object:  Trigger [dbo].[tr_Product_BeforeInsert]    Script Date: 24-01-2024 15:15:05 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TRIGGER [dbo].[tr_Product_BeforeInsert]
		ON [dbo].[Product]
		FOR INSERT
		AS
		BEGIN
			PRINT 'BEFORE INSERT trigger on Product table';
		END;
GO
ALTER TABLE [dbo].[Product] ENABLE TRIGGER [tr_Product_BeforeInsert]
GO
/****** Object:  Trigger [dbo].[tr_Product_BeforeUpdate]    Script Date: 24-01-2024 15:15:05 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TRIGGER [dbo].[tr_Product_BeforeUpdate]
		ON [dbo].[Product]
		FOR UPDATE
		AS
		BEGIN
			PRINT 'BEFORE UPDATE trigger on Product table';
		END;
GO
ALTER TABLE [dbo].[Product] ENABLE TRIGGER [tr_Product_BeforeUpdate]
GO
USE [master]
GO
ALTER DATABASE [Inventory] SET  READ_WRITE 
GO
