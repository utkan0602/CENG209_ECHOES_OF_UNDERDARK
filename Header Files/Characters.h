

#ifndef CHARACTERS_H
#define CHARACTERS_H
typedef struct {
    int health;
    int attack;
    char** inventory; // The items that character has.
    int inventory_count; // The item count of current inventory that character has.
    int max_inventory_size; // Each character has different capacity of inventory.
    int isQuestAccept;
} Character;

void initialize_character(Character* character, int health, int attack, int max_inventory_size, int isQuestAccept);
void free_character_inventory(Character* character); // This method will delete inventory when character die.
int add_item_to_inventory(Character* character, char* item); // This method will add item to character's inventory.
int remove_item_from_inventory(Character* character,const char* item); // This method will delete item from character's inventory.
void show_inventory(const Character* character); // This method will print every item in the character inventory.
void show_detailed_informations(const Character* character);
int search_in_inventory(const Character* character, const char* item);

#endif //CHARACTERS_H
