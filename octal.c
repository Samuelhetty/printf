#include "main.h"

/**
 * print_oct- writes unsigned long integer to buffer or stdout in base 8
 * @list: the arguments inventory with most commonly used arguments
 * @n: integer to be printed in octal
 * @size: the size to be malloc'd
 */
void print_oct(inventory_t *list, unsigned long int n, int size)
{
	int i, j;
	char *octal, *copy;

	if (!n)
	{
		list->ch0 = '0';
		write_buffer(list);
	}
	else
	{
		octal = _calloc(size, sizeof(char));
		if (octal)
		{
			for (i = 0; n; i++, n /= 8)
				octal[i] = (n % 8 + '0');
			copy = _calloc(i + 1, sizeof(char));
			if (copy)
			{
				for (j = 0, i--; i >= 0; j++, i--)
					copy[j] = octal[i];
				if (list->ch1 == '#')
				{
					list->ch0 = '0';
					write_buffer(list);
				}
				puts_buffer(list, copy);
				free(copy);
			}
			else
				list->error = 1;
			free(octal);
		}
		else
			list->error = 1;
	}
}

/**
 * print_octal- writes unsigned integer to buffer in base 8: octal
 * @list: the arguments inventory with most commonly used arguments
 */
void print_octal(inventory_t *list)
{
	unsigned int n;

	n = va_arg(*(list->arguments), int);

	print_oct(list, (unsigned long int)n, 12);
}
