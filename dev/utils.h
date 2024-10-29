
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
	return write(1, str, ft_strlen(str));
}

int	ft_puthex(unsigned int n, char *hex_base)
{
	int count;

	count = 0;
	if (n > 15)
		count += ft_puthex(n / 16, hex_base);
	count += ft_putchar(hex_base[n % 16]);
	return count;
}

int ft_puthex_lower(unsigned int n)
{
	return ft_puthex(n, "0123456789abcdef");
}

int ft_puthex_upper(unsigned int n)
{
	return ft_puthex(n, "0123456789ABCDEF");
}

int ft_putptr(void *ptr)
{
	int count;

	count = 0;
	count += ft_putstr("0x");
	count += ft_puthex_lower((unsigned long)ptr);
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

int ft_putunbr(unsigned int n)
{
	int count;
	long nbr;

	count = 0;
	nbr = n;
	if (nbr > 9)
		count += ft_putunbr(nbr / 10);
	count += ft_putchar(nbr % 10 + '0');
	return count;
}

#endif