/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 18:34:06 by aputman           #+#    #+#             */
/*   Updated: 2015/12/11 18:43:22 by aputman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	size_t	i;

	str = ft_strdup((const char *)s);
	if (!str)
		return (NULL);
	i = 0;
	while (str[i])
	{
		str[i] = f(str[i]);
		i++;
	}
	return (str);
}
