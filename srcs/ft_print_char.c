/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsiriyon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 19:30:03 by wsiriyon          #+#    #+#             */
/*   Updated: 2024/02/28 19:36:54 by wsiriyon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_print_char(int c, t_flags *flags)
{
	int	len;

	len = 0;
	if (flags->left == 1)
		len += ft_putchar(c);
	len += ft_pad_width(flags->width, 1, flags->zero);
	if (flags->left == 0)
		len += ft_putchar(c);
	return (len);
}
