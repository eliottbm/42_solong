/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_make_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebengtss <ebengtss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 10:50:51 by ebengtss          #+#    #+#             */
/*   Updated: 2024/07/26 11:17:44 by ebengtss         ###   ########.fr       */
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

int	is_cutted(char *tmpmap)
{
	int	i;
	int	is_space;
	int	is_before;
	int	is_after;

	i = 0;
	is_space = 0;
	is_before = 0;
	is_after = 0;
	while (tmpmap[i])
	{
		if (tmpmap[i] != '\n' && is_before == 0)
			is_before = 1;
		if (tmpmap[i + 1] && tmpmap[i] == '\n' && tmpmap[i + 1] == '\n'
			&& is_before == 1)
			is_space = 1;
		if (tmpmap[i] != '\n' && is_before == 1 && is_space == 1)
			is_after = 1;
		i++;
	}
	if (is_space == 1 && is_before == 1 && is_after == 1)
		return (ft_putstr_fd("Error\nmap cutted\n", 2), 1);
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
	while (buff)
	{
		tmpbuff = tmpmap;
		tmpmap = ft_gnljoin(tmpbuff, buff);
		if (!tmpmap)
			return (ft_putstr_fd("Error\ncreating the map\n", 2), free(buff), 1);
		free(buff);
		buff = ft_get_next_line(fd);
	}
	if (is_cutted(tmpmap))
		return (free(tmpmap), 1);
	gdata->map = ft_split(tmpmap, '\n');
	if (!gdata->map)
		return (ft_putstr_fd("Error\ncreating the map\n", 2), free(tmpmap), 1);
	return (free(tmpmap), 0);
}
