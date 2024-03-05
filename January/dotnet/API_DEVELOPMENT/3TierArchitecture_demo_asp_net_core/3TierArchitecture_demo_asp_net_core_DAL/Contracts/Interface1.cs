using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _3TierArchitecture_demo_asp_net_core_DAL.Contracts
{
    public interface IRepository<T>
    {
        public Task<T> Create(T _object);
        public void Delete(T _object);

        public void Update(T _object);

        public IEnumerable<T> GetAll();

        public T GetById(int Id);

    }
}
