/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 14:16:07 by aputman           #+#    #+#             */
/*   Updated: 2016/07/26 14:43:51 by aputman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		realloc_str(char **str)
{
	char		*tmp;

	if (!(*str))
	{
		if (!((*str) = ft_strnew(BUFF_SIZE + 1)))
			return (0);
		return (1);
	}
	if (!(tmp = (char *)malloc(sizeof(char) * (ft_strlen(*str) + 1))))
		return (0);
	ft_strcpy(tmp, *str);
	free(*str);
	if (!(*str = ft_strnew(sizeof(char) * ((ft_strlen(tmp) + BUFF_SIZE + 1)))))
		return (0);
	ft_strcpy(*str, tmp);
	free(tmp);
	return (1);
}

static char		*do_ur_shit(char *str, char **line)
{
	int			i;
	char		*tmp;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	*line = ft_strsub(str, 0, i);
	if ((size_t)i < ft_strlen(str) - 1)
	{
		tmp = ft_strsub(str, (i + 1), ft_strlen(str));
		free(str);
		str = ft_strsub(tmp, 0, ft_strlen(tmp));
		free(tmp);
	}
	else
	{
		free(str);
		str = NULL;
	}
	return (str);
}

int				get_next_line(const int fd, char **line)
{
	static char	*str = NULL;
	char		*tmp;
	int			rd;

	if (line == NULL || fd < 0 || !(tmp = ft_strnew(sizeof(char) * BUFF_SIZE)))
		return (-1);
	while ((rd = read(fd, tmp, BUFF_SIZE)) > 0)
	{
		if (!(realloc_str(&str)))
			return (-1);
		ft_strncat(str, tmp, BUFF_SIZE);
		if (ft_strchr(str, '\n'))
			break ;
		free(tmp);
		if (!(tmp = ft_strnew(sizeof(char) * BUFF_SIZE)))
			return (-1);
	}
	free(tmp);
	if (rd == 0 && !str)
		return (0);
	if (rd == -1)
		return (-1);
	str = do_ur_shit(str, &(*line));
	return (1);
}
