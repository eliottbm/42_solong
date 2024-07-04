/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_make_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebengtss <ebengtss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 10:50:51 by ebengtss          #+#    #+#             */
/*   Updated: 2024/07/04 15:05:17 by ebengtss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/so_long_bonus.h"

int	processmap(int fd, t_data *gdata)
{
	srand(time(NULL));
	initdata(gdata);
	gdata->fd = fd;
	if (makemap(fd, gdata))
		return (ft_putstr_fd("Error\ncreating the map from file\n", 2), 1);
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

void	ft_freemakemap(char *buff, char *tmpbuff, char *tmpmap)
{
	if (buff)
	{
		free(buff);
		buff = NULL;
	}
	if (tmpbuff)
	{
		free(tmpbuff);
		tmpbuff = NULL;
	}
	if (tmpmap)
	{
		free(tmpmap);
		tmpmap = NULL;
	}
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
			return (ft_freemakemap(buff, NULL, NULL), 1);
		ft_freemakemap(buff, NULL, NULL);
		buff = ft_get_next_line(fd);
	}
	gdata->map = ft_split(tmpmap, '\n');
	if (!gdata->map)
		return (ft_freemakemap(buff, tmpbuff, tmpmap), 1);
	return (ft_freemakemap(buff, NULL, tmpmap), 0);
}
