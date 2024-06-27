/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebengtss <ebengtss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 10:50:51 by ebengtss          #+#    #+#             */
/*   Updated: 2024/06/27 12:30:01 by ebengtss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/solong.h"

int	processmap(int fd, char ***map, t_data **gamedata)
{
	*map = makemap(fd);
	if (!(*map))
		return (ft_putstr_fd("Error creating the map from file", 2), 1);
	if (checkmap(*map))
		return (ft_freemain(*map, *gamedata), 1);
	*gamedata = getmapdata(*map);
	if (!gamedata)
		return (ft_freemain(*map, *gamedata), 1);
	if (ismapvalid(*map, *gamedata))
		return (ft_freemain(*map, *gamedata), 1);
	return (0);
}

int	checkmap(char **map)
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
				return (ft_putstr_fd("Error map isnt a square", 2), 1);
		if (i == 0 || !map[i + 1])
		{
			while (map[i][j])
			{
				if (map[i][j] != '1')
					return (ft_putstr_fd("Error border is invalid", 2), 1);
				j++;
			}
		}
		else if (map[i][0] != '1' || map[i][ft_strlen(map[i]) - 1] != '1')
			return (ft_putstr_fd("Error border is invalid", 2), 1);
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

char	**makemap(int fd)
{
	char	**map;
	char	*buff;
	char	*tmpbuff;
	char	*tmpmap;

	tmpbuff = NULL;
	tmpmap = NULL;
	buff = ft_get_next_line(fd);
	if (!buff)
		return (NULL);
	while (buff)
	{
		tmpbuff = tmpmap;
		tmpmap = ft_gnljoin(tmpbuff, buff);
		if (!tmpmap)
			return (ft_freemakemap(buff, NULL, NULL), NULL);
		ft_freemakemap(buff, NULL, NULL);
		buff = ft_get_next_line(fd);
	}
	map = ft_split(tmpmap, '\n');
	if (!map)
		return (ft_freemakemap(buff, tmpbuff, tmpmap), NULL);
	return (ft_freemakemap(buff, NULL, tmpmap), map);
}
