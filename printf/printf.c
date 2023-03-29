#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

void stringhy(char *str, int *strlen)
{
	if (!str) // not *
		str = "(null)";
	while (*str)
	{
		*strlen += write(1, str++,1);
	}
}

void hexy(long long int nb, int base, int *strlen)
{
	char *h = "0123456789abcdef";

	if (nb < 0)
	{
		*strlen += write(1, "-",1); // "" cus pointer
		nb *= -1;
	}
	if (nb >= base) // > AND = !!!
		hexy(nb/base, base, strlen); // SIC - just strlen
	*strlen += write(1, &h[nb%base], 1);
}
int ft_printf(const char *format, ...)
{
	int strlen = 0;
	va_list ap;

	va_start(ap, format);
	while (*format)
	{
		if ((*format == '%') && (*(format +1)))
		{
			format++;
			if (*format == 's')
				stringhy(va_arg(ap, char *), &strlen);
			else if (*format == 'd')
				hexy((long long int)va_arg(ap, int), 10, &strlen); // not an array, not *
			else if (*format == 'x')
				hexy((long long int)va_arg(ap, unsigned int), 16, &strlen);
		}
		else
			strlen += write(1, format, 1); // not a & HERE
		format++;
	}
	va_end(ap);
	return(strlen);
}

// int main()
// {
// 	ft_printf("PRINTING: %s\n", "string");
// 	ft_printf("PRINTING: %d\n", -3);
// 	ft_printf("Hexadecimal for %d is %x\n", 42, 42);
// }
