using Microsoft.AspNetCore.Http;
using Microsoft.AspNetCore.Mvc;

namespace DeviceMonitorServiceApiUsingController.Controllers
{
    [Route("api/[controller]")]
    [ApiController]

    //Service
    public class DeviceStatusController : ControllerBase
    {
        //Actions
        [HttpGet]
        public int Get()
        {
            DeviceStatusMonitorLib.DeviceMonitor _monitorRef = new DeviceStatusMonitorLib.DeviceMonitor();
            return _monitorRef.GetDeviceStatusCode();
        }

        
    }
}
