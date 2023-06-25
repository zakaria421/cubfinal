/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbentale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 13:15:51 by zbentale          #+#    #+#             */
/*   Updated: 2023/06/25 21:05:50 by zbentale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	height_count(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	the_first_char(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == '1')
		return (i);
	else
		return (-1);
}

int	the_last_char(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	i--;
	while (str[i] == ' ' || str[i] == '\t')
		i--;
	if (str[i] == '1')
		return (i);
	else
		return (-1);
}

void	check_if_its_valide(t_map *map)
{
	t_help	he;

	init_help(&he, map);
	while (map->map[he.i])
	{
		if (he.i == 0)
			check_first_lat_line(map->map[he.i]);
		else if (he.i == he.height - 1)
			check_first_lat_line(map->map[he.i]);
		else
			help_ifits_valide(&he, map);
		he.i++;
	}
}

void	parse_cub3d_file(char *filename, int x)
{
	t_map	map;

	init_map(&map);
	map.fd = open(filename, O_RDONLY);
	if (map.fd == -1)
		write_error("Error: failed to open file\n");
	while (1)
	{
		map.line = get_next_line(map.fd);
		if (map.line == NULL)
			break ;
		x = direction_take(&map);
		if (x == 1)
		{
			pars_six_line(&map);
			break ;
		}
		free(map.line);
	}
	if (x == 1)
		map_and_exec(&map);
	else
		write_error("Error: invalid map\n");
	close(map.fd);
}
