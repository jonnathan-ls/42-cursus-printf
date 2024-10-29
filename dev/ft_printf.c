#include <stdarg.h>
#include "utils.h"

int ft_printf(const char *str, ...)
{
	va_list args;
	int		count;

	// TODO: cobrir cenário quando NULL
	count = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (*str == 'c')
				count += ft_putchar(va_arg(args, int));
			else if (*str == 's')
				count += ft_putstr(va_arg(args, char *));
			else if (*str == 'd' || *str == 'i')
				count += ft_putnbr(va_arg(args, int));
			else if (*str == 'u')
				count += ft_putunbr(va_arg(args, unsigned int));
			else if (*str == 'x')
				count += ft_puthex_lower(va_arg(args, unsigned int));
			else if (*str == 'X')
				count += ft_puthex_upper(va_arg(args, unsigned int));
			else if (*str == 'p')
				count += ft_putptr(va_arg(args, void *));
			else if (*str == '%')
				count += ft_putchar('%');
		}
		else
			count += ft_putchar(*str);
		str++;
	}
	va_end(args);
	return count;
}


#include <stdio.h>
#include <limits.h>
int compare_functions(char type, void *param)
{
	int expected;
	int result;

	if (type == 'c')
	{
		expected =	printf("printf   : %c\n", *(char *)param);
		result = ft_printf("ft_printf: %c\n", *(char *)param);
	}
	else if (type == 's')
	{
		expected =	printf("printf   : %s\n", (unsigned char *)param);
		result = ft_printf("ft_printf: %s\n", (unsigned char *)param);
	}
	else if (type == 'd' || type == 'i')
	{
		expected =	printf("printf   : %d\n", *(int *)param);
		result = ft_printf("ft_printf: %d\n", *(int *)param);
	}
	else if (type == 'x')
	{
		expected =	printf("printf   : %x\n", *(unsigned int *)param);
		result = ft_printf("ft_printf: %x\n", *(unsigned int *)param);
	}
	else if (type == 'X')
	{
		expected =	printf("printf   : %X\n", *(unsigned int *)param);
		result = ft_printf("ft_printf: %X\n", *(unsigned int *)param);
	}
	else if (type == 'p')
	{
		expected =	printf("printf   : %p\n", param);
		result = ft_printf("ft_printf: %p\n", param);
	}
	else if (type == 'u')
	{
		expected =	printf("printf   : %u\n", *(unsigned int *)param);
		result = ft_printf("ft_printf: %u\n", *(unsigned int *)param);
	}
	else if (type == '%')
	{
		expected =	printf("printf   : %%\n");
		result = ft_printf("ft_printf: %%\n");
	}
	else
	{
		printf("Invalid type\n");
		return 0;
	}
	return (expected == result);
}
int main(void)
{
	char c = 255;
	char *s = "\x26Hello, World!\r"; // TODO: cobrir cenário quando NULL
	int n = INT_MIN;

	printf("Result of c: %s\n\n", compare_functions('c', &c) ? "🟩 OK" : "🟥 KO");
	printf("Result of s: %s\n\n", compare_functions('s', s) ? "🟩 OK" : "🟥 KO");
	printf("Result of d: %s\n\n", compare_functions('d', (void *)&n) ? "🟩 OK" : "🟥 KO");
	printf("Result of i: %s\n\n", compare_functions('i', (void *)&n) ? "🟩 OK" : "🟥 KO");
	printf("Result of u: %s\n\n", compare_functions('u', s) ? "🟩 OK" : "🟥 KO");
	printf("Result of x: %s\n\n", compare_functions('x', s) ? "🟩 OK" : "🟥 KO");
	printf("Result of X: %s\n\n", compare_functions('X', s) ? "🟩 OK" : "🟥 KO");
	printf("Result of p: %s\n\n", compare_functions('p', s) ? "🟩 OK" : "🟥 KO"); // TODO: is Fail
	printf("Result of %%: %s\n\n", compare_functions('%', s) ? "🟩 OK" : "🟥 KO");
	return 0;
}