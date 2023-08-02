#include "main.h"

/**
 * print_unsign - writes unsigned long integers to buffer
 * @list: the arguments inventory with most commonly used arguments
 * @n: unsigned long int to print (function can be used for shorts as well)
 */
void print_unsign(inventory_t *list, unsigned long int n)
{
	unsigned long int copy, size;
	int nth;

	size = 1;
	copy = n;
	if (n < 10)
	{
		list->ch0 = ('0' + n);
		write_buffer(list);
	}
	else
	{
		while (copy / 10 != 0)
			copy /= 10, size *= 10;
		while (size > 0)
		{
			nth = n / size;
			list->ch0 = ('0' + nth);
			write_buffer(list);
			n -= nth * size;
			size /= 10;
		}
	}
}

/**
 * print_unsigned - writes unsigned integers to buffer or stdout in decimal
 * @list: the arguments inventory with most commonly used arguments
 */
void print_unsigned(inventory_t *list)
{
	unsigned int n;

	n = va_arg(*(list->arguments), int);

	print_unsign(list, (unsigned long int)n);
}
