#include "weatherreport.h"
#include <string.h>

const char* Report(const struct WeatherSensor* sensor)
{
    int precipitation = sensor->Precipitation();
    const char* report = "Sunny Day";

    if (sensor->TemperatureInC() > 25) {
        if (precipitation >= 20 && precipitation < 60) {
            report = "Partly Cloudy";
        } else if (sensor->WindSpeedKMPH() > 50) {
            report = "Alert, Stormy with heavy rain";
        }
    }
    return report;
}
