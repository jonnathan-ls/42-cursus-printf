/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 21:52:12 by jlacerda          #+#    #+#             */
/*   Updated: 2024/11/15 14:38:20 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

# define STR_ARG_TYPE 's'
# define CHR_ARG_TYPE 'c'
# define PTR_ARG_TYPE 'p'
# define DIG_ARG_TYPE 'd'
# define INT_ARG_TYPE 'i'
# define UNS_ARG_TYPE 'u'
# define HEX_LOWER_ARG_TYPE 'x'
# define HEX_UPPER_ARG_TYPE 'X'
# define HEX_BASE_LOWER "0123456789abcdef"
# define HEX_BASE_UPPER "0123456789ABCDEF"

typedef struct s_lst
{
	char			chr;
	struct s_lst	*next;
}	t_lst;

t_lst	*ft_new_lst(char chr);
t_lst	*ft_last_lst(t_lst *lst);
void	ft_add_back_lst(t_lst **lst, t_lst *new);
void	ft_add_front_lst(t_lst **lst, t_lst *new);
int		ft_size_lst(t_lst *lst);

t_lst	*ft_get_nbr(int n);
t_lst	*ft_get_chr(char chr);
t_lst	*ft_get_str(char *str);
t_lst	*ft_get_ptr(void *ptr);
t_lst	*ft_get_unbr(unsigned int ui);
t_lst	*ft_get_hex(unsigned long ul, char *hex_base);

int		ft_printf(const char *fmt, ...);

#endif
