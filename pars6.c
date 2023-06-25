/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars6.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbentale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 22:02:40 by zbentale          #+#    #+#             */
/*   Updated: 2023/06/25 22:07:52 by zbentale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	help_me1(char *str, t_rgb *rgb)
{
	while (str[rgb->i] == ' ' || str[rgb->i] == '\t')
		rgb->i++;
	if (str[rgb->i] == ',')
		rgb->i++;
	else
		write_error("Error: invalid color\n");
}
