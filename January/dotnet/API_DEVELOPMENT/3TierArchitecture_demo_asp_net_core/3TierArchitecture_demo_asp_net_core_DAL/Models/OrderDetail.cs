﻿using System;
using System.Collections.Generic;

namespace _3TierArchitecture_demo_asp_net_core_DAL.Models
{

    public partial class OrderDetail
    {
        public int OrderDetailId { get; set; }

        public int? OrderId { get; set; }

        public int? ProductId { get; set; }

        public int? Quantity { get; set; }

        public decimal? Price { get; set; }

        public virtual Order? Order { get; set; }
    }
}