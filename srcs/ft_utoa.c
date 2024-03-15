/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsiriyon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 15:19:53 by wsiriyon          #+#    #+#             */
/*   Updated: 2024/03/15 15:29:26 by wsiriyon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_utoa_len(long num);

char	*ft_utoa(unsigned int num)
{
	char	*res;
	size_t	len;

	len = ft_utoa_len(num);
	res = ft_calloc(len + 1, sizeof(char));
	if (!res)
		return (NULL);
	while (--len)
	{
		res[len] = (num % 10) + '0';
		num /= 10;
	}
	res[0] = (num % 10) + '0';
	return (res);
}

static size_t	ft_utoa_len(long num)
{
	size_t	len;

	len = 0;
	if (num == 0)
		return (1);
	while (num >= 1)
	{
		len++;
		num /= 10;
	}
	return (len);
}
