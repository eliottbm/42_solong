/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebengtss <ebengtss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 10:50:51 by ebengtss          #+#    #+#             */
/*   Updated: 2024/06/26 11:36:29 by ebengtss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/solong.h"

int	checkmap(char **map)
{
	size_t	tmplen;
	int		i;
	int		j;

	i = -1;
	while (map[++i])
	{
		j = 0;
		tmplen = ft_strlen(map[i]);
		if (i > 0)
			if (tmplen != ft_strlen(map[i - 1]))
				return (ft_putstr_fd("Error map isnt a square", 2), 1);
		if (i == 0 || !map[i + 1])
		{
			while (map[i][j])
			{
				if (map[i][j] != '1')
					return (ft_putstr_fd("Error border is invalid", 2), 1);
				j++;
			}
		}
		else if (map[i][0] != '1' || map[i][ft_strlen(map[i]) - 1] != '1')
			return (ft_putstr_fd("Error border is invalid", 2), 1);
	}
	return (0);
}

char	**makemap(int fd)
{
	char	*buff;
	char	*tmpbuff;
	char	*tmpmap;
	int		doread;

	doread = 1;
	tmpbuff = NULL;
	tmpmap = NULL;
	while (doread)
	{
		buff = ft_get_next_line(fd);
		if (!buff)
		{
			doread = 0;
			break ;
		}
		if (tmpmap)
			tmpbuff = tmpmap;
		tmpmap = ft_gnljoin(tmpbuff, buff);
		if (!tmpmap)
			return (free(buff), free(tmpbuff), NULL);
		if (buff)
			free(buff);
	}
	return (ft_split(tmpmap, '\n'));
}
