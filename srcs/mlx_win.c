/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_win.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebengtss <ebengtss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 14:44:36 by ebengtss          #+#    #+#             */
/*   Updated: 2024/07/26 13:24:35 by ebengtss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

int	itow(t_data *gdata, void *img, int x, int y)
{
	return (mlx_put_image_to_window(gdata->mlx, gdata->win, img, x, y));
}

void	putimage2(t_data *gdata, t_img *tmpimg, int x, int y)
{
	if (gdata->map[y][x] == '1')
		tmpimg->img = gdata->ltex->mo1;
	else
		tmpimg->img = gdata->ltex->mf;
}

void	putimage1(t_data *gdata, t_img *tmpimg, int x, int y)
{
	if (y == 0 && x == 0)
		tmpimg->img = gdata->ltex->mtl;
	else if (y == 0 && !gdata->map[y][x + 1])
		tmpimg->img = gdata->ltex->mtr;
	else if (y == 0)
		tmpimg->img = gdata->ltex->mt;
	else if (!gdata->map[y + 1] && x == 0)
		tmpimg->img = gdata->ltex->mbl;
	else if (!gdata->map[y + 1] && !gdata->map[y][x + 1])
		tmpimg->img = gdata->ltex->mbr;
	else if (!gdata->map[y + 1])
		tmpimg->img = gdata->ltex->mb;
	else if (x == 0)
		tmpimg->img = gdata->ltex->ml;
	else if (!gdata->map[y][x + 1])
		tmpimg->img = gdata->ltex->mr;
	else if (gdata->map[y][x] == 'P')
		tmpimg->img = gdata->ltex->p1;
	else if (gdata->map[y][x] == 'E')
		tmpimg->img = gdata->ltex->me1;
	else if (gdata->map[y][x] == 'C')
		tmpimg->img = gdata->ltex->collec;
	else
		putimage2(gdata, tmpimg, x, y);
	itow(gdata, tmpimg->img, (64 * x), (64 * y));
}

int	fillwin(t_data	*gdata, char **tmpmap)
{
	int			x;
	int			y;
	t_img		*tmpimg;

	y = 0;
	if (initialize_imgs1(gdata))
		return (1);
	while (tmpmap[y])
	{
		x = 0;
		while (tmpmap[y][x])
		{
			tmpimg = ft_imgnew((64 * x), (64 * y), x, y);
			if (!tmpimg)
				return (ft_putstr_fd("Error\ndisplaying the images\n", 2), 1);
			putimage1(gdata, tmpimg, x, y);
			ft_imgadd_back(&(gdata->limg), tmpimg);
			x++;
		}
		y++;
	}
	return (0);
}

int	makewin(t_data	*gdata)
{
	char	**tmpmap;
	int		hmap;
	int		wmap;

	tmpmap = clonemap(gdata->map);
	if (!tmpmap)
		return (ft_putstr_fd("Error\nmaking the window\n", 2), 1);
	hmap = 0;
	wmap = (int)ft_strlen(tmpmap[hmap]);
	while (tmpmap[hmap])
		hmap++;
	gdata->hw = hmap * 64;
	gdata->ww = wmap * 64;
	gdata->mlx = mlx_init();
	if (!gdata->mlx)
		return (ft_putstr_fd("Error\nmissing env\n", 2), ft_freemap(tmpmap), 1);
	gdata->win = mlx_new_window(gdata->mlx, gdata->ww, gdata->hw, "so_long");
	if (!gdata->win)
		return (ft_putstr_fd("Error\nmissing env\n", 2), ft_freemap(tmpmap), 1);
	if (fillwin(gdata, tmpmap))
		return (ft_freemap(tmpmap), 1);
	ft_freemap(tmpmap);
	return (0);
}
