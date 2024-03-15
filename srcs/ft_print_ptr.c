/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsiriyon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 19:46:34 by wsiriyon          #+#    #+#             */
/*   Updated: 2024/03/15 21:18:30 by wsiriyon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_ptr_len(unsigned long n);
static void		ft_putadr(unsigned long ptr);
static int		ft_print_p(unsigned long n);

int	ft_print_ptr(unsigned long n, t_flags *flags)
{
	int	len;

	len = 0;
	if (n == 0)
		flags->width -= ft_strlen("0x0") - 1;
	else
		flags->width -= 2;
	if (flags->left == 1)
		len += ft_print_p(n);
	len += ft_pad_width(flags->width, ft_ptr_len(n), 0);
	if (flags->left == 0)
		len += ft_print_p(n);
	return (len);
}

static int	ft_print_p(unsigned long n)
{
	int	len;

	len = 0;
	if (n == 0)
	{
		len += ft_putchar("0x0");
		return (len);
	}
	len += ft_putchar("0x");
	ft_putadr(n);
	len += ft_ptr_len(n);
	return (len);
}

static void	ft_putadr(unsigned long ptr)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (ptr / 16 != 0)
		ft_putadr(ptr / 16);
	ft_putchar(hex[ptr % 16]);
}

static size_t	ft_ptr_len(unsigned long n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n >= 1)
	{
		len++;
		n /= 16;
	}
	return (len);
}
