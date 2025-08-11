#include "weatherreport.h"
#include <string.h>

const char* Report(const struct WeatherSensor *sensor) {
    int precipitation = sensor->Precipitation(sensor->impl);
    static char report[64] = "Sunny Day";

    if (sensor->TemperatureInC(sensor->impl) > 25) {
        if (precipitation >= 20 && precipitation < 60) {
            strcpy(report, "Partly Cloudy");
        } else if (sensor->WindSpeedKMPH(sensor->impl) > 50) {
            strcpy(report, "Alert, Stormy with heavy rain");
        }
    }
    return report;
}
