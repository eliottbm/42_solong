/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebengtss <ebengtss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 14:44:54 by ebengtss          #+#    #+#             */
/*   Updated: 2024/07/01 10:58:00 by ebengtss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_colclear(t_collec **lst)
{
	t_collec	*tmp;

	if (!(*lst))
		return ;
	while (*lst)
	{
		tmp = (*lst);
		(*lst) = (*lst)->next;
		free(tmp);
	}
}

void	ft_imgclear(t_img **lst)
{
	t_img	*tmp;

	if (!(*lst))
		return ;
	while (*lst)
	{
		tmp = (*lst);
		(*lst) = (*lst)->next;
		free(tmp);
	}
}
