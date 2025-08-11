#include <stdio.h>
#include <string.h>
#include "misaligned.h"

int main() {
    // --- 1. Generate actual output with bug ---
    struct ColorPair actualMap[MAJOR_COLORS * MINOR_COLORS];
    generateColorMap(actualMap);

    char actualOutput[1024];
    generateOutputString(actualOutput, sizeof(actualOutput), actualMap);

    // --- 2. Expected correct output ---
    const char* expectedOutput =
        "1 | White | Blue\n"
        "2 | White | Orange\n"
        "3 | White | Green\n"
        "4 | White | Brown\n"
        "5 | White | Slate\n"
        "6 | Red | Blue\n"
        "7 | Red | Orange\n"
        "8 | Red | Green\n"
        "9 | Red | Brown\n"
        "10 | Red | Slate\n"
        "11 | Black | Blue\n"
        "12 | Black | Orange\n"
        "13 | Black | Green\n"
        "14 | Black | Brown\n"
        "15 | Black | Slate\n"
        "16 | Yellow | Blue\n"
        "17 | Yellow | Orange\n"
        "18 | Yellow | Green\n"
        "19 | Yellow | Brown\n"
        "20 | Yellow | Slate\n"
        "21 | Violet | Blue\n"
        "22 | Violet | Orange\n"
        "23 | Violet | Green\n"
        "24 | Violet | Brown\n"
        "25 | Violet | Slate\n";

    // --- 3. Compare actual vs expected ---
    if (strcmp(actualOutput, expectedOutput) != 0) {
        printf("TEST FAILED: Bug detected in color map generation.\n");
        printf("\n--- Actual Output ---\n%s", actualOutput);
        printf("\n--- Expected Output ---\n%s", expectedOutput);
    } else {
        printf("TEST PASSED: No bug detected.\n");
    }

    return 0;
}
