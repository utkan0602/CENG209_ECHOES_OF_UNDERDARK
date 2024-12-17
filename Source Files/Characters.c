

#include "../Header Files/Characters.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "../Header Files/TextHeaderCreator.h"

void initialize_character(Character* character, int health, int attack, int max_inventory_size,  int isQuestAccept) {
    character -> health = health;
    character -> attack = attack;
    character -> inventory_count = 0; // Initially character has "0" item in inventory.
    character -> max_inventory_size = max_inventory_size;
    character -> inventory = (char **) malloc(max_inventory_size * sizeof(char *)); // Dynamic Memory Allocation for character inventory.

    for (int i = 0; i < max_inventory_size; ++i) {
        character->inventory[i] = NULL; // Initially character inventory has nothing.
    }
    character -> isQuestAccept = isQuestAccept;
}
void free_character_inventory(Character* character) {
    for (int i = 0; i < character->inventory_count; ++i) {
        free(character->inventory[i]);
    }
    free(character->inventory);
}
int add_item_to_inventory(Character* character, char* item) {
    // Control inventory size.
    if (character->inventory_count >= character->max_inventory_size) {
        printf("The inventory is full.\n");
        return 0; // Inventory full.
    }

    character->inventory[character->inventory_count] = (char*) malloc(strlen(item) + 1); // Make allocation for current item.

    if (!character->inventory[character->inventory_count]) {
        printf("Memory allocation failed for inventory item!\n");
        return 0; // Check for memory allocation fail.
    }

    strcpy(character->inventory[character->inventory_count], item); // Place the item to character inventory.

    character->inventory_count++; // Increment inventory count.

    return 1; // All done.
}
int remove_item_from_inventory(Character* character, const char* item) {
    for (int i = 0; i < character->inventory_count; ++i) {
        if (strcmp(character->inventory[i], item) == 0) {
            // Free the memory for the item being removed
            free(character->inventory[i]);

            // Shift items to fill the gap
            for (int j = i; j < character->inventory_count - 1; ++j) {
                character->inventory[j] = character->inventory[j + 1];
            }

            // Set the last item pointer to NULL after shifting
            character->inventory[character->inventory_count - 1] = NULL;

            // Decrease inventory count
            character->inventory_count--;

            return 1; // Item successfully removed
        }
    }
    return 0; // Item not found
}

void show_inventory(const Character* character) {
    if (character->inventory_count == 0) {
        printf("\n --> I do not have any item yet... Can we find items now ?\n");
    }

    else {
        printf("\n-      -      -      -     Current Items     -      -      -      -\n");
        printf("Inventory(%d):\n", character->inventory_count);

        for (int i = 0; i < character->inventory_count; i++) {
            printf("  - %s\n", character->inventory[i]);
        }
    }

}

int search_in_inventory(const Character* character, const char* item) {
    for (int i = 0; i < character->inventory_count; ++i) {
        if (strcmp(character->inventory[i], item) == 0) {
            return 1; // Item found in inventory
        }
    }
    return 0; // Item not found
}


void show_detailed_informations(const Character* character) {
    printTop(61);
    printf("\n* * * * * THE LATEST INFORMATION'S ABOUT CHARACTER * * * * *\n\n");
    printf("Health: %d\n", character->health); // Display current health of the player.
    printf("Attack: %d\n", character->attack); // Display current attack of the player.
    printf("Inventory Capacity: %d\n", character->max_inventory_size); // Display current inventory size of the player.
    printDown(61);
}
