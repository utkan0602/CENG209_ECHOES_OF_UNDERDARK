#include "../Header Files/NPC.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

NPC* createNPC(const char* name, const char* item, Treasure* treasure) {
    NPC* npc = (NPC*) malloc(sizeof(NPC));

    if (npc == NULL) {
        fprintf(stderr, "Memory allocation has been failed while creating NPC.\n");
    }

    npc -> name = strdup(name);
    npc -> item = strdup(item);
    npc -> treasure = treasure; // Treasure that npc will give.

    return npc;
}

void freeNPC(NPC* npc) {
    free(npc); // Release npc.
}
