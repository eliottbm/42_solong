/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_win.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebengtss <ebengtss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 14:44:36 by ebengtss          #+#    #+#             */
/*   Updated: 2024/07/01 16:49:16 by ebengtss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

int	itow(t_data *gdata, void *img, int x, int y)
{
	return (mlx_put_image_to_window(gdata->mlx, gdata->win, img, x, y));
}

void	putimage2(t_data *gdata, t_img *tmpimg, int i, int j)
{
	if (gdata->map[i][j] == 'C')
		tmpimg->img = gdata->ltex->collec;
	else
		tmpimg->img = gdata->ltex->mf;
}

void	putimage1(t_data *gdata, t_img *tmpimg, int i, int j)
{
	if (i == 0 && j == 0)
		tmpimg->img = gdata->ltex->mtl;
	else if (i == 0 && !gdata->map[i][j + 1])
		tmpimg->img = gdata->ltex->mtr;
	else if (i == 0)
		tmpimg->img = gdata->ltex->mt;
	else if (!gdata->map[i + 1] && j == 0)
		tmpimg->img = gdata->ltex->mbl;
	else if (!gdata->map[i + 1] && !gdata->map[i][j + 1])
		tmpimg->img = gdata->ltex->mbr;
	else if (!gdata->map[i + 1])
		tmpimg->img = gdata->ltex->mb;
	else if (j == 0)
		tmpimg->img = gdata->ltex->ml;
	else if (!gdata->map[i][j + 1])
		tmpimg->img = gdata->ltex->mr;
	else if (gdata->map[i][j] == 'P')
		tmpimg->img = gdata->ltex->p3;
	else if (gdata->map[i][j] == 'E')
		tmpimg->img = gdata->ltex->me1;
	else
		putimage2(gdata, tmpimg, i, j);
	itow(gdata, tmpimg->img, (64 * j), (64 * i));
}

int	fillwin(t_data	*gdata, char **tmpmap)
{
	int			i;
	int			j;
	t_img		*tmpimg;

	(void)tmpmap;
	(void)tmpimg;
	i = 0;
	j = 0;
	if (initialize_imgs1(gdata))
		return (1);
	while(tmpmap[i])
	{
		j = 0;
		while (tmpmap[i][j])
		{
			tmpimg = ft_imgnew((64 * j), (64 * i));
			if (!tmpimg)
				return (1);
			putimage1(gdata, tmpimg, i, j);
			ft_imgadd_back(&(gdata->limg), tmpimg);
			j++;
		}
		i++;
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
		return (ft_putstr_fd("Error making the window", 2), 1);
	hmap = 0;
	wmap = (int)ft_strlen(tmpmap[hmap]);
	while (tmpmap[hmap])
		hmap++;
	gdata->hw = hmap * 64;
	gdata->ww = wmap * 64;
	gdata->mlx = mlx_init();
	gdata->win = mlx_new_window(gdata->mlx, gdata->ww, gdata->hw, "so_long");
	if (fillwin(gdata, tmpmap))
	{
		ft_freemap(tmpmap);
		ft_putstr_fd("Error displaying the images", 2);
		return (1);
	}
	ft_freemap(tmpmap);
	return (0);
}
