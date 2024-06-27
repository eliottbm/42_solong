/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebengtss <ebengtss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 10:46:43 by ebengtss          #+#    #+#             */
/*   Updated: 2024/06/27 16:58:08 by ebengtss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H

# include <fcntl.h>
# include "../libft/incs/libft.h"
# include "../minilibx-linux/mlx.h"

typedef struct s_data
{
	int			xp;
	int			yp;
	int			cp;
	int			xe;
	int			ye;
	int			ce;
	int			ise;
	t_collec	*collecs;
	int			ccollecs;
}				t_data;

typedef struct s_mlx {
	void	*mlx;
	void	*win;
}			t_mlx;

t_data	*getmapdata(char **map);

char	**makemap(int fd);

char	**clonemap(char **map);

void	ft_freemain(char **map, t_data *gamedata);

void	ft_freemlx(t_mlx *mlxdata);

void	ft_printmap(char **map);

int		checkmap(char **map);

int		getlinedata(char *line, int y, t_data *gamedata, t_collec **clist);

int		checkmapdata(t_data *gamedata);

int		ismapvalid(char **map, t_data *gamedata);

int		processmap(int fd, char ***map, t_data **gamedata);

int		listen_inputs(int key, t_mlx *mlxdata);

#endif