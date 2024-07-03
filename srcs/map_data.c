/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebengtss <ebengtss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 10:55:31 by ebengtss          #+#    #+#             */
/*   Updated: 2024/07/03 14:47:15 by ebengtss         ###   ########.fr       */
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
		return (ft_putstr_fd("Error\nmissing collectibles\n", 2), 1);
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

int	addennemies(t_data *gdata, t_img *tmpimg, int x, int y)
{
	t_img		*tmpenm;

	tmpenm = ft_imgnew((64 * x), (64 * y), x, y);
	if (!tmpenm)
		return (1);
	tmpenm->img = tmpimg->img;
	ft_imgadd_back(&(gdata->lenm), tmpenm);
	return (0);
}

int	getlinedata(t_data *gdata, int y)
{
	t_collec	*tmpcollec;
	int			x;

	x = 0;
	while (gdata->map[y][x])
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
		x++;
	}
	return (0);
}

int	getmapdata(t_data *gdata)
{
	int			y;

	y = 0;
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
