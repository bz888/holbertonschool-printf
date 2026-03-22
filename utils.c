#include "main.h"

/**
 * _putchar - writes a character to stdout
 * @c: character to print
 *
 * Return: 1 on success
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - writes a string to stdout
 * @s: string to print
 *
 * Return: number of characters printed
 */
int _puts(char *s)
{
	int count;

	if (s == NULL)
		s = "(null)";

	count = 0;

	while (s[count] != '\0')
	{
		_putchar(s[count]);
		count++;
	}

	return (count);
}

/**
 * handle_specifier - handles format specifiers
 * @spec: format specifier character
 * @args: argument list
 *
 * Return: number of characters printed
 */
int handle_specifier(char spec, va_list args)
{
	char c;
	char *s;

	if (spec == 'c')
	{
		c = va_arg(args, int);
		return (_putchar(c));
	}

	if (spec == 's')
	{
		s = va_arg(args, char *);
		return (_puts(s));
	}

	if (spec == '%')
		return (_putchar('%'));

	return (_putchar('%') + _putchar(spec));
}

