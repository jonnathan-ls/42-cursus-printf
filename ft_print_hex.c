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

static int	ft_print_hex_nbr(unsigned int n, char *hex_base)
{
	unsigned int	count;

	count = 0;
	if (n > 15)
		count += ft_print_hex_nbr(n / 16, hex_base);
	count += write(1, &hex_base[n % 16], 1);
	return (count);
}

unsigned int	ft_print_hex(unsigned int n, char *hex_base)
{
	unsigned int	count;
	char			*nbr_str;

	count = 0;
	nbr_str = ft_ultoa(n);
	count += ft_print_hex_nbr(n, hex_base);
	free(nbr_str);
	return (count);
}
