/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 21:52:12 by jlacerda          #+#    #+#             */
/*   Updated: 2024/11/02 19:23:16 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_printunbr(unsigned int n)
{
	int		len;
	int		count;
	char	*nbr_str;

	count = 0;
	nbr_str = ft_ultoa(n);
	len = ft_strlen(nbr_str);
	count += write(1, nbr_str, len);
	free(nbr_str);
	return (count);
}
