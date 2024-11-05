/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 21:52:12 by jlacerda          #+#    #+#             */
/*   Updated: 2024/11/02 18:54:14 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_get_hex_nbr_size(unsigned long n)
{
	unsigned long	count;

	count = 0;
	while (n > 15)
	{
		n = n / 16;
		count++;
	}
	count++;
	return (count);
}

static char	*ft_get_hex_nbr(unsigned long n, char *hex_base)
{
	char			*nbr_str;
	unsigned long	nbr_len;

	nbr_len = ft_get_hex_nbr_size(n);
	nbr_str = malloc(nbr_len + 1);
	if (!nbr_str)
		return (NULL);
	nbr_str[nbr_len] = '\0';
	while (nbr_len > 0)
	{
		nbr_str[nbr_len - 1] = hex_base[n % 16];
		n /= 16;
		nbr_len--;
	}
	return (nbr_str);
}

char	*ft_print_hex(unsigned long n, char *hex_base)
{
	char	*nbr_str;

	nbr_str = ft_get_hex_nbr(n, hex_base);
	return (nbr_str);
}
