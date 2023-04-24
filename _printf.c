#include <stdio.h>
#include <stdarg.h>

/**
 * printint - function that prints long integers
 * @n: Input number
 *
 * Return: No value
 */

void printint(long n)
{
	if (n < 0)
	{
		putchar('-');
		n = -n;
	}

	if (n/10)
		printint(n/10);

	putchar(n % 10 + '0');
}

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
	const char *f = format;
	va_start(args, format);
	char specialchars[3] = {37, 92};
	char *specialnum = "cdefgiosux%";
	char *specialkeys = "abfnrtv%\\";

	while (*f)
	{
		if (*f == specialchars[0])
		{
			f++;
			while (*specialnum)
			{
				if (*f == *specialnum)
				{
					if (*specialnum == 'c')
					{
						char c = va_arg(args, int);
						putchar(c);
					}
					else if (*specialnum == 'd')
					{
						int d = va_arg(args, int);                        
						printint(d);

					}
					else if (*specialnum == 'e')
					{
						char e = va_arg(args, double);
						printint(e);
					}
					else if (*specialnum == 'f')
					{
						char f = va_arg(args, double);
						printint(f);
					}
					else if (*specialnum == 'i')
					{
						char i = va_arg(args, int);
						printint(i);
					}
					else if (*specialnum == 'o')
					{
						char o = va_arg(args, int);
					}
					else if (*specialnum == 's')
					{
						char *s = va_arg(args, char*);
						if (s == NULL)
							putchar('\0');
						else
						{
							_printf(s);
							s++;
						}
					}
					else if (*specialnum == 'u')
					{
						char u = va_arg(args, int);
					}
					else if (*specialnum == 'x')
					{
						int x = va_arg(args, int);
					}
					else if (*specialnum == '%')
					{
						putchar(37);
					}
				}
				specialnum++;
			}
		}
		else if (*f == specialchars[1])
		{
			f++;
			while (*specialkeys)
			{
				if (*f == *specialkeys)
				{
					if (*specialkeys == 'a')
					{
						putchar('\a');
					}
					if (*specialkeys == 'b')
					{
						putchar('\b');
					}
					if (*specialkeys == 'f')
					{
						putchar('\f');
					}
					if (*specialkeys == 'n')
					{
						putchar('\n');
					}
					if (*specialkeys == 'r')
					{
						putchar('\r');
					}
					if (*specialkeys == 't')
					{
						putchar('\t');
					}
					if (*specialkeys == 'v')
					{
						putchar('\v');
					}
					if (*specialkeys == 92)
					{
						putchar(92);
					}
					if (*specialkeys == 37)
					{
						putchar(37);
					}
				}
				specialkeys++;
			}
		}
		else
		{
			putchar(*f);
		}
		f++;
	}
	putchar('\n');
	va_end(args);
	return (0);

}

/**
 * main - this is the main functionnt main(void)
 * Return: 0 if succesful
 */
int main(void)
{
	_printf("1: string - %s2: char - %c\n2: int - %d\nEnd.", "blue", 'n', 756);
}
