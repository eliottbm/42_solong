/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebengtss <ebengtss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 14:44:54 by ebengtss          #+#    #+#             */
/*   Updated: 2024/06/25 15:20:39 by ebengtss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_collec **lst, void (*del)(int x, int y))
{
	t_collec	*tmp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		del((*lst)->xc, (*lst)->yc);
		tmp = (*lst);
		(*lst) = (*lst)->next;
		free(tmp);
	}
}
