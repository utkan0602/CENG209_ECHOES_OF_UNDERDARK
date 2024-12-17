#include "../Header Files/Trap.h"

#include <stdio.h>
#include <stdlib.h>

Trap* createTrap (const char* name, int healthDamage, int attackDamage) {
    Trap* trap = (Trap*) malloc(sizeof(Trap));

    if (trap == NULL) {
        fprintf(stderr, "Memory allocation has been failed while creating Trap.\n");
        exit(EXIT_FAILURE);
    }

    trap -> name = name;
    trap -> healthDamage = healthDamage;
    trap -> attackDamage = attackDamage;

    return trap;
}
void freeTrap (Trap* trap) {
    free(trap);
}
