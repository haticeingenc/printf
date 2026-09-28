*This project has been created as part of the 42 curriculum by hingenc.*

# ft_printf

A custom implementation of the standard C library function `printf()`. The goal of this project is to explore variadic functions in C, understand how arguments are handled on the call stack, and produce a standalone static library (`libftprintf.a`) without using libc buffer management.

---

## Description

The `ft_printf` function mimics the core behavior of the standard C library `printf()`. It parses a formatted string and outputs the requested variables to standard output (file descriptor `1`).

This implementation covers the mandatory conversions required by the 42 curriculum:
- `%c`: Prints a single character.
- `%s`: Prints a string (handles `NULL` pointers safely by outputting `(null)`).
- `%p`: Prints a pointer memory address in hexadecimal format prefixed with `0x` (handles `NULL` pointers by outputting `0x0`).
- `%d`: Prints a signed decimal integer (base 10).
- `%i`: Prints an integer in base 10 (identical to `%d` for output).
- `%u`: Prints an unsigned decimal integer (base 10).
- `%x`: Prints an unsigned integer in lowercase hexadecimal format (base 16).
- `%X`: Prints an unsigned integer in uppercase hexadecimal format (base 16).
- `%%`: Prints a literal percent sign.

The function returns the total number of characters printed to the standard output.

---

## Instructions

### Compilation

The project compiles into a static archive named `libftprintf.a` using `cc` with the flags `-Wall -Wextra -Werror` and the archive utility `ar rcs`.

To compile the library:
```bash
make