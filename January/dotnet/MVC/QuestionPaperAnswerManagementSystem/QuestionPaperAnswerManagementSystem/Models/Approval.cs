using Microsoft.AspNet.Identity;
using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Web;

namespace QuestionPaperAnswerManagementSystem.Models
{
    public class Approval
    {
        public int ApprovalID { get; set; }

        public int QuestionPaperID { get; set; }

        public string ApproverUserID { get; set; }

        [Required(ErrorMessage = "Approval status is required")]
        public string ApprovalStatus { get; set; }

        [Display(Name = "Approval Timestamp")]
        public DateTime ApprovalTimestamp { get; set; }

        // Navigation properties
        public QuestionPaper QuestionPaper { get; set; }

        public ApplicationUser ApproverUser { get; set; }
    }
}