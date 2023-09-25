/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motroian <motroian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 21:33:47 by motroian          #+#    #+#             */
/*   Updated: 2023/09/25 21:01:14 by motroian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	check_zero(char **map, int x, int y)
{
	if (map[y + 1][x] == 'V')
		return (1);
	if (map[y - 1][x] == 'V')
		return (1);
	if (map[y][x + 1] == 'V')
		return (1);
	if (map[y][x - 1] == 'V')
		return (1);
	return (0);
}

int	check_vide(t_data *data, char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if ((map[y][x] == '0') || (map[y][x] == 'N')
				|| (map[y][x] == 'S') || (map[y][x] == 'E') || (map[y][x] == 'W'))
			{
				if (check_zero(map, x, y) == 1)
					return (1);
			}
			x++;
		}
		y++;
	}
	data->y = y;
	data->x = x;
	return (0);
}

int	check_map(char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] != '1' && (map[y][x] != '0') && (map[y][x] != 'N')
				&& (map[y][x] != 'S') && (map[y][x] != 'E') && (map[y][x] != 'W')
				&& (map[y][x] != ' '&& (map[y][x] != '\t')))
					return (1);
			x++;
		}
		y++;
	}
	return (0);
}
