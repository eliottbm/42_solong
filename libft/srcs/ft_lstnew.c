/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebengtss <ebengtss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 10:40:24 by ebengtss          #+#    #+#             */
/*   Updated: 2024/06/28 14:14:35 by ebengtss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_collec	*ft_lstnew(int x, int y)
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
