## The Goal
In this project, I built a simple 2D game to get familiar with the MiniLibX library and basic UI. You play as a chess queen. Your goal is to collect all the pawns and then capture the king. When you succeed, the game closes automatically.

### Game Rules
The game we choose must follow a set of rules. The executable ``so_long`` will receive a map as the only argument, and this map will have a ``.ber`` filetype.

The file also must follow these rules:
- ``P`` *(Queen)*, ``1`` *(wall)*, ``0`` *(empty)*, ``C`` *(collectible)*, and ``E`` *(exit)* will be the only accepted characters in our map.
- The map must be rectangular.
- There must be at least one exit, one player, and one collectible on the map.
- The map must be closed, surrounded by walls.

If any of these checks fail, the game must end with ``Error\n`` followed by a custom message.


### Installing
Be sure to have minilibx-linux installed.
if you don`t have it, you can install it with:
```shell
git clone https://github.com/42Paris/minilibx-linux.git
cd minilibx-linux/
make
```

then clone my repository with:
```shell
git clone https://gitlab.com/mAlex-mfs/so_long.git
cd so_long
make
```

### Usage
```shell
./so_long map_test/valid3.ber
```

![so_long](https://github.com/user-attachments/assets/ebf44455-5938-4867-87d3-7fe867c120f2)
