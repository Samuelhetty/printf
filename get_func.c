#include "main.h"

/*************************GET FLAG*************************/
/**
 * get_flags - Calculates active flags
 * @format: Formatted string in which to print the arguments
 * @i: take a parameter.
 * Return: Flags:
 */
int get_flags(const char *format, int *i)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int j, c_par;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (c_par = *i + 1; format[c_par] != '\0'; c_par++)
	{
		for (j = 0; FLAGS_CH[j] != '\0'; j++)
			if (format[c_par] == FLAGS_CH[j])
			{
				flags |= FLAGS_ARR[j];
				break;
			}

		if (FLAGS_CH[j] == 0)
			break;
	}

	*i = c_par - 1;

	return (flags);
}

/*******************GET PRECISION*********************/
/**
 * get_precision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 * @arg: list of arguments.
 *
 * Return: Precision.
 */
int get_precision(const char *format, int *i, va_list arg)
{
	int c_par = *i + 1;
	int precision = -1;

	if (format[c_par] != '.')
		return (precision);

	precision = 0;

	for (c_par += 1; format[c_par] != '\0'; c_par++)
	{
		if (is_digit(format[c_par]))
		{
			precision *= 10;
			precision += format[c_par] - '0';
		}
		else if (format[c_par] == '*')
		{
			c_par++;
			precision = va_arg(arg, int);
			break;
		}
		else
			break;
	}

	*i = c_par - 1;

	return (precision);
}

/*************************GET SIZE*****************/
/**
 * get_size - Calculates the size to cast the argument
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 *
 * Return: Precision.
 */
int get_size(const char *format, int *i)
{
	int c_par = *i + 1;
	int size = 0;

	if (format[c_par] == 'l')
		size = S_LONG;
	else if (format[c_par] == 'h')
		size = S_SHORT;

	if (size == 0)
		*i = c_par - 1;
	else
		*i = c_par;

	return (size);
}

/**************GET WIDTH********************/
/**
 * get_width - Calculates the width for printing
 * @format: Formatted string in which to print the arguments.
 * @i: List of arguments to be printed.
 * @arg: list of arguments.
 *
 * Return: width.
 */
int get_width(const char *format, int *i, va_list arg)
{
	int c_par;
	int width = 0;

	for (c_par = *i + 1; format[c_par] != '\0'; c_par++)
	{
		if (is_digit(format[c_par]))
		{
			width *= 10;
			width += format[c_par] - '0';
		}
		else if (format[c_par] == '*')
		{
			c_par++;
			width = va_arg(arg, int);
			break;
		}
		else
			break;
	}

	*i = c_par - 1;

	return (width);
}
