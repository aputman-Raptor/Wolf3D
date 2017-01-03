/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 17:37:29 by aputman           #+#    #+#             */
/*   Updated: 2015/12/17 21:52:02 by aputman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	get_min(char const *s)
{
	size_t	min;

	min = 0;
	while (s[min] == ' ' || s[min] == '\n' || s[min] == '\t')
		min++;
	return (min);
}

static	size_t	get_max(char const *s)
{
	size_t	max;

	max = 0;
	while (s[max + 1])
		max++;
	while (s[max] == ' ' || s[max] == '\n' || s[max] == '\t')
		max--;
	return (max + 1);
}

char			*ft_strtrim(char const *s)
{
	char	*tab;
	int		i;
	size_t	min;
	size_t	max;

	i = 0;
	min = get_min(s);
	max = get_max(s);
	if (min >= max)
	{
		if (!(tab = (char *)malloc(sizeof(char) * 1)))
			return (NULL);
		tab = "\0";
		return (tab);
	}
	if ((max - min + 1) == ft_strlen(s))
		return (char *)(s);
	if (!(tab = (char *)malloc(sizeof(char) * (max - min) + 1)))
		return (NULL);
	while (min < max)
		tab[i++] = s[min++];
	tab[i] = '\0';
	return (tab);
}
