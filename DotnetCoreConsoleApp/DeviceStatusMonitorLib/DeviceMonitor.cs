namespace DeviceStatusMonitorLib
{
    public class DeviceMonitor
    {
        public int GetDeviceStatusCode()
        {
            return new System.Random().Next(1000, 2000);
        }

    }
}