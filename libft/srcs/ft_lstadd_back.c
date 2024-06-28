/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebengtss <ebengtss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 14:03:07 by ebengtss          #+#    #+#             */
/*   Updated: 2024/06/28 13:00:28 by ebengtss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_collec **lst, t_collec *new)
{
	t_collec	*elem;

	if (!(*lst))
		ft_lstadd_front(lst, new);
	else
	{
		elem = ft_lstlast(*lst);
		elem->next = new;
	}
}
