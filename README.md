# So_long

Welcome to **So_long**! This project is a game written in C, developed as a part of the 42 curriculum. The goal of the game is to guide a character through a maze, collecting items and reaching the exit while avoiding obstacles.

## Features

- Maze generation and rendering
- Collectibles and exit logic
- Player movement with keyboard controls
- Basic graphics using MiniLibX
- Error handling for invalid maps

## Getting Started

### Prerequisites

- GCC or another C compiler
- [MiniLibX](https://harm-smits.github.io/42docs/libs/minilibx) library (usually provided by 42)
- Make

### Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/LuirR91/So_long.git
   cd So_long
   ```

2. Build the project:
   ```bash
   make
   ```

### Running the Game

After compiling, run the game using:
```bash
./so_long [map_file.ber]
```
Replace `[map_file.ber]` with the path to your map file.

## Map File Format

The map file should be a `.ber` file containing characters representing walls, empty spaces, collectibles, player start, and exit. Example:
```
11111
1P0C1
101E1
11111
```
- `1`: Wall
- `0`: Empty space
- `P`: Player start
- `C`: Collectible
- `E`: Exit

## Controls

- Arrow keys / WASD: Move player
- ESC: Exit game

## Project Structure

- `src/`: Main source code
- `include/`: Header files
- `maps/`: Example map files
