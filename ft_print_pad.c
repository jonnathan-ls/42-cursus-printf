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
	while (size-- > 0)
		count += write(1, &c, 1);
	return (count);
}

int	ft_print_pad(int len, t_flags *flags)
{
	int count;

	count = 0;
	if (flags->zero_padding)
			count += ft_print_chr_padding('0', len, flags);
	else if (flags->left_justify)
		count += ft_print_chr_padding(' ', len, flags);
	if (flags->alternate)
		count += write(1, "0x", 2);
	if (flags->space)
		count += ft_print_chr_padding(' ', len, flags);
	if (flags->sign)
	{
		// TODO: Precisa cobrir verificando o	sinal do número em vez de sign flag
		if (flags->sign == 1)
			count += write(1, "+", 1);
		else
			count += write(1, "-", 1);
		count	+= ft_print_chr_padding(' ', len + count, flags);
	}
	if (flags->width)
		count += ft_print_chr_padding(' ', len + count, flags);
	return (count);
}
