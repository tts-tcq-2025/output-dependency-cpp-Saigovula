#include "weatherreport.h"
#include <assert.h>
#include <string.h>
#include <stdio.h>

// Declaration from weather_stub.c
struct WeatherSensor CreateStubSensor(double t, int p, int h, int w);

void TestWeatherScenarios() {
    // Case 1: Stormy rainy day
    struct WeatherSensor stormy = CreateStubSensor(26.0, 70, 72, 52);
    const char* report1 = Report(&stormy);
    printf("Report1: %s\n", report1);
    assert(strstr(report1, "rain") != NULL);

    // Case 2: High precipitation, low wind (bug check)
    struct WeatherSensor highPrecip = CreateStubSensor(26.0, 70, 72, 40);
    const char* report2 = Report(&highPrecip);
    printf("Report2: %s\n", report2);
    assert(strlen(report2) > 0);
}

int main() {
    TestWeatherScenarios();
    printf("All is well (maybe)\n");
    return 0;
}
