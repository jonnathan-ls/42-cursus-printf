/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pad.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 21:52:12 by jlacerda          #+#    #+#             */
/*   Updated: 2024/11/02 19:10:20 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int ft_print_chr_padding(char c, int len, t_flags *flags)
{
	int	count;
	int size;

	count = 0;
	size = (flags->width - len);
	while (size > 0)
	{
		count += write(1, &c, 1);
		size--;
	}
	return (count);
}

int	ft_print_pad(int len, t_flags *flags, int has_sign)
{
	int count;

	count = 0;
	if (flags->is_width_first)
	{
		if (flags->precision)
			count += ft_print_chr_padding(' ', flags->precision_value, flags);
	}
	if (flags->zero_padding)
	{
		if (has_sign)
			write(1, "-", 1);
		count += ft_print_chr_padding('0', len + count, flags);
	}
	if (flags->left_justify)
		count += ft_print_chr_padding(' ', len + count, flags);
	if (flags->space)
		count += ft_print_chr_padding(' ', len + count, flags);
	if (flags->sign)
	{
		count += ft_print_chr_padding(' ', len + count + 1, flags);
		if (!has_sign)
			count += write(1, "+", 1);
	}
	if (flags->alternate)
		count += write(1, "0x", 2);
	if (flags->precision)
	{
		if (has_sign)
			write(1, "-0", 2);
		count += ft_print_chr_padding('0', len + count, flags);
	}
	if (flags->width)
		count += ft_print_chr_padding(' ', len + count, flags);
	if (has_sign && !flags->left_justify && !flags->precision && !flags->zero_padding)
			count += write(1, "-", 1);
	return (count);
}
