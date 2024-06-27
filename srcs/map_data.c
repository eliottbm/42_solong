/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebengtss <ebengtss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 10:55:31 by ebengtss          #+#    #+#             */
/*   Updated: 2024/06/27 16:36:09 by ebengtss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

int	checkmapdata(t_data *gamedata)
{
	if (gamedata->cp == 0)
		return (ft_putstr_fd("Error missing player", 2), 1);
	else if (gamedata->cp > 1)
		return (ft_putstr_fd("Error too many players", 2), 1);
	else if (gamedata->ce == 0)
		return (ft_putstr_fd("Error missing exit", 2), 1);
	else if (gamedata->ce > 1)
		return (ft_putstr_fd("Error too many exits", 2), 1);
	else if (gamedata->ccollecs == 0)
		return (ft_putstr_fd("Error missing collectibles", 2), 1);
	return (0);
}

void	adddata(char c, t_data *gamedata, int x, int y)
{
	if (c == 'P')
	{
		gamedata->xp = x;
		gamedata->yp = y;
		gamedata->cp += 1;
	}
	else if (c == 'E')
	{
		gamedata->xe = x;
		gamedata->ye = y;
		gamedata->ce += 1;
	}
}

int	getlinedata(char *line, int y, t_data *gamedata, t_collec **clist)
{
	t_collec	*tmpcollec;
	int			x;

	x = -1;
	while (line[++x])
	{
		if (line[x] == 'P' || line[x] == 'E')
			adddata(line[x], gamedata, x, y);
		else if (line[x] == 'C')
		{
			tmpcollec = ft_lstnew(x, y);
			if (!tmpcollec)
				return (1);
			ft_lstadd_back(clist, tmpcollec);
		}
	}
	return (0);
}

t_data	*getmapdata(char **map)
{
	t_collec	*colleclist;
	t_data		*gamedata;
	int			y;

	colleclist = NULL;
	gamedata = malloc(sizeof(t_data));
	if (!gamedata)
		return (NULL);
	y = 0;
	gamedata->ise = 0;
	gamedata->cp = 0;
	gamedata->ce = 0;
	while (map[y])
	{
		if (!(y == 0 || !map[y + 1]))
			if (getlinedata(map[y], y, gamedata, &colleclist))
				return (free(gamedata), NULL);
		y++;
	}
	gamedata->collecs = colleclist;
	gamedata->ccollecs = ft_lstsize(colleclist);
	if (checkmapdata(gamedata))
		return (ft_lstclear(&colleclist), free(gamedata), NULL);
	return (gamedata);
}
