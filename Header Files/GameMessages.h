

#ifndef GAMEMESSAGES_H
#define GAMEMESSAGES_H
#include "Characters.h"
#include "Monsters.h"
#include "Trap.h"

void gameStartMessage(); // Show the game start dialog.
void deadMessage(); // Show the dead message.
void winMessage(); // Show the win message for successfully finish game.
void welcomeDialog();  // Show the Character dialog for each character.
void movementDialog();
void movementHallDialog(char hall[50]);
void lookAroundDialog();
void lookRoomDialog(char direction[50], char currentHall[50]);
void defeatedMonsterMessage();
void showBattleDetail(Monster * monster, Character * player);
void trapMessage(Trap* trap, Character* player);
void getTreasureDescription(Treasure* treasure);
void saveMenuPrint();
#endif //GAMEMESSAGES_H
