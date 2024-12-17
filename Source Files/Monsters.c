#include "../Header Files/Monsters.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Monster* createMonster(const char* name, int health, int attack, Treasure* treasure) {
    Monster* monster = (Monster*) malloc(sizeof(Monster)); // Allocate memory for monster.
    if (monster == NULL) {
        fprintf(stderr, "Memory allocation has been failed while creating Monster NPC.\n"); // Error message.
        exit(EXIT_FAILURE); // Close the program with failure.
    }

    monster -> name = strdup(name);
    monster -> health = health;
    monster -> attack = attack;
    monster -> treasure = treasure; // The treasure that monster will drop after die.

    return monster; // Return the monster npc.
}
void monsterDetailedInformations(Monster* monster) {
    printf("\n====================================\n");
    printf("         CURRENT MONSTER STATS\n");
    printf("=> MONSTER HEALTH: %d\n", monster->health);
    printf("=> MONSTER ATTACK: %d\n", monster->attack);
    printf("\n====================================\n");
}
void freeMonster(Monster* monster) {
    free(monster);
}
