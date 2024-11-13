/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_node_add_pad.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 21:52:12 by jlacerda          #+#    #+#             */
/*   Updated: 2024/11/09 22:50:36 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	ft_node_add_sign_pad(t_node	**nodes, t_flags *flags, char arg_type, int *len)
{
	t_node	*tmp;

	if (arg_type == DIG_ARG_TYPE || arg_type == INT_ARG_TYPE || arg_type == PTR_ARG_TYPE)
	{
		if ((*nodes) && (*nodes)->chr != '(')
		{
			if ((*nodes)->chr != '-' || (*nodes)->chr == '0')
			{
				tmp = *nodes;
				ft_node_add_front(nodes, ft_node_new('+'));
				if (tmp->chr == '0' && tmp->next == NULL && flags->precision)
					(*nodes)->next = NULL;
			}
		}
	}
	*len = ft_node_size(*nodes);
}

static void	ft_node_add_alternate_pad(t_node **nodes, char arg_type, int *len)
{
	if ((*nodes) && (*nodes)->chr != '0')
	{
		if (arg_type == HEX_LOWER_ARG_TYPE)
		{
			ft_node_add_front(nodes, ft_node_new('x'));
			ft_node_add_front(nodes, ft_node_new('0'));
		}
		else if (arg_type == HEX_UPPER_ARG_TYPE)
		{
			ft_node_add_front(nodes, ft_node_new('X'));
			ft_node_add_front(nodes, ft_node_new('0'));
		}
		*len = ft_node_size(*nodes);
	}
}

static void	ft_node_add_zero_pad(t_node **nds, t_flags *flg, char at, int *len)
{
	if (at == PTR_ARG_TYPE && (*nds) && (*nds)->chr != '(')
	{
		while ((*len)++ < flg->width_value && (*nds) && (*nds)->next)
		{
			(*nds)->next->chr = '0';
			(*nds)->chr = 'x';
			ft_node_add_front(nds, ft_node_new('0'));
		}
	}
	else if (at != STR_ARG_TYPE && at != CHR_ARG_TYPE)
	{
		while ((*len)++ < flg->width_value && (*nds) && (*nds)->chr != '(')
		{
			if ((*nds) && (*nds)->chr == '-')
			{
				(*nds)->chr = '0';
				ft_node_add_front(nds, ft_node_new('-'));
			}
			else
				ft_node_add_front(nds, ft_node_new('0'));
		}
	}
	*len = ft_node_size(*nds);
}

static void	ft_node_add_space_pad(t_node **nds, t_flags *f, char at, int *len)
{
	if ((at == DIG_ARG_TYPE || at == INT_ARG_TYPE))
	{
		if ((*nds) == NULL || ((*nds)->chr == '0' && (*nds)->next == NULL))
			ft_node_add_front(nds, ft_node_new(' '));
		else
		{
			if (f->width_value)
			{
				if (*len >= f->width_value && (*nds)->chr != '-')
					ft_node_add_front(nds, ft_node_new(' '));
				while ((*len)++ < f->width_value && !f->align_left)
					ft_node_add_front(nds, ft_node_new(' '));
				if (f->align_left && (*nds) && (*nds)->chr != '-' && (*len) < f->width_value)
					ft_node_add_front(nds, ft_node_new(' '));
			}
			else if ((*nds) && (*nds)->chr != '-')
				ft_node_add_front(nds, ft_node_new(' '));
		}
	}
	else if (at == PTR_ARG_TYPE && (*nds) && (*nds)->chr != '(')
		ft_node_add_front(nds, ft_node_new(' '));
	*len = ft_node_size(*nds);
}

void	ft_node_add_pad(t_node **nodes, t_flags *flags, char arg_type)
{
	int	nodes_size;

	nodes_size = ft_node_size(*nodes);
	if (flags->sign)
		ft_node_add_sign_pad(nodes, flags, arg_type, &nodes_size);
	if (flags->alternate)
		ft_node_add_alternate_pad(nodes, arg_type, &nodes_size);
	if (flags->precision)
		ft_node_add_precision_pad(nodes, flags, arg_type, &nodes_size);
	if (flags->zero_padding && !flags->align_left)
		ft_node_add_zero_pad(nodes, flags, arg_type, &nodes_size);
	if (flags->space && !flags->sign)
		ft_node_add_space_pad(nodes, flags, arg_type, &nodes_size);
	if (flags->align_left)
	{
		while (nodes_size++ < flags->width_value)
			ft_node_add_back(nodes, ft_node_new(' '));
	}
	if (flags->min_width && !flags->align_left)
	{
		while (nodes_size++ < flags->width_value)
			ft_node_add_front(nodes, ft_node_new(' '));
	}
}
