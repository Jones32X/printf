#include "main.h"

/**
 * _printf - printf function.
 * @format: variable
 * Return:  printed for printing.
 */

int _printf(const char *format, ...)
{
	va_list list;
	unsigned int ice;
	unsigned int char_num;
	char_num = 0;
	ice = 0;

	if (!format)
	{
		return (-1);
	}

	va_start(list, format);
	for (; format[ice] != '\0'; ice++)
	{
		if (format[ice] == '%')
		{
			if (format[ice + 1] == '\0')
				return (-1);

			else if (format[ice + 1] == '%')
			{
				_putchar('%');
				char_num++;
				ice++;
			}
			else if (cmp_func(format[ice + 1]) != NULL)
			{
				char_num += (cmp_func(format[ice + 1]))(list);
				ice++;
			}
			else
			{
				_putchar(format[ice]);
				char_num++;
			}
		}
		else
		{
			_putchar(format[ice]);
			char_num++;
		}
	}
	va_end(list);
	return (char_num);
}

/**
 * cmp_func - Entry point
 * @a: character.
 * Return: 0.
 */

int (*cmp_func(const char a))(va_list)
{
	print_f printf[] = {
		{'c', printc},
		{'s', print_string},
		{'d', print_n},
		{'i', print_n},
		{'\0', NULL}
	};

	int kit;
	kit = 0;

	for (; printf[kit].tx != '\0'; kit++)
	{
		if (printf[kit].tx == a)
		{
			return (printf[kit].func);
		}
	}

	return (0);
}
