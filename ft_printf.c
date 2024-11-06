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

static char	*ft_get_arg(char chr, va_list *args)
{
	char	*str_arg;

	str_arg	= NULL;
	if (chr == 'c')
		str_arg = ft_get_chr(va_arg(*args, int));
	if (chr == 's')
		str_arg = ft_get_str(va_arg(*args, char *));
	if (chr == 'p')
		str_arg = ft_get_ptr(va_arg(*args, void *));
	if (chr == 'd' || chr == 'i')
		str_arg = ft_get_nbr(va_arg(*args, int));
	if (chr == 'u')
		str_arg = ft_get_unbr(va_arg(*args, unsigned int));
	if (chr == 'x')
		str_arg = ft_get_hex(va_arg(*args, unsigned int), "0123456789abcdef");
	if (chr == 'X')
		str_arg = ft_get_hex(va_arg(*args, unsigned int), "0123456789ABCDEF");
	if (chr == '%')
		str_arg = ft_get_chr('%');
	return	(str_arg);
}

static int	ft_print_str(char *arg, int len, t_flags *flags)
{
	int	count;;

	count = 0;
	if (flags->precision && len > 0 && len <	flags->precision_value)
		count += write(1, arg, flags->precision_value);
	else
	{
		if (flags->type_arg	== 'c' && len == 0)
			count += write(1, arg, 1);
		else
			count += write(1, arg, len);
	}
	return (count);
}

static int	ft_printf_arg(char *str, int len, int has_sign, t_flags *flags)
{
	int	count;

	count = 0;
	if (flags->right_justify)
	{
		count += ft_print_str(str, len, flags);
		count += ft_print_pad(count, flags, has_sign);
	}
	else
	{
		count += ft_print_pad(len, flags, has_sign);
		if (has_sign)
		{
			count -= 1;
			str++;
		}
		count += ft_print_str(str, len, flags);
	}
	return	(count);
}

static int ft_printf_argument(char chr, va_list *args, t_flags *flags)
{
	int		count;
	int		str_len;
	char	*str_arg;
	int		has_sign;

	count = 0;
	flags->type_arg = chr;
	str_arg	= ft_get_arg(chr, args);
	if (!str_arg)
		return (0);
	str_len = ft_strlen(str_arg);
	has_sign	= 0;
	if (str_arg)
		has_sign = str_arg[0] == '-';
	count += ft_printf_arg(str_arg, str_len, has_sign, flags);
	return (count);
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
			count += ft_printf_argument(*str, &args, &flags);
		}
		else
			count += write(1, str, 1);
		str++;
	}
	va_end(args);
	return (count);
}
