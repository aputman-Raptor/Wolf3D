/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/16 09:18:51 by aputman           #+#    #+#             */
/*   Updated: 2016/12/16 09:54:18 by aputman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void		get_color(t_ray *ray, t_color *color)
{
	if (ray->side == 0 && ray->raydir_x > 0)
	{
		color->r = 255;
		color->g = 0;
		color->b = 0;
	}
	else if (ray->side == 0)
	{
		color->r = 0;
		color->g = 255;
		color->b = 0;
	}
	if (ray->side == 1 && ray->raydir_y < 0)
	{
		color->r = 0;
		color->g = 0;
		color->b = 255;
	}
	else if (ray->side == 1)
	{
		color->r = 255;
		color->g = 255;
		color->b = 0;
	}
}
