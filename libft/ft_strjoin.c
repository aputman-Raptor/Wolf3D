/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 17:11:26 by aputman           #+#    #+#             */
/*   Updated: 2015/12/18 15:45:24 by aputman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*tab;
	int		i;

	i = 0;
	if (!(tab = (char *)malloc(sizeof(char) * ((ft_strlen(s1) +
							ft_strlen(s2) + 1)))))
		return (NULL);
	while (*s1)
	{
		tab[i] = *s1++;
		i++;
	}
	while (*s2)
	{
		tab[i] = *s2++;
		i++;
	}
	tab[i] = '\0';
	return (tab);
}
