*This project has been created as part of the 42 curriculum by sirawan.*

## Description

`ft_printf` is a recode of the C library function `printf`. The goal of the project is to learn how variadic functions work in C (`va_list`, `va_start`, `va_arg`, `va_end`).

The function has the prototype `int ft_printf(const char *, ...);`. It writes the formatted output to the standard output and returns the number of characters printed, like the original.

Handled conversions:

| Conversion | Prints |
|---|---|
| `%c` | a single character |
| `%s` | a string (`(null)` if the pointer is NULL) |
| `%p` | a pointer in hexadecimal, with `0x` in front |
| `%d` / `%i` | a signed decimal number |
| `%u` | an unsigned decimal number |
| `%x` / `%X` | a hexadecimal number, lowercase / uppercase |
| `%%` | a percent sign |

The buffer management of the original `printf` is not implemented.

## Instructions

Build the library:

```
make
```

This creates `libftprintf.a` at the root of the repository.

Use it in your own program:

```c
#include "ft_printf.h"

int	main(void)
{
	ft_printf("Hello %s, you are %d years old\n", "world", 42);
	return (0);
}
```

```
cc -Wall -Wextra -Werror main.c libftprintf.a
```

Other Makefile rules:

- `make clean`: removes the object files
- `make fclean`: removes the object files and `libftprintf.a`
- `make re`: rebuilds everything from scratch

## Algorithm

**Main loop.** `ft_printf` reads the format string one character at a time. A normal character is written directly. When it finds a `%`, it takes the next character (the conversion letter) and sends it to `ft_format`. Then it skips both characters.

**Dispatcher.** `ft_format` checks the conversion letter and calls the matching helper. Every helper returns the number of characters it printed, and `ft_printf` adds these numbers into one total, which it returns at the end.

**Variable arguments.** The `va_list` is created in `ft_printf` and passed to `ft_format` by pointer. A pointer is needed because a copy would not move the position, so the next `va_arg` would read the same argument again. The type given to `va_arg` depends on the conversion: `int` for `c`, `d` and `i`, `char *` for `s`, `unsigned int` for `u`, `x` and `X`, and `void *` for `p`.

**Numbers.** Decimal numbers are printed with recursion: the function first prints `n / 10` (the digits in front), then the last digit `n % 10 + '0'`. This prints the digits in the right order without a buffer. `INT_MIN` is a special case, because `-n` does not fit in an `int`, so it is printed directly.

**Hexadecimal.** The digit is chosen from a lookup string (`"0123456789abcdef"` or `"0123456789ABCDEF"`). Passing the string as a parameter lets one function handle both `%x` and `%X`. For `%p`, the pointer is cast to `unsigned long` so the whole 8-byte address fits, and `0x` is printed first.

**Why this design.** Each function is short, which respects the Norm (25 lines per function). Adding a new conversion only needs one new `if` in `ft_format` and one helper, without changing the main loop.

## Resources

- `man 3 stdarg` (variadic functions)
- `man 2 write`
- `man 3 printf`
- The 42 `ft_printf` subject

### How AI was used

I used Claude as a tutor while working on this project. It was used for:

- Explaining concepts: variadic functions (`va_list`, `va_start`, `va_arg`, `va_end`), why `va_arg` reads a `char` as an `int`, recursion, and the `INT_MIN` overflow.
- Finding bugs in my code and explaining the compiler and linker errors.
- Giving partial code outlines (with blanks) to fill in, and guidance on the Makefile structure and the Norm.
- Helping to draft this README.

I wrote and tested the code myself, and I checked the output against the real `printf`.