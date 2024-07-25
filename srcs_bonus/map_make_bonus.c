/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_make_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebengtss <ebengtss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 10:50:51 by ebengtss          #+#    #+#             */
/*   Updated: 2024/07/25 11:16:04 by ebengtss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/so_long_bonus.h"

int	processmap(int fd, t_data *gdata)
{
	srand(time(NULL));
	initdata(gdata);
	gdata->fd = fd;
	if (makemap(fd, gdata))
		return (1);
	if (checkmapsize(gdata->map))
		return (1);
	if (checkmapformat(gdata->map))
		return (1);
	if (checkmapchar(gdata->map))
		return (ft_putstr_fd("Error\nnon allowed characters\n", 2), 1);
	if (getmapdata(gdata))
		return (1);
	if (ismapvalid(gdata))
		return (1);
	return (0);
}

int	makemap(int fd, t_data *gdata)
{
	char	*buff;
	char	*tmpbuff;
	char	*tmpmap;

	tmpbuff = NULL;
	tmpmap = NULL;
	buff = ft_get_next_line(fd);
	if (!buff)
		return (ft_putstr_fd("Error\nmap empty\n", 2), 1);
	if ((ft_strlen(buff) * 64) > 1920)
		return (free(buff), ft_putstr_fd("Error\nmap too large\n", 2), 1);
	while (buff)
	{
		tmpbuff = tmpmap;
		tmpmap = ft_gnljoin(tmpbuff, buff);
		if (!tmpmap)
			return (ft_putstr_fd("Error\ncreating the map\n", 2), free(buff), 1);
		free(buff);
		buff = ft_get_next_line(fd);
	}
	gdata->map = ft_split(tmpmap, '\n');
	if (!gdata->map)
		return (ft_putstr_fd("Error\ncreating the map\n", 2), free(tmpmap), 1);
	return (free(tmpmap), 0);
}
