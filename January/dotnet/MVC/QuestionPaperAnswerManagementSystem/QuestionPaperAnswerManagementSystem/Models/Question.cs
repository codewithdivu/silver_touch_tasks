using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Web;

namespace QuestionPaperAnswerManagementSystem.Models
{
    public class Question
    {
        public int QuestionID { get; set; }

        public int QuestionPaperID { get; set; }

        [Required(ErrorMessage = "Question text is required")]
        public string QuestionText { get; set; }

        [Required(ErrorMessage = "Option 1 is required")]
        public string Option1 { get; set; }

        [Required(ErrorMessage = "Option 2 is required")]
        public string Option2 { get; set; }

        [Required(ErrorMessage = "Option 3 is required")]
        public string Option3 { get; set; }

        [Required(ErrorMessage = "Option 4 is required")]
        public string Option4 { get; set; }

        [Required(ErrorMessage = "Correct answer is required")]
        public string CorrectAnswer { get; set; }

        // Navigation property for the associated Question Paper
        public QuestionPaper QuestionPaper { get; set; }
    }
}