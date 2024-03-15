/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsiriyon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 15:40:52 by wsiriyon          #+#    #+#             */
/*   Updated: 2024/03/15 21:17:21 by wsiriyon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count_digit(long num);

char	*ft_ltoa(long num)
{
	char			*res;
	int				digit;
	unsigned long	n;

	digit = ft_count_digit(num);
	res = ft_calloc(digit + 1, sizeof(char));
	if (!res)
		return (NULL);
	if (num < 0)
	{
		res[0] = '-';
		n = num * -1;
	}
	else
		n = num;
	while (n != 0)
	{
		res[--digit] = (n % 10) + '0';
		n /= 10;
	}
	if (n == 0)
		res[0] = '0';
	return (res);
}

static int	ft_count_digit(long num)
{
	int	count;

	count = 0;
	if (num < 0)
		count++;
	while (num / 10 != 0)
	{
		count++;
		num /= 10;
	}
	return (count + 1);
}
