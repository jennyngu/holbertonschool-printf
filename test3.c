#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>


int _printf(const char *format, ...)
{
	va_list ap;
	int i;
	int j;
	int num_of_chars;
	char *str;

    	va_start (ap, format);

	i = 0;
	num_of_chars = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '%')
			{
				putchar('%');
				i = i + 1;
				num_of_chars = num_of_chars + 1;
			}
			if (format[i + 1] == 'c')
			{
				putchar(va_arg(ap, int));
				i = i + 1;
				num_of_chars = num_of_chars + 1;
			}
			if (format[i + 1] == 's')
			{
				j = 0;
				str = va_arg(ap, char*);
				while (*str != '\0')
				{
					putchar(*str);
					str = str + 1;
					num_of_chars = num_of_chars + 1;
				}
			}
		}
		else
		{
			putchar(format[i]);
			num_of_chars = num_of_chars + 1;
		}
		i = i + 1;
	}

	va_end(ap);
	return (num_of_chars);
}

void main()
{
	char h;
	int i;
	char *string;
	int len, len1;

	string = "Hello";
	i = '%';
	_printf("This is a == %s\n", string);
	printf("This is a == %s\n", string);
	printf("_printf = %d, printf = %d\n", len, len1);
}
