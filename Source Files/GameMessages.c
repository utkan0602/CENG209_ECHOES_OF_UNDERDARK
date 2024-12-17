#include "../Header Files/GameMessages.h"
#include "../Header Files/TextHeaderCreator.h"
#include "../Header Files/Game.h"
#include "../Header Files/DungeonMap.h"
#include <stdio.h>

void gameStartMessage() {
    printTop(212);
    printf("\nECHOES OF THE UNDERDARK: Prologue\n\n");
    printf("The heavy air reeks of damp earth and faint traces of decay. You awaken to the sound of distant echoes—a haunting symphony of dripping water, skittering claws, and whispers that seem to speak directly into your soul. You’re in the depths of the Underdark, a sprawling labyrinth of ancient ruins and treacherous caverns, where the shadows themselves seem alive.\n\n");
    printf("Legends tell of the Heart of Nyx, an artifact of unimaginable power, hidden deep within the dungeon. Many have sought it, lured by the promise of wealth, power, or redemption. None have returned. Some say the dungeon is cursed, a living entity that reshapes itself to challenge those who dare to enter.\n\n");
    printf("You are no ordinary adventurer. Armed with your wits, courage, and a weapon forged by your past, you’ve descended into the abyss, determined to uncover the secrets of this forsaken place. But beware: every choice you make could be your last. The dungeon watches. It learns. It hungers.\n\n");
    printf("Will you conquer the darkness or become another forgotten echo?\n");
    printDown(212);
}
void deadMessage() {
    printf("\n= = = = You fall to the cold, unforgiving stone floor. = = =\n");
    printf("= = = = The last breath escapes your lips, and darkness closes in around you. = = = = \n");
    printf("= = = = The echoes of your struggle fade into the depths of the dungeon, unheard. = = = = \n");
    printf("= = = = In the end, you were just another forgotten soul, swallowed by the abyss. = = = = \n\n");
    printf("= = = = = = = = = = = = ... GAME OVER ... = = = = = = = = = = = =\n");
}
void winMessage() {
    printf("\nYou stand victorious in the heart of the dungeon.\n");
    printf("The Heart of Nyx pulses in your grasp, its power coursing through you.\n");
    printf("The shadows retreat, unable to withstand your resolve.\n");
    printf("Your journey was long, fraught with peril, but you have emerged triumphant.\n\n");
    printf("The dungeon may never forget your name, but you will leave it behind.\n");
    printf("You have conquered the darkness. You are the light that remains.\n");
    printf("Congratulations, Hero. The Underdark is no longer your prison.\n");
}

void movementDialog() {
    printf("\n\n");
    printf("---> Okey, so where should I go now ? : ");
}

