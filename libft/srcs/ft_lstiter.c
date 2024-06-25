/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebengtss <ebengtss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:10:52 by ebengtss          #+#    #+#             */
/*   Updated: 2024/06/25 15:22:26 by ebengtss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_collec *lst, void (*f)(int x, int y))
{
	if (!lst)
		return ;
	while (lst)
	{
		f(lst->xc, lst->yc);
		lst = lst->next;
	}
}
