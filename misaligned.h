#ifndef COLOR_MAP_H
#define COLOR_MAP_H

#define MAJOR_COLORS 5
#define MINOR_COLORS 5

struct ColorPair {
    int index;
    const char* major;
    const char* minor;
};

// Function to generate the (buggy) color map
void generateColorMap(struct ColorPair colorMap[]);

// Generate the color map output as a single string
void generateOutputString(char *buffer, size_t bufSize, struct ColorPair colorMap[]);

#endif
