#include "holberton.h"
/**
 * print_int - print integer
 * @ap:va_list pointer for integer handle %i
 * @modif:struct modifier containig modifier fields
 * Return:int length
 */
int print_int(modifier_t *modif, va_list ap)
{
	int long x, count = 0, aux, num = 1;
	unsigned int long div = 1;

	if (!ap || !modif)
		return (0);

	x = va_arg(ap, int);
	if (x < 0)
	{
		_putchar('-');
		num = -x;
		count++;
	}
	else
		num = x;

	aux = num / 10;
	while (aux != 0)
	{
		aux /= 10;
		div *= 10;
	}

	while (div != 1)
	{
		_putchar((num / div) + '0');
		count++;
		num %= div;
		div /= 10;
	}

	_putchar(num + '0');
	count++;
	return (count);
}
