#include "main.h"

/**
 * _printf - prints anything
 * @format: the format string
 *
 * Return: number of bytes printed
 */
#include "main.h"

/**
 * _printf - Function that prints formatted output.
 *
 * @format: a string composed of zero or more characters to print or use as
 * directives that handle subsequent arguments and special characters.
 *
 * Description: This function can take a variable number and type of arguments
 * that should be printed to standard output.
 *
 * Return: int
 */
int _printf(const char *format, ...)
{
    va_list args;
    int i = 0, chars_printed = 0;

    va_start(args, format);
    while (format && format[i])
    {
        if (format[i] != '%')
        {
            chars_printed += _putchar(format[i]);
        }
        else if (format[i + 1])
        {
            i++;
            if (format[i] == 'c' || format[i] == 's')
                chars_printed += format[i] == 'c' ? _putchar(va_arg(args, int)) : print_string(va_arg(args, char *));

            chars_printed += print_unknown_spec(format[i]);
        }
        i++;
    }
    va_end(args);
    return (chars_printed);
}