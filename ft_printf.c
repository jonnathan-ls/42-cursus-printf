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

int	ft_printarg(char chr, va_list *args, t_flags *flags)
{
	int count;

	count = 0;
	if (chr == 'c')
	{
		count += ft_printchar(va_arg(*args, int));					
		if (flags->zero_padding)
			count += print_chr_padding('0', flags->width - 1);
		else if (flags->left_justify)
			count += print_chr_padding(' ', flags->width - 1);
	}
	else if (chr == 's')
	{
		count += ft_printstr(va_arg(*args, char *));
		if (flags->zero_padding)
			count += print_chr_padding('0', flags->width - count);
		else if (flags->left_justify)
			count += print_chr_padding(' ', flags->width - count);
	}
	else if (chr == 'd' || chr == 'i')
	{
		count += ft_printnbr(va_arg(*args, int));
		if (flags->zero_padding)
			count += print_chr_padding('0', flags->width - count);
		else if (flags->left_justify)
			count += print_chr_padding(' ', flags->width - count);
	}
	else if (chr == 'u')
	{
		count += ft_printunbr(va_arg(*args, unsigned int));
		if (flags->zero_padding)
			count += print_chr_padding('0', flags->width - count);
		else if (flags->left_justify)
			count += print_chr_padding(' ', flags->width - count);
	}
	else if (chr == 'x')
	{
		count += ft_printhex(va_arg(*args, unsigned int), "0123456789abcdef");
		if (flags->zero_padding)
			count += print_chr_padding('0', flags->width - count);
		else if (flags->left_justify)
			count += print_chr_padding(' ', flags->width - count);
	}
	else if (chr == 'X')
	{
		count += ft_printhex(va_arg(*args, unsigned int), "0123456789ABCDEF");
		if (flags->zero_padding)
			count += print_chr_padding('0', flags->width - count);
		else if (flags->left_justify)
			count += print_chr_padding(' ', flags->width - count);
	}
	else if (chr == 'p')
	{
		count += ft_printptr(va_arg(*args, void *));
		if (flags->zero_padding)
			count += print_chr_padding('0', flags->width - count);
		else if (flags->left_justify)
			count += print_chr_padding(' ', flags->width - count);
	}
	else if (chr == '%')
	{
		count += ft_printchar('%');
		if (flags->zero_padding)
			count += print_chr_padding('0', flags->width - count);
		else if (flags->left_justify)
			count += print_chr_padding(' ', flags->width - count);
	}
	else if (chr == '%')
		return (ft_printchar('%'));
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
			init_flags(&flags);
			parse_flags(&str, &flags);
			count += ft_printarg(*str, &args, &flags);
		}
		else
			count += write(1, str, 1);
		str++;
	}
	va_end(args);
	return (count);
}
