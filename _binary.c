#include "main.h"

/**
 * print_binary - Print an integer as binary
 * @list: The arguments inventory
 */
void print_binary(inventory_t *list)
{
	unsigned int n = va_arg(*(list->arguments), unsigned int);
	int i, j;
	char *binary, *copy;

	binary = _calloc(33, sizeof(char));
	if (binary)
	{
		for (i = 0; n; i++, n /= 2)
			binary[i] = ((n % 2) + '0');
		if (i == 0)
		{
			list->ch0 = '0';
			write_buffer(list);
		}
		else
		{
			copy = _calloc(i + 1, sizeof(char));
			if (copy)
			{
				for (j = 0, i--; i >= 0; j++, i--)
					copy[j] = binary[i];

				puts_buffer(list, copy);
				free(copy);
			}
			else
				list->error = 1;
		}
		free(binary);
	}
	else
		list->error = 1;
}
