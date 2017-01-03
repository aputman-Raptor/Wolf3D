/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 18:40:09 by aputman           #+#    #+#             */
/*   Updated: 2015/12/19 14:57:40 by aputman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_find_next_prime(int nb)
{
	int	value;

	if (nb == 0 || nb == 1)
		return (0);
	else
	{
		value = 2;
		while (nb % value != 0 && value != nb)
			value++;
		if (value == nb)
			return (nb);
		else
		{
			nb++;
			nb = ft_find_next_prime(nb);
			return (nb);
		}
	}
}
