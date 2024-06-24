/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebengtss <ebengtss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 10:02:04 by ebengtss          #+#    #+#             */
/*   Updated: 2024/06/24 14:29:18 by ebengtss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_gnljoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	lens1;
	size_t	lens2;

	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
	{
		free((void *)s1);
		return (NULL);
	}
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	str = malloc(sizeof(char) * (lens1 + lens2 + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, lens1);
	ft_strlcpy(&(str[lens1]), s2, lens2);
	free((void *)s1);
	return (str);
}

static int	ft_free(char **str, char *buff)
{
	if (str && *str)
	{
		free(*str);
		*str = NULL;
	}
	if (buff)
		free(buff);
	return (1);
}

static char	*trim_line(char **tab, int fd)
{
	char	*tmp;
	char	*tmp2;
	int		i;

	i = 0;
	while (tab[fd][i] && tab[fd][i] != '\n')
		i++;
	tmp = malloc(sizeof(char) * (i + 2));
	if (!tmp)
		return (NULL);
	ft_strlcpy(tmp, tab[fd], (i + 1));
	if (tab[fd] && tab[fd][i] == '\n' && tab[fd][i + 1])
	{
		tmp2 = ft_strdup(&(tab[fd][++i]));
		ft_free(&tab[fd], ft_strdup(""));
		tab[fd] = tmp2;
	}
	else
		ft_free(&tab[fd], ft_strdup(""));
	return (tmp);
}

static int	read_line(char **tab, int fd)
{
	char	*buff;
	int		rbytes;

	buff = malloc(sizeof(char) * (GNL_BUFFER_SIZE + 1));
	if (!buff)
		return (1);
	rbytes = 1;
	while (rbytes > 0)
	{
		rbytes = read(fd, buff, GNL_BUFFER_SIZE);
		if ((rbytes < 0) || (rbytes == 0 && !tab[fd]))
			return (ft_free(&tab[fd], buff));
		buff[rbytes] = '\0';
		tab[fd] = ft_gnljoin(tab[fd], buff);
		if (!tab[fd])
			return (1);
		if (is_nl(tab[fd]) == 0)
			break ;
	}
	if (buff)
		free(buff);
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*tab[1024];
	char		*str;

	if (fd < 0 || fd > 1024 || GNL_BUFFER_SIZE < 0)
		return (NULL);
	if (read_line(tab, fd))
		return (NULL);
	str = trim_line(tab, fd);
	if (!str)
		return (NULL);
	return (str);
}
