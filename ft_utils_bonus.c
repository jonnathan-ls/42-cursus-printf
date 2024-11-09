#include "ft_printf_bonus.h"

static int	ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}

static int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] >= 48 && nptr[i] <= 57)
	{
		result = result * 10 + nptr[i] - '0';
		i++;
	}
	return (result * sign);
}

static void	ft_init_flags(t_flags *flags)
{
	flags->sign = 0;
	flags->space = 0;
	// flags->has_flags = 1;
	flags->min_width = 0;
	flags->precision = 0;
	flags->alternate = 0;
	flags->align_left = 0;
	flags->width_value = 0;
	flags->zero_padding = 0;
	flags->precision_value = -1;
}

static int	ft_str_has_flag(const char *str, char chr)
{
	while (*str && *str != chr)
		str++;
	if (*str == chr)
		return 1;
	return 0;
}

void	ft_initialize_flags(const char **format, t_flags *flags)
{
	ft_init_flags(flags);
	while (ft_str_has_flag(FLAGS, **format) || ft_isdigit(**format))
	{
		if (**format == ALIGN_LEFT_FLAG && !flags->align_left)
			flags->align_left = 1;
		else if (**format == SIGN_FLAG && !flags->sign)
			flags->sign = 1;
		else if (**format == ALTERNATE_FLAG && !flags->alternate)
			flags->alternate = 1;
		else if (**format == ZERO_PADDING_FLAG && !flags->zero_padding)
			flags->zero_padding = 1;
		else if (**format == SPACE_FLAG && !flags->space)
			flags->space = 1;
		else if (ft_isdigit(**format) && !flags->min_width)
		{
			flags->min_width = 1;
			flags->width_value	= ft_atoi(*format);
		}
		else if (**format == PRECISION_FLAG && !flags->precision)
		{
			flags->precision = 1;
			flags->precision_value = ft_atoi(*format + 1);
		}
		(*format)++;
	}
}
