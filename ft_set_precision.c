/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_precision.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 21:52:12 by jlacerda          #+#    #+#             */
/*   Updated: 2024/11/14 00:59:12 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	ft_precision_str(t_lst **lst, t_flags *flags)
{
	int		index;
	t_lst	*tmp;
	t_lst	*temp_node;

	index = 0;
	tmp = NULL;
	temp_node = NULL;
	if ((*lst) && (*lst)->chr == '(' && flags->precision_value < 6)
		return (ft_free_lst(lst));
	while ((*lst) && index++ < flags->precision_value)
	{
		tmp = *lst;
		ft_add_back_lst(&temp_node, ft_new_lst((*lst)->chr));
		*lst = (*lst)->next;
		free(tmp);
	}
	while (*lst)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		free(tmp);
	}
	*lst = temp_node;
}

static void	ft_precision_nbr(t_lst **lst, t_flags *flags, int *len)
{
	t_lst	*temp_node;

	temp_node = NULL;
	if (ft_is_null_node_lst(*lst) && flags->precision_value == 0)
		return (ft_free_lst(lst));
	if ((*lst) && (*lst)->chr == '-' && *len <= flags->precision_value)
	{
		temp_node = ft_new_lst('-');
		(*lst)->chr = '0';
	}
	else if (flags->sign && *len < flags->precision_value)
	{
		temp_node = ft_new_lst('+');
		(*lst)->chr = '0';
	}
	while ((*len)++ < flags->precision_value)
		ft_add_front_lst(lst, ft_new_lst('0'));
	if (temp_node && temp_node->chr == '-')
		ft_add_front_lst(lst, ft_new_lst('-'));
	if (temp_node && temp_node->chr == '+')
		ft_add_front_lst(lst, ft_new_lst('+'));
	if (temp_node)
		free(temp_node);
}

static void	ft_precision_hex(t_lst **lst, t_flags *flags, int *len)
{
	t_lst	*temp_node;

	temp_node = NULL;
	if (ft_is_null_node_lst(*lst) && flags->precision_value == 0)
		return (ft_free_lst(lst));
	if (flags->alternate && (*lst)->next)
	{
		temp_node = ft_new_lst((*lst)->next->chr);
		flags->precision_value += 2;
		(*lst)->next->chr = '0';
	}
	while ((*len)++ < flags->precision_value)
		ft_add_front_lst(lst, ft_new_lst('0'));
	if (flags->alternate && temp_node)
		(*lst)->next->chr = temp_node->chr;
	if (temp_node)
		free(temp_node);
}

static void	ft_precision_ptr(t_lst **lst, t_flags *flags, int *len)
{
	t_lst	*temp_node;

	*len -= 2;
	temp_node = NULL;
	if (flags->sign)
	{
		temp_node = (*lst);
		(*lst) = (*lst)->next;
		*len -= 1;
	}
	while ((*len)++ < flags->precision_value && (*lst) && (*lst)->next)
	{
		(*lst)->next->chr = '0';
		ft_add_front_lst(lst, ft_new_lst('0'));
		(*lst)->next->chr = 'x';
	}
	if (temp_node && flags->precision_value > 0 && !flags->sign)
	{
		ft_add_front_lst(lst, ft_new_lst('x'));
		ft_add_front_lst(lst, ft_new_lst('0'));
	}
	if (flags->sign)
		ft_add_front_lst(lst, ft_new_lst(temp_node->chr));
}

void	ft_set_precision(t_lst **lst, t_flags *flags, char at, int *len)
{
	flags->zero_padding = 0;
	if (at == STR_ARG_TYPE)
		ft_precision_str(lst, flags);
	else if (at == DIG_ARG_TYPE || at == INT_ARG_TYPE)
		ft_precision_nbr(lst, flags, len);
	else if (at == HEX_LOWER_ARG_TYPE || at == HEX_UPPER_ARG_TYPE)
		ft_precision_hex(lst, flags, len);
	else if (at == PTR_ARG_TYPE && (*lst) && (*lst)->chr != '(')
		ft_precision_ptr(lst, flags, len);
	else if (at == UNS_ARG_TYPE)
	{
		if (ft_is_null_node_lst(*lst) && flags->precision_value == 0)
		{
			free(*lst);
			*lst = NULL;
		}
		else
		{
			while ((*len)++ < flags->precision_value)
				ft_add_front_lst(lst, ft_new_lst('0'));
		}
	}
	*len = ft_size_lst(*lst);
}
