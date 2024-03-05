namespace QuestionPaperAnswerManagementSystem.Migrations
{
    using System;
    using System.Data.Entity.Migrations;
    
    public partial class AddQuestionsAndPapers : DbMigration
    {
        public override void Up()
        {
            CreateTable(
                "dbo.QuestionPapers",
                c => new
                    {
                        QuestionPaperID = c.Int(nullable: false, identity: true),
                        Title = c.String(nullable: false),
                        Description = c.String(nullable: false),
                        CreationDate = c.DateTime(nullable: false),
                        Status = c.String(),
                        CreatorUserID = c.String(maxLength: 128),
                    })
                .PrimaryKey(t => t.QuestionPaperID)
                .ForeignKey("dbo.AspNetUsers", t => t.CreatorUserID)
                .Index(t => t.CreatorUserID);
            
            CreateTable(
                "dbo.Questions",
                c => new
                    {
                        QuestionID = c.Int(nullable: false, identity: true),
                        QuestionPaperID = c.Int(nullable: false),
                        QuestionText = c.String(nullable: false),
                        Option1 = c.String(nullable: false),
                        Option2 = c.String(nullable: false),
                        Option3 = c.String(nullable: false),
                        Option4 = c.String(nullable: false),
                        CorrectAnswer = c.String(nullable: false),
                    })
                .PrimaryKey(t => t.QuestionID)
                .ForeignKey("dbo.QuestionPapers", t => t.QuestionPaperID, cascadeDelete: true)
                .Index(t => t.QuestionPaperID);
            
        }
        
        public override void Down()
        {
            DropForeignKey("dbo.Questions", "QuestionPaperID", "dbo.QuestionPapers");
            DropForeignKey("dbo.QuestionPapers", "CreatorUserID", "dbo.AspNetUsers");
            DropIndex("dbo.Questions", new[] { "QuestionPaperID" });
            DropIndex("dbo.QuestionPapers", new[] { "CreatorUserID" });
            DropTable("dbo.Questions");
            DropTable("dbo.QuestionPapers");
        }
    }
}
