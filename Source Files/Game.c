
#include "../Header Files/Game.h"

#include "../Header Files/DungeonMap.h"


void gameLoop() {

        welcomeScreen();

        gameStartMessage();

        enterToGo();

        Character* player = chooseCharacter();

        clearBuffer();

        enterToGo();

        welcomeDialog();

        runGame(player);







}
void clearBuffer() {
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
}
void enterToGo() {
        char input;

        printf("\nPress ENTER to continue...");




        while (1) {
                input = getchar(); // Waits for user input

                if (input == '\n') {
                        break;
                }
                clearBuffer();
                printf("Invalid input! Press Enter to exit.\n");
        }
}
void enterToGoDialog() {
        char input;

        while (1) {
                input = getchar(); // Waits for user input

                if (input == '\n') {
                        break;
                };
                clearBuffer();
        }
}

void runGame(Character* player) {
        Transition *currentTransition = NULL;
        Room* currentRoom = NULL;

        setupTransitions(&currentTransition);

        char command[50]; // Store input.
        while (1) {
                displayMenuChoose(&currentTransition);
                fgets(command, sizeof(command), stdin); // Get input.
                command[strcspn(command, "\n")] = '\0'; // Remove \n

                choosenOperation(command, &currentTransition, player, &currentRoom);
                clearBuffer();
        }
}
void displayMenuChoose(Transition** currentTransition) {
        printf("\n\n1-) Go to \"Save Menu\".\n");
        printf("2-) Go to \"Inventory Menu\".\n");
        printf("3-) Move Around (%s)\n", (*currentTransition) -> name ? (*currentTransition)->name : "Spawn Area");
        printf("4-) Look Around\n");
        printf("5-) Display \"Character Details\".\n");
        printf("6-) Show the Dungeon Map.\n");
        printf("7-) Quit.\n");
        printf("\nChoose your operation: ");
}

void moveAround(Transition** currentTransition, Character* player, Room** currentRoom) {
        movementDialog();
        char command[50]; // To detect move direction.

        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = '\0';


        processTransition(currentTransition, command, player, currentRoom);
}

void lookAround(Transition ** currentTransition) {
        lookAroundDialog();
        char command[50];

        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = '\0';


        lookRooms(currentTransition, command);
}

void removeItemMenu(Character* player) {

        if (player -> inventory_count == 0) {
                printf("\n---> Ohhh, i don't have any items to remove...\n");
                return;
        }
        char command[50];
        printf("\nWhich item do you want to remove ?: ");

        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = '\0';

        if (remove_item_from_inventory(player, command)) {
                printf("\n= = = Item %s is successfully removed. = = =\n", command);
        }
        else {
                printf("\n= = = There is no such item in your Inventory ! = = =\n");
        }
}

void use_item(const char * str, Character * player) {
        FILE* file;

        int* healthContribution = 0;
        int* attackContribution = 0;

        file = fopen(str, "r");

        if (file == NULL) {
                printf("Error: Unable to open item details.\n");
                exit(EXIT_FAILURE);
        }

        char line[256];

        while (fgets(line, sizeof(line), file)) {
                if (strncmp(line, "Health Contribution =", 21) == 0) {
                        sscanf(line, "Health Contribution = %d", healthContribution);
                } else if (strncmp(line, "Attack Contribution =", 21) == 0) {
                        sscanf(line, "Attack Contribution = %d", attackContribution);
                }
        }

        player -> attack += *attackContribution;
        player -> health += *healthContribution;


}

void use_item_from_inventory(Character * player) {
        if (player -> inventory_count <= 0) {
                printf("\n ---> I do not have item yet...");
                return;
        }

        char command[50];

        while (player -> inventory_count > 0) {
                printf("\n <<<<<<<<<<<<<< Which item do you want to use ? >>>>>>>>>>>>>>>>>\n");
                show_inventory(player);
                printf("\n Enter the item name:");
                fgets(command, sizeof(command), stdin); // Get input.
                command[strcspn(command, "\n")] = '\0'; // Remove \n

                if(search_in_inventory(player, command) && strcmp(command, "Escape Pot") != 0) {
                        printf("\n---> I found it ! ");
                        use_item(command, player);
                        show_detailed_informations(player);
                }
                else if (strcmp(command, "Escape Pot") == 0) {
                        printf("\n---> I can not use Escape Pot. It can be only used in battles...\n");
                        break;
                }
                else {
                        printf("\n---> Are you sure it is in my inventory ? ");
                }
        }

}

void manageInventoryMenu(Character * player) {
        char command[50];

        while (1) {

                printf("\n\n1-) Remove Item.\n");
                printf("2-) Show Current Items.\n");
                printf("3-) Use Item.\n");
                printf("4-) Exit.\n");

                printf("\nChoose your operation: ");

                fgets(command, sizeof(command), stdin); // Get input.
                command[strcspn(command, "\n")] = '\0'; // Remove \n

                if(command[0] == '1') {
                        removeItemMenu(player);
                }
                else if (command[0] == '2') {
                        show_inventory(player);
                }
                else if (command[0] == '3') {
                        use_item_from_inventory(player);
                }
                else if (command[0] == '4') {
                        break;
                }
                else {
                        printf("\nInvalid command !\n");
                }
        }
}



