/* Online C compiler to run C program online */
#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * _printf - function that produces output according to a format.
 * @format: pointer to character string composed of 0 or more directives.
 *
 * write output to stdout, the standard output stream.
 * You need to handle the following conversion specifiers: c, s, %.
 * You don’t have to reproduce the buffer handling of the C library printf,
 * function.
 * You don’t have to handle the flag characters.
 * You don’t have to handle field width.
 * You don’t have to handle precision.
 * You don’t have to handle the length modifiers.
 *
 * Return: the number of characters printed excluding the null byte,
 * used to end output strings.
 */

int _printf(const char *format, ...)
{
	unsigned int i = 0, len = 0, ibuf = 0;
	va_list arguments;
	int (*function)(va_list, char *, unsigned int);
	char *buffer;

	va_start(arguments, format), buffer = malloc(sizeof(char) * 1024);
	if (!format || !buffer || (format[i] == '%' && !format[i + 1]))
		return (-1);
	if (!format[i])
		return (0);
	for (i = 0; format && format[i]; i++)
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
			{	print_buf(buffer, ibuf), free(buffer), va_end(arguments);
				return (-1);
			}
			else
			{	function = get_print_func(format, i + 1);
				if (function == NULL)
				{
					if (format[i + 1] == ' ' && !format[i + 2])
						return (-1);
					handl_buf(buffer, format[i], ibuf), len++, i--;
				}
				else
				{
					len += function(arguments, buffer, ibuf);
					i += ev_print_func(format, i + 1);
				}
			} i++;
		}
		else
			handl_buf(buffer, format[i], ibuf), len++;
		for (ibuf = len; ibuf > 1024; ibuf -= 1024)
			;
	}
	print_buf(buffer, ibuf), free(buffer), va_end(arguments);
	return (len);
}
