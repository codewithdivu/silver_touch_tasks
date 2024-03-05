using Microsoft.AspNet.Identity;
using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Web;

namespace QuestionPaperAnswerManagementSystem.Models
{
    public class Answer
    {
        public int AnswerID { get; set; }

        public int QuestionPaperID { get; set; }

        public int QuestionID { get; set; }

        public string UserID { get; set; }

        [Required(ErrorMessage = "Selected answer is required")]
        public string SelectedAnswer { get; set; }

        [Display(Name = "Submission Timestamp")]
        public DateTime SubmissionTimestamp { get; set; }

        // Navigation properties
        public QuestionPaper QuestionPaper { get; set; }

        public Question Question { get; set; }

        public ApplicationUser User { get; set; }
    }
}