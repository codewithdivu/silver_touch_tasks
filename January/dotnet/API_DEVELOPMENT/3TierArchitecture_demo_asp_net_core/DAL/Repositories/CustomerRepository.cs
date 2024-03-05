using DAL.Contracts;
using DAL.Data;
using DAL.Models;


namespace DAL.Repositories
{
    public class CustomerRepository : IRepository<Customer>
    {
        private readonly CustomerDbContext _CustomerDbContext;

        public CustomerRepository(CustomerDbContext customerDbContext)
        {
            _CustomerDbContext = customerDbContext;
        }

        public  Customer Create(Customer customer)
        {
            try
            {
                if (customer != null)
                {
                    var obj = _CustomerDbContext.Customers.Add(customer);
                    if (obj != null)
                        _CustomerDbContext.SaveChanges();
                    return obj.Entity;
                }
                else
                {
                    return null;
                }
            }
            catch (Exception)
            {
                throw;
            }
        }

        public async void Delete(int id)
        {
            try
            {
                if (id != null)
                {
                    var ob1 = await _CustomerDbContext.Customers.FindAsync(id);
                    var obj =  _CustomerDbContext.Customers.Remove(ob1);
                    if (obj != null)
                        _CustomerDbContext.SaveChangesAsync();
                }
            }
            catch (Exception)
            {
                throw;
            }
        }

        public IEnumerable<Customer> GetAll()
        {
            try
            {
                var obj = _CustomerDbContext.Customers.ToList();
                if (obj != null)
                    return obj;
                else
                    return null;
            }
            catch (Exception)
            {
                throw;
            }
        }

        public Customer GetById(int Id)
        {
            try
            {
                if (Id != null)
                {
                    var Obj = _CustomerDbContext.Customers.FirstOrDefault(x => x.CustomerId == Id);
                    if (Obj != null)
                        return Obj;
                    else
                        return null;
                }
                else
                {
                    return null;
                }
            }
            catch (Exception)
            {
                throw;
            }
        }

        public void Update(Customer customer)
        {
            try
            {
                if (customer != null)
                {
                    var obj = _CustomerDbContext.Customers.Update(customer);
                    if (obj != null)
                        _CustomerDbContext.SaveChanges();
                }
            }
            catch (Exception)
            {
                throw;
            }
        }
    }
}
