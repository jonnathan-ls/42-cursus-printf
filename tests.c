#include "ft_printf.h"

#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <string.h>

int main(void)
{
	setvbuf(stdout, NULL, _IONBF, 0); // Define o buffer de saída como não-bufferizado

	// int i = 42;
	// unsigned int ui = 2024;
	// char *str =	"Hello, World!";

	int n[] = { INT_MIN, -42, 0, 42, INT_MAX };
	char c[] = { (char)INT_MIN, -42, 0, 42, (char)INT_MAX };
	char *s[] = { "Hello, World!", "\x23", "\b", "42", "" };

	int result; int expected; char *format = NULL; char chr_arg; int int_arg; char *str_arg;

	printf("\n[ Casos de Testes sem uso das Flags ]:\n");
	
	printf("Testes com o tipo de argumento %%c :\n");
	for (int index = 0; index < 5; index++)
	{
		chr_arg = c[index];

		format = strdup("|%c|");
		printf("\nOriginal ==> "); expected = printf(format, chr_arg);
		printf("\nReplica  ==> "); result = ft_printf(format, chr_arg);
		printf("\nAre equal? %s", expected == result ? "🟩" : "🟥");
		printf(" O:%d R:%d\n", expected, result);
		free(format);
	}

	printf("\nTestes com o tipo de argumento %%d & %%i & %%u :\n");
	for (int index = 0; index < 5; index++)
	{
		int_arg = n[index];

		format = strdup("|%d|");
		printf("\nOriginal ==> "); expected = printf(format, int_arg);
		printf("\nReplica  ==> "); result = ft_printf(format, int_arg);
		printf("\nAre equal? %s", expected == result ? "🟩" : "🟥");
		printf(" O:%d R:%d\n", expected, result);
		free(format);

		format = strdup("|%i|");
		printf("\nOriginal ==> "); expected = printf(format, int_arg);
		printf("\nReplica  ==> "); result = ft_printf(format, int_arg);
		printf("\nAre equal? %s", expected == result ? "🟩" : "🟥");
		printf(" O:%d R:%d\n", expected, result);
		free(format);
		
		format = strdup("|%u|");
		printf("\nOriginal ==> "); expected = printf(format, int_arg);
		printf("\nReplica  ==> "); result = ft_printf(format, int_arg);
		printf("\nAre equal? %s", expected == result ? "🟩" : "🟥");
		printf(" O:%d R:%d\n", expected, result);
	}

	printf("\nTestes com o tipo de argumento %%s & %%p :\n");
	for (int index = 0; index < 5; index++)
	{
		str_arg =	s[index];

		format = strdup("|%s|");
		printf("\nOriginal ==> "); expected = printf(format, str_arg);
		printf("\nReplica  ==> "); result = ft_printf(format, str_arg);
		printf("\nAre equal? %s", expected == result ? "🟩" : "🟥");
		printf(" O:%d R:%d\n", expected, result);
		free(format);
			
		format = strdup("|%p|");
		printf("\nOriginal ==> "); expected = printf(format, str_arg);
		printf("\nReplica  ==> "); result = ft_printf(format, str_arg);
		printf("\nAre equal? %s", expected == result ? "🟩" : "🟥");
		printf(" O:%d R:%d\n", expected, result);
	}

	return (0);
}
