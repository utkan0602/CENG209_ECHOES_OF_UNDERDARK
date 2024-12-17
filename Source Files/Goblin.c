#include "../Header Files/Goblin.h"


#include <stdlib.h>
#include <stdio.h>

Goblin* createGoblin() {
    // Allocate memory for a Wizard
    Goblin* goblin = malloc(sizeof(Goblin));

    if (!goblin) { // Prevent memory allocation fail.
        fprintf(stderr, "Memory allocation failed for Goblin.\n");
        return NULL;
    }
    initialize_character((Character*)goblin,200, 40, 7, 1); // Customize as needed
    return goblin;
}