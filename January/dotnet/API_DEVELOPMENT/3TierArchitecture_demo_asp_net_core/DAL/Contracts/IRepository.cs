using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DAL.Contracts
{
    public interface IRepository<T>
    {
        public T Create(T _object);
        public async void Delete(int Id);

        public void Update(T _object);

        public IEnumerable<T> GetAll();

        public T GetById(int Id);

    }
}
