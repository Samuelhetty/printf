#include "main.h"

/**
 * print_rev_string - writes string to buffer or stdout in reverse
 * @list: the arguments inventory with most commonly used arguments
 * Return: number of chars wrote to buffer
 */
void print_rev_string(inventory_t *list)
{
	int i = 0, j, len;
	char *string, *copy;

	string = va_arg(*(list->arguments), char *);

	len = _strlen(string);
	if (len == 1)
	{
		list->ch0 = string[0];
		write_buffer(list);
	}
	else
	{
		copy = _calloc(len + 1, sizeof(char));
		for (i = len - 1, j = 0; i >= 0; i--, j++)
			copy[j] = string[i];

		puts_buffer(list, copy);
		free(copy);
	}
}

/**
 * print_rot13 - translates string to ROT13 and writes to stdout buffer
 * @list: the arguments inventory with most commonly used arguments
 * Return: string after conversion of ROT13
 */
void print_rot13(inventory_t *list)
{
	int i, j, l;
	char *alphabet, *rot_13, *str, *copy;

	alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	rot_13 =   "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";
	str = va_arg(*(list->arguments), char *);
	l = str ? _strlen(str) : 0;

	if (l)
	{
		copy = _calloc(l + 1, sizeof(char));

		for (i = 0; str[i] != '\0'; i++)
		{
			for (j = 0; j < 52; j++)
			{
				if (str[i] == alphabet[j])
				{
					copy[i] = rot_13[j];
					break;
				}
			}
			if (j == 52)
				copy[i] = str[i];
		}

		puts_buffer(list, copy);
		free(copy);
	}
}
