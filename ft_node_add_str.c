/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_node_add_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 21:52:12 by jlacerda          #+#    #+#             */
/*   Updated: 2024/11/02 19:22:10 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_node	*ft_node_add_str(char *str)
{
	t_node	*str_node;

	if (!str)
	{
		str_node = ft_node_add_str("(null)");
		return (str_node);
	}
	if (!*str)
		return	NULL;
	str_node = ft_node_new(*str++);
	while (*str)
		ft_node_add_back(&str_node, ft_node_new(*str++));
	return (str_node);
}
