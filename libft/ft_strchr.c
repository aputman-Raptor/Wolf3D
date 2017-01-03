/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 17:39:20 by aputman           #+#    #+#             */
/*   Updated: 2015/12/17 15:28:32 by aputman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	conv;

	conv = (char)c;
	while (*s)
	{
		if (*s++ == conv)
			return (char *)(s - 1);
	}
	if (*s++ == conv)
		return (char *)(s - 1);
	return (NULL);
}
