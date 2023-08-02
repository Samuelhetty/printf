#include "main.h"

/**
 * print_hex - writes in base hexidecimal
 * @list: the arguments inventory with most commonly used arguments
 * @n: unsigned long int number to be converted
 * @hexcase: the hexcase either upper or lower
 * @size: the size to be malloc'd
 */
void print_hex(inventory_t *list, unsigned long int n, int hexcase, int size)
{
	int i, j;
	char *hex = NULL, *copy = NULL;
	const char *conv, *pre;
	static const char * const convset[] = {
		"0123456789abcdef", "0123456789ABCDEF", NULL };
	static const char * const preset[] = { "0x", "0X", NULL };

	conv = convset[hexcase];
	if (!n)
	{
		list->ch0 = '0';
		write_buffer(list);
	}
	else
	{
		if (list->ch1 == '#')
		{
			pre = preset[hexcase];
			puts_buffer(list, (char *)pre);
		}
		hex = _calloc(size, sizeof(char));
		if (hex)
		{
			for (i = 0; n; i++, n /= 16)
				hex[i] = conv[n % 16];
			copy = _calloc(i + 1, sizeof(char));
			if (copy)
			{
				for (j = 0, i--; i >= 0; j++, i--)
					copy[j] = hex[i];
				puts_buffer(list, copy);
				free(copy);
			}
			else
				list->error = 1;
			free(hex);
		}
		else
			list->error = 1;
	}
}

/**
 * print_lowhex - writes unsigned integer to buffer in base hexidec downcase
 * @list: the arguments inventory with most commonly used arguments
 */
void print_lowhex(inventory_t *list)
{
	unsigned int n;

	n = va_arg(*(list->arguments), int);

	print_hex(list, (unsigned long int)n, LOWHEX, 9);
}

/**
 * print_uphex - writes unsigned integer to buffer in base hexidecimal upcase
 * @list: the arguments inventory with most commonly used arguments
 */
void print_uphex(inventory_t *list)
{
	unsigned int n;

	n = va_arg(*(list->arguments), int);

	print_hex(list, (unsigned long int)n, UPHEX, 9);
}
