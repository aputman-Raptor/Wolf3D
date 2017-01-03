/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 12:13:13 by aputman           #+#    #+#             */
/*   Updated: 2015/12/08 15:30:05 by aputman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *str)
{
	int		sign;
	char	*ptr;
	int		result;

	result = 0;
	ptr = (char *)str;
	while (ft_isspace(*ptr))
		ptr++;
	sign = (*ptr == '-') ? -1 : 1;
	ptr = (*ptr == '+' || *ptr == '-') ? ptr + 1 : ptr;
	while (*ptr >= '0' && *ptr <= '9')
	{
		result = result * 10 + *ptr - 48;
		ptr++;
	}
	result *= sign;
	return (result);
}
