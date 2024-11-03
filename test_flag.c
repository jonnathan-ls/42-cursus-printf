#include "ft_printf.h"

#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void)
{
	char *str =	"Hello, World!";
	int i = 42;
	unsigned int ui = 2024;

	// int c[] = { INT_MIN, -42, 0, 42, INT_MAX };
	// long n[] = { LONG_MIN, -42, 0, 42, LONG_MAX };
	// char *s[] = { "Hello, World!", "\x23", "\b", "42", "" };


	// printf("\nPrintf SEM Flag:\n");
	// for (int index = 0; index < 5; index++)
	// {
	// 	printf("|%c|\n", c[index]);
	// 	ft_printf("|%c|\n", c[index]);
	// }

	// for (int index = 0; index < 5; index++)
	// {
	// 	printf("|%s|\n", s[index]);
	// 	printf("|%p|\n", s[index]);
	// 	ft_printf("|%s|\n", s[index]);
	// 	ft_printf("|%p|\n", s[index]);
	// }

	// for (int index = 0; index < 5; index++)
	// {
	// 	printf("|%d|\n", n[index]);
	// 	printf("|%i|\n", n[index]);
	// 	printf("|%u|\n", n[index]);
		
	// 	ft_printf("|%d|\n", n[index]);
	// 	ft_printf("|%i|\n", n[index]);
	// 	ft_printf("|%u|\n", n[index]);
	// }

	// // Testando SEM Flag
	// printf("\nPrintf SEM Flag:\n");
	// printf("|%c|\n", 'c');
	// printf("|%s|\n", str);
	// printf("|%p|\n", str);
	// printf("|%d|\n", i);
	// printf("|%d|\n", -i);
	// printf("|%i|\n", i);
	// printf("|%i|\n", -i);
	// printf("|%u|\n", i);
	// printf("|%u|\n", -i);
	// printf("|%x|\n", ui);
	// printf("|%X|\n", ui);

	// printf("\nFT_Printf SEM Flag:\n");
	// printf("|%c|\n", 'c');
	// printf("|%s|\n", str);
	// printf("|%p|\n", str);
	// printf("|%d|\n", i);
	// printf("|%d|\n", -i);
	// printf("|%i|\n", i);
	// printf("|%i|\n", -i);
	// printf("|%u|\n", i);
	// printf("|%u|\n", -i);
	// printf("|%x|\n", ui);
	// printf("|%X|\n", ui);

	// Testando flag '-'
	printf("\nprintf Flag '-':\n");
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

	printf("\nFt_printf flag '-':\n");
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
	ft_printf("|%-20%|\n", str);

	// Testando flag '0'
	printf("\nprintf Flag '0':\n");
	printf("|%020d|\n", i);
	printf("|%020d|\n", -i);
	printf("|%020i|\n", i);
	printf("|%020i|\n", -i);
	printf("|%020u|\n", i);
	printf("|%020u|\n", -i);
	printf("|%020x|\n", ui);
	printf("|%020X|\n", ui);

	printf("\nFt_printf flag '0':\n");
	ft_printf("|%020d|\n", i);
	ft_printf("|%020d|\n", -i);
	ft_printf("|%020i|\n", i);
	ft_printf("|%020i|\n", -i);
	ft_printf("|%020u|\n", i);
	ft_printf("|%020u|\n", -i);
	ft_printf("|%020x|\n", ui);
	ft_printf("|%020X|\n", ui);

	// Testando flag '.'
	printf("\nPrint Flag '.':\n");
	printf("|%.20s|\n", str);
	printf("|%.20d|\n", i);
	printf("|%.20d|\n", -i);
	printf("|%.20i|\n", i);
	printf("|%.20i|\n", -i);
	printf("|%.20u|\n", i);
	printf("|%.20u|\n", -i);
	printf("|%.20x|\n", ui);
	printf("|%.20X|\n", ui);

	printf("\nFT_Printf Flag '.':\n");
	ft_printf("|%.20s|\n", str);
	ft_printf("|%.20d|\n", i);
	ft_printf("|%.20d|\n", -i);
	ft_printf("|%.20i|\n", i);
	ft_printf("|%.20i|\n", -i);
	ft_printf("|%.20u|\n", i);
	ft_printf("|%.20u|\n", -i);
	ft_printf("|%.20x|\n", ui);
	ft_printf("|%.20X|\n", ui);

	// // Testando flag '#'
	printf("\nPrint Flag '#':\n");
	printf("|%#x|\n", ui);
	printf("|%#X|\n", ui);

	printf("\nFT_Print Flag '#':\n");
	ft_printf("|%#x|\n", ui);
	ft_printf("|%#X|\n", ui);

	// // Testando flag ' '
	printf("\nPrintf Flag ' ':\n");
	// printf("|% 20c|\n", 'c');
	// printf("|% 20s|\n", str);
	// printf("|% 20p|\n", str);
	printf("|% 20d|\n", i);
	printf("|% 20d|\n", -i);
	printf("|% 20i|\n", i);
	printf("|% 20i|\n", -i);
	// printf("|% 20u|\n", i);
	// printf("|% 20u|\n", -i);
	// printf("|% 20x|\n", ui);
	// printf("|% 20X|\n", ui);

	printf("\nFT_Printf Flag ' ':\n");
	// ft_printf("|% 20c|\n", 'c');
	// ft_printf("|% 20s|\n", str);
	// ft_printf("|% 20p|\n", str);
	ft_printf("|% 20d|\n", i);
	ft_printf("|% 20d|\n", -i);
	ft_printf("|% 20i|\n", i);
	ft_printf("|% 20i|\n", -i);
	// ft_printf("|% 20u|\n", i);
	// ft_printf("|% 20u|\n", -i);
	// ft_printf("|% 20x|\n", ui);
	// ft_printf("|% 20X|\n", ui);

	// // Testando flag '+'
	printf("\nPrintf Flag '+':\n");
	// printf("\nFlag ' ':\n");
	// printf("|%+20c|\n", 'c');
	// printf("|%+20s|\n", str);
	// printf("|%+20p|\n", str);
	printf("|%+20d|\n", i);
	printf("|%+20d|\n", -i);
	printf("|%+20i|\n", i);
	printf("|%+20i|\n", -i);
	// printf("|%+20u|\n", i);
	// printf("|%+20u|\n", -i);
	// printf("|%+20x|\n", ui);
	// printf("|%+20X|\n", ui);

	printf("\nFT_Printf Flag '+':\n");
	// ft_printf("\nFlag ' ':\n");
	// ft_printf("|%+20c|\n", 'c');
	// ft_printf("|%+20s|\n", str);
	// ft_printf("|%+20p|\n", str);
	ft_printf("|%+20d|\n", i);
	ft_printf("|%+20d|\n", -i);
	ft_printf("|%+20i|\n", i);
	ft_printf("|%+20i|\n", -i);
	// ft_printf("|%+20u|\n", i);
	// ft_printf("|%+20u|\n", -i);
	// ft_printf("|%+20x|\n", ui);
	// ft_printf("|%+20X|\n", ui);

	// Testando largura mínima
	printf("\nLargura mínima:\n");
	printf("\nPrintf Flag 'Largura Minima':\n");
	printf("|%20c|\n", 'c');
	printf("|%20s|\n", str);
	printf("|%20p|\n", str);
	printf("|%20d|\n", i);
	printf("|%20d|\n", -i);
	printf("|%20i|\n", i);
	printf("|%20i|\n", -i);
	printf("|%20u|\n", i);
	printf("|%20u|\n", -i);
	printf("|%20x|\n", ui);
	printf("|%20X|\n", ui);

	printf("\nFT_Printf Flag 'Largura Minima':\n");
	ft_printf("|%20c|\n", 'c');
	ft_printf("|%20s|\n", str);
	ft_printf("|%20p|\n", str);
	ft_printf("|%20d|\n", i);
	ft_printf("|%20d|\n", -i);
	ft_printf("|%20i|\n", i);
	ft_printf("|%20i|\n", -i);
	ft_printf("|%20u|\n", i);
	ft_printf("|%20u|\n", -i);
	ft_printf("|%20x|\n", ui);
	ft_printf("|%20X|\n", ui);

	// Testando combinações de flags
	printf("\nPrintf Combinações de flags:\n");
	// printf("|%20.5c|\n", 'c');
	printf("|%20.5s|\n", str);
	// printf("|%20.5p|\n", str);
	printf("|%20.5d|\n", i);
	printf("|%20.5d|\n", -i);
	printf("|%20.5i|\n", i);
	printf("|%20.5i|\n", -i);
	printf("|%20.5u|\n", i);
	printf("|%20.5u|\n", -i);
	printf("|%20.5x|\n", ui);
	printf("|%20.5X|\n", ui);

	printf("\nFT_Printf Combinações de flags:\n");
	// ft_printf("|%20.5c|\n", 'c');
	ft_printf("|%20.5s|\n", str);
	// ft_printf("|%20.5p|\n", str);
	ft_printf("|%20.5d|\n", i);
	ft_printf("|%20.5d|\n", -i);
	ft_printf("|%20.5i|\n", i);
	ft_printf("|%20.5i|\n", -i);
	ft_printf("|%20.5u|\n", i);
	ft_printf("|%20.5u|\n", -i);
	ft_printf("|%20.5x|\n", ui);
	ft_printf("|%20.5X|\n", ui);
		
	// // Testando cenários inesperados com flags
	printf("\nPrintf Cenários inesperados com flags:\n");
	// printf("|%-20s|\n", (char *)NULL); // String NULL com '-'
	// printf("|%20s|\n", (char *)NULL);		// String NULL com largura mínima
	// printf("|%.5s|\n", (char *)NULL);		// String NULL com precisão
	printf("|%-20s|\n", "");											// String vazia com '-'
	printf("|%20s|\n", "");												// String vazia com largura mínima
	printf("|%.5s|\n", "");												// String vazia com precisão
	printf("|%20.5s|\n", "");											// String vazia com largura e precisão
	printf("|%+d|\n", INT_MAX);								// Valor máximo de int com '+'
	printf("|%+d|\n", INT_MIN);								// Valor mínimo de int com '+'
	printf("|%020d|\n", INT_MAX);						// Valor máximo de int com '0'
	printf("|%020d|\n", INT_MIN);						// Valor mínimo de int com '0'
	printf("|%20.5d|\n", INT_MAX);						// Valor máximo de int com largura e precisão
	printf("|%20.5d|\n", INT_MIN);						// Valor mínimo de int com largura e precisão

	printf("\nFT_Printf Cenários inesperados com flags:\n");
	// ft_printf("|%-20s|\n", (char *)NULL); // String NULL com '-'
	// ft_printf("|%20s|\n", (char *)NULL);		// String NULL com largura mínima
	// ft_printf("|%.5s|\n", (char *)NULL);		// String NULL com precisão
	ft_printf("|%-20s|\n", "");											// String vazia com '-'
	ft_printf("|%20s|\n", "");												// String vazia com largura mínima
	ft_printf("|%.5s|\n", "");												// String vazia com precisão
	ft_printf("|%20.5s|\n", "");											// String vazia com largura e precisão
	ft_printf("|%+d|\n", INT_MAX);								// Valor máximo de int com '+'
	ft_printf("|%+d|\n", INT_MIN);								// Valor mínimo de int com '+'
	ft_printf("|%020d|\n", INT_MAX);						// Valor máximo de int com '0'
	ft_printf("|%020d|\n", INT_MIN);						// Valor mínimo de int com '0'
	ft_printf("|%20.5d|\n", INT_MAX);						// Valor máximo de int com largura e precisão
	ft_printf("|%20.5d|\n", INT_MIN);						// Valor mínimo de int com largura e precisão

	return (0);
}
