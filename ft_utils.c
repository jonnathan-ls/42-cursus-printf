#include "ft_printf.h"

void init_flags(t_flags *flags)
{
 flags->left_justify = 0;
 flags->zero_padding = 0;
 flags->precision = 0;
 flags->alternate = 0;
 flags->space = 0;
 flags->sign = 0;
 flags->width = 0;
 flags->precision_value = -1; // -1 indica que a precisão não foi especificada
}

void parse_flags(const char **format, t_flags *flags)
{
	while (**format == '-' || **format == '0' || **format == '.' || **format == '#' || **format == ' ' || **format == '+') // ft_strchr("-0.# +", **format)
	{
		if (**format == '-')
			flags->left_justify = 1;
		else if (**format == '0')
			flags->zero_padding = 1;
		else if (**format == '.')
			flags->precision = 1;
		else if (**format == '#')
			flags->alternate = 1;
		else if (**format == ' ')
			flags->space = 1;
		else if (**format == '+')
			flags->sign = 1;
		(*format)++;
	}
	// Parsing da largura mínima
	if (**format >= '0' && **format <= '9') // ft_isdigit(**format)
	{
		flags->width = atoi(*format); // ft_atoi(*format)
		while (**format >= '0' && **format <= '9')
			(*format)++;
	}
	// Parsing da precisão
	if (flags->precision && **format == '.')
	{
		(*format)++;
		flags->precision_value = atoi(*format);
		while (**format >= '0' && **format <= '9')
			(*format)++;
 }
}