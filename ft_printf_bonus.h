/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 21:52:12 by jlacerda          #+#    #+#             */
/*   Updated: 2024/11/15 14:38:20 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include "ft_printf.h"

# define FLAGS "-0.# +"

# define SIGN_FLAG '+'
# define SPACE_FLAG ' '
# define PRECISION_FLAG '.'
# define ALTERNATE_FLAG '#'
# define ALIGN_LEFT_FLAG '-'
# define ZERO_PADDING_FLAG '0'

typedef struct s_flags
{
	int	sign;
	int	space;
	int	precision;
	int	alternate;
	int	min_width;
	int	align_left;
	int	width_value;
	int	zero_padding;
	int	precision_value;
}	t_flags;

void	ft_free_lst(t_lst **lst);
int		ft_is_null_node_lst(t_lst *lst);
void	ft_set_flags(const char **chr, t_flags *flags);
void	ft_set_padding(t_lst **lst, t_flags *flags, char arg_type);
void	ft_set_precision(t_lst **lst, t_flags *f, char at, int *len);

#endif
