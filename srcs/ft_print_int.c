/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsiriyon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 20:55:52 by wsiriyon          #+#    #+#             */
/*   Updated: 2024/03/15 21:33:52 by wsiriyon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putint(char *str, int n, t_flags *flags);
static int	ft_print_zero_space(char *str, t_flags *flags);

int	ft_print_int(int n, t_flags *flags)
{
	char	*res;
	long	num;
	int		len;

	num = n;
	len = 0;
	if (num < 0)
	{
		num *= -1;
		if (flags->zero == 0)
			flags->width--;
	}
	if (flags->precision == 0 && n == 0)
	{
		len += ft_pad_width(flags->width, 0, 0);
		return (len);
	}
	res = ft_ltoa(num);
	if (!res)
		return (0);
	len += ft_putint(res, n, flags);
	free(res);
	return (len);
}

static int	ft_putint(char *str, int n, t_flags *flags)
{
	int	len;

	len = 0;
	if (flags->zero == 1)
		len += ft_putsign(n, flags);
	if (flags->left == 1)
		len += ft_print_pre(str, n, flags);
	if (flags->precision >= 0 && flags.precision < (int)ft_strlen(str))
		flags->precision = ft_strlen(str);
	if (flags->precision >= 0)
	{
		flags->width -= flags->precision;
		if (n < 0 && flags->left == 0)
			flags->width--;
		len += ft_pad_width(flags->width, 0, 0);
	}
	else
		len += ft_print_zero_space(str, flags);
	if (flags->left == 0)
		len += ft_print_pre(str, n, flags);
	return (len);
}

static int	ft_print_zero_space(char *str, t_flags *flags)
{
	int	len;

	len = 0;
	if (flags->zero && flags->space)
	{
		len += ft_pad_width(flags->width - flags->plus,
				ft_strlen(str), flags->zero);
	}
	else
	{
		len += ft_pad_width(flags->width - flags->plus - flags->space,
				ft_strlen(str), flags->zero);
	}
	return (len);
}
