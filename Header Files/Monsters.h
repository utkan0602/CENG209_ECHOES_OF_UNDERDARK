#include "Treasure.h"

#ifndef MONSTERS_H
#define MONSTERS_H

typedef struct  {
    char* name;
    int health;
    int attack;
    Treasure* treasure;
} Monster;

Monster* createMonster(const char* name, int health, int attack, Treasure* treasure); // This method will create a monster npc.
void monsterDetailedInformations(Monster* monster);
void freeMonster(Monster* monster); // This method will release the monster after defeating.

#endif //MONSTERS_H
