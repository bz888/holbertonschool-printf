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
	int n;

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

	if (spec == 'd' || spec == 'i')
	{
		n = va_arg(args, int);
		return (print_int(n));
	}

	return (_putchar('%') + _putchar(spec));
}

/**
 * print_int - prints an integer
 * @n: integer to print
 *
 * Return: number of characters printed
 */
int print_int(int n)
{
	long num;
	int count;

	num = n;
	count = 0;

	if (num < 0)
	{
		count += _putchar('-');
		num = -num;
	}

	if (num / 10 != 0)
		count += print_int(num / 10);

	count += _putchar((num % 10) + '0');

	return (count);
}

