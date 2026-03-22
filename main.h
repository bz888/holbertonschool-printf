#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...);
int _putchar(char c);
int _puts(char *s);
int handle_specifier(char spec, va_list args);
int print_int(int n);

#endif

