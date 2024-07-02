/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebengtss <ebengtss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 10:40:24 by ebengtss          #+#    #+#             */
/*   Updated: 2024/07/02 14:16:23 by ebengtss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_collec	*ft_colnew(int x, int y)
{
	t_collec	*newelem;

	newelem = malloc(sizeof(t_collec));
	if (!newelem)
		return (NULL);
	newelem->xc = x;
	newelem->yc = y;
	newelem->next = NULL;
	return (newelem);
}

t_img	*ft_imgnew(int xi, int yi, int xm, int ym)
{
	t_img	*newelem;

	newelem = malloc(sizeof(t_img));
	if (!newelem)
		return (NULL);
	newelem->img = NULL;
	newelem->xi = xi;
	newelem->yi = yi;
	newelem->xm = xm;
	newelem->ym = ym;
	newelem->next = NULL;
	return (newelem);
}
