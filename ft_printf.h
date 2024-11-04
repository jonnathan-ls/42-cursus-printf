/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 21:52:12 by jlacerda          #+#    #+#             */
/*   Updated: 2024/11/02 19:22:55 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
#include "libft/libft.h"
#include <stdio.h>  // REMOVER 

typedef struct s_flags {
	int	left_justify;
	int	zero_padding;
	int	precision;
	int	alternate;
	int	space;
	int	sign;
	int	width;
	int is_width_first;
	int	precision_value;
}	t_flags;

void	ft_init_flags(t_flags *flags);
int		ft_print_pad(int len, t_flags *flags, int has_sign);
void	ft_parse_flags(const char **format, t_flags *flags);

char	*ft_print_nbr(int n);
char	*ft_print_chr(char c);
char	*ft_print_ptr(void *ptr);
char	*ft_print_str(char *str);
char	*ft_print_unbr(unsigned int n);
char	*ft_print_hex(unsigned int n, char *hex_base);

int	ft_printf(const char *str, ...);

#endif
