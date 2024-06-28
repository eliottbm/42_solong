/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebengtss <ebengtss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 10:55:31 by ebengtss          #+#    #+#             */
/*   Updated: 2024/06/28 13:00:42 by ebengtss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

int	checkmapdata(t_data *gamedata)
{
	if (gamedata->c_player < 1)
		return (ft_putstr_fd("Error missing player", 2), 1);
	else if (gamedata->c_player > 1)
		return (ft_putstr_fd("Error too many players", 2), 1);
	else if (gamedata->c_exit < 1)
		return (ft_putstr_fd("Error missing exit", 2), 1);
	else if (gamedata->c_exit > 1)
		return (ft_putstr_fd("Error too many exits", 2), 1);
	else if (gamedata->c_collec < 1)
		return (ft_putstr_fd("Error missing collectibles", 2), 1);
	return (0);
}

void	adddata(char c, t_data *gamedata, int x, int y)
{
	if (c == 'P')
	{
		gamedata->x_player = x;
		gamedata->y_player = y;
		gamedata->c_player += 1;
	}
	else if (c == 'E')
	{
		gamedata->x_exit = x;
		gamedata->y_exit = y;
		gamedata->c_exit += 1;
	}
}

int	getlinedata(t_data *gamedata, int y)
{
	t_collec	*tmpcollec;
	int			x;

	x = -1;
	while (gamedata->map[y][++x])
	{
		if (gamedata->map[y][x] == 'P' || gamedata->map[y][x] == 'E')
			adddata(gamedata->map[y][x], gamedata, x, y);
		else if (gamedata->map[y][x] == 'C')
		{
			tmpcollec = ft_lstnew(x, y);
			if (!tmpcollec)
				return (1);
			ft_lstadd_back(&(gamedata->l_collec), tmpcollec);
		}
	}
	return (0);
}

int	getmapdata(t_data *gamedata)
{
	int			y;

	y = 0;
	gamedata->c_player = 0;
	gamedata->c_exit = 0;
	gamedata->is_exit = 0;
	gamedata->l_collec = NULL;
	while (gamedata->map[y])
	{
		if (!(y == 0 || !gamedata->map[y + 1]))
			if (getlinedata(gamedata, y))
				return (ft_freemain(gamedata), 1);
		y++;
	}
	gamedata->c_collec = ft_lstsize(gamedata->l_collec);
	if (checkmapdata(gamedata))
		return (ft_freemain(gamedata), 1);
	return (0);
}
