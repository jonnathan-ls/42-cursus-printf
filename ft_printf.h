/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 21:52:12 by jlacerda          #+#    #+#             */
/*   Updated: 2024/10/31 22:45:30 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int				ft_printnbr(int n);
int				ft_printchar(char c);
int				ft_strlen(char *str);
int				ft_printptr(void *ptr);
int				ft_printstr(char *str);
unsigned int	ft_printunbr(unsigned int n);
int				ft_printf(const char *str, ...);
unsigned long	ft_printhex(unsigned long n, char *hex_base);

// BONUS

typedef struct s_flags {
	int	left_justify; // '-'
	int	zero_padding; // '0'
	int	precision;    // '.'
	int	alternate;    // '#'
	int	space;        // ' '
	int	sign;         // '+'
	int	width;        // largura mínima
	int	precision_value; // valor da precisão
}	t_flags;

#endif
