var builder = WebApplication.CreateBuilder(args);
var app = builder.Build();

//endpoint registration
// http://localhost:5281/devicestatus
// http-action - get (select) ,post (create,new) ,put (update) ,delete (remove)


//minimal api
app.MapGet("/devicestatus", () => {

    //invoke reusable code 
    DeviceStatusMonitorLib.DeviceMonitor _deviceMonitor = new DeviceStatusMonitorLib.DeviceMonitor();
    return _deviceMonitor.GetDeviceStatusCode();

});

app.MapGet("/add/{x}/{y}", (int x, int y) => { return x + y; });


app.Run();
