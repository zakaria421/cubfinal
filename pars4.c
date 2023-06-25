/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbentale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 13:33:19 by zbentale          #+#    #+#             */
/*   Updated: 2023/06/25 18:45:42 by zbentale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	help_direction_take1(int i, t_map *map, int test)
{
	if (ft_strncmp(&map->line[i], "EA ", 3) == 0 && test == 0)
	{
		map->ea = ft_strdupspace(&map->line[i] + 3);
		map->check.east++;
		map->count++;
		test++;
	}
	else if (ft_strncmp(&map->line[i], "F ", 2) == 0 && test == 0)
	{
		map->f = floorandceiling(&map->line[i]);
		map->check.floor++;
		map->count++;
		test++;
	}
	else if (ft_strncmp(&map->line[i], "C ", 2) == 0 && test == 0)
	{
		map->c = floorandceiling(&map->line[i]);
		map->check.ceiling++;
		map->count++;
		test++;
	}
	return (test);
}

void	help_ifits_valide(t_help *he, t_map *map)
{
	he->a = the_first_char(map->map[he->i]);
	he->b = the_last_char(map->map[he->i]);
	if (he->a == -1 || he->b == -1)
		write_error("Error: Nuh uh1 ;)\n");
	he->a++;
	he->b--;
	while (he->a <= he->b)
	{
		if (map->map[he->i][he->a] == '0')
			help_the_help(he, map);
		he->a++;
	}
	he->a = 0;
	he->b = 0;
}

void	help_the_help(t_help *he, t_map *map)
{
	he->x = the_last_char(map->map[he->i - 1]);
	he->y = the_last_char(map->map[he->i + 1]);
	if (he->a > he->x)
		write_error("Error: Nuh uh6 ;)\n");
	else if (he->a > he->y)
		write_error("Error: Nuh uh7 ;)\n");
	else if (map->map[he->i - 1][he->a] == ' ' || map->map[he->i
			- 1][he->a] == '\t')
		write_error("Error: Nuh uh2 ;)\n");
	else if (map->map[he->i + 1][he->a] == ' ' || map->map[he->i
			+ 1][he->a] == '\t')
		write_error("Error: Nuh uh3 ;)\n");
	else if (map->map[he->i][he->a - 1] == ' ' || map->map[he->i][he->a
			- 1] == '\t')
		write_error("Error: Nuh uh4 ;)\n");
	else if (map->map[he->i][he->a + 1] == ' ' || map->map[he->i][he->a
			+ 1] == '\t')
		write_error("Error: Nuh uh5 ;)\n");
}

void	pars_six_line(t_map *map)
{
	map->xpm = open(map->no, O_RDONLY);
	if (map->xpm == -1)
		write_error("Error: failed to open NO texture\n");
	else
	{
		if (ft_strlen(map->no) < 5)
			write_error("Error: NO texture is not a .xpm file\n");
		if (ft_strncmp(map->no + ft_strlen(map->no) - 4, ".xpm", 4) != 0)
			write_error("Error: NO texture is not a .xpm file\n");
		close(map->xpm);
	}
	map->xpm = open(map->so, O_RDONLY);
	if (map->xpm == -1)
		write_error("Error: failed to open SO texture\n");
	else
	{
		if (ft_strlen(map->so) < 5)
			write_error("Error: SO texture is not a .xpm file\n");
		if (ft_strncmp(map->so + ft_strlen(map->so) - 4, ".xpm", 4) != 0)
			write_error("Error: SO texture is not a .xpm file\n");
		close(map->xpm);
	}
	pars_six_line1(map);
}

void	pars_six_line1(t_map *map)
{
	map->xpm = open(map->we, O_RDONLY);
	if (map->xpm == -1)
		write_error("Error: failed to open WE texture\n");
	else
	{
		if (ft_strlen(map->we) < 5)
			write_error("Error: WE texture is not a .xpm file\n");
		if (ft_strncmp(map->we + ft_strlen(map->we) - 4, ".xpm", 4) != 0)
			write_error("Error: WE texture is not a .xpm file\n");
		close(map->xpm);
	}
	map->xpm = open(map->ea, O_RDONLY);
	if (map->xpm == -1)
		write_error("Error: failed to open EA texture\n");
	else
	{
		if (ft_strlen(map->ea) < 5)
			write_error("Error: EA texture is not a .xpm file\n");
		if (ft_strncmp(map->ea + ft_strlen(map->ea) - 4, ".xpm", 4) != 0)
			write_error("Error: EA texture is not a .xpm file\n");
		close(map->xpm);
	}
}
