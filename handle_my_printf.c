#include "main.h"
/**
 * build_inventory - builds variables inventory
 * @arguments: variadic arguments list
 * @format: format input string
 * Return: struct of arguments initialized
 */
inventory_t *build_inventory(va_list *arguments, const char *format)
	{
	inventory_t *list;

	list = malloc(sizeof(inventory_t) * 1);

	if (list)
	{
		list->buffer = _calloc(BUFSIZE, sizeof(char));
		list->buf_index = 0;
		list->arguments = arguments;
		list->fmt = format;
		list->i = 0;
		list->flag = 0;
		if (!list->buffer)
			list->error = 1;
		else
			list->error = 0;
	}

	return (list);
}


/**
 * parse_specifier - parses character that follow the % character
 * @list: the arguments inventory
 */
void parse_specifier(inventory_t *list)
	{
	int j, i = list->i + 1, space = 0;
	static const char flags[] = "hl+#";

	list->space = 0;
	while (list->fmt[i] == ' ')
		i++, list->i++, space = 1;

	list->ch1 = list->fmt[i++];
	if (space && list->ch1 != '+')
	{
		space = 0, list->space = 1, list->ch0 = ' ';
		write_buffer(list);
	}
	for (j = 0; flags[j] != '\0'; j++)
	{
		if (list->ch1 == flags[j])
		{
			while (list->fmt[i] == ' ')
				i++, list->i++, space = 1;
			if (space && list->ch1 != '+')
			{
				list->ch0 = ' ';
				write_buffer(list);
			}
			break;
		}
	}
	list->ch2 = list->ch1 ? list->fmt[i++] : '\0';
	list->ch0 = list->ch2 ? list->fmt[i] : '\0';
}

/**
* finalize_inventory - terminates _printf() in error cases
* @list: the arguments inventory with most commonly used arguments
* Return: -1 always
*/
int finalize_inventory(inventory_t *list)
	{
	int ret_value;

	if (list)
	{
		ret_value = list->error ? -1 : list->buf_index;
		if (list->i)
			puts_mod(list->buffer, list->buf_index);
		va_end(*(list->arguments));
		if (list->buffer)
			free(list->buffer);
		free(list);
	}
	else
		ret_value = -1;
	return (ret_value);
}

/**
* get_specifier_func - matches specifier function for each conversion specifier
*
* @list: the arguments inventory with most commonly used arguments
* Return: pointer to the helper function or NULL
*/
void (*get_specifier_func(inventory_t *list))(inventory_t *list)
{
	int i = 0;
	char check = list->ch1;
	static get_t specifier_list[] = {
		{'d', print_int}, {'i', print_int}, {'x', print_lowhex},
		{'X', print_uphex}, {'o', print_octal}, {'u', print_unsigned},
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'b', print_binary}, {'p', print_pointer}, {'r', print_rev_string},
		{'R', print_rot13}, {'\0', NULL}
	};
	while (specifier_list[i].ch != '0')
	{
		if (specifier_list[i].ch == check)
		{
			list->i++;
			return (specifier_list[i].func);
		}
		i++;
	}
	return (NULL);
}
