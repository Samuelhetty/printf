#include <unistd.h>

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * puts_mod - prints input buffer
 * @str: buffer to print
 */
void puts_mod(char *str, unsigned int l)
{
	write(STDOUT_FILENO, str, l);
}
