/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbentale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 13:15:26 by zbentale          #+#    #+#             */
/*   Updated: 2023/06/25 17:09:33 by zbentale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_strjoin1(char *s1, char const *s2)
{
	char	*p;
	int		s1_len;
	int		s2_len;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	p = malloc(s2_len + s1_len + 1);
	if (!p)
		return (NULL);
	while (i < s1_len)
	{
		p[i] = s1[i];
		i++;
	}
	while (j < s2_len)
		p[i++] = s2[j++];
	return (p[i] = '\0', free(s1), p);
}

void	check_format(char *str)
{
	if (ft_strncmp(str + ft_strlen(str) - 4, ".cub", 4))
		write_error("Error: invalid file format\n");
}

void	init_map(t_map *map)
{
	map->no = NULL;
	map->so = NULL;
	map->we = NULL;
	map->ea = NULL;
	map->map = NULL;
	map->line = NULL;
	map->allin = NULL;
	map->fd = 0;
	map->count = 0;
	map->f = 0;
	map->c = 0;
	map->check.north = 0;
	map->check.south = 0;
	map->check.east = 0;
	map->check.west = 0;
	map->check.floor = 0;
	map->check.ceiling = 0;
	map->check.player = 0;
}

char	*ft_strdupspace(const char *s1)
{
	char	*p;
	size_t	i;
	size_t	len;

	i = 0;
	while (*s1 == ' ' || *s1 == '\t')
		s1++;
	len = ft_strlen(s1);
	p = malloc(sizeof(char) * (len + 1));
	if (p == 0)
		return (NULL);
	while (s1[i] != '\n')
	{
		p[i] = s1[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

int	rgb_to_int(int r, int g, int b)
{
	return (r * 256 * 256 + g * 256 + b);
}
