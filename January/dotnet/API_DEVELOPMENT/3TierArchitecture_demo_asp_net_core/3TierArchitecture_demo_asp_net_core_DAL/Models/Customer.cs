using System;
using System.Collections.Generic;

namespace _3TierArchitecture_demo_asp_net_core_DAL.Models
{

    public partial class Customer
    {
        public int CustomerId { get; set; }

        public string? FirstName { get; set; }

        public string? LastName { get; set; }

        public string? Email { get; set; }

        public virtual ICollection<Order> Orders { get; set; } = new List<Order>();
    }

}