void saveProgress(Room ** room, Transition ** transition, Character * player, char* filename) {

        FILE* file = fopen(filename, "w"); // Create file.

        if (file == NULL) { // Prevent error.
              printf("Error: Unable to create save file.\n");
              return;
        }
        // Save player stats.
        fprintf(file, "Player\n");
        fprintf(file, "Health: %d\n", player->health);
        fprintf(file, "Attack: %d\n", player->attack);
        fprintf(file, "Inventory:\n");
        for (int i = 0; i < player->inventory_count; i++) {
                fprintf(file, "%s\n", player->inventory[i]);
        }

        // Save rooms
        fprintf(file, "\nRooms:\n");
        for (int i = 0; i < 9; i++) {
                Room* currentArrRoom = globalRoomArray[i];
                fprintf(file, "Room: %s, Cleaned: %d\n", currentArrRoom->name, currentArrRoom->isCleaned);
        }

        fclose(file);
        printf("\nGame saved to %s\n", filename);


}

void loadGame(Character * player, char * filename) {
        FILE* file = fopen(filename, "r");
        if (file == NULL) {
                printf("Error: Unable to open save file.\n");
                exit(EXIT_FAILURE);
        }

        char line[256];
        int inventoryReading = 0; // Inventory kısmını okuduğumuzu izlemek için bayrak

        while (fgets(line, sizeof(line), file)) {
                // Oyuncu istatistiklerini yükle
                if (strncmp(line, "Health:", 7) == 0) {
                        sscanf(line, "Health: %d", &player->health);
                }
                else if (strncmp(line, "Attack:", 7) == 0) {
                        sscanf(line, "Attack: %d", &player->attack);
                }
                else if (strncmp(line, "Inventory:", 10) == 0) {
                        inventoryReading = 1; // Inventory kısmını okuma başlasın
                }
                else if (inventoryReading && line[0] != '\n' && line[0] != 'R') {
                        // Inventory'deki itemleri ekle
                        line[strcspn(line, "\n")] = '\0'; // Satır sonunu temizle
                        if (line[0] != '\0') { // Boş satır kontrolü
                                if (!add_item_to_inventory(player, line)) { // Envantere eklemeye çalış
                                        printf("Warning: Unable to add '%s' to inventory (inventory full).\n", line);
                                }
                        }
                }
                else if (strncmp(line, "Rooms:", 6) == 0) {
                        inventoryReading = 0; // Inventory kısmını bitir
                }

                // Odaların durumunu yükle
                else if (strncmp(line, "Room:", 5) == 0) {
                        char roomName[50];
                        int isCleaned;
                        sscanf(line, "Room: %[^,], Cleaned: %d", roomName, &isCleaned);

                        // Global room array üzerinden durumu güncelle
                        for (int i = 0; i < 9; i++) {
                                if (strcmp(globalRoomArray[i]->name, roomName) == 0) {
                                        globalRoomArray[i]->isCleaned = isCleaned;
                                        break;
                                }
                        }
                }
        }

        fclose(file);
        printf("Game loaded successfully from %s\n", filename);
}

void saveMenu(Room ** room, Transition ** transition, Character * player) {
        char command[10]; // Store input.

        while (1) {
                saveMenuPrint(); // Print menu.

                fgets(command, sizeof(command), stdin); // Get input.
                command[strcspn(command, "\n")] = '\0'; // Remove \n

                if (command[0] == '1') {
                        printf("Enter the save file name: ");
                        char filename[20]; // File name.

                        fgets(filename, sizeof(filename), stdin); // Get input.
                        filename[strcspn(filename, "\n")] = '\0'; // Remove \n

                        saveProgress(room, transition, player, filename);

                }
                else if (command[0] == '2') {
                        printf("Enter the load file name: ");
                        char filename[20]; // File name.

                        fgets(filename, sizeof(filename), stdin); // Get input.
                        filename[strcspn(filename, "\n")] = '\0'; // Remove \n
                        loadGame(player, filename);
                        break;
                }
                else if (command[0] == '3') {
                        break;
                }
                else {
                        printf("\nInvalid operation try again !");
                }
        }


}

void free_everything(Character * player, Transition ** transition, Room ** room) {
        free_character_inventory(player);

        free(player);

        for (int i = 0; i < 9; ++i) {
                freeRoom(globalRoomArray[i]);// Free rooms.
        }

        for (int i = 0; i < 3; ++i) {
                free(globalTransitionArray[i]); // Free transitions.
        }


}

void choosenOperation(const char operation[50], Transition** currentTransition, Character* player, Room** currentRoom) {
        switch (operation[0]) {
                case '1':
                        saveMenu(currentRoom, currentTransition, player);
                                break;
                case '2':
                        manageInventoryMenu(player);
                                break;
                case '3':
                        moveAround(currentTransition, player, currentRoom);
                                break;
                case '4':
                        lookAround(currentTransition);
                                break;
                case '5':
                        show_detailed_informations(player);
                                break;
                case '6':
                        printMap();
                                break;
                case '7':
                        free_everything(player, currentTransition, currentRoom);
                        exit(EXIT_SUCCESS);
                default:
                        printf("\nInvalid Menu Operation ! \n");
                        break;

        }
}
int headOrTail() {
        srand(time(NULL));

        return rand() % 2;
}
