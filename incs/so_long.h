/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebengtss <ebengtss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 10:46:43 by ebengtss          #+#    #+#             */
/*   Updated: 2024/06/28 12:48:14 by ebengtss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H

# include <fcntl.h>
# include "../libft/incs/libft.h"
# include "../minilibx-linux/mlx.h"

typedef struct s_data
{
	int			x_player;
	int			y_player;
	int			c_player;
	int			x_exit;
	int			y_exit;
	int			c_exit;
	int			is_exit;
	t_collec	*l_collec;
	int			c_collec;
	char		**map;
	void		*mlx;
	void		*win;
}				t_data;

typedef struct s_tmptrack
{
	int		c_collec;
	int		t_collec;
	int		is_exit;
	int		is_finish;
	char	**map;
}			t_tmptrack;

t_tmptrack	*clonestruct(t_data *gamedata);

char		**clonemap(char **map);

void		ft_freemain(t_data *gamedata);

void		ft_freevalidmap(t_tmptrack *tmpgamedata);

void		ft_freemakemap(char *buff, char *tmpbuff, char *tmpmap);

void		ft_printmap(char **map);

void		adddata(char c, t_data *gamedata, int x, int y);

int			checkmap(char **map);

int			makemap(int fd, t_data *gamedata);

int			getmapdata(t_data *gamedata);

int			getlinedata(t_data *gamedata, int y);

int			checkmapdata(t_data *gamedata);

int			ismapvalid(t_data *gamedata);

int			processmap(int fd, t_data *gamedata);

int			listen_inputs(int key, t_data *gamedata);

int			testmap(t_tmptrack *gamedata, int x, int y);

#endif