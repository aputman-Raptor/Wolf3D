/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprime.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 18:30:51 by aputman           #+#    #+#             */
/*   Updated: 2015/12/19 16:03:17 by aputman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isprime(int nb)
{
	int value;

	if (nb == 0 || nb == 1 || (nb % 2) == 0)
		return (0);
	else
	{
		value = 3;
		while (nb % value != 0 && value != nb)
			value += 2;
		if (value == nb)
			return (1);
		else
			return (0);
	}
}
