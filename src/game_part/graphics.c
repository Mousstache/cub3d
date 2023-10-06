/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motroian <motroian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 18:17:49 by motroian          #+#    #+#             */
/*   Updated: 2023/10/06 20:12:49 by motroian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	verline(t_data *data, int start, int end, int x, int color)
{
	while (start <= end)
		mlx_pixel_put(data->mlx, data->win, x, start++, color);
}

int	main_loop(t_data *data)
{
	calc(data);
	return (0);
}

int	key_press(int key, t_data *data)
{
	if (key == 'w')
		move_up(data);
	if (key == 's')
		move_down(data);
	if (key == 'a')
		move_left(data);
	if (key == 'd')
		move_right(data);
	if (key == 65363)
		rotate_right(data);
	if (key == 65361)
		rotate_left(data);
	if (key == 65307 || key == 113)
		exit(1);
	return (0);
}

void	graphic_part(t_data *data)
{
	data->game.dirx = -1;
	data->game.diry = 0;
	data->game.planex = 0;
	data->game.planey = 0.66;
	data->game.movespeed = 0.09;
	data->game.rotspeed = 0.09;
	data->mlx = mlx_init();
	if (!data->mlx)
		exit(EXIT_FAILURE);
	data->win = mlx_new_window(data->mlx, width, height, "le cuvub");
	mlx_hook(data->win, 0, 1L << 0, &key_press, data);
	mlx_hook(data->win, 17, 0, &free_palestine, data);
	mlx_key_hook(data->win, &key_press, data);
	mlx_loop_hook(data->mlx, &main_loop, data);
	mlx_loop(data->mlx);
}
