#include "main.h"

/**
 * ch - function to return char
 * @character: list given
 * Return: number of char printed
 */
int ch(va_list character)
{
	return (_putchar(va_arg(character, int)));
}
