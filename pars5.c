/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbentale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 18:43:29 by zbentale          #+#    #+#             */
/*   Updated: 2023/06/25 22:07:49 by zbentale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ret_number(int r, int g, int b)
{
	int	color;

	color = 0;
	if (r > 255 || g > 255 || b > 255)
		write_error("Error: invalid color\n");
	color = rgb_to_int(r, g, b);
	return (color);
}

void	init_help(t_help *he, t_map *map)
{
	he->i = 0;
	he->j = 0;
	he->a = 0;
	he->b = 0;
	he->x = 0;
	he->y = 0;
	he->height = height_count(map->map);
}

void	init_rgb(t_rgb *rgb)
{
	rgb->i = 0;
	rgb->r = 0;
	rgb->g = 0;
	rgb->b = 0;
}

void	helpf_andc(t_rgb *rgb, char *str)
{
	while (str[rgb->i] >= '0' && str[rgb->i] <= '9')
	{
		rgb->b = rgb->b * 10 + str[rgb->i] - '0';
		rgb->i++;
	}
	while (str[rgb->i] == ' ' || str[rgb->i] == '\t')
		rgb->i++;
	if (str[rgb->i] != '\n')
		write_error("Error: invalid color\n");
}

int	help_direction_take(int i, t_map *map, int test)
{
	if (ft_strncmp(&map->line[i], "NO ", 3) == 0 && test == 0)
	{
		map->no = ft_strdupspace(&map->line[i] + 3);
		map->check.north++;
		map->count++;
		test++;
	}
	else if (ft_strncmp(&map->line[i], "SO ", 3) == 0 && test == 0)
	{
		map->so = ft_strdupspace(&map->line[i] + 3);
		map->check.south++;
		map->count++;
		test++;
	}
	else if (ft_strncmp(&map->line[i], "WE ", 3) == 0 && test == 0)
	{
		map->we = ft_strdupspace(&map->line[i] + 3);
		map->check.west++;
		map->count++;
		test++;
	}
	return (test);
}
