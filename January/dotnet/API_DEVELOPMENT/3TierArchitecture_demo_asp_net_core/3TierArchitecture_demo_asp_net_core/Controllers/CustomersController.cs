using _3TierArchitecture_demo_asp_net_core.Commons;
using BAL.Services;
using DAL.Models;
using Microsoft.AspNetCore.Http;
using Microsoft.AspNetCore.Identity;
using Microsoft.AspNetCore.Mvc;

namespace _3TierArchitecture_demo_asp_net_core.Controllers
{
    [Route("api/[controller]")]
    [ApiController]
    public class CustomersController : ControllerBase
    {
        private readonly CustomerService _customerService;

        public CustomersController(CustomerService customerService)
        {
            _customerService = customerService;
        }

        [HttpGet]
        [Route("GetAll")]
        public IActionResult GetAllCustomers()
        {
            try
            {
                var customers = _customerService.GetAllCustomers();
                return Ok(new Response<IEnumerable<Customer>> { Status = "Success", Message = "Customers fetched successfully", Data = customers });
            }
            catch (Exception ex)
            {
                return StatusCode(500, new Response<IEnumerable<Customer>> { Status = "Error", Message = $"Internal server error: {ex.Message}", Data = null });
            }
        }

        [HttpGet]
        [Route("{id}")]
        public IActionResult GetCustomer(int id) {
            try
            {
                var customer = _customerService.GetCustomer(id);
                return Ok(new Response<Customer> { Status = "Success", Message = "Customer fetched successfully",Data = customer });
            }
            catch (Exception ex)
            {
                return StatusCode(500, new Response<IEnumerable<Customer>> { Status = "Error", Message = $"Internal server error: {ex.Message}", Data = null });
            }
        }

        [HttpPost]
        [Route("Create")]
        public IActionResult CreateCustomer(Customer customer)
        {
            try
            {
                var data =  _customerService.AddCustomer(customer);
                return Ok(new Response<Customer> { Status = "Success", Message = "Customer Created successfully", Data = data });

            }
            catch (Exception ex)
            {
                return StatusCode(500, new Response<IEnumerable<Customer>> { Status = "Error", Message = $"Internal server error: {ex.Message}", Data = null });
            }
        }

        [HttpDelete]
        [Route("{id}")]
        public IActionResult DeleteCustomer(int id) {
            try
            {
                _customerService.DeleteCustomer(id);
                return Ok(new Response<string> { Status = "Success", Message = "Customer deleted successfully", Data = null });


            }
            catch (Exception ex)
            {
                return StatusCode(500, new Response<String> { Status = "Error", Message = $"Internal server error: {ex.Message}", Data = null });
            }
        }

        [HttpPut]
        [Route("{id}")]
        public IActionResult UpdateCustomer(int id, Customer customer)
        {
            try
            {
                _customerService.UpdateCustomer(id,customer);
                return Ok(new Response<string> { Status = "Success", Message = "Customer updated successfully", Data = null });
            }
            catch (Exception ex)
            {
                return StatusCode(500, new Response<IEnumerable<Customer>> { Status = "Error", Message = $"Internal server error: {ex.Message}", Data = null });
            }
        }

    }
}
