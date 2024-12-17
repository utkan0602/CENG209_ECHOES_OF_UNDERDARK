
#include "Characters.h"
#include "Trap.h"
#include "Monsters.h"
#include "Treasure.h"
#include "NPC.h"


#ifndef ROOMS_H
#define ROOMS_H

typedef struct {
    char* name; // Name of the room.
    Monster* monster; // Monster in the room.
    Treasure* treasure; // Treasure in the room.
    Trap* trap; // Trap in the room.
    NPC* npc; // Add NPC.
    int isThereMonster;
    int isThereTreasure;
    int isThereTrap;
    int isThereNPC;
    int isCleaned;
} Room;

typedef struct {
    char* name;
    Room* northRoom;
    Room* eastRoom;
    Room* westRoom;
    Room* southRoom;
} Transition;

Room* globalRoomArray[9];
Transition* globalTransitionArray[3];
#endif //ROOMS_H
void setupTransitions (Transition **spawnArea);
void processTransition(Transition **currentTransition, char *command, Character* player, Room** currentRoom);
void lookRooms (Transition** currentTransition, char* command);
Room* createRoom(const char* name, Monster* monster, Treasure* treasure, Trap* trap, NPC* npc, int boolMonster, int boolTreasure, int boolTrap, int boolNPC, int isCleaned);
void freeRoom (Room* room);
void getRoomDescription(const char* roomName);
void startBattleMechanicsm(Transition** currentTransition,Room** currentRoom, Character* player);
void battleChoiceMenu(void);
void addRoomToGlobalArray(Room* room);