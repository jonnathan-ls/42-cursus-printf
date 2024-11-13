/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 21:52:12 by jlacerda          #+#    #+#             */
/*   Updated: 2024/11/09 19:04:23 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static t_node	*ft_put_node_argument(va_list *args, char arg_type)
{
	t_node	*nodes;

	nodes = NULL;
	if (arg_type == CHR_ARG_TYPE)
		nodes = ft_node_add_chr(va_arg(*args, int));
	else if (arg_type == STR_ARG_TYPE)
		nodes = ft_node_add_str(va_arg(*args, char *));
	else if (arg_type == PTR_ARG_TYPE)
		nodes = ft_node_add_ptr(va_arg(*args, void *));
	else if (arg_type == DIG_ARG_TYPE || arg_type == INT_ARG_TYPE)
		nodes = ft_node_add_nbr(va_arg(*args, int));
	else if (arg_type == UNS_ARG_TYPE)
		nodes = ft_node_add_uns_nbr(va_arg(*args, unsigned int));
	else if (arg_type == HEX_LOWER_ARG_TYPE)
		nodes = ft_node_add_hex(va_arg(*args, unsigned int), HEX_BASE_LOWER);
	else if (arg_type == HEX_UPPER_ARG_TYPE)
		nodes = ft_node_add_hex(va_arg(*args, unsigned int), HEX_BASE_UPPER);
	else if (arg_type == '%')
		nodes = ft_node_add_chr('%');
	return (nodes);
}

static int	ft_print_argument(const char *str, va_list *args, t_flags *flags)
{
	t_node	*nodes;
	t_node	*print_node;
	int		print_count;
	char	arg_type;

	print_count = 0;
	arg_type = *str;
	nodes = ft_put_node_argument(args, arg_type);
	ft_node_add_pad(&nodes, flags, arg_type);
	while (nodes)
	{
		print_node = nodes;
		print_count += write(1, &print_node->chr, 1);
		nodes = nodes->next;
		free(print_node);
	}
	// if (nodes)
	// 	free(nodes);
	// if (print_node)
	// 	free(print_node);
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
