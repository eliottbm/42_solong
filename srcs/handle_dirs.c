/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_dirs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebengtss <ebengtss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 11:48:01 by ebengtss          #+#    #+#             */
/*   Updated: 2024/07/03 15:16:11 by ebengtss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

int	isdir(t_data *gdata, char pos)
{
	if (pos == '1' || (pos == 'E' && gdata->ise == 0))
		return (0);
	return (1);
}

void	ennemidir2(t_img *tmpenm, t_textures *tmptex, int dir)
{
	if (tmpenm->img == tmptex->e21 || tmpenm->img == tmptex->e22
		|| tmpenm->img == tmptex->e23 || tmpenm->img == tmptex->e24)
	{
		if (dir == 1)
			tmpenm->img = tmptex->e21;
		else if (dir == 2)
			tmpenm->img = tmptex->e22;
		else if (dir == 3)
			tmpenm->img = tmptex->e23;
		else if (dir == 4)
			tmpenm->img = tmptex->e24;
	}
	else if (tmpenm->img == tmptex->e31 || tmpenm->img == tmptex->e32
		|| tmpenm->img == tmptex->e33 || tmpenm->img == tmptex->e34)
	{
		if (dir == 1)
			tmpenm->img = tmptex->e31;
		else if (dir == 2)
			tmpenm->img = tmptex->e32;
		else if (dir == 3)
			tmpenm->img = tmptex->e33;
		else if (dir == 4)
			tmpenm->img = tmptex->e34;
	}
}

void	ennemidir1(t_img *tmpenm, t_textures *tmptex, int dir)
{
	if (tmpenm->img == tmptex->e11 || tmpenm->img == tmptex->e12
		|| tmpenm->img == tmptex->e13 || tmpenm->img == tmptex->e14)
	{
		if (dir == 1)
			tmpenm->img = tmptex->e11;
		else if (dir == 2)
			tmpenm->img = tmptex->e12;
		else if (dir == 3)
			tmpenm->img = tmptex->e13;
		else if (dir == 4)
			tmpenm->img = tmptex->e14;
	}
	else
		ennemidir2(tmpenm, tmptex, dir);
}

void	*playerdir(t_data *gdata, int x, int y)
{
	void	*img;

	img = NULL;
	if (x > gdata->lx)
		img = gdata->ltex->p2;
	else if (x < gdata->lx)
		img = gdata->ltex->p4;
	else if (y > gdata->ly)
		img = gdata->ltex->p3;
	else if (y < gdata->ly)
		img = gdata->ltex->p1;
	return (img);
}
