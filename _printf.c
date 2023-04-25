#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	int i, count = 0, printed = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list arg;
	char buffer[BUFF_SIZE];

	if (!format)
		return (-1);

	va_start(arg, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);

			/* write(1, &format[i], 1);*/
			printed++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &i);
			width = get_width(format, &i, arg);
			precision = get_precision(format, &i, arg);
			size = get_size(format, &i);
			++i;
			count = handle_print(format, &i, arg, buffer,
				flags, width, precision, size);
			if (count == -1)
				return (-1);
			printed += count;
		}
	}

	print_buffer(buffer, &buff_ind);

	va_end(arg);

	return (printed);
}
/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}
