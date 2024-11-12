/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_node_add_nbr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 21:52:12 by jlacerda          #+#    #+#             */
/*   Updated: 2024/11/09 18:45:14 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_node	*ft_node_add_nbr(int n)
{
	long	nbr;
	char	digit;
	t_node	*node;
	t_node	*sign_node;

	nbr = n;
	sign_node = NULL;
	if (nbr < 0)
	{
		nbr = -nbr;
		sign_node = ft_node_new('-');
	}
	digit = nbr % 10 + '0';
	if (nbr >= 10)
	{
		node = ft_node_add_nbr(nbr / 10);
		ft_node_add_back(&node, ft_node_new(digit));
	}
	else
		node = ft_node_new(digit);
	if (sign_node)
	{
		ft_node_add_front(&node, ft_node_new('-'));
		free(sign_node);
	}
	return (node);
}
