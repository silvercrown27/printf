#include "main.h"

/**
 * get_flags - Computes active flags
 * @format: Format to print the arguments
 * @i: receive a parameter.
 * Return: return flags:
 */

int get_flags(const char *format, int *i)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int j, arg_i;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (arg_i = *i + 1; format[arg_i] != '\0'; arg_i++)
	{
		for (j = 0; FLAGS_CH[j] != '\0'; j++)
			if (format[arg_i] == FLAGS_CH[j])
			{
				flags |= FLAGS_ARR[j];
				break;
			}

		if (FLAGS_CH[j] == 0)
			break;
	}

	*i = arg_i - 1;

	return (flags);
}
