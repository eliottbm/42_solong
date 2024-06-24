/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebengtss <ebengtss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 10:05:06 by ebengtss          #+#    #+#             */
/*   Updated: 2024/05/31 19:15:12 by ebengtss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_free_all(char **strs)
{
	size_t	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (NULL);
}

static int	count_word(char const *str, char set)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (str[i])
	{
		if (i == 0 && str[i] != set)
			counter++;
		if (str[i] == set && str[i + 1] != '\0'
			&& str[i + 1] != set)
			counter++;
		i++;
	}
	return (counter);
}

static void	ft_initialize_index(int *i, int *j, int *k)
{
	*i = 0;
	*j = 0;
	*k = 0;
}

char	**ft_split(char const *s, char c)
{
	char	**splitted_str;
	int		i;
	int		j;
	int		k;

	splitted_str = malloc(sizeof(char *) * (count_word(s, c) + 1));
	if (!splitted_str)
		return (NULL);
	ft_initialize_index(&i, &j, &k);
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == '\0' || s[i + 1] == c))
		{
			splitted_str[k] = malloc(sizeof(char) * (i - j + 2));
			if (!splitted_str[k])
				return (ft_free_all(splitted_str));
			ft_strlcpy(splitted_str[k], &s[j], (i - j + 2));
			k++;
		}
		if (s[i++] == c && s[i] != c)
			j = i;
	}
	splitted_str[k] = NULL;
	return (splitted_str);
}
