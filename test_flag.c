#include "ft_printf.h"

#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void)
{
	char *str =	ft_strdup("Hello, world!");
	int i = 42;
	unsigned int ui = 2024;
	// Testando flag '-'
	printf("printf Flag '-':\n");
	printf("|%-20c|\n", 'c');
	printf("|%-20s|\n", str);
	printf("|%-20p|\n", str);
	printf("|%-20d|\n", i);
	printf("|%-20d|\n", -i);
	printf("|%-20i|\n", i);
	printf("|%-20i|\n", -i);
	printf("|%-20u|\n", i);
	printf("|%-20u|\n", -i);
	printf("|%-20x|\n", ui);
	printf("|%-20X|\n", ui);

	printf("\n\nFt_printf flag '-':\n");
	ft_printf("|%-20c|\n", 'c');
	ft_printf("|%-20s|\n", str);
	ft_printf("|%-20p|\n", str);
	ft_printf("|%-20d|\n", i);
	ft_printf("|%-20d|\n", -i);
	ft_printf("|%-20i|\n", i);
	ft_printf("|%-20i|\n", -i);
	ft_printf("|%-20u|\n", i);
	ft_printf("|%-20u|\n", -i);
	ft_printf("|%-20x|\n", ui);
	ft_printf("|%-20X|\n", ui);

	// // Testando flag '0'
	// printf("\nFlag '0':\n");
	// printf("|%020d|\n", i);
	// printf("|%020d|\n", -i);
	// printf("|%020u|\n", i);
	// printf("|%020u|\n", -i);
	// printf("|%020f|\n", f);
	// printf("|%020f|\n", -f);

	// // Testando flag '.'
	// printf("\nFlag '.':\n");
	// printf("|%.5s|\n", str);
	// printf("|%.5d|\n", i);
	// printf("|%.5d|\n", -i);
	// printf("|%.5u|\n", i);
	// printf("|%.5u|\n", -i);
	// printf("|%.5f|\n", f);
	// printf("|%.5f|\n", -f);

	// // Testando flag '#'
	// printf("\nFlag '#':\n");
	// printf("|%#x|\n", i);
	// printf("|%#X|\n", i);	
	// printf("|%#f|\n", f);


	// // Testando flag ' '
	// printf("\nFlag ' ':\n");
	// printf("|% d|\n", 42);
	// printf("|% d|\n", -42);

	// // Testando flag '+'
	// printf("\nFlag '+':\n");
	// printf("|%+d|\n", 42);
	// printf("|%+d|\n", -42);
	// printf("|%+f|\n", f);
	// printf("|%+f|\n", -f);

	// // Testando largura mínima
	// printf("\nLargura mínima:\n");
	// printf("|%20c|\n", 'c');
	// printf("|%20s|\n", str);
	// printf("|%20p|\n", str);
	// printf("|%20d|\n", i);
	// printf("|%20d|\n", -i);
	// printf("|%20u|\n", i);
	// printf("|%20u|\n", -i);
	// printf("|%20f|\n", f);
	// printf("|%20f|\n", -f);

	// // Testando combinações de flags
	// printf("\nCombinações de flags:\n");
	// printf("|%020.5d|\n", i);
	// printf("|%020.5d|\n", -i);
	// printf("|%020.5u|\n", i);
	// printf("|%020.5u|\n", -i);
	// printf("|%020.5f|\n", f);
	// printf("|%020.5f|\n", -f);
		
	// // Testando cenários inesperados com flags
	// printf("\nCenários inesperados com flags:\n");
	// printf("|%-20s|\n", (char *)NULL); // String NULL com '-'
	// printf("|%20s|\n", (char *)NULL);		// String NULL com largura mínima
	// printf("|%.5s|\n", (char *)NULL);		// String NULL com precisão
	// printf("|%-20s|\n", "");											// String vazia com '-'
	// printf("|%20s|\n", "");												// String vazia com largura mínima
	// printf("|%.5s|\n", "");												// String vazia com precisão
	// printf("|%+d|\n", INT_MAX);								// Valor máximo de int com '+'
	// printf("|%+d|\n", INT_MIN);								// Valor mínimo de int com '+'
	// printf("|%020d|\n", INT_MAX);						// Valor máximo de int com '0'
	// printf("|%020d|\n", INT_MIN);						// Valor mínimo de int com '0'
	// printf("|% f|\n", FLT_MAX);								// Valor máximo de float com ' '
	// printf("|% f|\n", FLT_MIN);								// Valor mínimo de float com ' '
	// printf("|%+f|\n", 0.0);												// Zero em ponto flutuante com '+'
	// printf("|%+f|\n", -0.0);											// Zero negativo em ponto flutuante com '+'
	// printf("|%+f|\n", 1.0 / 0.0);						// Infinito positivo com '+'
	// printf("|%+f|\n", -1.0 / 0.0);					// Infinito negativo com '+'
	// printf("|% f|\n", 0.0 / 0.0);						// NaN (Not a Number) com ' '

	return (0);
}
