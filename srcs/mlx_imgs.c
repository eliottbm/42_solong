/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_imgs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebengtss <ebengtss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 14:41:44 by ebengtss          #+#    #+#             */
/*   Updated: 2024/07/01 16:29:25 by ebengtss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

void	*xtoi(t_data *gdata, char *file)
{
	int	hi;
	int	wi;

	hi = gdata->hi;
	wi = gdata->wi;
	return (mlx_xpm_file_to_image(gdata->mlx, file, &wi, &hi));
}

int	initialize_imgs3(t_data *gdata, t_textures *tltex)
{
	tltex->ml = xtoi(gdata, "./texs/map/ml.xpm");
	tltex->mtl = xtoi(gdata, "./texs/map/mtl.xpm");
	tltex->mtr = xtoi(gdata, "./texs/map/mtr.xpm");
	tltex->mbl = xtoi(gdata, "./texs/map/mbl.xpm");
	tltex->mbr = xtoi(gdata, "./texs/map/mbr.xpm");
	tltex->me1 = xtoi(gdata, "./texs/map/me1.xpm");
	tltex->me2 = xtoi(gdata, "./texs/map/me2.xpm");
	tltex->mo1 = xtoi(gdata, "./texs/obstacles/mo1.xpm");
	tltex->mo2 = xtoi(gdata, "./texs/obstacles/mo2.xpm");
	tltex->mo3 = xtoi(gdata, "./texs/obstacles/mo3.xpm");
	tltex->mo4 = xtoi(gdata, "./texs/obstacles/mo4.xpm");
	tltex->mo5 = xtoi(gdata, "./texs/obstacles/mo5.xpm");
	if (!(tltex->mtl) || !(tltex->mtr) || !(tltex->mbl) || !(tltex->mbr)
		|| !(tltex->me1) || !(tltex->me2) || !(tltex->mo1) || !(tltex->mo2)
		|| !(tltex->mo3) || !(tltex->mo4) || !(tltex->mo5) || !(tltex->ml))
		return (ft_freetexs1(gdata), 1);
	gdata->ltex = tltex;
	return (0);
}

int	initialize_imgs2(t_data *gdata, t_textures *tltex)
{
	tltex->e24 = xtoi(gdata, "./texs/ennemis/e2/e24.xpm");
	tltex->e31 = xtoi(gdata, "./texs/ennemis/e3/e31.xpm");
	tltex->e32 = xtoi(gdata, "./texs/ennemis/e3/e32.xpm");
	tltex->e33 = xtoi(gdata, "./texs/ennemis/e3/e33.xpm");
	tltex->e34 = xtoi(gdata, "./texs/ennemis/e3/e34.xpm");
	tltex->e41 = xtoi(gdata, "./texs/ennemis/e4/e41.xpm");
	tltex->e42 = xtoi(gdata, "./texs/ennemis/e4/e42.xpm");
	tltex->e43 = xtoi(gdata, "./texs/ennemis/e4/e43.xpm");
	tltex->e44 = xtoi(gdata, "./texs/ennemis/e4/e44.xpm");
	tltex->mf = xtoi(gdata, "./texs/map/mf.xpm");
	tltex->mt = xtoi(gdata, "./texs/map/mt.xpm");
	tltex->mr = xtoi(gdata, "./texs/map/mr.xpm");
	tltex->mb = xtoi(gdata, "./texs/map/mb.xpm");
	if (!(tltex->e31) || !(tltex->e32) || !(tltex->e34) || !(tltex->e41)
		|| !(tltex->e42) || !(tltex->e43) || !(tltex->e44) || !(tltex->mf)
		|| !(tltex->mt) || !(tltex->mr) || !(tltex->mb) || !(tltex->e31))
		return (ft_freetexs1(gdata), 1);
	initialize_imgs3(gdata, tltex);
	return (0);
}

int	initialize_imgs1(t_data *gdata)
{
	t_textures	*tltex;

	tltex = malloc(sizeof(t_textures));
	if (!tltex)
		return (1);
	tltex->collec = xtoi(gdata, "./texs/cols/col.xpm");
	tltex->p1 = xtoi(gdata, "./texs/joueur/p1.xpm");
	tltex->p2 = xtoi(gdata, "./texs/joueur/p2.xpm");
	tltex->p3 = xtoi(gdata, "./texs/joueur/p3.xpm");
	tltex->p4 = xtoi(gdata, "./texs/joueur/p4.xpm");
	tltex->e11 = xtoi(gdata, "./texs/ennemis/e1/e11.xpm");
	tltex->e12 = xtoi(gdata, "./texs/ennemis/e1/e12.xpm");
	tltex->e13 = xtoi(gdata, "./texs/ennemis/e1/e13.xpm");
	tltex->e14 = xtoi(gdata, "./texs/ennemis/e1/e14.xpm");
	tltex->e21 = xtoi(gdata, "./texs/ennemis/e2/e21.xpm");
	tltex->e22 = xtoi(gdata, "./texs/ennemis/e2/e22.xpm");
	tltex->e23 = xtoi(gdata, "./texs/ennemis/e2/e23.xpm");
	if (!(tltex->collec) || !(tltex->p1) || !(tltex->p2) || !(tltex->p3)
		|| !(tltex->p4) || !(tltex->e11) || !(tltex->e12) || !(tltex->e13)
		|| !(tltex->e14) || !(tltex->e21) || !(tltex->e22) || !(tltex->e23))
		return (ft_freetexs1(gdata), 1);
	initialize_imgs2(gdata, tltex);
	return (0);
}
