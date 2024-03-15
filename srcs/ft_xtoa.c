/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsiriyon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 15:31:04 by wsiriyon          #+#    #+#             */
/*   Updated: 2024/03/15 15:55:27 by wsiriyon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_xtoa_len(long num);

char	*ft_xtoa(unsigned long num, const char format)
{
	char	*hex;
	char	*res;
	size_t	len;

	hex = "0123456789abcdef";
	len = ft_xtoa_len(num);
	res = ft_calloc(len + 1, sizeof(char));
	if (!res)
		return (NULL);
	while (num / 16 != 0)
	{
		res[--len] = hex[num % 16];
		num /= 16;
	}
	res[--len] = hex[num % 16];
	while (res[len] && format == 'X')
	{
		if (ft_isalpha(res[len]))
			res[len] = ft_toupper(res[len]);
		len++;
	}
	return (res);
}

static size_t	ft_xtoa_len(long num)
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
