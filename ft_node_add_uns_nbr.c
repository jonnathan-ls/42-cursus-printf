/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_node_add_uns_nbr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 21:52:12 by jlacerda          #+#    #+#             */
/*   Updated: 2024/11/09 18:46:48 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_node	*ft_node_add_uns_nbr(unsigned int ui)
{
	t_node	*uns_nbr_node;

	if (ui < 10)
	{
		uns_nbr_node = ft_node_new(ui + '0');
		return (uns_nbr_node);
	}
	uns_nbr_node = ft_node_add_uns_nbr(ui / 10);
	ft_node_add_back(&uns_nbr_node, ft_node_new(ui % 10 + '0'));
	return (uns_nbr_node);
}
