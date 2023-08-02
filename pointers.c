#include "main.h"

/**
 * p_string_hex - writes string to buffer or stdout ascii
 * @list: the arguments inventory with most commonly used arguments
 */
void p_string_hex(inventory_t *list)
{
	char *string, *current, *hexvalues, *null_string;
	int c = 0, num;

	hexvalues = "0123456789ABCDEF";
	null_string = "(null)";
	string = va_arg(*(list->arguments), char*);

	if (!string)
	{
		string = null_string;
		puts_buffer(list, null_string);
	}
	else
	{
		current = _calloc(5, sizeof(char));
		current[0] = 92;
		current[1] = 'x';
		while (string[c] != '\0')
		{
			num = string[c];
			if (num > 31 && num < 127)
			{
				list->ch0 = num;
				write_buffer(list);
			}
			else
			{
				current[2] = hexvalues[(num / 16) % 16];
				current[3] = hexvalues[num % 16];
				puts_buffer(list, current);
			}
			c++;
		}
		free(current);
	}
}
/**
 * print_pointer - writes pointer value (an address) to buffer in hexidecimal
 * @list: the arguments inventory with most commonly used arguments
 */
void print_pointer(inventory_t *list)
{
	int i, j;
	unsigned long int pointer_value;
	char *hex, *null_string, *hexvalues, *copy;
	void *pointer;

	pointer = va_arg(*(list->arguments), void *);
	hexvalues = "0123456789abcdef";
	null_string = "(nil)";

	if (!pointer)
		puts_buffer(list, null_string);
	else
	{
		hex = _calloc(13, sizeof(char));
		puts_buffer(list, "0x");
		pointer_value = (unsigned long int)pointer;
		for (i = 0; pointer_value; i++, pointer_value /= 16)
			hex[i] = hexvalues[pointer_value % 16];
		copy = _calloc(i + 1, sizeof(char));
		for (j = 0, i--; i >= 0; j++, i--)
			copy[j] = hex[i];
		puts_buffer(list, copy);
		free(copy);
		free(hex);
	}
}
