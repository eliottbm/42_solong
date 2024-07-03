/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_imgs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebengtss <ebengtss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 15:58:11 by ebengtss          #+#    #+#             */
/*   Updated: 2024/07/03 15:27:13 by ebengtss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

void	replaceenm2(t_data *gdata, t_img *tmpenm, int dir)
{
	if (dir == 3 && gdata->map[tmpenm->ym + 1][tmpenm->xm] == '0')
	{
		tmpenm->yi += 64;
		tmpenm->ym += 1;
		ennemidir1(tmpenm, gdata->ltex, dir);
	}
	else if (dir == 4 && gdata->map[tmpenm->ym][tmpenm->xm - 1] == '0')
	{
		tmpenm->xi -= 64;
		tmpenm->xm -= 1;
		ennemidir1(tmpenm, gdata->ltex, dir);
	}
}

void	replaceenm1(t_data *gdata, t_img *tmpenm, int dir)
{
	gdata->map[tmpenm->ym][tmpenm->xm] = '0';
	itow(gdata, gdata->ltex->mf, tmpenm->xi, tmpenm->yi);
	if (dir == 1 && gdata->map[tmpenm->ym - 1][tmpenm->xm] == '0')
	{
		tmpenm->yi -= 64;
		tmpenm->ym -= 1;
		ennemidir1(tmpenm, gdata->ltex, dir);
	}
	else if (dir == 2 && gdata->map[tmpenm->ym][tmpenm->xm + 1] == '0')
	{
		tmpenm->xi += 64;
		tmpenm->xm += 1;
		ennemidir1(tmpenm, gdata->ltex, dir);
	}
	else
		replaceenm2(gdata, tmpenm, dir);
	gdata->map[tmpenm->ym][tmpenm->xm] = 'D';
	itow(gdata, tmpenm->img, tmpenm->xi, tmpenm->yi);
}

void	replaceimg(t_data *gdata, int y, int x, char c)
{
	t_img	*tmpimg;

	tmpimg = gdata->limg;
	while (tmpimg)
	{
		if (c == 'E' && tmpimg->img == gdata->ltex->me1)
		{
			tmpimg->img = gdata->ltex->me2;
			break ;
		}
		else if (tmpimg->xm == x && tmpimg->ym == y)
		{
			gdata->map[y][x] = c;
			if (c == 'P')
				tmpimg->img = playerdir(gdata, x, y);
			if (c == '0')
				tmpimg->img = gdata->ltex->mf;
			gdata->lx = x;
			gdata->ly = y;
			break ;
		}
		tmpimg = tmpimg->next;
	}
	itow(gdata, tmpimg->img, tmpimg->xi, tmpimg->yi);
}
