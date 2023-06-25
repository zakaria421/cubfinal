/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbentale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 13:15:43 by zbentale          #+#    #+#             */
/*   Updated: 2023/06/25 17:59:09 by zbentale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_char(char c)
{
	if ((c > 32 && c < 48) || (c > 57 && c < 127))
		write_error("Error: invalid color\n");
}

int	floorandceiling(char *str)
{
	t_rgb	rgb;

	init_rgb(&rgb);
	while (str[rgb.i] == ' ' || str[rgb.i] == '\t' || str[rgb.i] == 'F'
		|| str[rgb.i] == 'C')
		rgb.i++;
	check_char(str[rgb.i]);
	while (str[rgb.i] >= '0' && str[rgb.i] <= '9')
	{
		rgb.r = rgb.r * 10 + str[rgb.i] - '0';
		rgb.i++;
	}
	while (str[rgb.i] == ' ' || str[rgb.i] == '\t' || str[rgb.i] == ',')
		rgb.i++;
	check_char(str[rgb.i]);
	while (str[rgb.i] >= '0' && str[rgb.i] <= '9')
	{
		rgb.g = rgb.g * 10 + str[rgb.i] - '0';
		rgb.i++;
	}
	while (str[rgb.i] == ' ' || str[rgb.i] == '\t' || str[rgb.i] == ',')
		rgb.i++;
	check_char(str[rgb.i]);
	helpf_andc(&rgb, str);
	return (check_char(str[rgb.i]), ret_number(rgb.r, rgb.g, rgb.b));
}

int	direction_take(t_map *map)
{
	int	i;
	int	test;

	i = 0;
	test = 0;
	while (map->line[i] == ' ' || map->line[i] == '\t' || map->line[i] == '\n')
		i++;
	test = help_direction_take(i, map, test);
	test = help_direction_take1(i, map, test);
	if (ft_strncmp(&map->line[i], "1", 1) == 0 && map->count == 6 && test == 0)
	{
		test++;
		return (1);
	}
	else if (map->line[i] == '\0' && test == 0)
		return (test++, 0);
	else if (test == 0)
		write_error("Error: invalid map\n");
	if (map->check.north > 1 || map->check.south > 1 || map->check.west > 1
		|| map->check.east > 1 || map->check.floor > 1 || map->check.ceiling > 1
		|| map->count > 6)
		write_error("Error: invalid map\n");
	return (0);
}

void	check_the_map(t_map *map, int i, int j)
{
	while (map->allin[i])
	{
		if (map->allin[i] == 'N' || map->allin[i] == 'S' || map->allin[i] == 'W'
			|| map->allin[i] == 'E')
			map->check.player++;
		if (map->allin[i] != '1' && map->allin[i] != '0'
			&& map->allin[i] != '\n' && map->allin[i] != ' '
			&& map->allin[i] != '\t' && map->allin[i] != 'N'
			&& map->allin[i] != 'S' && map->allin[i] != 'W'
			&& map->allin[i] != 'E')
			write_error("Error: invalid map\n");
		if (map->allin[i] == '\n')
		{
			j = i;
			j++;
			while (map->allin[j] == '\t' || map->allin[j] == ' ')
				j++;
			if (map->allin[j] == '\n' || map->allin[j] == '\0')
				write_error("Error: invalid map\n");
		}
		i++;
	}
	if (map->check.player != 1)
		write_error("Error: invalid map\n");
}

void	check_first_lat_line(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '1' && str[i] != ' ' && str[i] != '\t')
			write_error("Error: invalid map\n");
		i++;
	}
}
