#include "../Header Files/Treasure.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Treasure* createTreasure (const char* name, int healthContribution, int attackContribution) {
    Treasure* treasure = (Treasure*) malloc(sizeof(treasure));

    if (treasure == NULL) {
        fprintf(stderr, "Memory allocation has been failed while creating Treasure Item.\n");
    }

    treasure -> name = strdup(name);
    treasure -> attackContribution = attackContribution;
    treasure -> healthContribution = healthContribution;

    return treasure;
}

void freeTreasure (Treasure* treasure) {
    free(treasure);
}
