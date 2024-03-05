using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using Vidly.Models;
using Vidly.ViewModels;

namespace Vidly.Controllers
{
    public class CustomerController : Controller
    {
        // GET: Customer
        public ActionResult Index()
        {
            var customer = new List<Customer>
            {
                new Customer { name="Divyesh Mavadiya", id=1},
                new Customer {name="Himanshu Prajapati", id=2},
            };
            var customerViewModel = new CustomerListViewModel
            {
                customers = customer,
            };
            return View(customerViewModel);
        }
        public ActionResult Details(int id)
        {
            var customers = new List<Customer>
            {
                new Customer { name="Divyesh Mavadiya", id=1},
                new Customer {name="Himanshu Prajapati", id=2},
            };
            Customer person = customers.FirstOrDefault(c => c.id == id);
            if (person == null)
            {
                return HttpNotFound();
            }

            Customer customer = new Customer()
            {
                name = person.name,
                id = person.id
            };
            return View(customer);
        }
    }
}