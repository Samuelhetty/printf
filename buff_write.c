#include "main.h"
/**
 * write_buffer - adds input char to buffer 1 at a time
 * @list: the arguments inventory with most commonly used arguments
 */
void write_buffer(inventory_t *list)
{
	unsigned int old, new;
	char *temp;

	if (list->buffer)
	{
		list->buffer[list->buf_index++] = list->ch0;

		if ((list->buf_index + 1) % BUFSIZE == 0)
		{
			old = list->buf_index + 1;
			new = old + BUFSIZE;
			temp = _realloc(list->buffer, old, new);

			if (!temp)
				list->error = 1;
			else
				list->buffer = temp;
		}
	}
}

/**
 * puts_buffer - puts string to buffer without newline
 * @list: the arguments inventory with most commonly used arguments
 * @s: string to print
 */
void puts_buffer(inventory_t *list, char *s)
{
	int i, l;

	l = _strlen(s);

	for (i = 0; i < l; i++)
	{
		list->ch0 = s[i];
		write_buffer(list);
	}
}
