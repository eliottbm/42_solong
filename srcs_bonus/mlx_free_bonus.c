/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_free_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebengtss <ebengtss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 14:51:22 by ebengtss          #+#    #+#             */
/*   Updated: 2024/07/04 15:05:29 by ebengtss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/so_long_bonus.h"

void	ft_freetexs4(t_data *gdata)
{
	if (gdata->ltex->mbl)
		mlx_destroy_image(gdata->mlx, gdata->ltex->mbl);
	if (gdata->ltex->me1)
		mlx_destroy_image(gdata->mlx, gdata->ltex->me1);
	if (gdata->ltex->me2)
		mlx_destroy_image(gdata->mlx, gdata->ltex->me2);
	if (gdata->ltex->mo1)
		mlx_destroy_image(gdata->mlx, gdata->ltex->mo1);
	if (gdata->ltex->mo2)
		mlx_destroy_image(gdata->mlx, gdata->ltex->mo2);
	if (gdata->ltex->mo3)
		mlx_destroy_image(gdata->mlx, gdata->ltex->mo3);
	if (gdata->ltex->mo4)
		mlx_destroy_image(gdata->mlx, gdata->ltex->mo4);
	if (gdata->ltex->mo5)
		mlx_destroy_image(gdata->mlx, gdata->ltex->mo5);
	free(gdata->ltex);
}

void	ft_freetexs3(t_data *gdata)
{
	if (gdata->ltex->mt)
		mlx_destroy_image(gdata->mlx, gdata->ltex->mt);
	if (gdata->ltex->mr)
		mlx_destroy_image(gdata->mlx, gdata->ltex->mr);
	if (gdata->ltex->mb)
		mlx_destroy_image(gdata->mlx, gdata->ltex->mb);
	if (gdata->ltex->ml)
		mlx_destroy_image(gdata->mlx, gdata->ltex->ml);
	if (gdata->ltex->mtl)
		mlx_destroy_image(gdata->mlx, gdata->ltex->mtl);
	if (gdata->ltex->mtr)
		mlx_destroy_image(gdata->mlx, gdata->ltex->mtr);
	if (gdata->ltex->mbr)
		mlx_destroy_image(gdata->mlx, gdata->ltex->mbr);
	ft_freetexs4(gdata);
}

void	ft_freetexs2(t_data *gdata)
{
	if (gdata->ltex->e23)
		mlx_destroy_image(gdata->mlx, gdata->ltex->e23);
	if (gdata->ltex->e24)
		mlx_destroy_image(gdata->mlx, gdata->ltex->e24);
	if (gdata->ltex->e31)
		mlx_destroy_image(gdata->mlx, gdata->ltex->e31);
	if (gdata->ltex->e32)
		mlx_destroy_image(gdata->mlx, gdata->ltex->e32);
	if (gdata->ltex->e33)
		mlx_destroy_image(gdata->mlx, gdata->ltex->e33);
	if (gdata->ltex->e34)
		mlx_destroy_image(gdata->mlx, gdata->ltex->e34);
	if (gdata->ltex->mf)
		mlx_destroy_image(gdata->mlx, gdata->ltex->mf);
	ft_freetexs3(gdata);
}

void	ft_freetexs1(t_data *gdata)
{
	if (gdata->ltex->collec)
		mlx_destroy_image(gdata->mlx, gdata->ltex->collec);
	if (gdata->ltex->p1)
		mlx_destroy_image(gdata->mlx, gdata->ltex->p1);
	if (gdata->ltex->p2)
		mlx_destroy_image(gdata->mlx, gdata->ltex->p2);
	if (gdata->ltex->p3)
		mlx_destroy_image(gdata->mlx, gdata->ltex->p3);
	if (gdata->ltex->p4)
		mlx_destroy_image(gdata->mlx, gdata->ltex->p4);
	if (gdata->ltex->e11)
		mlx_destroy_image(gdata->mlx, gdata->ltex->e11);
	if (gdata->ltex->e12)
		mlx_destroy_image(gdata->mlx, gdata->ltex->e12);
	if (gdata->ltex->e13)
		mlx_destroy_image(gdata->mlx, gdata->ltex->e13);
	if (gdata->ltex->e14)
		mlx_destroy_image(gdata->mlx, gdata->ltex->e14);
	if (gdata->ltex->e21)
		mlx_destroy_image(gdata->mlx, gdata->ltex->e21);
	if (gdata->ltex->e22)
		mlx_destroy_image(gdata->mlx, gdata->ltex->e22);
	ft_freetexs2(gdata);
}
