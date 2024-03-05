using api_integration_crud.Models;
using Microsoft.AspNetCore.Mvc;
using Newtonsoft.Json;
using Newtonsoft.Json.Linq;
using System.Text;

namespace api_integration_crud.Controllers
{
    public class ProductController : Controller
    {

        private readonly IHttpClientFactory _httpClientFactory;

        public ProductController(IHttpClientFactory httpClientFactory)
        {
            _httpClientFactory = httpClientFactory;
        }
 

        public async Task<IActionResult> List()
        {
            try
            {
                var httpClient = _httpClientFactory.CreateClient();

                httpClient.BaseAddress = new Uri("http://192.168.11.107:8082/");

                var response = await httpClient.GetAsync("api/Products");

                if (response.IsSuccessStatusCode)
                {
                    var responseData = await response.Content.ReadAsStringAsync();
                    var products = JsonConvert.DeserializeObject<List<Product>>(responseData);

                    return View(products);
                }
                else
                {
                    return RedirectToAction("Error");
                }
            }
            catch (Exception ex)
            {
                return RedirectToAction("Error");
            }
        }
        [HttpPost]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> Create(Product product)
        {
            try
            {
                var httpClient = _httpClientFactory.CreateClient();

                httpClient.BaseAddress = new Uri("http://192.168.11.107:8082/");

                var jsonProduct = JsonConvert.SerializeObject(product);

                var content = new StringContent(jsonProduct, Encoding.UTF8, "application/json");

                var response = await httpClient.PostAsync("api/Products", content);

                if (response.IsSuccessStatusCode)
                {
                    return RedirectToAction("List");
                }
                else
                {
                    return View("Error");
                }
            }
            catch (Exception ex)
            {
                return RedirectToAction("Error");
            }
        }

        public IActionResult Create()
        {
            return View();
        }

        public async Task<IActionResult> Edit(int id)
        {
            var httpClient = _httpClientFactory.CreateClient();
            var apiUrl = $"http://192.168.11.107:8082/api/Products/{id}";

            var response = await httpClient.GetAsync(apiUrl);
            if (response.IsSuccessStatusCode)
            {
                var productdata = await response.Content.ReadAsStringAsync();
                //dynamic deserializedResponse = JsonConvert.DeserializeObject(productdata);
                //dynamic productData = deserializedResponse.data;
              

                ViewBag.ProductId = id;

                return View("Edit", productdata);
            }
            else
            {
                return View("Error");
            }
        }
        [HttpPost]
        public async Task<IActionResult> Edit(IFormCollection formData)
        {
            var id = formData["Id"];

            var updatedProductData = new Dictionary<string, string>();
            for (int i = 0; i < formData.Count; i++)
            {
                string field = formData.Keys.ElementAt(i);
                string value = formData[field];
                updatedProductData.Add(field, value);
            }
            var jsonData = JsonConvert.SerializeObject(updatedProductData);

            var httpClient = _httpClientFactory.CreateClient();
            var apiUrl = $"http://192.168.11.107:8082/api/Products/{id}";

            var content = new StringContent(jsonData, Encoding.UTF8, "application/json");

            var response = await httpClient.PutAsync(apiUrl, content);
            if (response.IsSuccessStatusCode)
            {
                return RedirectToAction("Index");
            }
            else
            {
                return View("Error");
            }
        }
        public async Task<IActionResult> Details(int id)
        {
            try
            {
                var httpClient = _httpClientFactory.CreateClient();
                httpClient.BaseAddress = new Uri("http://192.168.11.107:8082/");

                var response = await httpClient.GetAsync($"api/Products/{id}");

                if (response.IsSuccessStatusCode)
                {
                    var responseData = await response.Content.ReadAsStringAsync();
                    dynamic responseObject = JsonConvert.DeserializeObject(responseData);

                    if (responseObject.status == 200 && responseObject.data != null)
                    {
                        var product = new Product
                        {
                            ProductId = responseObject.data.productId,
                            ProductName = responseObject.data.productName,
                            Description = responseObject.data.description,
                            Price = responseObject.data.price
                        };

                        return View(product);
                    }
                    else
                    {
                        return View("Error");
                    }
                }
                else
                {
                    return View("Error");
                }
            }
            catch (Exception ex)
            {
                return RedirectToAction("Error");
            }
        }

        public IActionResult DeleteConfirm(int id)
        {
            ViewBag.UserId = id; 
            return View("Delete");
        }


        [HttpPost, ActionName("Delete")]
        public async Task<IActionResult> Delete(int id)
        {
            try
            {
                var httpClient = _httpClientFactory.CreateClient();
                var response = await httpClient.DeleteAsync($"http://192.168.11.107:8082/api/Products/{id}");

                if (response.IsSuccessStatusCode)
                {
                    return RedirectToAction("List"); 
                }
                else
                {
                    TempData["ErrorMessage"] = "Failed to delete product"; 
                    return RedirectToAction("List");
                }
            }
            catch (HttpRequestException ex)
            {
                TempData["ErrorMessage"] = "Internal server error";
                return RedirectToAction("List");
            }
        }

    }

}

