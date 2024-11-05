#include <stdio.h>
#include <limits.h>
#include "../ft_printf.h"

int	compare_functions(char type, void *param)
{
	int	expected;
	int	result;

	if (type == 'c')
	{
		expected =	printf("printf   : %c \t\t\t", *(char *)param);
		result = ft_printf("ft_printf: %c \t\t\t", *(char *)param);
	}
	else if (type == 's')
	{
		expected =	printf("printf   : %s \t", (unsigned char *)param);
		result = ft_printf("ft_printf: %s \t", (unsigned char *)param);
		if (expected <= 15) write(1, "\t\t", 2);
		if (result <= 15) printf("\t\t");
		if (!param)
		{
			write(1, "\t", 2);
			printf("\t");
		}
	}
	else if (type == 'd' || type == 'i')
	{
		expected =	printf("printf   : %a \t\t\t", *(double *)param);
		result = ft_printf("ft_printf: %a \t\t\t", *(double *)param);
	}
	else if (type == 'x')
	{
		expected =	printf("printf   : %x \t\t", *(unsigned int *)param);
		result = ft_printf("ft_printf: %x \t\t", *(unsigned int *)param);
		if (expected < 20) write(1, "\t", 2);
		if (result < 20) printf("\t");
	}
	else if (type == 'X')
	{
		expected =	printf("printf   : %X \t\t", *(unsigned int *)param);
		result = ft_printf("ft_printf: %X \t\t", *(unsigned int *)param);
		if (expected < 20) write(1, "\t", 2);
		if (result < 20) printf("\t");
	}
	else if (type == 'p')
	{
		expected =	printf("printf   : %p \t", param);
		result = ft_printf("ft_printf: %p \t", param);
		if (expected < 25){
			write(1, "\t", 2);
			printf("\t");
		}
	}
	else if (type == 'u')
	{
		expected =	printf("printf   : %u \t\t", *(unsigned int *)param);
		result = ft_printf("ft_printf: %u \t\t", *(unsigned int *)param);
		if (expected < 20) write(1, "\t", 2);
		if (result < 20) printf("\t");
	}
	else if (type == '%')
	{
		expected =	printf("printf   : %% \t\t\t");
		result = ft_printf("ft_printf: %% \t\t\t");
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
	int c[] = { INT_MIN, -42, 0, 42, INT_MAX };
	int n[] = { INT_MIN, -42, 0, 42, INT_MAX };
	char *s[] = { "Hello, World!", "\x23", "\b", "42", "", NULL };

	for (int i = 0; i < 5; i++)
		printf("Result of c: %s \n", compare_functions('c', &c[i]) ? "🟩 OK" : "🟥 KO");

	for (int i = 0; i < 5; i++)
	{
		printf("Result of s: %s \n", compare_functions('s', s[i]) ? "🟩 OK" : "🟥 KO");
		printf("Result of p: %s \n", compare_functions('p', s[i]) ? "🟩 OK" : "🟥 KO");
		printf("Result of %%: %s \n", compare_functions('%', s[i]) ? "🟩 OK" : "🟥 KO");
	}

	for (int i = 0; i < 5; i++)
	{
		printf("Result of d: %s \n", compare_functions('d', &n[i]) ? "🟩 OK" : "🟥 KO");
		printf("Result of i: %s \n", compare_functions('i', &n[i]) ? "🟩 OK" : "🟥 KO");
		printf("Result of u: %s \n", compare_functions('u', &n[i]) ? "🟩 OK" : "🟥 KO");
		printf("Result of x: %s \n", compare_functions('x', &n[i]) ? "🟩 OK" : "🟥 KO");
		printf("Result of X: %s \n", compare_functions('X', &n[i]) ? "🟩 OK" : "🟥 KO");
	}
	return (0);
}