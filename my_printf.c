#include "main.h"
/**
 * _printf - replication of some of the features from C function printf()
 * @format: character string of directives, flags, modifiers, & specifiers
 * Description: This function uses the variable arguments functionality and is
 * supposed to resemble printf().
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list arguments;
	inventory_t *list;
	void (*specifier_func)(inventory_t *);

	if (!format)
		return (-1);

	va_start(arguments, format);
	list = build_inventory(&arguments, format);

	while (list && format[list->i] && !list->error)
	{
		list->ch0 = format[list->i];

			if (list->ch0 != '%')
				write_buffer(list);
			else
			{
				parse_specifier(list);
				specifier_func = get_specifier_func(list);

				if (specifier_func)
					specifier_func(list);
				else if (list->ch1)
				{
					if (list->flag)
						list->flag = 0;
					write_buffer(list);
				}
				else
				{
					if (list->space)
						list->buffer[--(list->buf_index)] = '0';
					list->error = 1;
				}
			}
		list->i++;
	}
	return (finalize_inventory(list));
}
