/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_inputs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebengtss <ebengtss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 16:29:42 by ebengtss          #+#    #+#             */
/*   Updated: 2024/07/02 16:30:36 by ebengtss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

int	isdir(t_data *gdata, char pos)
{
	if (pos == '1' || (pos == 'E' && gdata->ise == 0))
		return (0);
	return (1);
}

void	takecol(t_data *gdata)
{
	t_collec	*tmpcol;
	t_collec	*tmpcolpast;

	tmpcol = gdata->lcol;
	while (tmpcol)
	{
		if (tmpcol->xc == gdata->xp && tmpcol->yc == gdata->yp)
		{
			if (tmpcol == gdata->lcol)
				gdata->lcol = tmpcol->next;
			else
				tmpcolpast->next = tmpcol->next;
			free(tmpcol);
			gdata->ccol -= 1;
			break ;
		}
		tmpcolpast = tmpcol;
		tmpcol = tmpcol->next;
	}
	if (gdata->ccol == 0)
	{
		gdata->ise = 1;
		gdata->lcol = NULL;
		replaceimg(gdata, -1, -1, 'E');
	}
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

int	print_mooves(t_data *gdata)
{
	char	*mc;

	mc = ft_itoa(gdata->cm);
	if (!mc)
		return (1);
	ft_printf("total mooves: %s\n", mc);
	itow(gdata, gdata->ltex->mtl, 0, 0);
	mlx_string_put(gdata->mlx, gdata->win, 16, 32, 1, mc);
	free(mc);
	return (0);
}

int	listen_inputs(int key, t_data *gdata)
{
	if (key == 65307)
		return (mlx_loop_end(gdata->mlx), 1);
	if (key == 97 && isdir(gdata, gdata->map[gdata->yp][gdata->xp - 1]))
		replaceimg(gdata, gdata->yp, gdata->xp--, '0');
	else if (key == 119 && isdir(gdata, gdata->map[gdata->yp - 1][gdata->xp]))
		replaceimg(gdata, gdata->yp--, gdata->xp, '0');
	else if (key == 115 && isdir(gdata, gdata->map[gdata->yp + 1][gdata->xp]))
		replaceimg(gdata, gdata->yp++, gdata->xp, '0');
	else if (key == 100 && isdir(gdata, gdata->map[gdata->yp][gdata->xp + 1]))
		replaceimg(gdata, gdata->yp, gdata->xp++, '0');
	else
		return (2);
	gdata->cm += 1;
	if (print_mooves(gdata))
		return (1);
	if (gdata->map[gdata->yp][gdata->xp] == 'C')
		takecol(gdata);
	if (gdata->map[gdata->yp][gdata->xp] == 'E')
		return (mlx_loop_end(gdata->mlx), 0);
	replaceimg(gdata, gdata->yp, gdata->xp, 'P');
	return (0);
}
