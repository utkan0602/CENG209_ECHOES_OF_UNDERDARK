#include <stdio.h>
#include "../Header Files/CharacterChoosing.h"
#include "../Header Files/Goblin.h"
#include "../Header Files/TextHeaderCreator.h"
#include "../Header Files/Warrior.h"
#include "../Header Files/Wizard.h"

Character* chooseCharacter() {
    printTop(55);
    int choice;
    printf("\n* * * * * CHOOSE YOUR COMPANION * * * * *\n\n");
    printf("1. Wizard - High magic power, moderate health. (Health -> 250 | Attack -> 50 | Inventory Capacity -> 3)\n");
    printf("2. Goblin - Agile and tricky, low health but high inventory capacity. (Health -> 200 | Attack -> 40 | Inventory Capacity -> 7)\n");
    printf("3. Warrior - Strong and durable, high health and attack. (Health -> 400 | Attack -> 35 | Inventory Capacity -> 5)\n");
    printf("\nEnter your choice (1-3): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("\nSo You Like Magic or What ?!\n");
            printDown(55);
        return (Character*)createWizard();
        case 2:
            printf("\nWhy Does A Person Carry So Much Stuff?\n");
            printDown(55);
        return (Character*)createGoblin();
        case 3:

            printf("\nWho Will Carry This Heavy Armor?\n");
            printDown(55);
        return (Character*)createWarrior();
        default:
            printf("Invalid choice! Please try again.\n");
        return chooseCharacter(); // Recursively call until valid input
    }

}
