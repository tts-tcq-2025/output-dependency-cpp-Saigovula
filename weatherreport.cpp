#include "weatherreport.h"

const char* Report(IWeatherSensor* sensor) {
    int precipitation = sensor->Precipitation(sensor);
    const char* report = "Sunny Day";

    if (sensor->TemperatureInC(sensor) > 25) {
        if (precipitation >= 20 && precipitation < 60) {
            report = "Partly Cloudy";
        } else if (sensor->WindSpeedKMPH(sensor) > 50) {
            report = "Alert, Stormy with heavy rain";
        }
    }
    return report;
}
