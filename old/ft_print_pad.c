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

static int ft_get_chr_padding(char c, int len, t_flags *flags)
{
	int	count;
	int	size;

	count = 0;
	size = (flags->width - len);
	while (size > 0)
	{
		count += write(1, &c, 1);
		size--;
	}
	return (count);
}

static int	ft_print_zero_padding(int len, t_flags *flags, int has_sign)
{
	int	count;

	count = 0;
	if (has_sign)
		count -= write(1, "-", 1);
	count += ft_get_chr_padding('0', len + count, flags);
	return (count);
}

static int	ft_print_sign_padding(int len, t_flags *flags, int has_sign)
{
	int	count;

	count = 0;
	if (flags->sign)
	{
		count += ft_get_chr_padding(' ', len + count + 1, flags);
		if (!has_sign)
			count += write(1, "+", 1);
	}
	return (count);
}

static int	ft_print_precision_padding(int len, t_flags *flags, int has_sign)
{
	int	count;

	count = 0;
	if (has_sign)
			count -= write(1, "-", 1);
		if (len > 0)
			count += ft_get_chr_padding('0', len + count, flags);
	return (count);
}

int	ft_print_pad(int len, t_flags *flags, int has_sign)
{
	int	count;

	count = 0;
	if (flags->zero_padding && !ft_strchr("csp", flags->type_arg))
		count += ft_print_zero_padding(len, flags, has_sign);
	if (flags->right_justify)
		count += ft_get_chr_padding(' ', len + count, flags);
	if (flags->space)
		count += ft_get_chr_padding(' ', len + count, flags);
	if (flags->sign)
		count += ft_print_sign_padding(len, flags, has_sign);
	if (flags->alternate)
		count += write(1, "0x", 2);
	if (flags->precision)
		count += ft_print_precision_padding(len, flags, has_sign);
	if (flags->width)
		count += ft_get_chr_padding(' ', len + count, flags);
	if (has_sign && !flags->right_justify && !flags->precision && !flags->zero_padding)
		count += write(1, "-", 1);
	return (count);
}
