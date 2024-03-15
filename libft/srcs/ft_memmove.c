/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsiriyon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 16:00:27 by wsiriyon          #+#    #+#             */
/*   Updated: 2024/02/18 17:38:56 by wsiriyon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*p_dst;
	char	*p_src;
	size_t	i;

	if (!dest && !src)
		return (NULL);
	p_dst = (char *)dest;
	p_src = (char *)src;
	i = -1;
	if (p_dst > p_src)
		while (n-- > 0)
			p_dst[n] = p_src[n];
	else
		while (++i < n)
			p_dst[i] = p_src[i];
	return (dest);
}
