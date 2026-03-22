#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: format string
 *
 * Return: number of characters printed, or -1 on failure
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i, count;

	if (!format)
		return (-1);

	va_start(args, format);

	i = 0;
	count = 0;

	while (format && format[i])
	{
		if (format[i] == '%')
		{
			i++;

			if (format[i] == '\0')
			{
				va_end(args);
				return (-1);
			}

			count += handle_specifier(format[i], args);
		}
		else
		{
			count += _putchar(format[i]);
		}

		i++;
	}

	va_end(args);
	return (count);
}

