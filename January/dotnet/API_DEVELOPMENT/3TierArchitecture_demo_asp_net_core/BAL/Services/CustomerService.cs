using DAL.Contracts;
using DAL.Models;

namespace BAL.Services
{
    public class CustomerService 
    {
        public readonly IRepository<Customer> _repository;
        public CustomerService(IRepository<Customer> repository)
        {
            _repository = repository;
        }
        public  Customer AddCustomer(Customer customer)
        {
            try
            {
                if (customer == null)
                {
                    throw new ArgumentNullException(nameof(customer));
                }
                else
                {
                    return  _repository.Create(customer);
                }
            }
            catch (Exception)
            {

                throw;
            }
        }

        public void DeleteCustomer(int Id)

        {
            try
            {
                if (Id != 0)
                {
                    _repository.Delete(Id);
                }
            }
            catch (Exception)
            {
                throw;
            }
        }

        public void UpdateCustomer(int Id, Customer updatedCustomer)
        {
            try
            {
                if (Id != 0)
                {
                    var existingCustomer = _repository.GetById(Id);
                    if (existingCustomer != null)
                    {
                        existingCustomer.FirstName = updatedCustomer.FirstName;
                        existingCustomer.LastName = updatedCustomer.LastName;
                        existingCustomer.Email = updatedCustomer.Email;

                        _repository.Update(existingCustomer);
                    }
                    else
                    {
                        throw new ArgumentException("Customer not found");
                    }
                }
                else
                {
                    throw new ArgumentException("Invalid customer ID");
                }
            }
            catch (Exception ex)
            {
                throw new Exception("Error updating customer", ex);
            }
        }


        public IEnumerable<Customer> GetAllCustomers()
        {
            try
            {
                return _repository.GetAll().ToList();
            }
            catch (Exception)
            {

                throw;
            }
        }

        public Customer GetCustomer(int id)
        {
            try
            {
                return _repository.GetById(id);
            }
            catch (Exception)
            {
                throw;
            }
        }


    }
}
