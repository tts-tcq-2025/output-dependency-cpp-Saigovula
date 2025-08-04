#include <stdio.h>
#include <string.h>
#include <assert.h>

int printColorMap(char* buffer, size_t bufferSize) {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    int i = 0, j = 0;
    size_t offset = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            offset += snprintf(buffer + offset, bufferSize - offset, "%d | %s | %s\n", i * 5 + j, majorColor[i], minorColor[i]);
        }
    }
    return i * j;
}

void testPrintColorMap() {
    char output[1024] = {0};
    int result = printColorMap(output, sizeof(output));
    const char* expectedOutput = 
        "0 | White | Blue\n" "1 | White | Orange\n" "2 | White | Green\n" "3 | White | Brown\n" "4 | White | Slate\n" "5 | Red | Blue\n" "6 | Red | Orange\n"
        "7 | Red | Green\n" "8 | Red | Brown\n" "9 | Red | Slate\n" "10 | Black | Blue\n""11 | Black | Orange\n" "12 | Black | Green\n" "13 | Black | Brown\n"
        "14 | Black | Slate\n" "15 | Yellow | Blue\n" "16 | Yellow | Orange\n" "17 | Yellow | Green\n" "18 | Yellow | Brown\n" "19 | Yellow | Slate\n" "20 | Violet | Blue\n"
        "21 | Violet | Orange\n" "22 | Violet | Green\n" "23 | Violet | Brown\n" "24 | Violet | Slate\n";
    
    printf("\nPrint color map test\n");
    assert(strcmp(output, expectedOutput) == 0);
    assert(result == 25);
    printf("All is well (maybe!)\n");
}

int main() {
    testPrintColorMap();
    return 0;
}
