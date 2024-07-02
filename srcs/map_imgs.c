/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_imgs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebengtss <ebengtss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 15:58:11 by ebengtss          #+#    #+#             */
/*   Updated: 2024/07/02 16:33:48 by ebengtss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

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
