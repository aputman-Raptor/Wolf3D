/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 15:42:32 by aputman           #+#    #+#             */
/*   Updated: 2016/12/16 09:54:27 by aputman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static int	*get_numbers(char *str, t_map **map)
{
	int		i;
	int		*result;
	char	**hitler;

	i = 0;
	hitler = ft_strsplit(str, ' ');
	while (hitler[i])
		i++;
	if (!(result = (int *)ft_memalloc(sizeof(int) * (i + 1))))
		return (NULL);
	i = -1;
	while (hitler[++i])
	{
		result[i] = ft_atoi(hitler[i]);
		free(hitler[i]);
	}
	free(hitler);
	(*map)->len_x = i;
	return (result);
}

static void	get_truman(char **fdp, t_map **map)
{
	int		i;

	i = 0;
	while (fdp[i])
		i++;
	if (!((*map)->tmap = (int **)ft_memalloc(sizeof(int *) * (i + 1))))
		return ;
	i = -1;
	while (fdp[++i])
	{
		(*map)->tmap[i] = get_numbers(fdp[i], map);
		free(fdp[i]);
	}
	free(fdp);
	(*map)->len_y = i;
	(*map)->tmap[i] = NULL;
}

t_map		*getmap(t_map *map, char *argv)
{
	char	**fdp;
	char	*tmp;
	int		fd;
	int		i;

	if ((fd = open(argv, O_RDONLY)) == -1)
		return (NULL);
	if (!(fdp = (char **)ft_memalloc(sizeof(char *) * 21)))
		return (NULL);
	i = 0;
	while (get_next_line(fd, &tmp) > 0)
	{
		fdp[i++] = ft_strdup(tmp);
		free(tmp);
	}
	get_truman(fdp, &map);
	close(fd);
	return (map);
}
