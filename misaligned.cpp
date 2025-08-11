#include "color_map.h"
#include <stdio.h>
#include <string.h>

// BUG: using minorColor[i] instead of minorColor[j]
void generateColorMap(struct ColorPair colorMap[]) {
    const char* majorColor[MAJOR_COLORS] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[MINOR_COLORS] = {"Blue", "Orange", "Green", "Brown", "Slate"};

    int count = 0;
    for (int i = 0; i < MAJOR_COLORS; i++) {
        for (int j = 0; j < MINOR_COLORS; j++) {
            colorMap[count].index = count + 1;
            colorMap[count].major = majorColor[i];
            colorMap[count].minor = minorColor[i]; // <-- BUG
            count++;
        }
    }
}

void generateOutputString(char *buffer, size_t bufSize, struct ColorPair colorMap[]) {
    buffer[0] = '\0'; // clear buffer
    char line[50];
    for (int i = 0; i < MAJOR_COLORS * MINOR_COLORS; i++) {
        snprintf(line, sizeof(line), "%d | %s | %s\n",
                 colorMap[i].index, colorMap[i].major, colorMap[i].minor);
        strncat(buffer, line, bufSize - strlen(buffer) - 1);
    }
}





