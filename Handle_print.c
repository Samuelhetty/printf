#include "main.h"

/**
 * handle_print - Prints an argument based on its type
 * @format_str: Formatted string in which to print the arguments.
 * @arg: List of arguments to be printed.
 * @ind: ind.
 * @buffer: Buffer array to handle print.
 * @flags: Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: 1 or 2;
 */
int handle_print(const char *format_str, int *ind, va_list arg, char buffer[],
		int flags, int width, int precision, int size)
{
	int i, unknown_length = 0, printed = -1;

	Format formats[] = {
		{'c', print_c}, {'s', print_s}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_oct}, {'x', print_hexadecimal},
		{'X', print_hexa_upper}, {'p', print_ptr}, {'S', print_non_printable},
		{'r', print_rev}, {'R', print_rot13string}, {'\0', NULL}
	};

	for (i = 0; formats[i].Format != '\0'; i++)
	{
		if (format_str[*ind] == formats[i].Format)
		{
			return (formats[i].func_ptr(arg, buffer, flags, width, precision, size));
		}
	}

	if (formats[i].Format == '\0')
	{
		if (format_str[*ind] == '\0')
		{
			return (-1);
		}

		unknown_length += write(1, "%%", 1);

		if (format_str[*ind - 1] == ' ')
		{
			unknown_length += write(1, " ", 1);
		}
		else if (width)
		{
			--(*ind);

			while (format_str[*ind] != ' ' && format_str[*ind] != '%')
			{
				--(*ind);
			}

			if (format_str[*ind] == ' ')
			{
				--(*ind);
			}

			return (1);
		}

		unknown_length += write(1, &format_str[*ind], 1);

		return (unknown_length);
	}
	return (printed);
}
