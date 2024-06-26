/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebengtss <ebengtss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 13:17:29 by ebengtss          #+#    #+#             */
/*   Updated: 2024/06/26 15:47:12 by ebengtss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/solong.h"

int	testmap(char **map, t_data *gamedata, int x, int y)
{
	if (map[y][x] == '1' || map[y][x] == 'x')
		return (0);
	if (map[y][x] == 'E')
		return (gamedata->ise = 1, 0);
	if (map[y][x] == 'C')
		gamedata->ce += 1;
	if (gamedata->ise == 1 && gamedata->ce == gamedata->ccollecs)
		return (gamedata->cp = 0);
	map[y][x] = 'x';
	testmap(map, gamedata, x + 1, y);
	testmap(map, gamedata, x - 1, y);
	testmap(map, gamedata, x, y + 1);
	testmap(map, gamedata, x, y - 1);
	return (gamedata->cp);
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

t_data	*clonestruct(t_data *gamedata)
{
	t_data	*tmpgamedata;

	tmpgamedata = malloc(sizeof(t_data));
	if (!tmpgamedata)
		return (NULL);
	tmpgamedata->xp = gamedata->xp;
	tmpgamedata->yp = gamedata->yp;
	tmpgamedata->cp = 1;
	tmpgamedata->xe = gamedata->xe;
	tmpgamedata->ye = gamedata->ye;
	tmpgamedata->ce = 0;
	tmpgamedata->ise = gamedata->ise;
	tmpgamedata->collecs = NULL;
	tmpgamedata->ccollecs = gamedata->ccollecs;
	return (tmpgamedata);
}

int	ismapvalid(char **map, t_data *gamedata)
{
	char	**tmpmap;
	t_data	*tmpgamedata;

	tmpmap = clonemap(map);
	if (!tmpmap)
		return (1);
	tmpgamedata = clonestruct(gamedata);
	if (!tmpgamedata)
		return (1);
	if (testmap(tmpmap, tmpgamedata, tmpgamedata->xp, tmpgamedata->yp))
		return (ft_putstr_fd("Error map cant be finished", 2), 1);
	return (0);
}
