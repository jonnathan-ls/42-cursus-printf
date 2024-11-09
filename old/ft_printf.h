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
# include "libft/libft.h"

typedef struct s_flags {
	int		sign;
	int		width;
	int		space;
	int		precision;
	int		alternate;
	char	type_arg;
	int		zero_padding;
	int		right_justify;
	int		precision_value;
}	t_flags;

void	ft_init_flags(t_flags *flags);
int		ft_print_pad(int len, t_flags *flags, int has_sign);
void	ft_parse_flags(const char **format, t_flags *flags);

char	*ft_get_nbr(int n);
char	*ft_get_chr(char c);
char	*ft_get_ptr(void *ptr);
char	*ft_get_str(char *str);
char	*ft_get_unbr(unsigned long n);
char	*ft_get_hex(unsigned long n, char *hex_base);

int		ft_printf(const char *str, ...);

#endif
