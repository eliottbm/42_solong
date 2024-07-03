/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_dirs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebengtss <ebengtss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 11:48:01 by ebengtss          #+#    #+#             */
/*   Updated: 2024/07/03 11:49:08 by ebengtss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

int	isdir(t_data *gdata, char pos)
{
	if (pos == '1' || (pos == 'E' && gdata->ise == 0))
		return (0);
	return (1);
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
