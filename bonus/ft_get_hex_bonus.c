/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_hrx_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 21:52:12 by jlacerda          #+#    #+#             */
/*   Updated: 2024/11/15 14:38:20 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

t_lst	*ft_get_hex(unsigned long ul, char *hex_base)
{
	t_lst	*lst;

	if (ul < 16)
	{
		lst = ft_new_lst(hex_base[ul]);
		return (lst);
	}
	lst = ft_get_hex(ul / 16, hex_base);
	ft_add_back_lst(&lst, ft_new_lst(hex_base[ul % 16]));
	return (lst);
}
