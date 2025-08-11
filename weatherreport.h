#ifndef WEATHER_H
#define WEATHER_H

struct WeatherSensor {
    double (*TemperatureInC)(const void*);
    int    (*Precipitation)(const void*);
    int    (*Humidity)(const void*);
    int    (*WindSpeedKMPH)(const void*);
    const void *impl;  // Pointer to actual implementation
};

const char* Report(const struct WeatherSensor *sensor);

#endif
