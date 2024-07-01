/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebengtss <ebengtss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 14:03:07 by ebengtss          #+#    #+#             */
/*   Updated: 2024/07/01 11:01:37 by ebengtss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_coladd_back(t_collec **lst, t_collec *new)
{
	t_collec	*elem;

	if (!(*lst))
		ft_coladd_front(lst, new);
	else
	{
		elem = ft_collast(*lst);
		elem->next = new;
	}
}

void	ft_imgadd_back(t_img **lst, t_img *new)
{
	t_img	*elem;

	if (!(*lst))
		ft_imgadd_front(lst, new);
	else
	{
		elem = ft_imglast(*lst);
		elem->next = new;
	}
}
