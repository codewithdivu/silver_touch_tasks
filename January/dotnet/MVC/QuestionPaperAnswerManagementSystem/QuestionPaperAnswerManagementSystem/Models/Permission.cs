using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Web;
using Microsoft.AspNet.Identity;
using Microsoft.AspNet.Identity.EntityFramework;


namespace QuestionPaperAnswerManagementSystem.Models
{
    public class Permission : IdentityUser
    {
        public int PermissionID { get; set; }

        [Required]
        public int RoleID { get; set; }

        [Required]
        public string PermissionType { get; set; }

    }
}