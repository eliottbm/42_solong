/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebengtss <ebengtss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 13:17:29 by ebengtss          #+#    #+#             */
/*   Updated: 2024/06/28 12:47:31 by ebengtss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

int	testmap(t_tmptrack *tmpdata, int x, int y)
{
	if (tmpdata->map[y][x] == '1' || tmpdata->map[y][x] == 'x')
		return (0);
	if (tmpdata->map[y][x] == 'E')
		return (tmpdata->is_exit = 1, 0);
	if (tmpdata->map[y][x] == 'C')
		tmpdata->t_collec += 1;
	if (tmpdata->is_exit == 1 && tmpdata->t_collec == tmpdata->c_collec)
		return (tmpdata->is_finish = 0);
	tmpdata->map[y][x] = 'x';
	testmap(tmpdata, x + 1, y);
	testmap(tmpdata, x - 1, y);
	testmap(tmpdata, x, y + 1);
	testmap(tmpdata, x, y - 1);
	return (tmpdata->is_finish);
}

char	**clonemap(char **map)
{
	char	**tmpmap;
	int		i;

	i = 0;
	while (map[i])
		i++;
	tmpmap = malloc(sizeof(char *) * (i + 1));
	if (!tmpmap)
		return (NULL);
	i = 0;
	while (map[i])
	{
		tmpmap[i] = ft_strdup(map[i]);
		i++;
	}
	tmpmap[i] = NULL;
	return (tmpmap);
}

t_tmptrack	*clonestruct(t_data *gamedata)
{
	t_tmptrack	*tmpgamedata;

	tmpgamedata = malloc(sizeof(t_tmptrack));
	if (!tmpgamedata)
		return (NULL);
	tmpgamedata->c_collec = gamedata->c_collec;
	tmpgamedata->t_collec = 0;
	tmpgamedata->is_exit = 0;
	tmpgamedata->is_finish = 1;
	tmpgamedata->map = clonemap(gamedata->map);
	if (!tmpgamedata->map)
		return (NULL);
	return (tmpgamedata);
}

void	ft_freevalidmap(t_tmptrack *tmpgamedata)
{
	size_t	i;

	i = 0;
	if (tmpgamedata)
	{
		if (tmpgamedata->map)
		{
			while (tmpgamedata->map[i])
			{
				free(tmpgamedata->map[i]);
				i++;
			}
			free(tmpgamedata->map);
		}
		free(tmpgamedata);
	}
}

int	ismapvalid(t_data *gamedata)
{
	t_tmptrack	*tmpgamedata;

	tmpgamedata = clonestruct(gamedata);
	if (!tmpgamedata)
		return (ft_freevalidmap(tmpgamedata), 1);
	if (testmap(tmpgamedata, gamedata->x_player, gamedata->y_player))
	{
		ft_freevalidmap(tmpgamedata);
		return (ft_putstr_fd("Error map cant be finished", 2), 1);
	}
	ft_freevalidmap(tmpgamedata);
	return (0);
}
