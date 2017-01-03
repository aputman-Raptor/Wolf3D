/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/09 17:37:08 by aputman           #+#    #+#             */
/*   Updated: 2016/12/16 09:54:34 by aputman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static void		rot_left(t_player *player)
{
	double		old_dir_x;
	double		old_plane_x;

	old_dir_x = player->dir_x;
	player->dir_x = player->dir_x * cos(ROT) - player->dir_y * sin(ROT);
	player->dir_y = old_dir_x * sin(ROT) + player->dir_y * cos(ROT);
	old_plane_x = player->plane_x;
	player->plane_x = player->plane_x * cos(ROT) - player->plane_y * sin(ROT);
	player->plane_y = old_plane_x * sin(ROT) + player->plane_y * cos(ROT);
}

static void		rot_right(t_player *player)
{
	double		old_dir_x;
	double		old_plane_x;

	old_dir_x = player->dir_x;
	player->dir_x = player->dir_x * cos(-ROT) - player->dir_y * sin(-ROT);
	player->dir_y = old_dir_x * sin(-ROT) + player->dir_y * cos(-ROT);
	old_plane_x = player->plane_x;
	player->plane_x = player->plane_x * cos(-ROT) - player->plane_y * sin(-ROT);
	player->plane_y = old_plane_x * sin(-ROT) + player->plane_y * cos(-ROT);
}

static void		move_forward(int **tmap, t_player *player)
{
	if (!tmap[(int)(player->pos_x + player->dir_x)][(int)(player->pos_y)])
		player->pos_x += player->dir_x * SPEED;
	if (!tmap[(int)(player->pos_x)][(int)(player->pos_y + player->dir_y)])
		player->pos_y += player->dir_y * SPEED;
}

static void		move_backward(int **tmap, t_player *player)
{
	if (!tmap[(int)(player->pos_x - player->dir_x)][(int)(player->pos_y)])
		player->pos_x -= player->dir_x * SPEED;
	if (!tmap[(int)(player->pos_x)][(int)(player->pos_y - player->dir_y)])
		player->pos_y -= player->dir_y * SPEED;
}

int				input_manager(int keycode, t_env *env)
{
	if (keycode == ESC)
		destroy(env);
	else if (keycode == KEY_LEFT)
		rot_left(env->player);
	else if (keycode == KEY_RIGHT)
		rot_right(env->player);
	else if (keycode == KEY_DOWN)
		move_backward(env->map->tmap, env->player);
	else if (keycode == KEY_UP)
		move_forward(env->map->tmap, env->player);
	raycasting(env, env->player);
	return (0);
}
