#include "main.h"

/**
 * str - prints string to stdout
 * @string: list
 * Return: number of char
 */
int str(va_list string)
{
	int len;
	char *str;

	str = va_arg(string, char *);

	if (str == NULL)
		str = "(null)";
	len = 0;

	while (str[len] != '\0')
		len = len + _putchar(str[len]);
	return (len);
}
