/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/16 06:19:13 by aputman           #+#    #+#             */
/*   Updated: 2016/12/16 09:55:01 by aputman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static void		ray_init(t_ray *ray, t_player *player, int x)
{
	ray->raypos_x = player->pos_x;
	ray->raypos_y = player->pos_y;
	ray->camera = 2 * x / (double)WIDTH - 1;
	ray->raydir_x = player->dir_x + player->plane_x * ray->camera;
	ray->raydir_y = player->dir_y + player->plane_y * ray->camera;
	ray->mapx = (int)ray->raypos_x;
	ray->mapy = (int)ray->raypos_y;
	ray->deltadist_x = sqrt(1 + (ray->raydir_y * ray->raydir_y)
			/ (ray->raydir_x * ray->raydir_x));
	ray->deltadist_y = sqrt(1 + (ray->raydir_x * ray->raydir_x)
			/ (ray->raydir_y * ray->raydir_y));
	ray->hit = 0;
}

static void		pre_dda(t_ray *ray)
{
	if (ray->raydir_x < 0)
	{
		ray->stepx = -1;
		ray->sidedist_x = (ray->raypos_x - ray->mapx) * ray->deltadist_x;
	}
	else
	{
		ray->stepx = 1;
		ray->sidedist_x = (ray->mapx + 1.0 - ray->raypos_x) * ray->deltadist_x;
	}
	if (ray->raydir_y < 0)
	{
		ray->stepy = -1;
		ray->sidedist_y = (ray->raypos_y - ray->mapy) * ray->deltadist_y;
	}
	else
	{
		ray->stepy = 1;
		ray->sidedist_y = (ray->mapy + 1.0 - ray->raypos_y) * ray->deltadist_y;
	}
}

static void		perform_dda(int **tmap, t_ray *ray)
{
	while (ray->hit == 0)
	{
		if (ray->sidedist_x < ray->sidedist_y)
		{
			ray->sidedist_x += ray->deltadist_x;
			ray->mapx += ray->stepx;
			ray->side = 0;
		}
		else
		{
			ray->sidedist_y += ray->deltadist_y;
			ray->mapy += ray->stepy;
			ray->side = 1;
		}
		if (tmap[ray->mapx][ray->mapy] > 0)
			ray->hit = 1;
	}
	if (ray->side == 0)
		ray->perpwalldist = (ray->mapx - ray->raypos_x + (1 - ray->stepx) / 2)
			/ ray->raydir_x;
	else
		ray->perpwalldist = (ray->mapy - ray->raypos_y + (1 - ray->stepy) / 2)
			/ ray->raydir_y;
}

void			raycasting(t_env *env, t_player *player)
{
	t_ray		ray;
	int			x;

	(void)player;
	env->img = mlx_new_image(env->mlx, WIDTH, HEIGHT);
	x = -1;
	while (++x < WIDTH)
	{
		ray_init(&ray, env->player, x);
		pre_dda(&ray);
		perform_dda(env->map->tmap, &ray);
		ray.lineheight = (int)(HEIGHT / ray.perpwalldist);
		ray.draw_start = -ray.lineheight / 2 + HEIGHT / 2;
		if (ray.draw_start < 0)
			ray.draw_start = 0;
		ray.draw_end = ray.lineheight / 2 + HEIGHT / 2;
		if (ray.draw_end >= HEIGHT)
			ray.draw_end = HEIGHT - 1;
		get_color(&ray, &(*(env->color)));
		draw_column(x, ray.draw_start, ray.draw_end, &(*env));
	}
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	mlx_destroy_image(env->mlx, env->img);
}
