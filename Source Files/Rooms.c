#include "../Header Files/Rooms.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../Header Files/Game.h"
#include "../Header Files/GameMessages.h"

Room* globalRoomArray[9];
Transition* globalTransitionArray[3];

int roomIndex = 0;
int transitionIndex = 0;

void addRoomToGlobalArray(Room* room) {
        globalRoomArray[roomIndex++] = room;
}
void addTransitionToGlobalArray(Transition* transition) {
        globalTransitionArray[transitionIndex++] = transition;
}

void setupTransitions(Transition **spawnArea) {

    // Big Saloon transitions.
    Transition *bigSaloon = (Transition *)malloc(sizeof(Transition));
    bigSaloon->name = strdup("Big Saloon (Spawn Area)");
    bigSaloon->northRoom = NULL;
    bigSaloon->eastRoom = NULL;
    bigSaloon->westRoom = NULL;
    bigSaloon->southRoom = NULL; // No hall for south.

    // North hall transitions.
    Transition *northTransition = (Transition *)malloc(sizeof(Transition));

    northTransition->name = strdup("North Transition");

    northTransition->eastRoom = createRoom("Room 1", createMonster("Cave Crawler", 100, 10, createTreasure("Attack Contribution", 0, 5)), createTreasure("Escape Pot", 0, 0), NULL, NULL, 1, 1, 0, 0, 0);
    addRoomToGlobalArray(northTransition->eastRoom);

    northTransition->westRoom = createRoom("Room 2", NULL, createTreasure("Underground of Bad Fortune", 15, 0), createTrap("Fate's Grasp", 0, 5), NULL, 0, 1, 1, 0, 0);
    addRoomToGlobalArray(northTransition->westRoom);


    northTransition->northRoom = createRoom("Room 3", createMonster("Grimfang", 250, 15, createTreasure("Mini Boss Award", 50, 25)), NULL, NULL, NULL, 1, 0, 0, 0, 0);
    addRoomToGlobalArray(northTransition->northRoom);


    northTransition->southRoom = (Room *)bigSaloon; // Geri dönüş salona

    // East hall transitions.
    Transition *eastTransition = (Transition *)malloc(sizeof(Transition));

    eastTransition->name = strdup("East Transition");

    eastTransition->southRoom = createRoom("Room 5", NULL, createTreasure("Regular Chest", 5, 5), NULL, NULL, 0, 1, 0, 0, 0);
    addRoomToGlobalArray(eastTransition->southRoom);


    eastTransition->eastRoom = createRoom("Room 6", createMonster("Gloomfang the Shadow Spinner", 125, 30, createTreasure("Stroke of Luck", 0, 5)), createTreasure("Mini Boss Award", 25, 50), NULL, NULL, 1, 1, 0, 0, 0);
    addRoomToGlobalArray(eastTransition->eastRoom);


    eastTransition->northRoom = createRoom("Room 4", createMonster("Stone Golem", 100, 20, NULL), NULL , NULL, NULL, 1, 0, 0, 0, 0);
    addRoomToGlobalArray(eastTransition->northRoom);


    eastTransition->westRoom = (Room *)bigSaloon;

    // West hall transitions.
    Transition *westTransition = (Transition *)malloc(sizeof(Transition));

    westTransition->name = strdup("West Transition");

    westTransition->northRoom = createRoom("Room 10", NULL, createTreasure("Staff of Luminous Grace", 0, 0), createTrap("Betray Damage", 100, 10), NULL, 0, 1, 1, 0, 0);
    addRoomToGlobalArray(westTransition->northRoom);


    westTransition->westRoom = createRoom("Room 12", createMonster("Thal'gorath, the Earthbound Wraith", 500, 50, NULL), NULL, NULL, NULL, 1, 0, 0, 0, 0);
    addRoomToGlobalArray(westTransition->westRoom);


    westTransition->southRoom = createRoom("Room 11", NULL, NULL, NULL, createNPC("Elyra, the Lost Healer", "Staff of Luminous Grace", NULL), 0, 0, 0, 1, 0);
    addRoomToGlobalArray(westTransition->southRoom);


    westTransition->eastRoom = (Room *)bigSaloon; // Geri dönüş salona
    addRoomToGlobalArray(westTransition->eastRoom);
    // Transitions from big saloon.
    bigSaloon->northRoom = (Room *)northTransition;
    bigSaloon->eastRoom = (Room *)eastTransition;
    bigSaloon->westRoom = (Room *)westTransition;

    addTransitionToGlobalArray(northTransition);
    addTransitionToGlobalArray(eastTransition);
    addTransitionToGlobalArray(westTransition);


    *spawnArea = bigSaloon; // Spawn Point.
}



