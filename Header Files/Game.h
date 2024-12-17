

#ifndef GAME_H
#define GAME_H
#include "../Header Files/Game.h"
#include <stdio.h>
#include <string.h>

#include "../Header Files/Characters.h"
#include "../Header Files/GameMessages.h"
#include "../Header Files/WelcomeScreen.h"
#include "../Header Files/CharacterChoosing.h"
#include "../Header Files/Rooms.h"
#include <stdlib.h>
#include <time.h>
#include "../Header Files/SaveManagement.h"


void gameLoop();
void enterToGo();
void enterToGoDialog();
void clearBuffer();
void runGame(Character* player);
void displayMenuChoose(Transition** currentTransition);
void choosenOperation(const char operation[50], Transition** currentTransition, Character* player, Room** currentRoom);
void moveAround(Transition** currentTransition, Character* player, Room** currentRoom);
void lookAround(Transition ** currentTransition);
void manageInventoryMenu(Character * player);
void removeItemMenu(Character* player);
int headOrTail();
void saveMenu(Room ** room, Transition ** transition, Character * player);
void saveProgress(Room ** room, Transition ** transition, Character * player, char* filename);
void loadGame(Character * player, char * filename);
void use_item_from_inventory(Character * player);
void use_item(const char * str, Character * player);
void free_everything(Character * player, Transition ** transition, Room ** room);
#endif //GAME_H
