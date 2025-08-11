#ifndef WEATHER_H
#define WEATHER_H

// Abstract interface for weather sensor in C
typedef struct IWeatherSensor {
    double (*TemperatureInC)(struct IWeatherSensor* self);
    int (*Precipitation)(struct IWeatherSensor* self);
    int (*Humidity)(struct IWeatherSensor* self);
    int (*WindSpeedKMPH)(struct IWeatherSensor* self);
} IWeatherSensor;

// Returns a weather report string based on sensor readings
const char* Report(IWeatherSensor* sensor);

#endif
