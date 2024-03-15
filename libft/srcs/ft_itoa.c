/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsiriyon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 19:06:13 by wsiriyon          #+#    #+#             */
/*   Updated: 2024/02/23 21:19:36 by wsiriyon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_digit(int n);

char	*ft_itoa(int n)
{
	char			*res;
	int				digit;
	unsigned int	num;

	digit = ft_count_digit(n);
	res = ft_calloc(digit + 1, sizeof(char));
	if (!res)
		return (NULL);
	if (n < 0)
	{
		res[0] = '-';
		num = n * -1;
	}
	else
		num = n;
	while (num != 0)
	{
		res[--digit] = num % 10 + '0';
		num /= 10;
	}
	if (n == 0)
		res[0] = '0';
	return (res);
}

static int	ft_count_digit(int n)
{
	int	count;

	count = 0;
	if (n < 0)
		count++;
	while (n / 10 != 0)
	{
		count++;
		n /= 10;
	}
	return (count + 1);
}
