/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebengtss <ebengtss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 10:46:43 by ebengtss          #+#    #+#             */
/*   Updated: 2024/07/02 16:02:01 by ebengtss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H

# include <time.h>
# include <fcntl.h>
# include "../libft/incs/libft.h"
# include "../minilibx-linux/mlx.h"

typedef struct s_textures
{
	void	*collec;
	void	*p1;
	void	*p2;
	void	*p3;
	void	*p4;
	void	*e11;
	void	*e12;
	void	*e13;
	void	*e14;
	void	*e21;
	void	*e22;
	void	*e23;
	void	*e24;
	void	*e31;
	void	*e32;
	void	*e33;
	void	*e34;
	void	*e41;
	void	*e42;
	void	*e43;
	void	*e44;
	void	*mf;
	void	*mt;
	void	*mr;
	void	*mb;
	void	*ml;
	void	*mtl;
	void	*mtr;
	void	*mbr;
	void	*mbl;
	void	*me1;
	void	*me2;
	void	*mo1;
	void	*mo2;
	void	*mo3;
	void	*mo4;
	void	*mo5;
}			t_textures;

typedef struct s_checkdata
{
	int		ccol;
	int		mcol;
	int		ise;
	int		isf;
	char	**map;
}			t_checkdata;

typedef struct s_data
{
	int			fd;
	int			xp;
	int			yp;
	int			cp;
	int			xe;
	int			ye;
	int			ce;
	int			ise;
	int			cm;
	int			ccol;
	char		**map;
	void		*mlx;
	void		*win;
	int			hw;
	int			ww;
	int			hi;
	int			wi;
	int			lx;
	int			ly;
	t_collec	*lcol;
	t_img		*limg;
	t_textures	*ltex;
}				t_data;

t_checkdata	*clonestruct(t_data *gdata);

char		**clonemap(char **map);

void		*xtoi(t_data *gdata, char *file);

void		*playerdir(t_data *gdata, int x, int y);

void		ft_freemain(t_data *gdata);

void		ft_freemap(char **map);

void		ft_freemakemap(char *buff, char *tmpbuff, char *tmpmap);

void		adddata(char c, t_data *gdata, int x, int y);

void		takecol(t_data *gdata);

void		ft_freetexs1(t_data *gdata);

void		ft_freetexs2(t_data *gdata);

void		ft_freetexs3(t_data *gdata);

void		ft_freetexs4(t_data *gdata);

void		initdata(t_data *gdata);

void		replaceimg(t_data *gdata, int y, int x, char c);

int			checkmap(char **map);

int			makemap(int fd, t_data *gdata);

int			getmapdata(t_data *gdata);

int			getlinedata(t_data *gdata, int y);

int			checkmapdata(t_data *gdata);

int			ismapvalid(t_data *gdata);

int			processmap(int fd, t_data *gdata);

int			listen_inputs(int key, t_data *gdata);

int			testmap(t_checkdata *gdata, int x, int y);

int			isdir(t_data *gdata, char pos);

int			checkfilename(char *str, char *tofind);

int			listen_close(t_data *gdata);

int			makewin(t_data	*gdata);

int			initialize_imgs1(t_data *gdata);

int			initialize_imgs2(t_data *gdata, t_textures *tltex);

int			initialize_imgs3(t_data *gdata, t_textures *tltex);

int			rangerand(void);

int			itow(t_data *gdata, void *img, int x, int y);

int			print_mooves(t_data *gdata);

#endif