/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 12:17:20 by aputman           #+#    #+#             */
/*   Updated: 2015/12/08 15:32:58 by aputman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*c1;
	unsigned char	*c2;

	i = -1;
	c1 = (unsigned char *)src;
	c2 = (unsigned char *)dst;
	while (++i < n)
		c2[i] = c1[i];
	return (dst);
}
