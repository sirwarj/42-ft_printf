/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsiriyon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 21:01:44 by wsiriyon          #+#    #+#             */
/*   Updated: 2024/02/28 19:26:43 by wsiriyon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flags_init(t_flags *flags)
{
	flags = (t_flags *)malloc(sizeof(t_flags));
	flags->spec = 0;
	flags->width = 0;
	flags->left = 0;
	flags->zero = 0;
	flags->star = 0;
	flags->precision = -1;
	flags->hash = 0;
	flags->space = 0;
	flags->plus = 0;
}

void	ft_flag_left(t_flags *flags)
{
	flags->left = 1;
	flags->zero = 0;
}

void	ft_flag_digit(char c, t_flags *flags)
{
	if (flags->star == 1)
		flags->width = 0;
	flags->width = (flags->width * 10) + (c - '0');
}

void	ft_flag_width(va_list *args, t_flags *flags)
{
	flags->star = 1;
	flags->width = va_arg(*args, int);
	if (flags->width < 0)
	{
		flags->left = 1;
		flags->width *= -1;
	}
}

int	ft_flag_precision(const char *str, int pos, va_list *args, t_flags *flags)
{
	int	i;

	i = pos + 1;
	if (str[i] == '*')
	{
		flags->precision = va_arg(*args, int);
		return (i++);
	}
	flags->precision = 0;
	while (ft_isdigit(str[i]))
		flags->precision = (flags->precision * 10) + (str[i++] - '0');
	return (i);
}
