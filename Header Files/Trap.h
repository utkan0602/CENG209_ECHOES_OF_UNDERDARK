

#ifndef TRAP_H
#define TRAP_H
typedef struct {
    const char* name;
    int healthDamage;
    int attackDamage;
} Trap;

Trap* createTrap (const char* name, int healthDamage, int attackDamage);
void freeTrap (Trap* trap);
#endif //TRAP_H
