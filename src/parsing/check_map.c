/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motroian <motroian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 21:33:47 by motroian          #+#    #+#             */
/*   Updated: 2023/10/06 20:10:33 by motroian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

// void	stock_info(t_data *data)
// {
// 	int	y;
// 	int	x;

// 	y = 0;
// 	while (data->map[y])
// 	{
// 		x = 0;
// 		while (data->map[y][x])
// 		{
// 			if (data->map[y][x] == 'N' || data->map[y][x] == 'S'
// 				|| data->map[y][x] == 'E' || data->map[y][x] == 'W')
// 			{
// 				data->game.posx = (double)y;
// 				data->game.posy = (double)x;
// 				if (data->map[y][x] == 'N')
// 					data->dir = 'N';
// 				data->dir = data->map[y][x];
// 			}
// 			x++;
// 		}
// 		y++;
// 	}
// }

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

int	check_vide(char **map)
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

int	check_perso(t_data *data)
{
	int	z;
	int	y;
	int	x;

	y = 0;
	z = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if ((data->map[y][x] == 'N') || (data->map[y][x] == 'S') || (data->map[y][x] == 'E')
				|| (data->map[y][x] == 'W'))
			{
				z++;
				data->game.posx = (double)y;
				data->game.posy = (double)x;
				data->dir = data->map[y][x];
			}
			x++;
		}
		y++;
	}
	if (z == 1)
		return (0);
	else
		return (1);
}
