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

typedef struct s_flags {
	int	sign;
	int	space;
	// int has_flags;
	int	precision;
	int	alternate;
	int	min_width;
	int	align_left;
	int	width_value;
	int	zero_padding;
	int	precision_value;
}	t_flags;

// int		ft_str_has_flag(const char *s, char c);
void	ft_initialize_flags(const char **format, t_flags *flags);

#endif
