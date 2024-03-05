using demoMVCApplication.Models;
using demoMVCApplication.ViewModels;
using System.Collections.Generic;
using System.Web.Mvc;

namespace demoMVCApplication.Controllers
{
    public class MoviesController : Controller
    {
        // GET: Movies
        public ActionResult Index()
        {
            return Content("List of Movies");
        }
        public ActionResult Random(int id)
        {
            Movies movie = new Movies()
            {
                name = "Jack Ryan",
                id = id
            };
            return View(movie);
        }

        public ActionResult BestMovie()
        {
            Movies movie = new Movies()
            {
                name = "Jack Ryan",
            };
            var customer = new List<Customers>
            {
                new Customers {Name="Customer 1", Id = 1},
                new Customers {Name="Customer 2", Id = 2},
            };

            var viewModel = new BestMovieViewModel
            {
                Movie = movie,
                Customers = customer
            };
            return View(viewModel);
        }

        //convention routing
        public ActionResult Releasedby(int year, int month)
        {
            return Content("Released at" + string.Format("{0}/{1}", year, month));
        }

        //Attribute routing
        [Route("movies/paisa/{amount:range(500,50000000)}")]
        public ActionResult Budget(int amount)
        {
            return Content("Budget of movie is " + amount);
        }
    }
}