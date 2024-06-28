/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebengtss <ebengtss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 10:50:51 by ebengtss          #+#    #+#             */
/*   Updated: 2024/06/28 12:36:20 by ebengtss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

int	processmap(int fd, t_data *gamedata)
{
	if (makemap(fd, gamedata))
		return (ft_putstr_fd("Error creating the map from file", 2), 1);
	if (checkmap(gamedata->map))
		return (ft_freemain(gamedata), 1);
	if (getmapdata(gamedata))
		return (ft_freemain(gamedata), 1);
	if (ismapvalid(gamedata))
		return (ft_freemain(gamedata), 1);
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

int	makemap(int fd, t_data *gamedata)
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
	gamedata->map = ft_split(tmpmap, '\n');
	if (!gamedata->map)
		return (ft_freemakemap(buff, tmpbuff, tmpmap), 1);
	return (ft_freemakemap(buff, NULL, tmpmap), 0);
}
