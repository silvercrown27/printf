#include <stdio.h>
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
        const char *f = format;
        va_start(args, format);
        char specialchars[2] = {37, 92};
        char *specialnum = "cdefgiosux%";
        char *specialkeys = "abfnrtv";

        for (; *f; f++)
        {
            if (*f == specialchars[0])
            {
                f++;
                while (*specialnum)
                {
                    if (*f == *specialnum)
                    {
                        // if (*specialnum == 'c')
                        // {
                        //     char c = va_arg(args, int);
                        //     continue;
                        // }
                        if (*specialnum == 'd')
                        {
                            char d = va_arg(args, int);
                        }
                        if (*specialnum == 'e')
                        {
                            char e = va_arg(args, double);
                        }
                        if (*specialnum == 'g')
                        {
                            char g = va_arg(args, double);
                        }
                        if (*specialnum == 'i')
                        {
                            char i = va_arg(args, int);
                        }
                        if (*specialnum == 'o')
                        {
                            char o = va_arg(args, int);
                        }
                        if (*specialnum == 's')
                        {
                            char c = va_arg(args, int);
                        }
                        if (*specialnum == 'u')
                        {
                            char u = va_arg(args, int);
                        }
                        if (*specialnum == 'x')
                        {
                            int x = va_arg(args, int);
                        }
                        if (*specialnum == '%')
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
                        if (*specialkeys == '\\')
                        {
                            putchar(92);
                        }
                        if (*specialkeys == '%')
                        {
                            putchar(37);
                        }
                    }
                    specialkeys++;
                }
                continue;

            }
            else
                putchar(*f);
        }
        putchar('\n');
        va_end(args);
        return (0);

}

int main(void)
{
    _printf("Hello\nworld\tand\tgoodbye");
}
