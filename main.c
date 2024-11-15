#include "ft_printf.h"

#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <string.h>

int main(void)
{
	setvbuf(stdout, NULL, _IONBF, 0); // Define o buffer de saída como não-bufferizado

	char *format = strdup("|%32s|");
	int expected;
	int result;
	printf("\nOriginal ==> "); expected = printf(format,  "abc");
	printf("\nReplica  ==> "); result = ft_printf(format,  "abc");
	printf("\nAre equal? %s", expected == result ? "🟩" : "🟥");
	printf(" O:%d R:%d\n", expected, result);
	free(format);

	return (0);
}