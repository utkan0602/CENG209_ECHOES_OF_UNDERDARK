#include "../Header Files/Warrior.h"


#include <stdlib.h>
#include <stdio.h>

Warrior* createWarrior() {
    // Allocate memory for a Wizard
    Warrior* warrior = malloc(sizeof(Warrior));

    if (!warrior) { // Prevent memory allocation fail.
        fprintf(stderr, "Memory allocation failed for Warrior.\n");
        return NULL;
    }
    initialize_character((Character*)warrior,400, 35, 5, 1); // Customize as needed
    return warrior;
}