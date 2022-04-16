#include "main.h"

/**
 * _hex_str - converts the number from base 10 to hex
 * @n: number to be converted
 * @hex: base of 16 being passed
 * @alpha: Char 'A' to 'F' or 'a' to 'f'
 * Return: number of chars printed
 */
int _hex_str(unsigned int n, unsigned int hex, char alpha)
{
	unsigned int a = n % hex;
	unsigned int b = n / hex;
	char c;

	if (a > 10)
		c = (a - 10) + alpha;
	else
		c = a + '0';
	if (b == 0)
	{
		return (_putchar(c));
	}
	if (b < hex)
	{
		if (b > 10)
			return (_putchar(b - 10 + alpha) + _putchar(c));
		return (_putchar(b + '0') + _putchar(c));
	}
	return (_hex_str(b, hex, alpha) + _putchar(c));
}

/**
 * _hex_l - printing lower case hexa
 * @hexa: argument recieved
 * Return: no of char printed
 */
int _hex_l(va_list hexa)
{
	return (_hex_str(va_arg(hexa, unsigned int), 16, 'a'));
}

/**
 * _hex_u - printing upper case hexa
 * @hexa: argument recieved
 * Return: no. of char printed
 */
int _hex_u(va_list hexa)
{
	return (_hex_str(va_arg(hexa, unsigned int), 16, 'A'));
}
