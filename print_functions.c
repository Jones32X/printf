#include "main.h"
/**
 * _putchar - Entry function write characteres
 * @c: var va_list
 * Return: Written char
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * printc - Prints character
 * @list: variable va_list
 * Return: 1 Success
 */

int printc(va_list list)
{
	_putchar(va_arg(list, int));
	return (1);

}

/**
 * print_string - Prints string
 * @s: variable va_list
 * Return: k else 6 on NULL
 */

int print_string(va_list s)
{
	char *string;
	int kte;

	string = va_arg(s, char*);
	if (string == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	else
	{
		for (kte = 0; string[kte] != '\0'; kte++)
		{
			_putchar(string[kte]);
		}
	}
	return (kte);
}
/**
 * print_n - Prints num
 * @n: Variable va_list
 * Return: Count
 */

int print_n(va_list n)
{

	long int num;
	int counter, bse;
	int AuX_var;

	counter = 0;
	num = va_arg(n, int);

	if (num < 0)
	{
		num *= -1;
		_putchar(45);
		counter++;
	}
	if (num >= 0 && num <= 9)
	{
		_putchar(num + 48);
		counter++;
	}
	if (num > 9)
	{
		bse = 10;

		while (num / bse > 9)
		{
			bse *= 10;
		}

		while (bse > 0)
		{
			AuX_var = num / bse;
			num = num % bse;
			_putchar(AuX_var + 48);
			bse = bse / 10;
			counter++;
		}
	}
	return (counter);
}
