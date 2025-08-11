#include "weatherreport.h"
#include <assert.h>
#include <string.h>
#include <stdio.h>

/* ---- Test Stub Sensor Implementations ---- */
static double temp_high(void) { return 26.0; }
static double temp_low(void)  { return 20.0; }

static int precip_high(void)  { return 70; }  // should trigger "rain"
static int precip_low(void)   { return 30; }

static int humidity_mid(void) { return 72; }

static int wind_high(void)    { return 52; }
static int wind_low(void)     { return 20; }

/* Combined test function */
void testWeatherReport(void)
{
    struct WeatherSensor rainy_stub = { temp_high, precip_high, humidity_mid, wind_low };
    struct WeatherSensor cloudy_stub = { temp_high, precip_low, humidity_mid, wind_low };

    const char* report_rainy = Report(&rainy_stub);
    const char* report_cloudy = Report(&cloudy_stub);

    printf("Rainy case: %s\n", report_rainy);
    printf("Cloudy case: %s\n", report_cloudy);

    /* This will fail because of the bug — no “rain” in output */
    assert(strstr(report_rainy, "rain") != NULL);
    assert(strlen(report_cloudy) > 0);
}

int main(void) {
    testWeatherReport();
    return 0;
}
