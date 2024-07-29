/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebengtss <ebengtss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 16:05:25 by ebengtss          #+#    #+#             */
/*   Updated: 2024/07/29 20:12:12 by ebengtss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

int	checkmapchar(char **map)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] != '1' && map[y][x] != '0'
				&& map[y][x] != 'P' && map[y][x] != 'E'
				&& map[y][x] != 'C')
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

int	checkmapsize(char **map)
{
	char	**tmpmap;
	size_t	i;

	tmpmap = map;
	i = 0;
	if ((ft_strlen(tmpmap[i]) * 64) > 1920)
		return (ft_putstr_fd("Error\nmap too large\n", 2), 1);
	while (tmpmap[i])
		i++;
	if (i < 3)
		return (ft_putstr_fd("Error\nmap too small\n", 2), 1);
	if ((i * 64) > 1080)
		return (ft_putstr_fd("Error\nmap too large\n", 2), 1);
	return (0);
}

int	checkmapformat(char **map)
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
				return (ft_putstr_fd("Error\ninvalid map width\n", 2), 1);
		if (i == 0 || !map[i + 1])
		{
			while (map[i][j])
			{
				if (map[i][j] != '1')
					return (ft_putstr_fd("Error\ninvalid map border\n", 2), 1);
				j++;
			}
		}
		else if (map[i][0] != '1' || map[i][ft_strlen(map[i]) - 1] != '1')
			return (ft_putstr_fd("Error\ninvalid map border\n", 2), 1);
	}
	return (0);
}
