#include <stdarg.h>
#include <unistd.h>
#include "main.h"
#include <string.h>
#include <stdio.h>

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
 * _printf - prints formatted output
 * @format: the format string
 *
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	int i = 0;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			i++;
				if (*format == 'c')
				format++;

				if (*format == 'c')
				{
					char c = va_arg(args, int);

					write(1, &c, 1);
					count++;
				}
				else if (*format == 's')
				{
					char *s = va_arg(args, char *);
					int len = 0;

					while (*s)
					{
						write(1, s, 1);
						s++;
						len++;
						count++;
					}
				}
				else if (*format == '%')
				{
					write(1, "%", 1);
					count++;
				}
				else if (*format == 'd' || *format == 'i')
				{
					int value = va_arg(args, int);
					char buffer[1024];

					sprintf(buffer, "%d", value);
					fputs(buffer, stdout);
					count += (int)strlen(buffer);
				}
				else if (*format == 'u')
				{
					unsigned int value = va_arg(args, unsigned int);
					char buffer[1024];

					sprintf(buffer, "%u", value);
					fputs(buffer, stdout);
					count += (int)strlen(buffer);
				}
				else if (*format == 'o')
				{
					unsigned int value = va_arg(args, unsigned int);
					char buffer[1024];

					sprintf(buffer, "%o", value);
					fputs(buffer, stdout);
					count += (int)strlen(buffer);
				}
				else if (*format == 'x')
				{
					unsigned int value = va_arg(args, unsigned int);
					char buffer[1024];

					sprintf(buffer, "%x", value);
					fputs(buffer, stdout);
					count += (int)strlen(buffer);
				}
				else if (*format == 'X')
				{
					unsigned int value = va_arg(args, unsigned int);
					char buffer[1024];

					sprintf(buffer, "%X", value);
					fputs(buffer, stdout);
					count += (int)strlen(buffer);
				}
				else if (*format == 'S')
				{
					unsigned int value = va_arg(args, unsigned int);
					char buffer[1024];

					sprintf(buffer, "%s", value);
					fputs(buffer, stdout);
					count += (int)strlen(buffer);
				}
				else if (*format == 'p')
				{
					void *value = va_arg(args, void *);
					char buffer[1024];

					sprintf(buffer, "%p", value);
					fputs(buffer, stdout);
					count += (int)strlen(buffer);
				}
				else if (*format == 'b')
				{
					unsigned int value = va_arg(args, unsigned int);
					char buffer[1024];

					sprintf(buffer, "%b", value);
					fputs(buffer, stdout);
					count += (int)strlen(buffer);
				}
				else
				{
					_putchar(*format);
					count++;
				}
				i++;
		}
		else
		{
			_putchar(*format);
			count++;
			i++;
		}
	}

	va_end(args);

	return (count);
}
