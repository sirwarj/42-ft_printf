/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsiriyon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 18:35:36 by wsiriyon          #+#    #+#             */
/*   Updated: 2024/02/20 20:27:27 by wsiriyon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*tmp;
	size_t	len;

	if (nmemb > 0 && SIZE_MAX / nmemb < size)
		return (NULL);
	len = nmemb * size;
	tmp = (void *)malloc(len);
	if (!tmp)
		return (NULL);
	ft_memset(tmp, 0, len);
	return (tmp);
}
