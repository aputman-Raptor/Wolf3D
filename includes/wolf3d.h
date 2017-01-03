/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/09 16:23:20 by aputman           #+#    #+#             */
/*   Updated: 2016/12/13 15:27:10 by aputman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "libft.h"
# include "mlx.h"

# define WIDTH 1920
# define HEIGHT 1080

# define ESC 53
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_RIGHT 124
# define KEY_LEFT 123

# define SPEED 0.5
# define ROT (M_PI / 30)

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	void			*img;
	int				rgb;
	int				rgb_line;
	int				endian;
	struct s_map	*map;
	struct s_player	*player;
	struct s_color	*color;
}					t_env;

typedef struct		s_map
{
	int				**tmap;
	int				len_x;
	int				len_y;
}					t_map;

typedef struct		s_player
{
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	double			rot;
}					t_player;

typedef struct		s_ray
{
	double			raypos_x;
	double			raypos_y;
	double			raydir_x;
	double			raydir_y;
	double			sidedist_x;
	double			sidedist_y;
	double			deltadist_x;
	double			deltadist_y;
	double			perpwalldist;
	double			plane_x;
	double			plane_y;
	double			rot;
	double			camera;
	int				stepx;
	int				stepy;
	int				mapx;
	int				mapy;
	int				lineheight;
	int				draw_start;
	int				draw_end;
	int				hit;
	int				side;
}					t_ray;

typedef struct		s_color
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}					t_color;

void				mlx_env_init(t_env *env);
int					input_manager(int keycode, t_env *env);

t_map				*getmap(t_map *map, char *argv);
t_player			*create_player(void);

int					destroy(t_env *env);

void				raycasting(t_env *env, t_player *player);
void				get_color(t_ray *ray, t_color *color);
void				draw_column(int x, int drawstart, int drawend, t_env *env);

#endif
