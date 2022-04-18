#include "main.h"

/**
 * print_%
 *
 * @c: character
 * Return: chars_printed
 */
int print_spec(char c)
{
    int chars_printed = 0;

    if (c == '%')
    {
        chars_printed += _putchar('%');
    }
    else
    {
        chars_printed += _putchar('%');
        chars_printed += _putchar(c);
    }
    return (chars_printed);
}