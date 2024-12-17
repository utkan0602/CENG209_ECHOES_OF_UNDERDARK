#include "Treasure.h"

#ifndef NPC_H
#define NPC_H
typedef struct {
    char* name; // Name of the NPC.
    char* item; // Necessary item that NPC needs.
    Treasure* treasure; // Treasure that NPC will give.
}NPC;

NPC* createNPC(const char* name, const char* item, Treasure* treasure); // This method will create NPC.
void freeNPC(NPC* npc); // This method will release NPC.
#endif //NPC_H
