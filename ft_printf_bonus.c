/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 21:52:12 by jlacerda          #+#    #+#             */
/*   Updated: 2024/11/02 19:24:47 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static t_node	*ft_put_node_argument(va_list *args, char arg_type)
{
	t_node	*list_node;

	if (arg_type == CHR_ARG_TYPE)
		list_node = ft_node_add_chr(va_arg(*args, int));
	else if (arg_type == STR_ARG_TYPE)
		list_node = ft_node_add_str(va_arg(*args, char *));
	else if (arg_type == PTR_ARG_TYPE)
		list_node = ft_node_add_ptr(va_arg(*args, void *));
	else if (arg_type == DIG_ARG_TYPE || arg_type == INT_ARG_TYPE)
		list_node = ft_node_add_nbr(va_arg(*args, int));
	else if (arg_type == UNS_ARG_TYPE)
		list_node = ft_node_add_uns_nbr(va_arg(*args, unsigned int));
	else if (arg_type == HEX_LOWER_ARG_TYPE)
		list_node = ft_node_add_hex(va_arg(*args, unsigned int), HEX_BASE_LOWER);
	else if (arg_type == HEX_UPPER_ARG_TYPE)
		list_node = ft_node_add_hex(va_arg(*args, unsigned int), HEX_BASE_UPPER);
	else if (arg_type == '%')
		list_node = ft_node_add_chr('%');
	return (list_node);
}

void	ft_put_padding(t_node **nodes, t_flags *flags, char arg_type)
{
	int	nodes_size;
	// int node_index;
	// t_node	*temp_node;

	nodes_size = ft_node_size(*nodes);
	if (flags->sign && (arg_type == DIG_ARG_TYPE || arg_type == INT_ARG_TYPE))
	{
		if ((*nodes)->chr != '-' && (nodes_size++ < flags->width_value))
			ft_node_add_front(nodes, ft_node_new('+'));
	}
	if (flags->align_left)
	{
		while (nodes_size++ < flags->width_value)
			ft_node_add_back(nodes, ft_node_new(' '));
	}
	if (flags->space && (arg_type == DIG_ARG_TYPE || arg_type == INT_ARG_TYPE))
	{
		if ((*nodes)->chr != '-' && (nodes_size++ < flags->width_value))
			ft_node_add_front(nodes, ft_node_new(' '));
	}
	if (flags->alternate && (arg_type == HEX_LOWER_ARG_TYPE || arg_type == HEX_UPPER_ARG_TYPE))
	{
		if (arg_type == HEX_LOWER_ARG_TYPE)
		{
			ft_node_add_front(nodes, ft_node_new('x'));
			ft_node_add_front(nodes, ft_node_new('0'));
		}
		else
		{
			ft_node_add_front(nodes, ft_node_new('X'));
			ft_node_add_front(nodes, ft_node_new('0'));
		}
	}
	// if (flags->zero_padding && flags->width_value > nodes_size && (arg_type != STR_ARG_TYPE || arg_type != PTR_ARG_TYPE || arg_type != CHR_ARG_TYPE))
	// {
	// 	if ((*nodes)->chr == '-'){
	// 		(*nodes)->chr = '0';
	// 		while (nodes_size++ < flags->width_value - 1)
	// 			ft_node_add_front(nodes, ft_node_new('0'));
	// 		ft_node_add_front(nodes, ft_node_new('-'));
	// 	}
	// 	else
	// 	{
	// 		while (nodes_size++ < flags->width_value)
	// 			ft_node_add_front(nodes, ft_node_new('0'));
	// 	}
	// }
	if (flags->min_width)
	{
		while (nodes_size++ < flags->width_value)
			ft_node_add_front(nodes, ft_node_new(' '));
	}
}

static int	ft_print_argument(const char *str, va_list *args, t_flags *flags)
{
	t_node	*nodes;
	t_node	*print_node;
	int		print_count;
	char	arg_type;

	print_count	= 0;
	arg_type = *str;
	nodes = ft_put_node_argument(args, arg_type);
	ft_put_padding(&nodes, flags, arg_type);
	while (nodes)
	{
		print_node = nodes;
		print_count += write(1, &print_node->chr, 1);
		nodes = nodes->next;
		free(print_node);
	}
	return (print_count);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	args;
	t_flags	flags;
	int		print_size;

	if (!fmt)
		return (-1);
	print_size = 0;
	va_start(args, fmt);
	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt++;
			ft_initialize_flags(&fmt, &flags);
			print_size += ft_print_argument(fmt, &args, &flags);
		}
		else
			print_size += write(1, fmt, 1);
		fmt++;
	}
	va_end(args);
	return (print_size);
}
