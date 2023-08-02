#include "main.h"
/**
* print_char - writes char to buffer or standard output
* @list: the arguments inventory with most commonly used arguments
* Return: number of chars wrote to buffer
*/
void print_char(inventory_t *list)
{
	list->ch0 = va_arg(*(list->arguments), int);
	write_buffer(list);
}
/**
* print_percent - writes a percent symbol to buffer or stdout
* @list: the arguments inventory with most commonly used arguments
* Return: number of chars wrote to buffer
*/
void print_percent(inventory_t *list)
{
	list->ch0 = '%';

	if (list->space)
	{
		list->space = 0;
		list->buffer[--(list->buf_index)] = '\0';
	}
	write_buffer(list);
}
/**
* print_string - writes string to buffer or stdout
* @list: the arguments inventory with most commonly used arguments
* Return: number of chars wrote to buffer
*/
void print_string(inventory_t *list)
{
	int l;
	char *string, *null_string;

	string = va_arg(*(list->arguments), char *);
	null_string = "(null)";

	if (string == NULL)
		string = null_string;

	l = _strlen(string);
	if (l)
		puts_buffer(list, string);
}
/**
* _strlen - returns the length of a string
*
* @s: string
* Return: length
*/
size_t __attribute__ ((warn_unused_result)) _strlen(const char *s)
{
	size_t longi = 0;

	while (*s++)
	{
		longi++;
	}
	return (longi);
}