void startBattleMechanicsm(Transition** currentTransition, Room** currentRoom, Character* player) {
     if ((*currentRoom)-> isThereMonster) {
        printf("\n============ YOU'VE ENCOUNTERED A MONSTER, FIGHT, DIE OR RUN ! ============ \n");
        enterToGo();
        char operation[50];



        while (1) {
            battleChoiceMenu(); // Print menu of the battle.

            // Kullanıcının input alması için fgets ve yeni satır temizleme işlemi.
            if (fgets(operation, sizeof(operation), stdin) == NULL) {
                printf("Error reading input.\n");
                continue;
            }
            operation[strcspn(operation, "\n")] = '\0'; // newline karakterini temizle

            if (operation[0] == '1') { // Choose to fight.


                printf("\n\n ! ! ! ! ! THE BATTLE HAS STARTED SHOW YOUR SKILLS ! ! ! ! !\n\n");
                clearBuffer();
                while ((*currentRoom)->monster->health > 0 && player->health > 0) { // Start battle

                    char attackType[1];

                    /*monsterDetailedInformations((*currentRoom)->monster);
                    show_detailed_informations(player);*/

                    showBattleDetail((*currentRoom)->monster, player);

                    printf("\n----------> Head or Tail ? (H/T) <----------\n");

                    scanf("%c", &attackType[0]);
                    operation[strcspn(operation, "\n")] = '\0';


                    int headTail = headOrTail(); // H = 0 , T = 1

                    clearBuffer();
                    if ((attackType[0] == 'H' || attackType[0] == 'h') && headTail == 0) {
                        printf("\nCORRECT GUESS ! You attacked %d !\n", player->attack);
                        (*currentRoom)->monster->health -= player->attack;
                        enterToGo();
                    }
                    else if ((attackType[0] == 'T' || attackType[0] == 't') && headTail == 1) {
                        printf("\nCORRECT GUESS ! You attacked %d !\n", player->attack);
                        (*currentRoom)->monster->health -= player->attack;
                        enterToGo();
                    } else {
                        printf("\nWRONG GUESS ! The monster dealt %d damage to you !\n", (*currentRoom)->monster->attack);
                        player->health -= (*currentRoom)->monster->attack;
                        enterToGo();
                    }
                }

                if (player->health <= 0) {
                    deadMessage();
                    free_everything(player, currentTransition, currentRoom);
                    exit(EXIT_SUCCESS); // Game over.
                }
                if ((*currentRoom)->monster->health <= 0) {
                    if (strcmp((*currentRoom)->monster->name, "Thal'gorath, the Earthbound Wraith.") == 0) {
                        winMessage();
                        enterToGo();
                        free_everything(player, currentTransition, currentRoom);
                        exit(EXIT_SUCCESS);
                    }
                    defeatedMonsterMessage();
                    enterToGo();
                    break;
                }
            }

            else if (operation[0] == '2') { // Choose to run away.  // Bu kısıma ekstradan yazı tura ile kaçma eklenilebilir. Kaçamazsa %20 can gitsin.
                if (player->inventory_count == 0) { // If inventory empty.
                    printf("\n --> I can not run from the monster... I don't have an item...");
                } else {
                    if (search_in_inventory(player, "Escape Pot")) { // If player has it in inventory.
                        remove_item_from_inventory(player, "Escape Pot");
                        printf("\n You've Escaped from %s !!\n", (*currentRoom) -> name);
                        (*currentRoom) = NULL;
                        return;
                    }
                    printf("\n\n--> Oh my god, just when I wanted to escape I didn't have any escape potions!");
                }
            }
            else { // Invalid op.
                printf("Invalid Operation !\n");
            }
        }
         if ((*currentRoom) -> monster -> treasure != NULL) {
             // That mean Monster has a treasure.
             printf("\n >>>>>>>>>>>>>>>>>> Monster dropped a treasure ! <<<<<<<<<<<<<<<:\n");
             printf("\n=>Attack Contribution: %d\n", (*currentRoom) -> monster -> treasure -> attackContribution);
             printf("=>Health Contribution: %d\n", (*currentRoom) -> monster -> treasure -> healthContribution);

             player -> health += (*currentRoom) -> monster -> treasure -> healthContribution; // Add contributions to the player.
             player -> attack += (*currentRoom) -> monster -> treasure -> attackContribution;

             enterToGo();

             freeMonster((*currentRoom) -> monster); // Free allocated memory.
         }
         else {
             freeMonster((*currentRoom) -> monster); // Free allocated memory.
         }
    }
     if((*currentRoom) -> isThereTrap) {
         if (strcmp((*currentRoom) -> trap -> name, "Betray Damage") == 0 && player -> isQuestAccept == 0) {
            trapMessage((*currentRoom) -> trap, player);
         }
         else if (strcmp((*currentRoom) -> trap -> name, "Betray Damage") != 0) {
             trapMessage((*currentRoom) -> trap, player);
         }

         if (player -> health <= 0) {
             deadMessage();
             free_everything(player, currentTransition, currentRoom);
         }

         if (player -> attack <= 0) {
             player->attack = 1;
         }

         freeTrap((*currentRoom) -> trap); // Free allocated memory.
    }
     if ((*currentRoom) -> isThereTreasure) {

        char operation[20];

        printf("\n__________________>>>>> YEEESS ! A chest. Let's see what's inside. <<<<<__________________\n");
        enterToGo();

        while (1) {
            getTreasureDescription((*currentRoom)->treasure);

            // Kullanıcıdan giriş al.
            printf("\nType 'pick up' to take the treasure or 'leave' to leave it: ");
            if (fgets(operation, sizeof(operation), stdin) == NULL) {
                printf("Error reading input.\n");
                continue;
            }
            operation[strcspn(operation, "\n")] = '\0'; // Satır sonunu temizle.

            // Kullanıcı seçimini kontrol et.
            if (strcmp(operation, "pick up") == 0) {
                printf("\nYou took the treasure!\n");
                add_item_to_inventory(player, (*currentRoom)->treasure->name);
                break;
            }
            if (strcmp(operation, "leave") == 0) {
                printf("\nYou left the treasure.\n");
                break;
            }
            printf("Invalid operation! Please type 'pick up' or 'leave'.\n");

        }
         freeTreasure((*currentRoom) -> treasure); // Free allocated memory.

    }
     if ((*currentRoom) -> isThereNPC) {
         printf("\nThe Dungeon takes you on a side quest, do you want to take it ? (Y/N): ");

         char command[10];
         fgets(command, sizeof(command), stdin);
         command[strcspn(command, "\n")] = '\0';

         if (strcmp(command,"Y") == 0 || strcmp(command,"y") == 0) {
             printf("\n>>>>>>> You accepted the side quest ! <<<<<<<<");
             printf("\n ---> I need to help this wizard...");
             enterToGoDialog();
             printf("\n ---> She lost her wand while fighting one of the monsters, and her life is seriously diminished without it.");
             enterToGoDialog();
             printf("\n ---> I need to find the Staff of Luminous Grace!\n");
             enterToGoDialog();
             if (search_in_inventory(player, "Staff of Luminous Grace")) {
                 printf("---> And I already have it !");
                 printf("\n= = = = You Completed The Side Quest = = = = =");
                 printf("\n- As a reward you took advantage against Final Boss !");
                 remove_item_from_inventory(player, "Staff of Luminous Grace");
                 globalRoomArray[7] -> monster -> health /= 2;
                 player -> isQuestAccept = 0;
             }
             else if (globalRoomArray[6] -> isCleaned){
                 printf("\n*** You left the \"Staff of Luminous Grace\" on Room 10... ***");
                 enterToGoDialog();
                 printf("\n*** You can not help to the wizard... ***");
                 player -> isQuestAccept = 0;
             }
             else {
                 printf("\n---> Let's find it !");
             }

         }
         else {
             if (search_in_inventory(player, "Staff of Luminous Grace")) {
                 printf("\nYou rejected the side quest... Be very, very careful about the items you take next time... Ohh, you already took it...\n");
                 printf("\n- You trapped by \"Betray Damage\" because of hiding the life of Wizard...");
                 printf("\n- You took a 100 Health and 10 Attack Damage ! Good luck.");
                 player -> health -= 100;
                 player -> attack -= 10;
                 player -> isQuestAccept = 0;
             }
             else {
                 printf("You rejected the side quest... Be very, very careful about the items you take next time...");
                 player ->isQuestAccept = 0;
             }

         }
     }

     if (strcmp((*currentRoom) -> name, "Room 11") == 0 && player -> isQuestAccept != 0) {
        (*currentRoom) = NULL;
        return;
    }

    (*currentRoom) ->isCleaned = 1;
    (*currentRoom) = NULL;



}
void battleChoiceMenu(void) {
    printf("\n_______________________\n");
    printf("\n1-) Fight !\n2-) Run !\n_______________________\n\nChoose Operation: ");

}

