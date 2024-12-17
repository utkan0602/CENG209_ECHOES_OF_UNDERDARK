

#ifndef WARRIOR_H
#define WARRIOR_H
#include "Characters.h"

typedef struct {
    Character base; // Get the character  for wizard.
} Warrior;

Warrior* createWarrior();
#endif //WARRIOR_H
