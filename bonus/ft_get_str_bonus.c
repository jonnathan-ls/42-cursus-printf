/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_str_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 21:52:12 by jlacerda          #+#    #+#             */
/*   Updated: 2024/11/15 14:38:20 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

t_lst	*ft_get_str(char *str)
{
	t_lst	*str_node;

	if (!str)
	{
		str_node = ft_get_str("(null)");
		return (str_node);
	}
	if (!*str)
		return (NULL);
	str_node = ft_new_lst(*str++);
	while (*str)
		ft_add_back_lst(&str_node, ft_new_lst(*str++));
	return (str_node);
}
