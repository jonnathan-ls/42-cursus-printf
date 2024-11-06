/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 21:52:12 by jlacerda          #+#    #+#             */
/*   Updated: 2024/11/02 19:10:20 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_get_ptr(void *ptr)
{
	char	*nbr_str;
	char	*str;

	if (!ptr)
		return ft_strdup("(nil)");
	str = ft_strdup("0x");
	nbr_str = ft_get_hex((unsigned long)ptr, "0123456789abcdef");
	return (ft_strjoin(str, nbr_str));
}
