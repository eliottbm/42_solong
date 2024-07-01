/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebengtss <ebengtss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 10:55:31 by ebengtss          #+#    #+#             */
/*   Updated: 2024/07/01 11:34:17 by ebengtss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

int	checkmapdata(t_data *gdata)
{
	if (gdata->cp < 1)
		return (ft_putstr_fd("Error missing player", 2), 1);
	else if (gdata->cp > 1)
		return (ft_putstr_fd("Error too many players", 2), 1);
	else if (gdata->ce < 1)
		return (ft_putstr_fd("Error missing exit", 2), 1);
	else if (gdata->ce > 1)
		return (ft_putstr_fd("Error too many exits", 2), 1);
	else if (gdata->ccol < 1)
		return (ft_putstr_fd("Error missing collectibles", 2), 1);
	return (0);
}

void	adddata(char c, t_data *gdata, int x, int y)
{
	if (c == 'P')
	{
		gdata->xp = x;
		gdata->yp = y;
		gdata->cp += 1;
	}
	else if (c == 'E')
	{
		gdata->xe = x;
		gdata->ye = y;
		gdata->ce += 1;
	}
}

int	getlinedata(t_data *gdata, int y)
{
	t_collec	*tmpcollec;
	int			x;

	x = -1;
	while (gdata->map[y][++x])
	{
		if (gdata->map[y][x] == 'P' || gdata->map[y][x] == 'E')
			adddata(gdata->map[y][x], gdata, x, y);
		else if (gdata->map[y][x] == 'C')
		{
			tmpcollec = ft_colnew(x, y);
			if (!tmpcollec)
				return (1);
			ft_coladd_back(&(gdata->lcol), tmpcollec);
		}
	}
	return (0);
}

int	getmapdata(t_data *gdata)
{
	int			y;

	y = 0;
	gdata->cp = 0;
	gdata->ce = 0;
	gdata->ise = 0;
	gdata->cm = 0;
	gdata->lcol = NULL;
	gdata->hw = 0;
	gdata->ww = 0;
	gdata->limg = NULL;
	while (gdata->map[y])
	{
		if (!(y == 0 || !gdata->map[y + 1]))
			if (getlinedata(gdata, y))
				return (ft_freemain(gdata), 1);
		y++;
	}
	gdata->ccol = ft_colsize(gdata->lcol);
	if (checkmapdata(gdata))
		return (ft_freemain(gdata), 1);
	return (0);
}
