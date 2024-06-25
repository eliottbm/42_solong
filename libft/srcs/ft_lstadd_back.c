/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebengtss <ebengtss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 14:03:07 by ebengtss          #+#    #+#             */
/*   Updated: 2024/06/25 15:42:47 by ebengtss         ###   ########.fr       */
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
