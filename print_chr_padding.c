#include "ft_printf.h"

int	print_chr_padding(char c, int len)
{
	int	count;

	count = 0;
	while (len-- > 0)
		count += write(1, &c, 1);
	return (count);
}
