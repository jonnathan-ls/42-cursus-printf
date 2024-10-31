/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 21:52:12 by jlacerda          #+#    #+#             */
/*   Updated: 2024/10/30 23:25:51 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printnbr(int n)
{
	int		count;
	long	nbr;

	count = 0;
	nbr = n;
	if (nbr < 0)
	{
		count += ft_printchar('-');
		nbr = -nbr;
	}
	if (nbr > 9)
		count += ft_printnbr(nbr / 10);
	count += ft_printchar(nbr % 10 + '0');
	return (count);
}
