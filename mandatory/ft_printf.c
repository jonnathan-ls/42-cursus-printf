/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 21:52:12 by jlacerda          #+#    #+#             */
/*   Updated: 2024/11/15 14:38:20 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_lst	*ft_get_argument(va_list *args, char arg_type)
{
	t_lst	*lst;

	lst = NULL;
	if (arg_type == CHR_ARG_TYPE)
		lst = ft_get_chr(va_arg(*args, int));
	else if (arg_type == STR_ARG_TYPE)
		lst = ft_get_str(va_arg(*args, char *));
	else if (arg_type == PTR_ARG_TYPE)
		lst = ft_get_ptr(va_arg(*args, void *));
	else if (arg_type == DIG_ARG_TYPE || arg_type == INT_ARG_TYPE)
		lst = ft_get_nbr(va_arg(*args, int));
	else if (arg_type == UNS_ARG_TYPE)
		lst = ft_get_unbr(va_arg(*args, unsigned int));
	else if (arg_type == HEX_LOWER_ARG_TYPE)
		lst = ft_get_hex(va_arg(*args, unsigned int), HEX_BASE_LOWER);
	else if (arg_type == HEX_UPPER_ARG_TYPE)
		lst = ft_get_hex(va_arg(*args, unsigned int), HEX_BASE_UPPER);
	else if (arg_type == '%')
		lst = ft_get_chr('%');
	return (lst);
}

static int	ft_print_argument(const char *str, va_list *args)
{
	t_lst	*lst;
	t_lst	*print_node;
	int		print_count;

	print_count = 0;
	lst = ft_get_argument(args, *str);
	while (lst)
	{
		print_node = lst;
		print_count += write(1, &print_node->chr, 1);
		lst = lst->next;
		free(print_node);
	}
	return (print_count);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	args;
	int		print_size;

	if (!fmt)
		return (-1);
	print_size = 0;
	va_start(args, fmt);
	while (*fmt)
	{
		if (*fmt == '%')
			print_size += ft_print_argument(++fmt, &args);
		else
			print_size += write(1, fmt, 1);
		fmt++;
	}
	va_end(args);
	return (print_size);
}
