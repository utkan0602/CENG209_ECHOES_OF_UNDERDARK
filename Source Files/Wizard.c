#include "../Header Files/Wizard.h"


#include <stdlib.h>
#include <stdio.h>

Wizard* createWizard() {
    // Allocate memory for a Wizard
    Wizard* wizard = malloc(sizeof(Wizard));

    if (!wizard) { // Prevent memory allocation fail.
        fprintf(stderr, "Memory allocation failed for Wizard.\n");
        return NULL;
    }
    initialize_character((Character*)wizard,250, 50, 3, 1); // Customize as needed
    return wizard;
}
