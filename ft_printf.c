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

static char	*ft_print_arg(char chr, va_list *args)
{
	char	*str_arg;

	str_arg	= NULL;
	if (chr == 'c')
		str_arg = ft_print_chr(va_arg(*args, int));
	if (chr == 's')
		str_arg = ft_print_str(va_arg(*args, char *));
	if (chr == 'p')
		str_arg = ft_print_ptr(va_arg(*args, void *));
	if (chr == 'd' || chr == 'i')
		str_arg = ft_print_nbr(va_arg(*args, int));
	if (chr == 'u')
		str_arg = ft_print_unbr(va_arg(*args, unsigned int));
	if (chr == 'x')
		str_arg = ft_print_hex(va_arg(*args, unsigned int), "0123456789abcdef");
	if (chr == 'X')
		str_arg = ft_print_hex(va_arg(*args, unsigned int), "0123456789ABCDEF");
	return	(str_arg);
}

static int ft_process_padding(char chr, va_list *args, t_flags *flags)
{
	int count;
	char *str_arg;
	int	has_sign;
	int str_len;

	count = 0;
	str_arg	= ft_print_arg(chr, args);
	str_len = ft_strlen(str_arg);
	has_sign = str_arg[0] == '-';
	if (str_len == 0 && flags->precision)
	{
		write(1, "", 1);
		return	(0);
	}
	if (flags->left_justify) // TODO Alterar para right justify
	{
		count	+= write(1, str_arg, str_len);
		count	+= ft_print_pad(count, flags, has_sign);
	}
	else
	{
		if (has_sign)
			str_arg++;
		count	+= ft_print_pad(str_len, flags, has_sign);
		if (flags->precision)
			count += write(1, str_arg, flags->precision_value);
		else
			count += write(1, str_arg, str_len);
	}
	return (count);
}

int	ft_printf(const char *str, ...)
{
	t_flags flags;
	va_list	args;
	int		count;

	count = 0;
	va_start(args, str);
	while (*str !=	'\0')
	{
		if (*str == '%')
		{
			str++;
			ft_init_flags(&flags);
			ft_parse_flags(&str, &flags);
			count += ft_process_padding(*str, &args, &flags);
		}
		else
			count += write(1, str, 1);
		str++;
	}
	va_end(args);
	return (count);
}
