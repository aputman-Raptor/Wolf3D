/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/09 16:22:14 by aputman           #+#    #+#             */
/*   Updated: 2016/12/16 09:54:50 by aputman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void			draw_pixel(t_env *env, int x, int y, t_color *color)
{
	char		*data;

	data = mlx_get_data_addr(env->img, &env->rgb, &env->rgb_line,
			&env->endian);
	data[x * env->rgb / 8 + y * env->rgb_line] = color->b;
	data[x * env->rgb / 8 + 1 + y * env->rgb_line] = color->g;
	data[x * env->rgb / 8 + 2 + y * env->rgb_line] = color->r;
}

void			draw_column(int x, int drawstart, int drawend, t_env *env)
{
	while (drawstart <= drawend)
	{
		draw_pixel(env, x, drawstart, env->color);
		drawstart++;
	}
}

t_player		*create_player(void)
{
	t_player	*player;

	if (!(player = (t_player *)malloc(sizeof(t_player))))
		return (NULL);
	player->pos_x = 1.01;
	player->pos_y = 1.01;
	player->dir_x = -1;
	player->dir_y = 0;
	player->plane_x = 0;
	player->plane_y = 0.66;
	return (player);
}

static int	ft_error(void)
{
	ft_putstr_fd("\033[31mOpen/Read error\033[m", 2);
	return (-1);
}

int				main(void)
{
	t_env		env;

	mlx_env_init(&env);
	if (!(env.map = getmap(env.map, "map.wolf3d")))
		return (ft_error());
	raycasting(&env, env.player);
	mlx_loop(env.mlx);
	return (0);
}
