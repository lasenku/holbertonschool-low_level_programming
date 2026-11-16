# C - more malloc, free

This project covers checked dynamic memory allocation in C.

## Requirements

- Compiled on Ubuntu 20.04 LTS with `gcc -Wall -Werror -Wextra -pedantic -std=gnu89`
- Code follows the Betty style
- No global variables
- The only standard library functions allowed are `malloc`, `free` and `exit`

## Files

| File | Description |
|------|-------------|
| `main.h` | Header file containing the prototypes of all functions |
| `0-malloc_checked.c` | Function that allocates memory using malloc, exiting with status 98 on failure |
| `1-string_nconcat.c` | Function that concatenates two strings, using at most n bytes from the second |
| `2-calloc.c` | Function that allocates and zeroes memory for an array, using malloc |
