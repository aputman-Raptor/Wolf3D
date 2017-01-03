/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/09 17:28:07 by aputman           #+#    #+#             */
/*   Updated: 2016/12/16 09:54:42 by aputman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static int	key_ft(int keycode, t_env *env)
{
	input_manager(keycode, env);
	return (0);
}

int			destroy(t_env *env)
{
	free(env->color);
	free(env->player);
	free(env->map->tmap);
	free(env->map);
	mlx_destroy_window(env->mlx, env->win);
	exit(0);
}

void		mlx_env_init(t_env *env)
{
	if (!(env->mlx = mlx_init()))
		exit(0);
	if (!(env->map = (t_map *)malloc(sizeof(t_map))))
		exit(0);
	if (!(env->color = (t_color *)malloc(sizeof(t_color))))
		exit(0);
	env->player = create_player();
	env->win = mlx_new_window(env->mlx, WIDTH, HEIGHT, "Wolf3D");
	mlx_hook(env->win, 2, 1L << 0, key_ft, env);
	mlx_hook(env->win, 17, 1L << 17, destroy, env);
}
