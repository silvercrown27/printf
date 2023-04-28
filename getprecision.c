#include "main.h"
#include <stdarg.h>

/**
 * get_precision - The fn gets the precision for printing
 * @format: Format to print the arguments
 * @i:arguments.
 * @list: arguments list.
 * Return: Precision.
 */

int get_precision(const char *format, int *i, va_list list)
{
	int arg_i = *i + 1;
	int precision = -1;

	if (format[arg_i] != '.')
		return (precision);

	precision = 0;

	for (arg_i += 1; format[arg_i] != '\0'; arg_i++)
	{
		if (is_digit(format[arg_i]))
		{
			precision *= 10;
			precision += format[arg_i] - '0';
		}
		else if (format[arg_i] == '*')
		{
			arg_i++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = arg_i - 1;

	return (precision);
}
