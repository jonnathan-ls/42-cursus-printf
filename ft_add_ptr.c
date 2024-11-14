/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_ptr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 21:52:12 by jlacerda          #+#    #+#             */
/*   Updated: 2024/11/09 18:45:48 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_lst	*ft_add_ptr(void *ptr)
{
	t_lst	*ptr_node;
	t_lst	*hex_node;

	if (!ptr)
		ptr_node = ft_add_str("(nil)");
	else
	{
		ptr_node = ft_add_str("0x");
		hex_node = ft_add_hex((unsigned long)ptr, HEX_BASE_LOWER);
		ft_add_back_lst(&ptr_node, hex_node);
	}
	return (ptr_node);
}
