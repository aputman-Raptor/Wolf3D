/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 18:29:53 by aputman           #+#    #+#             */
/*   Updated: 2015/12/17 20:29:20 by aputman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		lengths(int n, size_t *len, int *weight)
{
	*len = 1;
	if (n >= 0)
	{
		*len = 0;
		n = -n;
	}
	*weight = 1;
	while (n / *weight < -9)
	{
		*weight *= 10;
		*len += 1;
	}
}

char			*ft_itoa(int n)
{
	size_t		len;
	size_t		i;
	int			weight;
	char		*str;

	lengths(n, &len, &weight);
	if (!(str = (char *)malloc(sizeof(char) * (len + 2))))
		return (NULL);
	if (!str)
		return (NULL);
	i = 0;
	if (n < 0)
	{
		str[i] = '-';
		i++;
	}
	if (n > 0)
		n = -n;
	while (weight >= 1)
	{
		str[i++] = -(n / weight % 10) + 48;
		weight /= 10;
	}
	str[i] = '\0';
	return (str);
}
