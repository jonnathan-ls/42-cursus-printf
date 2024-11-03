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

#include "ft_printf.h"

static int	ft_print_arg(char chr, va_list *args, t_flags *flags)
{
	int count;

	count = 0;
	if (chr == 'c')
		count += ft_print_pad(ft_print_chr(va_arg(*args, int)), flags);
	else if (chr == 's')
		count += ft_print_pad(ft_print_str(va_arg(*args, char *)), flags);
	else if (chr == 'd' || chr == 'i')
		count += ft_print_pad(ft_print_nbr(va_arg(*args, int)), flags);
	else if (chr == 'u')
		count += ft_print_pad(ft_print_unbr(va_arg(*args, unsigned int)), flags);
	else if (chr == 'x')
		count += ft_print_pad(ft_print_hex(va_arg(*args, unsigned int), "0123456789abcdef"), flags);
	else if (chr == 'X')
		count += ft_print_pad(ft_print_hex(va_arg(*args, unsigned int), "0123456789ABCDEF"), flags);
	else if (chr == 'p')
		count += ft_print_pad(ft_print_ptr(va_arg(*args, void *)), flags);
	else if (chr == '%')
		count += ft_print_pad(ft_print_chr('%'), flags);
	return (0);
}

int	ft_printf(const char *str, ...)
{
	t_flags flags;
	va_list	args;
	int		count;

	count = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			ft_init_flags(&flags);
			ft_parse_flags(&str, &flags);
			count += ft_print_arg(*str, &args, &flags);
		}
		else
			count += write(1, str, 1);
		str++;
	}
	va_end(args);
	return (count);
}
