/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_nbr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 21:52:12 by jlacerda          #+#    #+#             */
/*   Updated: 2024/11/09 18:45:14 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_lst	*ft_add_nbr(int n)
{
	long	nbr;
	t_lst	*lst;
	t_lst	*sign_node;

	nbr = n;
	sign_node = NULL;
	if (nbr < 0)
	{
		nbr = -nbr;
		sign_node = ft_new_lst('-');
	}
	if (nbr >= 10)
	{
		lst = ft_add_nbr(nbr / 10);
		ft_add_back_lst(&lst, ft_new_lst(nbr % 10 + '0'));
	}
	else
		lst = ft_new_lst(nbr % 10 + '0');
	if (sign_node)
	{
		ft_add_front_lst(&lst, ft_new_lst('-'));
		free(sign_node);
	}
	return (lst);
}
