# C - structures, typedef

This project covers structures and typedef in C.

## Requirements

- Compiled on Ubuntu 20.04 LTS with `gcc -Wall -Werror -Wextra -pedantic -std=gnu89`
- Code follows the Betty style
- No global variables
- The only standard library functions allowed are `printf`, `malloc`, `free` and `exit`
- All header files are include guarded

## Files

| File | Description |
|------|-------------|
| `dog.h` | Header file defining the struct dog type |
| `1-init_dog.c` | Function that initializes a variable of type struct dog |
| `2-print_dog.c` | Function that prints a struct dog |
| `dog.h` (updated) | Defines dog_t as an alias for struct dog |
| `4-new_dog.c` | Function that creates a new dog, storing copies of name and owner |
| `5-free_dog.c` | Function that frees a dog created by new_dog |
