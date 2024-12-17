

#ifndef TREASURE_H
#define TREASURE_H
typedef struct {
    char* name; // Item name.
    int healthContribution; // Properties of item.
    int attackContribution;
} Treasure;

Treasure* createTreasure (const char* name, int healthContribution, int attackContribution);// This method will create treasure item.
void freeTreasure (Treasure* treasure);// This method will release treasure item.
#endif //TREASURE_H
