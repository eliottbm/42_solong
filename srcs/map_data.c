/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebengtss <ebengtss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 10:55:31 by ebengtss          #+#    #+#             */
/*   Updated: 2024/07/26 15:30:29 by ebengtss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

int	checkmapdata(t_data *gdata)
{
	if (gdata->cp < 1)
		return (ft_putstr_fd("Error\nmissing player\n", 2), 1);
	else if (gdata->cp > 1)
		return (ft_putstr_fd("Error\ntoo many players\n", 2), 1);
	else if (gdata->ce < 1)
		return (ft_putstr_fd("Error\nmissing exit\n", 2), 1);
	else if (gdata->ce > 1)
		return (ft_putstr_fd("Error\ntoo many exits\n", 2), 1);
	else if (gdata->ccol < 1)
		return (ft_putstr_fd("Error\nmissing collectible\n", 2), 1);
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

int	getlinedata(t_data *gdata, char **tmpmap, int y)
{
	t_collec	*tmpcollec;
	int			x;

	x = 0;
	while (tmpmap[y][x])
	{
		if (tmpmap[y][x] == 'P' || tmpmap[y][x] == 'E')
			adddata(tmpmap[y][x], gdata, x, y);
		else if (tmpmap[y][x] == 'C')
		{
			tmpcollec = ft_colnew(x, y);
			if (!tmpcollec)
				return (1);
			ft_coladd_back(&(gdata->lcol), tmpcollec);
		}
		x++;
	}
	return (0);
}

int	getmapdata(t_data *gdata)
{
	char		**tmpmap;
	int			y;

	tmpmap = gdata->map;
	y = 0;
	while (tmpmap[y])
	{
		if (!(y == 0 || !tmpmap[y + 1]))
			if (getlinedata(gdata, tmpmap, y))
				return (1);
		y++;
	}
	gdata->ccol = ft_colsize(gdata->lcol);
	if (checkmapdata(gdata))
		return (1);
	return (0);
}
