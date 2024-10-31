/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 21:52:12 by jlacerda          #+#    #+#             */
/*   Updated: 2024/10/30 22:36:04 by jlacerda         ###   ########.fr       */
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

#endif
