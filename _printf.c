#include "main.h"
#include <stdarg.h>

/**
 * _printf - function that prints input
 * @format: input that states the format of the output
 * @...: arguments for the function
 *
 * Return: 0 if successful else 1
 */

int _printf(const char *format, ...)
{
	va_list args;
	constant char *f = format;
	char *specialchars[] = "%/";

}
