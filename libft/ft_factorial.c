/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_factorial.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 19:08:15 by aputman           #+#    #+#             */
/*   Updated: 2015/12/19 14:57:27 by aputman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_factorial(int nb)
{
	int valtemp;

	if (nb == 0 || nb == 1)
		return (1);
	valtemp = nb;
	while (valtemp-- > 1)
		nb *= valtemp;
	if (nb > 0)
		return (nb);
	return (0);
}
