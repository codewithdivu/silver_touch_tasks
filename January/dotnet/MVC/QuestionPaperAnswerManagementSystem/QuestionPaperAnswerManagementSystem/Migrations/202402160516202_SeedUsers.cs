namespace QuestionPaperAnswerManagementSystem.Migrations
{
    using System;
    using System.Data.Entity.Migrations;
    
    public partial class SeedUsers : DbMigration
    {
        public override void Up()
        {
            Sql(@"
            INSERT INTO [dbo].[AspNetUsers] ([Id], [Email], [EmailConfirmed], [PasswordHash], [SecurityStamp], [PhoneNumber], [PhoneNumberConfirmed], [TwoFactorEnabled], [LockoutEndDateUtc], [LockoutEnabled], [AccessFailedCount], [UserName]) VALUES (N'01dd608c-157a-4192-9dbc-4acc20b86661', N'admin@gmail.com', 0, N'AMwY71UJECXtp5VVeRHLFaViNmkAuu+lcVUCXryv86dUzDoqYZZGgBI5+oiTnGLKfg==', N'89105dae-ef4b-4cf6-909a-d72c4cf79478', NULL, 0, 0, NULL, 1, 0, N'admin@gmail.com')
INSERT INTO [dbo].[AspNetUsers] ([Id], [Email], [EmailConfirmed], [PasswordHash], [SecurityStamp], [PhoneNumber], [PhoneNumberConfirmed], [TwoFactorEnabled], [LockoutEndDateUtc], [LockoutEnabled], [AccessFailedCount], [UserName]) VALUES (N'bc71bb72-b52f-4fa3-a3fa-1cb4e62cd4bf', N'guest@gmail.com', 0, N'ACuFVJOAa09SZeKvqepzG+6gpYg1ddBgcYFgjFS5rdy3OePS0INvpj9X77nGXMgaLA==', N'fad817d4-2276-4624-858f-f67919a662b8', NULL, 0, 0, NULL, 1, 0, N'guest@gmail.com')
INSERT INTO [dbo].[AspNetUsers] ([Id], [Email], [EmailConfirmed], [PasswordHash], [SecurityStamp], [PhoneNumber], [PhoneNumberConfirmed], [TwoFactorEnabled], [LockoutEndDateUtc], [LockoutEnabled], [AccessFailedCount], [UserName]) VALUES (N'c2500214-c9d9-4339-9359-5b1fda8b10e0', N'teacher@gmail.com', 0, N'AG+XfIFQYlxiFWmEgTMNJhxhcXEOf1sS996/8E3bdVy04klI4U9AmpJCzLgdalzz9w==', N'4ba710ba-1df3-4b6c-9c12-10338cb0d756', NULL, 0, 0, NULL, 1, 0, N'teacher@gmail.com')
INSERT INTO [dbo].[AspNetUsers] ([Id], [Email], [EmailConfirmed], [PasswordHash], [SecurityStamp], [PhoneNumber], [PhoneNumberConfirmed], [TwoFactorEnabled], [LockoutEndDateUtc], [LockoutEnabled], [AccessFailedCount], [UserName]) VALUES (N'e94bdb2a-5a0d-4750-b924-f65c5b4b9d47', N'student@gmail.com', 0, N'AJ0IC0oQ1r6xQcHJ2iETfn+dYHr5a4izuQw7jioWUSil702ObPyOe5w7VeiGl+OoVg==', N'8257d5e0-9f18-45b7-8f1e-f78603f465e2', NULL, 0, 0, NULL, 1, 0, N'student@gmail.com')

INSERT INTO [dbo].[AspNetRoles] ([Id], [Name]) VALUES (N'b1142c86-9c25-433d-b240-12493ab2d99f', N'admin')
INSERT INTO [dbo].[AspNetRoles] ([Id], [Name]) VALUES (N'8006b8d7-7ecd-4448-ad20-f508c3d44fa7', N'student')
INSERT INTO [dbo].[AspNetRoles] ([Id], [Name]) VALUES (N'3c2c3f42-bcdb-4132-8d99-c983a8030ae3', N'teacher')

INSERT INTO [dbo].[AspNetUserRoles] ([UserId], [RoleId]) VALUES (N'c2500214-c9d9-4339-9359-5b1fda8b10e0', N'3c2c3f42-bcdb-4132-8d99-c983a8030ae3')
INSERT INTO [dbo].[AspNetUserRoles] ([UserId], [RoleId]) VALUES (N'e94bdb2a-5a0d-4750-b924-f65c5b4b9d47', N'8006b8d7-7ecd-4448-ad20-f508c3d44fa7')
INSERT INTO [dbo].[AspNetUserRoles] ([UserId], [RoleId]) VALUES (N'01dd608c-157a-4192-9dbc-4acc20b86661', N'b1142c86-9c25-433d-b240-12493ab2d99f')
 
            ");
        }
        
        public override void Down()
        {
        }
    }
}
