#ifndef COLOR_MAP_H
#define COLOR_MAP_H

#define MAJOR_COLORS 5
#define MINOR_COLORS 5

struct ColorPair {
    int index;
    const char* major;
    const char* minor;
};

int printColourMap();

#endif
