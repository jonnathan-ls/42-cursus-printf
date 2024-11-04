#include "ft_printf.h"

void	ft_init_flags(t_flags *flags)
{
	flags->sign = 0;
	flags->space = 0;
	flags->width = 0;
	flags->precision = 0;
	flags->alternate = 0;
	flags->left_justify = 0;
	flags->zero_padding = 0;
	flags->is_width_first = 0;
	flags->precision_value = -1;
}

void	ft_parse_flags(const char **format, t_flags *flags)
{
	flags->is_width_first = ft_atoi(*format) > 0;
	if (flags->is_width_first)
	{
		if (**format	== '0')
		{
			flags->zero_padding = 1;
			(*format)++;
		}
		flags->width = ft_atoi(*format);
		while (ft_isdigit(**format))
			(*format)++;
	}
	while (ft_strchr("-0.# +", **format))
	{
		if (**format == '-')
			flags->left_justify = 1;
		else if (**format == '0')
			flags->zero_padding = 1;
		else if (**format == '.')
		{
			flags->precision = 1;
			if (flags->is_width_first)
			{
				(*format)++;
				flags->precision_value = ft_atoi(*format);
			}
		}
		else if (**format == '#')
			flags->alternate = 1;
		else if (**format == ' ')
			flags->space = 1;
		else if (**format == '+')
			flags->sign = 1;
		(*format)++;
	}
	if (ft_isdigit(**format))
	{
		if (!flags->is_width_first)
			flags->width = ft_atoi(*format);
		if (flags->precision && !flags->is_width_first)
			flags->precision_value = flags->width;
		while (ft_isdigit(**format))
			(*format)++;
	}
}