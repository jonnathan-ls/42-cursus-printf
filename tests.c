#include "ft_printf.h"

#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <string.h>

int main(void)
{
	setvbuf(stdout, NULL, _IONBF, 0); // Define o buffer de saída como não-bufferizado

	int i = 42;
	unsigned int ui = 2024;
	char *str =	"Hello, World!";

	int n[] = { INT_MIN, -42, 0, 42, INT_MAX };
	char c[] = { (char)INT_MIN, -42, 0, 42, (char)INT_MAX };
	char *s[] = { "Hello, World!", "\x23", "\b", "42", "" };

	int result; int expected; char *format = NULL; int int_arg; char chr_arg; char *str_arg;

	// printf("\n[ Casos de Testes sem uso das Flags ]:\n");
	
	// printf("Testes com o tipo de argumento %%c :\n");
	// for (int index = 0; index < 5; index++)
	// {
	// 	chr_arg = c[index];

	// 	format = strdup("|%c|");
	// 	printf("\nOriginal ==> "); expected = printf(format, chr_arg);
	// 	printf("\nReplica  ==> "); result = ft_printf(format, chr_arg);
	// 	printf("\nAre equal? %s", expected == result ? "🟩" : "🟥");
	// 	printf(" O:%d R:%d\n", expected, result);
	// 	free(format);
	// }

	// printf("\nTestes com o tipo de argumento %%d & %%i & %%u :\n");
	// for (int index = 0; index < 5; index++)
	// {
	// 	int_arg = n[index];

	// 	format = strdup("|%d|");
	// 	printf("\nOriginal ==> "); expected = printf(format, int_arg);
	// 	printf("\nReplica  ==> "); result = ft_printf(format, int_arg);
	// 	printf("\nAre equal? %s", expected == result ? "🟩" : "🟥");
	// 	printf(" O:%d R:%d\n", expected, result);
	// 	free(format);

	// 	format = strdup("|%i|");
	// 	printf("\nOriginal ==> "); expected = printf(format, int_arg);
	// 	printf("\nReplica  ==> "); result = ft_printf(format, int_arg);
	// 	printf("\nAre equal? %s", expected == result ? "🟩" : "🟥");
	// 	printf(" O:%d R:%d\n", expected, result);
	// 	free(format);
		
	// 	format = strdup("|%u|");
	// 	printf("\nOriginal ==> "); expected = printf(format, int_arg);
	// 	printf("\nReplica  ==> "); result = ft_printf(format, int_arg);
	// 	printf("\nAre equal? %s", expected == result ? "🟩" : "🟥");
	// 	printf(" O:%d R:%d\n", expected, result);
	// }

	// printf("\nTestes com o tipo de argumento %%s & %%p :\n");
	// for (int index = 0; index < 5; index++)
	// {
	// 	str_arg =	s[index];

	// 	format = strdup("|%s|");
	// 	printf("\nOriginal ==> "); expected = printf(format, str_arg);
	// 	printf("\nReplica  ==> "); result = ft_printf(format, str_arg);
	// 	printf("\nAre equal? %s", expected == result ? "🟩" : "🟥");
	// 	printf(" O:%d R:%d\n", expected, result);
	// 	free(format);
			
	// 	format = strdup("|%p|");
	// 	printf("\nOriginal ==> "); expected = printf(format, str_arg);
	// 	printf("\nReplica  ==> "); result = ft_printf(format, str_arg);
	// 	printf("\nAre equal? %s", expected == result ? "🟩" : "🟥");
	// 	printf(" O:%d R:%d\n", expected, result);
	// }

	
	// // Testando flag '-'
	// printf("\nprintf Flag '-':\n");
	// printf("|%-20c|\n", 'c');
	// printf("|%-20s|\n", str);
	// printf("|%-20p|\n", str);
	// printf("|%-20d|\n", i);
	// printf("|%-20d|\n", -i);
	// printf("|%-20i|\n", i);
	// printf("|%-20i|\n", -i);
	// printf("|%-20u|\n", i);
	// printf("|%-20u|\n", -i);
	// printf("|%-20x|\n", ui);
	// printf("|%-20X|\n", ui);

	// printf("\nFt_printf flag '-':\n");
	// ft_printf("|%-20c|\n", 'c');
	// ft_printf("|%-20s|\n", str);
	// ft_printf("|%-20p|\n", str);
	// ft_printf("|%-20d|\n", i);
	// ft_printf("|%-20d|\n", -i);
	// ft_printf("|%-20i|\n", i);
	// ft_printf("|%-20i|\n", -i);
	// ft_printf("|%-20u|\n", i);
	// ft_printf("|%-20u|\n", -i);
	// ft_printf("|%-20x|\n", ui);
	// ft_printf("|%-20X|\n", ui);

	// // // Testando flag '0'
	// printf("\nprintf Flag '0':\n");
	// printf("|%020d|\n", i);
	// printf("|%020d|\n", -i);
	// printf("|%020i|\n", i);
	// printf("|%020i|\n", -i);
	// printf("|%020u|\n", i);
	// printf("|%020u|\n", -i);
	// printf("|%020x|\n", ui);
	// printf("|%020X|\n", ui);

	// printf("\nFt_printf flag '0':\n");
	// ft_printf("|%020d|\n", i);
	// ft_printf("|%020d|\n", -i);
	// ft_printf("|%020i|\n", i);
	// ft_printf("|%020i|\n", -i);
	// ft_printf("|%020u|\n", i);
	// ft_printf("|%020u|\n", -i);
	// ft_printf("|%020x|\n", ui);
	// ft_printf("|%020X|\n", ui);

	// // // Testando flag '.'
	// printf("\nPrint Flag '.':\n");
	// printf("|%.2s|\n", str);
	// printf("|%.20d|\n", i);
	// printf("|%.20d|\n", -i);
	// printf("|%.20i|\n", i);
	// printf("|%.20i|\n", -i);
	// printf("|%.20u|\n", i);
	// printf("|%.20u|\n", -i);
	// printf("|%.20x|\n", ui);
	// printf("|%.20X|\n", ui);

	// printf("\nFT_Printf Flag '.':\n");
	// ft_printf("|%.2s|\n", str);
	// ft_printf("|%.20d|\n", i);
	// ft_printf("|%.20d|\n", -i);
	// ft_printf("|%.20i|\n", i);
	// ft_printf("|%.20i|\n", -i);
	// ft_printf("|%.20u|\n", i);
	// ft_printf("|%.20u|\n", -i);
	// ft_printf("|%.20x|\n", ui);
	// ft_printf("|%.20X|\n", ui);

	// // // Testando flag '#'
	// printf("\nPrint Flag '#':\n");
	// printf("|%#x|\n", ui);
	// printf("|%#X|\n", ui);

	// printf("\nFT_Print Flag '#':\n");
	// ft_printf("|%#x|\n", ui);
	// ft_printf("|%#X|\n", ui);

	// // // Testando flag ' '
	// printf("\nPrintf Flag ' ':\n");
	// // printf("|% 20c|\n", 'c');
	// // printf("|% 20s|\n", str);
	// // printf("|% 20p|\n", str);
	// printf("|% 20d|\n", i);
	// printf("|% 20d|\n", -i);
	// printf("|% 20i|\n", i);
	// printf("|% 20i|\n", -i);
	// // printf("|% 20u|\n", i);
	// // printf("|% 20u|\n", -i);
	// // printf("|% 20x|\n", ui);
	// // printf("|% 20X|\n", ui);

	// printf("\nFT_Printf Flag ' ':\n");
	// // ft_printf("|% 20c|\n", 'c');
	// // ft_printf("|% 20s|\n", str);
	// // ft_printf("|% 20p|\n", str);
	// ft_printf("|% 20d|\n", i);
	// ft_printf("|% 20d|\n", -i);
	// ft_printf("|% 20i|\n", i);
	// ft_printf("|% 20i|\n", -i);
	// // ft_printf("|% 20u|\n", i);
	// // ft_printf("|% 20u|\n", -i);
	// // ft_printf("|% 20x|\n", ui);
	// // ft_printf("|% 20X|\n", ui);

	// // // Testando flag '+'
	// printf("\nPrintf Flag '+':\n");
	// // printf("\nFlag ' ':\n");
	// // printf("|%+20c|\n", 'c');
	// // printf("|%+20s|\n", str);
	// // printf("|%+20p|\n", str);
	// printf("|%+20d|\n", i);
	// printf("|%+20d|\n", -i);
	// printf("|%+20i|\n", i);
	// printf("|%+20i|\n", -i);
	// // printf("|%+20u|\n", i);
	// // printf("|%+20u|\n", -i);
	// // printf("|%+20x|\n", ui);
	// // printf("|%+20X|\n", ui);

	// printf("\nFT_Printf Flag '+':\n");
	// // ft_printf("\nFlag ' ':\n");
	// // ft_printf("|%+20c|\n", 'c');
	// // ft_printf("|%+20s|\n", str);
	// // ft_printf("|%+20p|\n", str);
	// ft_printf("|%+20d|\n", i);
	// ft_printf("|%+20d|\n", -i);
	// ft_printf("|%+20i|\n", i);
	// ft_printf("|%+20i|\n", -i);
	// // ft_printf("|%+20u|\n", i);
	// // ft_printf("|%+20u|\n", -i);
	// // ft_printf("|%+20x|\n", ui);
	// // ft_printf("|%+20X|\n", ui);

	// // Testando largura mínima
	// printf("\nLargura mínima:\n");
	// printf("\nPrintf Flag 'Largura Minima':\n");
	// printf("|%20c|\n", 'c');
	// printf("|%20s|\n", str);
	// printf("|%20p|\n", str);
	// printf("|%20d|\n", i);
	// printf("|%20d|\n", -i);
	// printf("|%20i|\n", i);
	// printf("|%20i|\n", -i);
	// printf("|%20u|\n", i);
	// printf("|%20u|\n", -i);
	// printf("|%20x|\n", ui);
	// printf("|%20X|\n", ui);

	// printf("\nFT_Printf Flag 'Largura Minima':\n");
	// ft_printf("|%20c|\n", 'c');
	// ft_printf("|%20s|\n", str);
	// ft_printf("|%20p|\n", str);
	// ft_printf("|%20d|\n", i);
	// ft_printf("|%20d|\n", -i);
	// ft_printf("|%20i|\n", i);
	// ft_printf("|%20i|\n", -i);
	// ft_printf("|%20u|\n", i);
	// ft_printf("|%20u|\n", -i);
	// ft_printf("|%20x|\n", ui);
	// ft_printf("|%20X|\n", ui);

	// // Testando cenários inesperados com flags
	// printf("\nPrintf Cenários inesperados com flags:\n");
	// printf("|%.5s|\n", "");											// String vazia com '0' expected '-'
	// printf("|%-20s|\n", "");											// String vazia com '-'
	// printf("|%20s|\n", "");												// String vazia com largura mínima
	// printf("|%.s|\n", "");												// String vazia com precisão
	// printf("|%20.5s|\n", "");											// String vazia com largura expected precisão
	// printf("|%+d|\n", INT_MAX);								// Valor máximo de int com '+'
	// printf("|%+d|\n", INT_MIN);								// Valor mínimo de int com '+'
	// printf("|%20i|\n", INT_MAX);						// Valor máximo de int com '0'
	// printf("|%20i|\n", INT_MIN);						// Valor mínimo de int com '0'
	// printf("|%20.5d|\n", INT_MAX);						// Valor máximo de int com largura expected precisão
	// printf("|%.5d|\n", INT_MIN);						// Valor mínimo de int com largura expected precisão

	// printf("\nFT_Printf Cenários inesperados com flags:\n");
	// ft_printf("|%.5s|\n", "");											// String vazia com '0' expected '-'
	// ft_printf("|%-20s|\n", "");											// String vazia com '-'
	// ft_printf("|%20s|\n", "");												// String vazia com largura mínima
	// ft_printf("|%.s|\n", "");												// String vazia com precisão
	// ft_printf("|%20.5s|\n", "");											// String vazia com largura expected precisão
	// ft_printf("|%+d|\n", INT_MAX);								// Valor máximo de int com '+'
	// ft_printf("|%+d|\n", INT_MIN);								// Valor mínimo de int com '+'
	// ft_printf("|%20i|\n", INT_MAX);						// Valor máximo de int com '0'
	// ft_printf("|%20i|\n", INT_MIN);						// Valor mínimo de int com '0'
	// ft_printf("|%20d|\n", INT_MAX);						// Valor máximo de int com largura expected precisão
	// ft_printf("|%.5d|\n", INT_MIN);						// Valor mínimo de int com largura expected precisão

	// // // Testando combinações de flags
	// printf("\nPrintf Combinações de flags:\n");
	// printf("|%-20.s|\n", str);
	// printf("|%-20.5s|\n", str);
	// printf("|%20.5s|\n", str);
	// printf("|%0-20.5d|\n", i);
	// printf("|%20.5d|\n", -i);
	// printf("|%20.5i|\n", i);
	// printf("|%20.5i|\n", -i);
	// printf("|%20.5u|\n", i);
	// printf("|%20.5u|\n", -i);
	// printf("|%20.5x|\n", ui);
	// printf("|%20.5X|\n", ui);

	// printf("\nFT_Printf Combinações de flags:\n");
	// ft_printf("|%-20.s|\n", str);
	// ft_printf("|%-20.5s|\n", str);
	// ft_printf("|%20.5s|\n", str);
	// ft_printf("|%0-20.5d|\n", i);
	// ft_printf("|%20.5d|\n", i);
	// ft_printf("|%20.5d|\n", -i);
	// ft_printf("|%20.5i|\n", i);
	// ft_printf("|%20.5i|\n", -i);
	// ft_printf("|%20.5u|\n", i);
	// ft_printf("|%20.5u|\n", -i);
	// ft_printf("|%20.5x|\n", ui);
	// ft_printf("|%20.5X|\n", ui);

	int_arg =	1;
	str_arg	=	"";
	chr_arg	=	'c';
	format = strdup("|%+.5p|");
	long long *p;
	printf("\nOriginal ==> "); expected = printf(format, (void*)0x3039);
	printf("\nReplica  ==> "); result = ft_printf(format, (void*)0x3039);
	printf("\nAre equal? %s", expected == result ? "🟩" : "🟥");
	printf(" O:%d R:%d\n", expected, result);

	return (0);
}
