/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 21:52:12 by jlacerda          #+#    #+#             */
/*   Updated: 2024/11/02 18:54:14 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_node	*ft_node_add_hex(unsigned long ul, char *hex_base)
{
	t_node	*node;

	if (ul < 16)
	{
		node = ft_node_new(hex_base[ul]);
		return (node);
	}
	node = ft_node_add_hex(ul / 16, hex_base);
	ft_node_add_back(&node, ft_node_new(hex_base[ul % 16]));
	return (node);
}
