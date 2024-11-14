/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_padding.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 21:52:12 by jlacerda          #+#    #+#             */
/*   Updated: 2024/11/09 22:50:36 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	ft_add_sign(t_lst	**lst, t_flags *flags, char arg_type, int *len)
{
	t_lst	*tmp;

	if (arg_type == DIG_ARG_TYPE
		|| arg_type == INT_ARG_TYPE
		|| arg_type == PTR_ARG_TYPE)
	{
		if ((*lst) && (*lst)->chr != '(')
		{
			if ((*lst)->chr != '-' || (*lst)->chr == '0')
			{
				tmp = *lst;
				ft_add_front_lst(lst, ft_new_lst('+'));
				if (tmp->chr == '0' && tmp->next == NULL && flags->precision)
					(*lst)->next = NULL;
			}
		}
	}
	*len = ft_size_lst(*lst);
}

static void	ft_add_alternate(t_lst **lst, char arg_type, int *len)
{
	if ((*lst) && (*lst)->chr != '0')
	{
		if (arg_type == HEX_LOWER_ARG_TYPE)
		{
			ft_add_front_lst(lst, ft_new_lst('x'));
			ft_add_front_lst(lst, ft_new_lst('0'));
		}
		else if (arg_type == HEX_UPPER_ARG_TYPE)
		{
			ft_add_front_lst(lst, ft_new_lst('X'));
			ft_add_front_lst(lst, ft_new_lst('0'));
		}
		*len = ft_size_lst(*lst);
	}
}

static void	ft_add_zero(t_lst **lst, t_flags *flg, char at, int *len)
{
	if (at == PTR_ARG_TYPE && (*lst) && (*lst)->chr != '(')
	{
		while ((*len)++ < flg->width_value && (*lst) && (*lst)->next)
		{
			(*lst)->next->chr = '0';
			(*lst)->chr = 'x';
			ft_add_front_lst(lst, ft_new_lst('0'));
		}
	}
	else if (at != STR_ARG_TYPE && at != CHR_ARG_TYPE)
	{
		while ((*len)++ < flg->width_value && (*lst) && (*lst)->chr != '(')
		{
			if ((*lst) && (*lst)->chr == '-')
			{
				(*lst)->chr = '0';
				ft_add_front_lst(lst, ft_new_lst('-'));
			}
			else
				ft_add_front_lst(lst, ft_new_lst('0'));
		}
	}
	*len = ft_size_lst(*lst);
}

static void	ft_add_space(t_lst **lst, t_flags *flags, char at, int *len)
{
	if ((at == DIG_ARG_TYPE || at == INT_ARG_TYPE))
	{
		if ((*lst) == NULL || ((*lst)->chr == '0' && (*lst)->next == NULL))
			ft_add_front_lst(lst, ft_new_lst(' '));
		else
		{
			if (flags->width_value)
			{
				if (*len >= flags->width_value && (*lst)->chr != '-')
					ft_add_front_lst(lst, ft_new_lst(' '));
				while ((*len)++ < flags->width_value && !flags->align_left)
					ft_add_front_lst(lst, ft_new_lst(' '));
				if (flags->align_left && (*lst) && (*lst)->chr != '-'
					&& (*len) < flags->width_value)
					ft_add_front_lst(lst, ft_new_lst(' '));
			}
			else if ((*lst) && (*lst)->chr != '-')
				ft_add_front_lst(lst, ft_new_lst(' '));
		}
	}
	else if (at == PTR_ARG_TYPE && (*lst) && (*lst)->chr != '(')
		ft_add_front_lst(lst, ft_new_lst(' '));
	*len = ft_size_lst(*lst);
}

void	ft_add_padding(t_lst **lst, t_flags *flags, char arg_type)
{
	int	nodes_size;

	nodes_size = ft_size_lst(*lst);
	if (flags->sign)
		ft_add_sign(lst, flags, arg_type, &nodes_size);
	if (flags->alternate)
		ft_add_alternate(lst, arg_type, &nodes_size);
	if (flags->precision)
		ft_add_precision(lst, flags, arg_type, &nodes_size);
	if (flags->zero_padding && !flags->align_left)
		ft_add_zero(lst, flags, arg_type, &nodes_size);
	if (flags->space && !flags->sign)
		ft_add_space(lst, flags, arg_type, &nodes_size);
	if (flags->align_left)
	{
		while (nodes_size++ < flags->width_value)
			ft_add_back_lst(lst, ft_new_lst(' '));
	}
	if (flags->min_width && !flags->align_left)
	{
		while (nodes_size++ < flags->width_value)
			ft_add_front_lst(lst, ft_new_lst(' '));
	}
}
