/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 15:18:21 by aputman           #+#    #+#             */
/*   Updated: 2015/12/04 15:39:54 by aputman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	check;
	unsigned char	*str;

	check = (unsigned char)c;
	str = (unsigned char *)s;
	while (n--)
	{
		if (*str++ == check)
			return (str - 1);
	}
	return (NULL);
}
