/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebengtss <ebengtss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 12:49:16 by ebengtss          #+#    #+#             */
/*   Updated: 2024/07/26 11:22:39 by ebengtss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/so_long_bonus.h"

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
	gdata->lenm = NULL;
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
		if (gdata->lenm)
			ft_imgclear(&(gdata->lenm));
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

int	rangerand(int min, int max)
{
	return ((rand() % (max - min + 1)) + min);
}
