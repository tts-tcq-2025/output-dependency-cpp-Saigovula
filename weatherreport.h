#ifndef WEATHERREPORT_H
#define WEATHERREPORT_H

struct WeatherSensor {
    double (*TemperatureInC)(void);
    int    (*Precipitation)(void);
    int    (*Humidity)(void);
    int    (*WindSpeedKMPH)(void);
};

const char* Report(const struct WeatherSensor* sensor);

#endif
