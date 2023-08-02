#include "main.h"

/**
 * print_integers - writes integers to buffer
 * @list: the arguments inventory with most commonly used arguments
 * @n: integer to be printed, may be type casted to long int.
 */
void print_integers(inventory_t *list, int n)
{
	int size, ones, copy;
	int nth;

	copy = n < 0 ? -n : n;
	ones = copy % 10;
	size = 1;
	copy /= 10;

	if (n < 0)
	{
		list->ch0 = '-';
		write_buffer(list);
	}
	else if (list->ch1 == '+')
	{
		list->ch0 = '+';
		write_buffer(list);
	}
	if (copy > 0)
	{
		while (copy != 0)
			copy /= 10, size *= 10;

		copy = n < 0 ? -n : n;

		while (size > 0)
		{
			nth = copy / size;
			list->ch0 = ('0' + nth);
			write_buffer(list);
			copy -= nth * size;
			size /= 10;
		}
	}
	list->ch0 = ('0' + ones);
	write_buffer(list);
}

/**
 * print_int - writes integers to buffer
 * @list: the arguments inventory with most commonly used arguments
 */
void print_int(inventory_t *list)
{
	int n;

	n = va_arg(*(list->arguments), int);

	print_integers(list, n);
}
