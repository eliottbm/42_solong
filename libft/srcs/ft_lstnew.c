/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebengtss <ebengtss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 10:40:24 by ebengtss          #+#    #+#             */
/*   Updated: 2024/05/30 11:01:51 by ebengtss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*newelem;

	newelem = malloc(sizeof(t_list));
	if (!newelem)
		return (NULL);
	newelem->content = content;
	newelem->next = NULL;
	return (newelem);
}
