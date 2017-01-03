/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 13:36:19 by aputman           #+#    #+#             */
/*   Updated: 2015/12/08 15:26:22 by aputman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	check;
	unsigned char	*c1;
	unsigned char	*c2;

	i = -1;
	check = (unsigned char)c;
	c1 = (unsigned char *)src;
	c2 = (unsigned char *)dst;
	while (++i < n)
	{
		if ((*c2++ = *c1++) == check)
			return (void *)(c2);
	}
	return (NULL);
}
