using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using Vidly.Models;
using Vidly.ViewModels;


namespace Vidly.Controllers
{
    public class MoviesController : Controller
    {
        // GET: Movies
        public ActionResult Index()
        {
            var movie = new List<Movie>
            {
                new Movie { name="Jack Ryan", id=1},
                new Movie {name="Night Agent", id=2},
            };

            var movieViewModel = new MovieListViewModel
            {
                movies = movie,
            };
            return View(movieViewModel);
        }
    }
}