#include "main.h"

/**
 * _oct - function to print octal
 * @octo: list being passed
 * Return: updated count
 */
int _oct(va_list octo)
{
	int count = 0, i;
	int *arr;
	unsigned int n = va_arg(octo, unsigned int);
	unsigned int tmp = n;

	while (n / 8 != 0)
	{
		n /= 8;
		count++;
	}
	count++;
	arr = malloc(count * sizeof(int));
	for (i = 0; i < count; i++)
	{
		arr[i] = tmp % 8;
		tmp /= 8;
	}
	for (i = count - 1; i >= 0; i--)
	{
		_putchar(arr[i] + '0');
	}
	free(arr);
	return (count);
}
