/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebengtss <ebengtss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 10:50:51 by ebengtss          #+#    #+#             */
/*   Updated: 2024/07/03 11:45:25 by ebengtss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

int	processmap(int fd, t_data *gdata)
{
	srand(time(NULL));
	initdata(gdata);
	gdata->fd = fd;
	if (makemap(fd, gdata))
		return (ft_putstr_fd("Error\ncreating the map from file", 2), 1);
	if (checkmapsize(gdata->map))
		return (1);
	if (checkmapchar(gdata->map))
		return (ft_putstr_fd("Error\nmap contain non allowed characters", 2), 1);
	if (getmapdata(gdata))
		return (1);
	if (ismapvalid(gdata))
		return (1);
	return (0);
}

int	checkmapchar(char **map)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] != '1' && map[y][x] != '0'
				&& map[y][x] != 'P' && map[y][x] != 'E'
				&& map[y][x] != 'C')
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

int	checkmapsize(char **map)
{
	size_t	tmplen;
	int		i;
	int		j;

	i = -1;
	while (map[++i])
	{
		j = 0;
		tmplen = ft_strlen(map[i]);
		if (i > 0)
			if (tmplen != ft_strlen(map[i - 1]))
				return (ft_putstr_fd("Error\nmap isnt a square", 2), 1);
		if (i == 0 || !map[i + 1])
		{
			while (map[i][j])
			{
				if (map[i][j] != '1')
					return (ft_putstr_fd("Error\nborder is invalid", 2), 1);
				j++;
			}
		}
		else if (map[i][0] != '1' || map[i][ft_strlen(map[i]) - 1] != '1')
			return (ft_putstr_fd("Error\nborder is invalid", 2), 1);
	}
	return (0);
}

void	ft_freemakemap(char *buff, char *tmpbuff, char *tmpmap)
{
	if (buff)
	{
		free(buff);
		buff = NULL;
	}
	if (tmpbuff)
	{
		free(tmpbuff);
		tmpbuff = NULL;
	}
	if (tmpmap)
	{
		free(tmpmap);
		tmpmap = NULL;
	}
}

int	makemap(int fd, t_data *gdata)
{
	char	*buff;
	char	*tmpbuff;
	char	*tmpmap;

	tmpbuff = NULL;
	tmpmap = NULL;
	buff = ft_get_next_line(fd);
	if (!buff)
		return (1);
	while (buff)
	{
		tmpbuff = tmpmap;
		tmpmap = ft_gnljoin(tmpbuff, buff);
		if (!tmpmap)
			return (ft_freemakemap(buff, NULL, NULL), 1);
		ft_freemakemap(buff, NULL, NULL);
		buff = ft_get_next_line(fd);
	}
	gdata->map = ft_split(tmpmap, '\n');
	if (!gdata->map)
		return (ft_freemakemap(buff, tmpbuff, tmpmap), 1);
	return (ft_freemakemap(buff, NULL, tmpmap), 0);
}
