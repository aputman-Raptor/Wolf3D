/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 11:33:34 by aputman           #+#    #+#             */
/*   Updated: 2015/12/08 15:38:17 by aputman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	if (s2[0] == '\0')
		return (char *)(s1);
	while (s1[i] != '\0')
	{
		i = j;
		k = 0;
		while (s1[i] == s2[k])
		{
			i++;
			k++;
			if (s2[k] == '\0')
				return (char *)(&s1[j]);
		}
		j++;
	}
	return (NULL);
}
