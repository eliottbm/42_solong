/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebengtss <ebengtss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 12:45:57 by ebengtss          #+#    #+#             */
/*   Updated: 2024/07/26 11:20:09 by ebengtss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

void	initdata(t_data *gdata)
{
	gdata->cp = 0;
	gdata->ce = 0;
	gdata->cm = 0;
	gdata->ccol = 0;
	gdata->ise = 0;
	gdata->hw = 0;
	gdata->ww = 0;
	gdata->hi = 64;
	gdata->wi = 64;
	gdata->lx = 0;
	gdata->ly = 0;
	gdata->lcol = NULL;
	gdata->limg = NULL;
	gdata->ltex = NULL;
	gdata->mlx = NULL;
	gdata->win = NULL;
	gdata->map = NULL;
}

void	ft_freemain(t_data *gdata)
{
	if (gdata)
	{
		if (gdata->map)
			ft_freemap(gdata->map);
		if (gdata->lcol)
			ft_colclear(&(gdata->lcol));
		if (gdata->limg)
			ft_imgclear(&(gdata->limg));
		if (gdata->ltex)
			ft_freetexs1(gdata);
		if (gdata->win)
			mlx_destroy_window(gdata->mlx, gdata->win);
		if (gdata->mlx)
		{
			mlx_destroy_display(gdata->mlx);
			free(gdata->mlx);
		}
		close(gdata->fd);
		free(gdata);
	}
}

int	checkfilename(char *str, char *tofind)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		if (str[i] == tofind[j])
		{
			while ((str[i + j] == tofind[j])
				&& (str[i + j] && tofind[j]))
				j++;
			if (!str[i + j] && !tofind[j])
				return (0);
		}
		i++;
	}
	return (1);
}
