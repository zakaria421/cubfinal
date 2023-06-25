/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbentale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 11:40:26 by zbentale          #+#    #+#             */
/*   Updated: 2023/06/25 21:05:36 by zbentale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	write_error(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(2, &str[i], 1);
		i++;
	}
	exit(1);
}

void	map_and_exec(t_map *map)
{
	map->allin = ft_strdup(map->line);
	free(map->line);
	while (1)
	{
		map->line = get_next_line(map->fd);
		if (map->line == NULL)
			break ;
		map->allin = ft_strjoin1(map->allin, map->line);
		free(map->line);
	}
	check_the_map(map, 0, 0);
	map->map = ft_split(map->allin, '\n');
	free(map->allin);
	check_if_its_valide(map);
	start(map);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		check_format(argv[1]);
		parse_cub3d_file(argv[1], 0);
	}
	else
		write_error("Error: invalid number of arguments\n");
	return (0);
}
