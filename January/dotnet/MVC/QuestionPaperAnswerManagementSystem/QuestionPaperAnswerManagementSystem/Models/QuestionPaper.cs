using Microsoft.AspNet.Identity;
using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Web;

namespace QuestionPaperAnswerManagementSystem.Models
{
    public class QuestionPaper 
    {
        public int QuestionPaperID { get; set; }

        [Required(ErrorMessage = "Title is required")]
        public string Title { get; set; }

        [Required(ErrorMessage = "Description is required")]
        public string Description { get; set; }

        [Display(Name = "Creation Date")]
        public DateTime CreationDate { get; set; }

        [Display(Name = "Status")]
        public string Status { get; set; }

        [Display(Name = "Creator User ID")]
        public string CreatorUserID { get; set; }

        public ApplicationUser CreatorUser { get; set; }

        public ICollection<Question> Questions { get; set; }
    }
}