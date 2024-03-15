/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsiriyon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 15:46:42 by wsiriyon          #+#    #+#             */
/*   Updated: 2024/02/18 15:59:51 by wsiriyon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*p_dst;
	unsigned char	*p_src;

	if (!dest && !src)
		return (dest);
	p_dst = (unsigned char *)dest;
	p_src = (unsigned char *)src;
	while (n-- > 0)
		*p_dst++ = *p_src++;
	return (dest);
}
