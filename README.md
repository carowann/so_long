# So Long

A simple 2D game built with MiniLibX for 42 School.

## Installation

```bash
git clone https://github.com/your-username/so_long.git
cd so_long
make
```

*MiniLibX will be downloaded automatically if not present.*

## Usage

```bash
./so_long maps/map.ber
```

### Controls
- `WASD` or arrow keys to move
- `ESC` to exit

## Map Rules
- `.ber` files only
- Must be rectangular and surrounded by walls (`1`)
- One player (`P`), one exit (`E`), at least one collectible (`C`)
- Collect all items before reaching the exit

### Example Map
```
1111111111111
10010000000C1
1000011111001
1P0011E000001
1111111111111
```

## Make Commands
- `make` - Build
- `make clean` - Remove objects
- `make fclean` - Remove all
- `make re` - Rebuild
