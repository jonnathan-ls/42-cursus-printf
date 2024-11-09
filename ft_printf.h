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
# define HEX_BASE_LOWER "0123456789abcdef"
# define HEX_BASE_UPPER "0123456789ABCDEF"
# define STR_ARG_TYPE 's'
# define CHR_ARG_TYPE 'c'
# define PTR_ARG_TYPE 'p'
# define DIG_ARG_TYPE 'd'
# define INT_ARG_TYPE 'i'
# define UNS_ARG_TYPE 'u'
# define HEX_LOWER_ARG_TYPE 'x'
# define HEX_UPPER_ARG_TYPE 'X' 

typedef struct s_node
{
	char			chr;
	struct s_node	*next;
}	t_node;

// Utils
t_node	*ft_node_new(char chr);
t_node	*ft_node_last(t_node *node);
void	ft_node_add_back(t_node **node, t_node *new);
void	ft_node_add_front(t_node **node, t_node *new);
int		ft_node_size(t_node *node);

// Node Types
t_node	*ft_node_add_chr(char chr);
t_node	*ft_node_add_str(char *str);
t_node	*ft_node_add_ptr(void *ptr);
t_node	*ft_node_add_nbr(int n);
t_node	*ft_node_add_uns_nbr(unsigned int ui);
t_node	*ft_node_add_hex(unsigned long ul, char *hex_base);

int		ft_printf(const char *fmt, ...);

#endif
