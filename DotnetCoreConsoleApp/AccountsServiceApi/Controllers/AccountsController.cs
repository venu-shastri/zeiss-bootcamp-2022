using Microsoft.AspNetCore.Mvc;

// For more information on enabling Web API for empty projects, visit https://go.microsoft.com/fwlink/?LinkID=397860

namespace AccountsServiceApi.Controllers
{
    [Route("api/[controller]")]
    [ApiController]
    public class AccountsController : ControllerBase
    {
        static List<Models.IdentityModel> identityModels = new List<Models.IdentityModel>();
        // GET: api/accounts
        [HttpGet]
        public IEnumerable<Models.IdentityModel> Get()
        {
            return identityModels;
        }

        // GET api/accounts/tom
        [HttpGet("{name}")]
        public Models.IdentityModel Get(string name)
        {
            return null;
        }

        // POST api/accounts
        [HttpPost]
        public void Post([FromBody] Models.IdentityModel value)
        {
            identityModels.Add(value);
        }

        // PUT api/accounts/tom
        [HttpPut("{name}")]
        public void Put(string  name, [FromBody] Models.IdentityModel value)
        {
            //update
        }

        // DELETE api/accounts/tom
        [HttpDelete("{name}")]
        public void Delete(string  name)
        {
            //remove from the list
        }
    }
}
