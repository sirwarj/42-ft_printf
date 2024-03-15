/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsiriyon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:18:50 by wsiriyon          #+#    #+#             */
/*   Updated: 2024/03/15 20:54:38 by wsiriyon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_formats(char format, va_list *args, t_flags *flags);
static int	ft_parse(const char *str, va_list *args);
static int	ft_parse_flags(const char *str, int i,
				va_list *args, t_flags *flags);

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;

	if (!format || *format == '\0')
		return (0);
	va_start(args, format);
	len = ft_parse(format, &args);
	va_end(args);
	return (len);
}

static int	ft_print_formats(char format, va_list *args, t_flags *flags)
{
	int	len;

	len = 0;
	if (format == 'c')
		len += ft_print_char(va_arg(*args, int), flags);
	else if (format == 's')
		len += ft_print_str(va_arg(*args, const char *), flags);
	else if (format == 'p')
		len += ft_print_ptr((unsigned long)va_arg(*args, void *), flags);
	else if (format == 'd' || format == 'i')
		len += ft_print_int(va_args(*args, int), flags);
	else if (format == 'u')
		len += ft_print_unsigned(va_args(*args, unsigned int), flags);
	else if (format == 'x' || format == 'X')
		len += ft_print_hex(va_arg(*args, unsigned int), format, flags);
	else if (format == '%')
		len += ft_print_char('%', flags);
	return (len);
}

static int	ft_parse_flags(const char *str, int i,
		va_list *args, t_flags *flags)
{
	while (str[++i] && ft_isflag(str[i]))
	{
		if (str[i] == '-')
			ft_flag_left(flags);
		if (str[i] == '#')
			flags->hash = 1;
		if (str[i] == ' ')
			flags->space = 1;
		if (str[i] == '+')
			flags->plus = 1;
		if (str[i] == '0' && flags->left == 0 && flags->width == 0)
			flags->zero = 1;
		if (str[i] == '.')
			i = ft_flag_precision(str, i, args, flags);
		if (str[i] == '*')
			ft_flag_width(args, flags);
		if (ft_isdigit(str[i]))
			ft_flag_digit(str[i], *flags);
		if (ft_istype(str[i]))
		{
			flags->spec = str[i];
			break ;
		}
	}
	return (i);
}

static int	ft_parse(const char *str, va_list *args)
{
	t_flags	*flags;
	int		i;
	int		len;

	i = -1;
	len = 0;
	while (str[++i])
	{
		ft_flags_init(flags);
		if (str[i] == '%' && str[i + 1] != '\0')
		{
			i = ft_parse_ flags(str, i, args, flags);
			if (str[i] != '\0' && flags->spec > 0 && ft_istype(str[i]))
				len += ft_print_formats(str[i], flags);
			else if (str[i] != '\0')
				len += ft_print_char(str[i], flags);
		}
		else
			len += ft_print_c(str[i]);
	}
	free(flags)
	return (len);
}
