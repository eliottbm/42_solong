/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebengtss <ebengtss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:13:55 by ebengtss          #+#    #+#             */
/*   Updated: 2024/05/31 19:03:28 by ebengtss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*tmp;
	void	*newelem;

	if (!lst || !f || !del)
		return (NULL);
	newlst = NULL;
	while (lst)
	{
		newelem = f(lst->content);
		tmp = ft_lstnew(newelem);
		if (!tmp)
		{
			del(newelem);
			ft_lstclear(&newlst, del);
			return (NULL);
		}
		ft_lstadd_back(&newlst, tmp);
		lst = lst->next;
	}
	return (newlst);
}
