/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 21:52:12 by jlacerda          #+#    #+#             */
/*   Updated: 2024/10/30 22:45:58 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printarg(char chr, va_list *args)
{
	if (chr == 'c')
		return (ft_printchar(va_arg(*args, int)));
	else if (chr == 's')
		return (ft_printstr(va_arg(*args, char *)));
	else if (chr == 'd' || chr == 'i')
		return (ft_printnbr(va_arg(*args, int)));
	else if (chr == 'u')
		return (ft_printunbr(va_arg(*args, unsigned int)));
	else if (chr == 'x')
		return (ft_printhex(va_arg(*args, unsigned int), "0123456789abcdef"));
	else if (chr == 'X')
		return (ft_printhex(va_arg(*args, unsigned int), "0123456789ABCDEF"));
	else if (chr == 'p')
		return (ft_printptr(va_arg(*args, void *)));
	else if (chr == '%')
		return (ft_printchar('%'));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			count += ft_printarg(*str, &args);
		}
		else
			count += ft_printchar(*str);
		str++;
	}
	va_end(args);
	return (count);
}
