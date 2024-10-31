/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 21:52:12 by jlacerda          #+#    #+#             */
/*   Updated: 2024/10/30 23:15:29 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_printunbr(unsigned int n)
{
	long			nbr;
	unsigned int	count;

	nbr = n;
	count = 0;
	if (nbr > 9)
		count += ft_printunbr(nbr / 10);
	count += ft_printchar(nbr % 10 + '0');
	return (count);
}