void movementHallDialog(char hall[50]) {
    if (strcmp(hall, "Big Saloon (Spawn Area)") == 0) {
        printf("\n--> I think this is the place where I come into my own.");
    }
    else if (strcmp(hall, "North Transition") == 0) {
        printf("\n--> So heading North... Let's see.");
    }
    else if (strcmp(hall, "East Transition") == 0) {
        printf("\n--> So heading East... Kinda weird doors and smells ?");
    }
    else if (strcmp(hall, "West Transition") == 0) {
        printf("\n--> So heading West... I don't seem to like it very much here. I can hear strange noises and the ground is shaking !");
    }
    else {
        printf("\n--> Where is it ? ");
    }
}
void lookAroundDialog() {
    printf("\n\n--> Where should I look ?: ");
}
void lookRoomDialog(char direction[50], char currentHall[50]) {

    if (strcmp(currentHall, "North Transition") == 0) {

        if (strcmp(direction, "look east") == 0) {getRoomDescription("Room 1");}
        else if (strcmp(direction, "look west") == 0) {getRoomDescription("Room 2");}
        else if (strcmp(direction, "look north") == 0) {getRoomDescription("Room 3");}
        else if (strcmp(direction, "look south") == 0) {getRoomDescription("Big Saloon");}
        else {printf("\n --> I did not understand that command...");}

    }

    else if (strcmp(currentHall, "East Transition") == 0) {

        if (strcmp(direction, "look east") == 0) {getRoomDescription("Room 6");}
        else if (strcmp(direction, "look south") == 0) {getRoomDescription("Room 5");}
        else if (strcmp(direction, "look north") == 0) {getRoomDescription("Room 4");}
        else if (strcmp(direction, "look west") == 0) {getRoomDescription("Big Saloon");}
        else {printf("\n --> I did not understand that command...");}

    }

    else if (strcmp(currentHall, "West Transition") == 0) {

        if (strcmp(direction, "look south") == 0) {getRoomDescription("Room 11");}
        else if (strcmp(direction, "look west") == 0) {getRoomDescription("Room 12");}
        else if (strcmp(direction, "look north") == 0) {getRoomDescription("Room 10");}
        else if (strcmp(direction, "look east") == 0) {getRoomDescription("Big Saloon");}
        else {printf("\n --> I did not understand that command...");}
    }

    else {

        printf("\n--> I need to go hall to look rooms...");

    }
}
void welcomeDialog() {
    printTop(100);
    printf("*\t*\t*\t*\t* GAME STARTED GOOD LUCK :) *\t*\t*\t*\t*\n");

    enterToGoDialog();
    printf("\t\t\t\t HERE IS THE MAP OF THE DUNGEON (You can see the map when you can interact with your character.)\n");
    enterToGoDialog();
    printMap(); // Print map.
    printf("\n");
    printDown(150);

    printf("\n* * * * *\tDURING THE GAME YOU HAVE TO TYPE \"move west\", \"move east\", \"move north\" and \"move south\" COMMANDS TO MOVE YOUR CHARACTER !\t* * * * *\n");

}
void defeatedMonsterMessage() {
    printf("\n\n-----------------------------------------------------\n");
    printf("  The battle is over. You have emerged victorious.\n");
    printf("  Another foe lies defeated in your path.\n");
    printf("-----------------------------------------------------\n\n");
}
void showBattleDetail(Monster * monster, Character * player) {
    printf("\n= = = = = = = = = = = = = = =  THE BATTLE WITH \"%s\" = = = = = = = = = = = = = = =\n\n", monster->name);
    printf("                               ___CURRENT STATS___\n");
    printf("        M O N S T E R                                                 P L A Y E R\n");
    printf("Health:        %d                                            Health:      %d\n", monster->health, player->health);
    printf("Attack:        %d                                             Attack:       %d\n", monster->attack, player->attack);
    printf("= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =\n");
}
void trapMessage(Trap* trap, Character* player) {

    printf("\n________________________>>> YOU STEPPED ON A TRAP ! <<<________________\n");
    printf("\n --> Ah! I should've seen that coming! Next time I won't enter the room without looking.\n");
    enterToGo();

    if (trap->healthDamage == 0) {
        printf("\n You've been damaged by %s it costed you %d attack damaged !", trap -> name, trap -> attackDamage);
        player -> attack -= trap -> attackDamage;

        if (player -> attack <= 0) {
            player -> attack = 1;
        }

        enterToGo();
        show_detailed_informations(player);
    }
    else if (trap -> attackDamage == 0) {
        printf("\n You've been damaged by %s it costed you %d health damaged !", trap -> name, trap -> healthDamage);
        player -> health -= trap -> healthDamage;
        enterToGo();
        show_detailed_informations(player);
    }
    else {
        printf("\n! ! ! ! !  You've been damaged by %s it costed you %d attack and %d health damaged ! ! ! ! ! (You should do the side quest.)", trap -> name, trap -> attackDamage, trap -> healthDamage);
        player -> attack -= trap -> attackDamage;
        player -> health -= trap -> healthDamage;
        enterToGo();
        show_detailed_informations(player);
    }

}
void getTreasureDescription(Treasure* treasure) {
    printf("\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
    FILE* file;
    char line[256];
    char filePath[100];


    snprintf(filePath, sizeof(filePath), "../%s.txt", treasure->name);


    file = fopen(filePath, "r");


    if (file == NULL) {
        printf("Error: Unable to open the file (Room Description).\n");
        exit(EXIT_FAILURE);
    }


    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
    printf("\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
    // Dosyayı kapat
    fclose(file);


}
void saveMenuPrint() {
    printf("\n1-) Save the Game.\n");
    printf("2-) Load the Game.\n");
    printf("3-) Exit.\n");
    printf("\n Choose your operation: ");
}

