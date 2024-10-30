
#ifndef UTILS_H
#define UTILS_H
#include <unistd.h>
#include <stdlib.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_putchar(char c)
{
	return write(1, &c, 1);
}

int	ft_putstr(char *str)
{
	if (!str)
		return write(1, "(null)", 6);
	return write(1, str, ft_strlen(str));
}

unsigned long	ft_puthex(unsigned long n, char *hex_base)
{
	unsigned long count;

	count = 0;
	if (n > 15)
		count += ft_puthex(n / 16, hex_base);
	count += ft_putchar(hex_base[n % 16]);
	return count;
}

int ft_putptr(void *ptr)
{
	int count;

	count = 0;
	if (!ptr)
		count += write(1, "(nil)", 5);
	else
	{
		count += ft_putstr("0x");
		count += ft_puthex((unsigned long)ptr, "0123456789abcdef");
	}
	return count;
}

int ft_putnbr(int n)
{
	int count;
	long nbr;

	count = 0;
	nbr	= n;
	if (nbr < 0)
	{
		count += ft_putchar('-');
		nbr = -nbr;
	}
	if (nbr > 9)
		count += ft_putnbr(nbr / 10);
	count += ft_putchar(nbr % 10 + '0');
	return count;
}

unsigned int ft_putunbr(unsigned int n)
{
	unsigned int count;
	long nbr;

	count = 0;
	nbr = n;
	if (nbr > 9)
		count += ft_putunbr(nbr / 10);
	count += ft_putchar(nbr % 10 + '0');
	return count;
}

#endif