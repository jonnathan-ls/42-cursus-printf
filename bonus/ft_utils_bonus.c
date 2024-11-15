/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 21:52:12 by jlacerda          #+#    #+#             */
/*   Updated: 2024/11/14 01:43:08 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_free_lst(t_lst **lst)
{
	t_lst	*next;

	if (!lst)
		return ;
	while (*lst)
	{
		next = (*lst)->next;
		free(*lst);
		*lst = next;
	}
	*lst = NULL;
	return ;
}

int	ft_is_null_node_lst(t_lst *node)
{
	return (node && node->chr == '0' && node->next == NULL);
}