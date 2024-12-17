#include "../Header Files/DungeonMap.h"
#include <stdio.h>
#include <stdlib.h>

void printMap() {
    FILE *file;
    char line[256]; // Buffer to hold each line of the file

    // Open the file in read mode
    file = fopen("../Dungeon Map.txt", "r");
    if (file == NULL) {
        printf("Error: Unable to open the file.\n");
        exit(EXIT_FAILURE);
    }

    // Read and print each line
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }

    // Close the file
    fclose(file);
}
