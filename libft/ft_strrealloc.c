/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrealloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 14:56:27 by aputman           #+#    #+#             */
/*   Updated: 2017/01/03 13:39:28 by aputman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrealloc(char *str, int size)
{
	char	*tmp;

	tmp = ft_strdup(str);
	free(str);
	if (!(str = ft_strnew(ft_strlen(tmp) + size + 1)))
		return (NULL);
	ft_strcpy(str, tmp);
	free(tmp);
	return (str);
}
