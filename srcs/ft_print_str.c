/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsiriyon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 15:56:11 by wsiriyon          #+#    #+#             */
/*   Updated: 2024/03/15 21:04:34 by wsiriyon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putstrn(const char *str, int n);
static int	ft_print_pre(const char *str, t_flags *flags);

int	ft_print_str(const char *str, t_flags *flags)
{
	int	len;

	len = 0;
	if (str == NULL)
		str = "(null)";
	if (flags->precision >= 0 && str && flags->precision > (int)ft_strlen(str))
		flags->precision = ft_strlen(str);
	if (flags->left == 1)
		len += ft_print_pre(str, flags);
	if (flags->precision >= 0)
		len += ft_pad_width(flags->width, flags->precision, 0);
	else
		len += ft_pad_width(flags->width, ft_strlen(str), 0);
	if (flags->left == 0)
		len += ft_print_pre(str, flags);
	return (len);
}

static int	ft_print_pre(const char *str, t_flags *flags)
{
	int	len;

	len = 0;
	if (flags->precision >= 0)
	{
		len += ft_pad_width(flags->precision, ft_strlen(str), 0);
		len += ft_putstrn(str, flags->precision);
	}
	else
		len += ft_putstrn(str, ft_strlen(str));
	return (len);
}

static int	ft_putstrn(const char *str, int n)
{
	int	len;

	len = 0;
	while (str[len] && len < n)
		write(1, &str[len++], 1);
	return (len);
}

int	ft_putstr(const char *str)
{
	int	len;

	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	len = ft_strlen(str);
	write(1, str, len);
	return (len);
}
