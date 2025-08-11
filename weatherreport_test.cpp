#include "weatherreport.h"
#include <assert.h>
#include <stdio.h>

// --- Stub Sensor Implementations ---

typedef struct {
    IWeatherSensor base;
} SensorStubNormal;

double StubNormal_Temperature(IWeatherSensor* self) { return 26; }
int StubNormal_Precipitation(IWeatherSensor* self) { return 70; }
int StubNormal_Humidity(IWeatherSensor* self) { return 72; }
int StubNormal_Wind(IWeatherSensor* self) { return 52; }

SensorStubNormal CreateSensorStubNormal() {
    SensorStubNormal stub;
    stub.base.TemperatureInC = StubNormal_Temperature;
    stub.base.Precipitation = StubNormal_Precipitation;
    stub.base.Humidity = StubNormal_Humidity;
    stub.base.WindSpeedKMPH = StubNormal_Wind;
    return stub;
}

// Stub that exposes the bug
typedef struct {
    IWeatherSensor base;
} SensorStubBugExpose;

double StubBug_Temperature(IWeatherSensor* self) { return 30; }
int StubBug_Precipitation(IWeatherSensor* self) { return 80; }
int StubBug_Humidity(IWeatherSensor* self) { return 65; }
int StubBug_Wind(IWeatherSensor* self) { return 40; }

SensorStubBugExpose CreateSensorStubBugExpose() {
    SensorStubBugExpose stub;
    stub.base.TemperatureInC = StubBug_Temperature;
    stub.base.Precipitation = StubBug_Precipitation;
    stub.base.Humidity = StubBug_Humidity;
    stub.base.WindSpeedKMPH = StubBug_Wind;
    return stub;
}

// --- Tests ---

void TestRainy() {
    SensorStubNormal stub = CreateSensorStubNormal();
    const char* report = Report((IWeatherSensor*)&stub);
    printf("TestRainy: %s\n", report);
    assert(strstr(report, "rain") != NULL);
}

void TestBugExposure() {
    SensorStubBugExpose stub = CreateSensorStubBugExpose();
    const char* report = Report((IWeatherSensor*)&stub);
    printf("TestBugExposure: %s\n", report);
    assert(strstr(report, "rain") != NULL); // This should fail
}

int main() {
    printf("\nWeather report tests\n");
    // TestRainy(); // Passes
    TestBugExposure(); // Fails — bug exposed
    printf("All is well (maybe)\n");
    return 0;
}
