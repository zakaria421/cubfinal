/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbentale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 10:51:47 by zbentalh          #+#    #+#             */
/*   Updated: 2023/06/25 19:11:51 by zbentale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

size_t	ft_double_strlen(char **s)
{
	size_t	i;

	i = 0;
	while (s[i] != NULL)
	{
		i++;
	}
	return (i);
}

int	ft_stlen_v2(char **str, int y)
{
	int	i;

	i = 0;
	while (str[y][i])
		i++;
	return (i);
}

float	calcul_c(int y, int c)
{
	float	i;

	i = 0;
	while (y <= HIGHT / 2 + c / 2)
	{
		y++;
		i++;
	}
	return (i);
}

int	close_pro(t_cube *cube)
{
	mlx_destroy_window(cube->mlx.mlx_ptr, cube->mlx.win_ptr);
	exit(0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (len == 0 || start > ft_strlen(s))
		return (p = malloc(1), p[i] = '\0', p);
	else if (len >= ft_strlen(s))
	{
		p = malloc((ft_strlen(s) - start) + 1);
		if (!p)
			return (NULL);
	}
	else
	{
		p = malloc(len + 1);
		if (!p)
			return (NULL);
	}
	while (i < len && s[start] != '\0')
		p[i++] = s[start++];
	return (p[i] = '\0', p);
}
