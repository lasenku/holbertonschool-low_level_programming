# C - File I/O

This project covers file I/O system calls in C: open, close, read, write.

## Requirements

- Compiled on Ubuntu 20.04 LTS with `gcc -Wall -Werror -Wextra -pedantic -std=gnu89`
- Code follows the Betty style
- No global variables
- The only standard library functions allowed are `malloc`, `free` and `exit`
- Allowed syscalls: `read`, `write`, `open`, `close`
- All header files are include guarded

## Files

| File | Description |
|------|-------------|
| `main.h` | Header file containing the prototypes of all functions |
| `0-read_textfile.c` | Function that reads a text file and prints it to stdout |
| `1-create_file.c` | Function that creates a file and writes text content to it |
| `2-append_text_to_file.c` | Function that appends text at the end of a file |
| `3-cp.c` | Program that copies the content of a file to another file |