void processTransition(Transition **currentTransition, char *command, Character* player, Room** currentRoom) {
    if (strcmp(command, "move north") == 0) {
        if ((*currentTransition)->northRoom) {

            if ((*currentTransition)->northRoom->name[0] == 'R') {
                //////////
                if ((*currentTransition)->northRoom->isCleaned) {
                    printf("\n---> I've already cleaned this room...");
                    return;
                }
                else {
                    *currentRoom = (*currentTransition)->northRoom;
                    printf("\nYou have entered %s.\n", (*currentRoom)->name);
                }

            }
            else {
                *currentTransition = (Transition *)(*currentTransition)->northRoom;
            }
        } else {
            printf("I don't think I can get to this part...\n");
        }
    }
    else if (strcmp(command, "move south") == 0) {
        if ((*currentTransition)->southRoom) {
                /////////////
            if ((*currentTransition)->southRoom->name[0] == 'R') {
                if ((*currentTransition)->southRoom->isCleaned) {
                    printf("\n---> I've already cleaned this room...");
                    return;
                }
                else {
                    *currentRoom = (*currentTransition)->southRoom;
                    printf("\nYou have entered %s.\n", (*currentRoom)->name);
                }

            } else {
                *currentTransition = (Transition *)(*currentTransition)->southRoom;
            }
        } else {
            printf("I don't think I can get to this part...\n");
        }
    }
    else if (strcmp(command, "move east") == 0) {
        if ((*currentTransition)->eastRoom) {

            if ((*currentTransition)->eastRoom->name[0] == 'R') {
                ////////////
                if ((*currentTransition)->eastRoom->isCleaned) {
                    printf("\n---> I've already cleaned this room...");
                    return;
                }
                else {
                    *currentRoom = (*currentTransition)->eastRoom;
                    printf("\nYou have entered %s.\n", (*currentRoom)->name);
                }
            } else {
                *currentTransition = (Transition *)(*currentTransition)->eastRoom;
            }
        } else {
            printf("I don't think I can get to this part...\n");
        }
    }
    else if (strcmp(command, "move west") == 0) {
        if ((*currentTransition)->westRoom) {

                if ((*currentTransition)->westRoom->name[0] == 'R') {
                    ////////
                    if ((*currentTransition)->westRoom->isCleaned) {
                        printf("\n---> I've already cleaned this room...");
                        return;
                    }
                    else {
                        *currentRoom = (*currentTransition)->westRoom;
                        printf("\nYou have entered %s.\n", (*currentRoom)->name);
                    }

            }
            else {
                *currentTransition = (Transition *)(*currentTransition)->westRoom;
            }

        } else {
            printf("I don't think I can get to this part...\n");
        }
    }
    else {
        printf("\nCan you check the direction again ?");
    }

    if (*currentRoom) {

        startBattleMechanicsm(currentTransition, currentRoom, player);
    }

    else if (strcmp((*currentTransition)->name, "Big Saloon (Spawn Area)") == 0
        || strcmp((*currentTransition)->name, "West Transition") == 0
        || strcmp((*currentTransition)->name, "North Transition") == 0
        || strcmp((*currentTransition)->name, "East Transition") == 0) {
        movementHallDialog((*currentTransition)->name);
    }

}

