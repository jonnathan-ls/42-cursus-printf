/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_node_add_precision_pad.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 21:52:12 by jlacerda          #+#    #+#             */
/*   Updated: 2024/11/09 22:50:36 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	ft_add_str_pad(t_node **nds, t_flags *f)
{
	int		index;
	t_node	*tmp;
	t_node	*temp_node;

	index = 0;
	tmp = NULL;
	temp_node = NULL;
	if ((*nds) && (*nds)->chr == '(' && f->precision_value < 6)
	{
		free(*nds);
		*nds = NULL;
		return ;
	}
	while ((*nds) && index++ < f->precision_value)
	{
		tmp = *nds;
		ft_node_add_back(&temp_node, ft_node_new((*nds)->chr));
		*nds = (*nds)->next;
		free(tmp);
	}
	while (*nds)
	{
		tmp = *nds;
		*nds = (*nds)->next;
		free(tmp);
	}
	*nds = temp_node;
}

static void	ft_add_nbr_pad(t_node **nds, t_flags *f, int *len)
{
	t_node	*temp_node;

	temp_node = NULL;
	if ((*nds) && (*nds)->chr == '0' && f->precision_value == 0)
	{
		free(*nds);
		*nds = NULL;
		return ;
	}
	if ((*nds) && (*nds)->chr == '-' && *len <= f->precision_value)
	{
		temp_node = ft_node_new('-');
		(*nds)->chr = '0';
	}
	else if (f->sign && *len < f->precision_value)
	{
		temp_node = ft_node_new('+');
		(*nds)->chr = '0';
	}
	while ((*len)++ < f->precision_value)
		ft_node_add_front(nds, ft_node_new('0'));
	if (temp_node && temp_node->chr == '-')
		ft_node_add_front(nds, ft_node_new('-'));
	if (temp_node && temp_node->chr == '+')
		ft_node_add_front(nds, ft_node_new('+'));
	if (temp_node)
		free(temp_node);
}

static void	ft_add_hex_pad(t_node **nds, t_flags *f, int *len)
{
	t_node	*temp_node;

	temp_node = NULL;
	if ((*nds) && (*nds)->chr == '0' && (*nds)->next == NULL && f->precision_value == 0)
	{
		free(*nds);
		*nds = NULL;
		return ;
	}
	if (f->alternate && (*nds)->next)
	{
		temp_node = ft_node_new((*nds)->next->chr);
		f->precision_value += 2;
		(*nds)->next->chr = '0';
	}
	while ((*len)++ < f->precision_value)
		ft_node_add_front(nds, ft_node_new('0'));
	if (f->alternate && temp_node)
		(*nds)->next->chr = temp_node->chr;
	if (temp_node)
		free(temp_node);
}

static void	ft_add_ptr_pad(t_node **nds, t_flags *f, int *len)
{
	t_node	*temp_node;

	*len -= 2;
	temp_node = NULL;
	if (f->sign)
	{
		temp_node = (*nds);
		(*nds) = (*nds)->next;
		*len -= 1;
	}
	while ((*len)++ < f->precision_value && (*nds) && (*nds)->next)
	{
		(*nds)->next->chr = '0';
		ft_node_add_front(nds, ft_node_new('0'));
		(*nds)->next->chr = 'x';
	}
	if (temp_node && f->precision_value > 0 && !f->sign)
	{
		ft_node_add_front(nds, ft_node_new('x'));
		ft_node_add_front(nds, ft_node_new('0'));
	}
	if (f->sign)
		ft_node_add_front(nds, ft_node_new(temp_node->chr));
}

void	ft_node_add_precision_pad(t_node **nds, t_flags *f, char at, int *len)
{
	f->zero_padding = 0;
	if (at == STR_ARG_TYPE)
		ft_add_str_pad(nds, f);
	else if (at == DIG_ARG_TYPE || at == INT_ARG_TYPE)
		ft_add_nbr_pad(nds, f, len);
	else if (at == HEX_LOWER_ARG_TYPE || at == HEX_UPPER_ARG_TYPE)
		ft_add_hex_pad(nds, f, len);
	else if (at == PTR_ARG_TYPE && (*nds) && (*nds)->chr != '(')
		ft_add_ptr_pad(nds, f, len);
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
	*len = ft_node_size(*nds);
}
