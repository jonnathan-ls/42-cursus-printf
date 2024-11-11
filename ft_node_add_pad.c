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

#include	"ft_printf_bonus.h"

static void	ft_node_add_sign_pad(t_node	**nodes, t_flags *flags, char arg_type, int *len)
{
	t_node *tmp;

	if (arg_type == DIG_ARG_TYPE || arg_type == INT_ARG_TYPE || arg_type == PTR_ARG_TYPE)
	{
	
		if ((*nodes) && (*nodes)->chr != '(')
		{
			if ((*nodes)->chr != '-' || (*nodes)->chr == '0')
			{
				tmp = *nodes;
				ft_node_add_front(nodes, ft_node_new('+'));
				if (tmp->chr == '0' &&	tmp->next == NULL && flags->precision)
					(*nodes)->next = NULL;
			}
		}
	}
	*len = ft_node_size(*nodes);
}

static void	ft_node_add_alternate_pad(t_node	**nodes, char arg_type, int *len)
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
	if (at != STR_ARG_TYPE || at != PTR_ARG_TYPE || at != CHR_ARG_TYPE)
	{
		while ((*len)++ < flg->width_value)
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
	if (at == DIG_ARG_TYPE || at == INT_ARG_TYPE)
	{
		if ((*nds) && (*nds)->chr == '0' && (*nds)->next == NULL)
			ft_node_add_front(nds, ft_node_new(' '));
		while ((*len)++ <= f->width_value)
			ft_node_add_front(nds, ft_node_new(' '));
	}
	*len = ft_node_size(*nds);
}

static void	ft_node_add_precision_pad(t_node **nds, t_flags *f, char at, int *len)
{
	t_node *temp_node;
	t_node *temp_node2;
	int index;

	index = 0;
	temp_node = NULL;
	f->zero_padding = 0;
	if (at == CHR_ARG_TYPE)
	{
		// if (f->align_left)
		// {
		// 	while ((*len)++ < f->width_value)
		// 		ft_node_add_back(nds, ft_node_new(' '));
		// }
		// else
		// {
		// 	while ((*len)++ < f->width_value)
		// 		ft_node_add_front(nds, ft_node_new(' '));
		// }
	}
	else if (at == STR_ARG_TYPE)
	{
		if ((*nds) && (*nds)->chr == '(' && f->precision_value < 6)
		{
			free(*nds);
			*nds = NULL;
		}
		else 
		{
			while ((*nds) && index++ < f->precision_value)
			{
				ft_node_add_back(&temp_node, ft_node_new((*nds)->chr));
				*nds = (*nds)->next;
			}
			*nds = temp_node;
		}
		
		// if (f->align_left)
		// {
		// 	while (index++ <= f->width_value && *len	< f->width_value)
		// 		ft_node_add_back(nds, ft_node_new(' '));
		// }
		// else
		// {
		// 	while (index++ <= f->width_value)
		// 		ft_node_add_front(nds, ft_node_new(' '));
		// }
	}
	else if (at == DIG_ARG_TYPE || at == INT_ARG_TYPE)
	{
		if ((*nds) && (*nds)->chr == '0' && f->precision_value == 0)
		{
			free(*nds);
			*nds = NULL;
		}
		else
		{
			if ((*nds) && (*nds)->chr == '-')
			{
				temp_node	= ft_node_new('-');
				(*nds) = (*nds)->next;
				
				if (f->precision_value > *len)
					ft_node_add_front(nds, ft_node_new('0'));
			}
			if (f->sign)
			{
				temp_node2 = ft_node_new((*nds)->chr);
				(*nds)->chr = '0';
				while ((*len)++ < f->precision_value + 1)
					ft_node_add_front(nds, ft_node_new('0'));
				(*nds)->chr = temp_node2->chr;
			}
			else
			{
				while ((*len)++ < f->precision_value)
					ft_node_add_front(nds, ft_node_new('0'));
			}
			if (temp_node)	
				ft_node_add_front(nds, ft_node_new('-'));
		}
	}
	else if (at == UNS_ARG_TYPE)
	{
		if ((*nds) && (*nds)->chr == '0' && f->precision_value == 0)
		{
			free(*nds);
			*nds = NULL;
		}
		else
		{
			while ((*len)++ < f->precision_value)
			ft_node_add_front(nds, ft_node_new('0'));
		}
	}
	else if (at == HEX_LOWER_ARG_TYPE || at == HEX_UPPER_ARG_TYPE)
	{
		if ((*nds) && (*nds)->chr == '0' && (*nds)->next == NULL && f->precision_value == 0)
		{
			free(*nds);
			*nds = NULL;
		}
		else
		{
			if (f->alternate && (*nds)->next)
			{
				temp_node	= ft_node_new((*nds)->next->chr);
				f->precision_value	+= 2;
				(*nds)->next->chr = '0';
			}
			while ((*len)++ < f->precision_value)
				ft_node_add_front(nds, ft_node_new('0'));
			if (f->alternate && temp_node)
				(*nds)->next->chr = temp_node->chr;
		}
	}
	else if (at == PTR_ARG_TYPE)
	{
		if ((*nds) && (*nds)->chr == '0' && f->precision_value > 0 && *len < f->precision_value)
		{
			temp_node	= *nds;
			(*nds)->next->chr = '0';
		}
		while (temp_node && (*len)++ < f->precision_value)
			ft_node_add_front(nds, ft_node_new('0'));
		if (temp_node && f->precision_value > 0)
		{
			ft_node_add_front(nds, ft_node_new('x'));
			ft_node_add_front(nds, ft_node_new('0'));
		}
	}
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
	if (flags->zero_padding && !flags->align_left && !flags->precision && (arg_type	== DIG_ARG_TYPE || arg_type == INT_ARG_TYPE || arg_type == UNS_ARG_TYPE || arg_type == HEX_LOWER_ARG_TYPE || arg_type == HEX_UPPER_ARG_TYPE))
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
