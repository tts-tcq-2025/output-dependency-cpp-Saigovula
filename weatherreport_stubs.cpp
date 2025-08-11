#include "weatherreport.h"

// Stub data struct
struct StubData {
    double temp;
    int precip;
    int humidity;
    int wind;
};

// Stub method implementations
static double Stub_Temp(const void* impl) {
    return ((struct StubData*)impl)->temp;
}
static int Stub_Precip(const void* impl) {
    return ((struct StubData*)impl)->precip;
}
static int Stub_Humidity(const void* impl) {
    return ((struct StubData*)impl)->humidity;
}
static int Stub_Wind(const void* impl) {
    return ((struct StubData*)impl)->wind;
}

// Helper to create stub sensor
struct WeatherSensor CreateStubSensor(double t, int p, int h, int w) {
    static struct StubData data;
    data.temp = t;
    data.precip = p;
    data.humidity = h;
    data.wind = w;

    struct WeatherSensor sensor = {
        .TemperatureInC = Stub_Temp,
        .Precipitation = Stub_Precip,
        .Humidity = Stub_Humidity,
        .WindSpeedKMPH = Stub_Wind,
        .impl = &data
    };
    return sensor;
}
