#include "main.h"

/**
 * printf_binary - prints a binary number
 * @num: number arguements
 * @printed: the printed characters
 * Return: printed charcaters
 */

int printf_binary(unsigned int num, int printed)
{
	int Bin[32] = {0};
	int ice;

	ice = 0;

	if (num == 0)
	{
		_putchar('0');
		printed++;
		return (printed);
	}

	while (num > 0)
	{
		Bin[ice] = num % 2;
		num /= 2;
		ice++;
	}

	while (ice > 0)
	{
		ice--;
		_putchar('0' + Bin[ice]);
		printed++;
	}

	return (printed);
}
