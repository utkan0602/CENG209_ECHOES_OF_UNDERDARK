# Dungeon Adventure Game

## Gameplay
Dungeon Adventure is a text-based role-playing game where players explore a dungeon filled with monsters, treasures, traps, and NPCs. The game involves strategic decision-making, turn-based battles, and resource management to survive and achieve victory.

### Key Features
- **Exploration**: Navigate through interconnected rooms using directional commands.
- **Combat**: Engage in battles using a coin-flip mechanic to determine attack success.
- **Treasures and Traps**: Collect valuable items and avoid harmful traps.
- **Inventory Management**: Limited inventory capacity requires careful item usage.
- **Save and Load**: Save progress and resume the game from saved states.

### How to Play
1. **Movement**: Use commands like `move north`, `move south`, `move east`, and `move west` to navigate.
2. **Interactions**:
   - Enter rooms to encounter monsters, treasures, or traps.
   - Use `look around` to check adjacent rooms without entering.
3. **Combat**:
   - Choose to fight or run when encountering a monster.
   - Use items like health potions to survive tough battles.
4. **Inventory Management**:
   - Pick up or drop items as needed.
5. **Save/Load**:
   - Save your progress using the save menu.
   - Reload your game from previously saved states.

---

## Code Structure
The project is organized into modular files, each handling a specific aspect of the game. Below is an overview of the key components:

### Directories and Files
- **`main.c`**: Entry point of the application. Initializes the game and manages the game loop.
- **Header Files**:
  - `Characters.h`: Handles character creation, inventory management, and player stats.
  - `Rooms.h`: Defines room mechanics, including monsters, treasures, and traps.
  - `Game.h`: Core game logic, including transitions, battle mechanics, and save/load functionalities.
  - `GameMessages.h`: Contains user-facing messages for game events.
- **Source Files**:
  - `Characters.c`: Implements character-related functionality.
  - `Rooms.c`: Manages room creation, cleanup, and interactions.
  - `Game.c`: Implements the game loop, transitions, and overall logic.

### Global Data Structures
- **Room Array**: Tracks all rooms and their statuses (e.g., cleaned or not).
- **Transition**: Links rooms and defines possible movements.

### Key Functions
- **Initialization**:
  - `setupTransitions`: Defines connections between rooms and transitions.
  - `initialize_character`: Creates the player and sets initial stats.
- **Game Mechanics**:
  - `processTransition`: Handles player movement between rooms and transitions.
  - `startBattleMechanicsm`: Manages combat encounters.
  - `useItem`: Applies item effects to the player.
- **Save/Load**:
  - `saveProgress`: Saves player stats, room statuses, and inventory to a file.
  - `loadGame`: Loads saved data into the game state.

---

## Game Logic

### Room Navigation
- Rooms are connected via transitions (north, south, east, west).
- Moving to a new room updates the player’s current location and triggers room-specific events.

### Combat
- Turn-based combat uses a coin-flip mechanic:
  - Guessing correctly allows the player to attack the monster.
  - Incorrect guesses result in the monster attacking the player.
- Combat ends when either the player or the monster runs out of health.

### Inventory Management
- Players can carry a limited number of items.
- Items can be picked up, dropped, or used during gameplay.
- Treasures provide health or attack boosts, while tools like escape potions help evade combat.

### Save and Load
- Progress is stored in a save file, including:
  - Player stats (health, attack, inventory).
  - Room statuses (e.g., cleaned or active).
- Save files are located in a designated directory (`Save Files`) and can be loaded to resume gameplay.

---

## Future Improvements
- Enhanced AI for monsters and NPC interactions.
- Visual interface for more immersive gameplay.
- Expanded dungeon layouts and random room generation.

---

## Conclusion
Dungeon Adventure is a fun and challenging text-based RPG that emphasizes exploration, combat, and strategy. Its modular design and engaging mechanics ensure a compelling experience for players.

-Utkan DİNDAROĞLU
