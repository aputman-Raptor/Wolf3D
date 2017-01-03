/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 11:33:34 by aputman           #+#    #+#             */
/*   Updated: 2015/12/17 17:28:20 by aputman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char *s1, char *s2, size_t n)
{
	size_t i;
	size_t j;
	size_t k;

	i = 0;
	j = 0;
	if (s2[0] == '\0')
		return (char *)(s1);
	while (s1[i] != '\0' && (n > 0))
	{
		i = j;
		k = 0;
		while (s1[i] == s2[k] && (k <= n))
		{
			i++;
			k++;
			if (s2[k] == '\0')
				return (char *)(&s1[j]);
		}
		j++;
		n--;
	}
	return (NULL);
}
