/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 18:05:30 by aputman           #+#    #+#             */
/*   Updated: 2015/12/17 17:53:56 by aputman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	conv;

	conv = (char)c;
	while (*s++ != '\0')
		;
	if (*--s == conv)
		return (char *)(s);
	while (*--s)
	{
		if (*s == conv)
			return (char *)(s);
	}
	return (NULL);
}
