using demoMVCApplication.Models;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace demoMVCApplication.ViewModels
{
    public class BestMovieViewModel
    {
        public Movies Movie { get; set; }
        public List<Customers> Customers { get; set; }
    }
}