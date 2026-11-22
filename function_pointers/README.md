# C - Function pointers

This project covers function pointers in C.

## Requirements

- Compiled on Ubuntu 20.04 LTS with `gcc -Wall -Werror -Wextra -pedantic -std=gnu89`
- Code follows the Betty style
- No global variables
- The only standard library functions allowed are `malloc`, `free` and `exit`
- All header files are include guarded

## Files

| File | Description |
|------|-------------|
| `function_pointers.h` | Header file containing the prototypes of all functions |
| `0-print_name.c` | Function that prints a name using a given function |
| `1-array_iterator.c` | Function that executes a function on each element of an array |
| `2-int_index.c` | Function that searches for the first element matching a comparison function |
| `3-calc.h` | Header file defining op_t and all function prototypes for the calc program |
| `3-op_functions.c` | The 5 arithmetic operation functions |
| `3-get_op_func.c` | Function that selects the correct operation function based on the operator |
| `3-main.c` | Main function for the calc program |
