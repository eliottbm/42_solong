/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_inputs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebengtss <ebengtss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 16:29:42 by ebengtss          #+#    #+#             */
/*   Updated: 2024/06/28 17:14:07 by ebengtss         ###   ########.fr       */
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
	tmpcolpast = tmpcol;
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
	}
}

int	listen_inputs(int key, t_data *gdata)
{
	if (key == 65307)
		return (mlx_loop_end(gdata->mlx), 1);
	if (key == 97 && isdir(gdata, gdata->map[gdata->yp][gdata->xp - 1]))
		gdata->map[gdata->yp][gdata->xp--] = '0';
	else if (key == 119 && isdir(gdata, gdata->map[gdata->yp - 1][gdata->xp]))
		gdata->map[gdata->yp--][gdata->xp] = '0';
	else if (key == 115 && isdir(gdata, gdata->map[gdata->yp + 1][gdata->xp]))
		gdata->map[gdata->yp++][gdata->xp] = '0';
	else if (key == 100 && isdir(gdata, gdata->map[gdata->yp][gdata->xp + 1]))
		gdata->map[gdata->yp][gdata->xp++] = '0';
	else
		return (2);
	if (gdata->map[gdata->yp][gdata->xp] == 'C')
		takecol(gdata);
	if (gdata->map[gdata->yp][gdata->xp] == 'E')
		return (mlx_loop_end(gdata->mlx), 0);
	gdata->map[gdata->yp][gdata->xp] = 'P';
	ft_printmap(gdata->map);
	return (0);
}

int	listen_close(t_data *gdata)
{
	return (mlx_loop_end(gdata->mlx), 0);
}