void lookRooms (Transition** currentTransition, char* command) {
    if(strcmp((*currentTransition) -> name, "West Transition") == 0
       || strcmp((*currentTransition) -> name, "North Transition") == 0
       || strcmp((*currentTransition) -> name, "East Transition") == 0) {
        lookRoomDialog(command, (*currentTransition) -> name);
    }
    else {
        printf("\nThere is no room to look here. That's look like a transition area.");
    }
}

void getRoomDescription(const char* roomName) {

    FILE *file;              // Dosya pointer'ı
    char line[256];          // Dosyadan her satırı tutacak buffer
    char filePath[100];      // Dosya yolu

    // Dosya yolunu oluştur
    snprintf(filePath, sizeof(filePath), "../%s.txt", roomName);

    // Dosyayı okuma modunda aç
    file = fopen(filePath, "r");

    // Dosya başarıyla açıldı mı kontrol et
    if (file == NULL) {
        printf("Error: Unable to open the file (Room Description).\n");
        exit(EXIT_FAILURE);
    }

    // Dosyayı satır satır oku ve yazdır
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }

    // Dosyayı kapat
    fclose(file);
}

Room* createRoom(const char* name, Monster* monster, Treasure* treasure, Trap* trap, NPC* npc, int boolMonster, int boolTreasure, int boolTrap, int boolNPC, int isCleaned) {
    Room* room = (Room*) malloc(sizeof(Room));

    if (room == NULL) {
        fprintf(stderr, "Memory allocation has been failed while creating Room.\n");
        exit(EXIT_FAILURE);
    }

    room -> name = strdup(name);
    room -> monster = monster;
    room -> treasure = treasure;
    room -> trap = trap;
    room -> npc = npc;

    room ->isThereMonster = boolMonster;
    room ->isThereTrap = boolTrap;
    room ->isThereTreasure = boolTreasure;
    room ->isThereNPC = boolNPC;
    room -> isCleaned = 0;
    return room;
}


void freeRoom(Room* room) {
        if (room == NULL) return;

        room->isCleaned = 1;

        freeMonster(room -> monster);
        freeTrap(room -> trap);
        freeTreasure(room -> treasure);
        freeNPC(room -> npc);

        free(room->name);

        free(room);
}

