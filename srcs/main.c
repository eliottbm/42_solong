/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebengtss <ebengtss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 15:15:25 by ebengtss          #+#    #+#             */
/*   Updated: 2024/07/19 12:46:11 by ebengtss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

int	main(int argc, char **argv)
{
	int		fd;
	t_data	*gdata;

	if (argc != 2)
		return (ft_putstr_fd("Error\nwrong args\n", 2), 1);
	if (checkfilename(argv[1], ".ber"))
		return (ft_putstr_fd("Error\nmap wrong extension\n", 2), 1);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (ft_putstr_fd("Error\nopening the map file\n", 2), 1);
	gdata = malloc(sizeof(t_data));
	if (!gdata)
		return (1);
	if (processmap(fd, gdata))
		return (ft_freemain(gdata), 1);
	if (makewin(gdata))
		return (ft_freemain(gdata), 1);
	mlx_key_hook(gdata->win, listen_inputs, gdata);
	mlx_hook(gdata->win, 17, 0, listen_close, gdata);
	mlx_loop(gdata->mlx);
	return (ft_freemain(gdata), 0);
}
