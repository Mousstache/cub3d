/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahouari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 18:17:49 by motroian          #+#    #+#             */
/*   Updated: 2023/10/26 22:19:37 by yahouari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	main_loop(t_data *data)
{
	calc(data);
	draw(data);
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
	{
		free_palestine(data);
		exit(0);
	}
	mlx_clear_window(data->mlx, data->win);
	main_loop(data);
	return (0);
}

void	define_view_side(t_data *data)
{
	if (data->dir == 'N')
	{
		data->game.dirx = -1;
		data->game.diry = 0;
	}
	else if (data->dir == 'S')
	{
		data->game.dirx = 1;
		data->game.diry = 0;
	}
	else if (data->dir == 'W')
	{
		data->game.dirx = 0;
		data->game.diry = -1;
	}
	else if (data->dir == 'E')
	{
		data->game.dirx = 0;
		data->game.diry = 1;
	}
}

void	init_malloc_graph_part(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	data->game.buf = (int **)malloc(sizeof(int *) * height + 1000);
	data->game.texture = (int **)malloc(sizeof(int *) * 8 + 1000);
	while (++i < height)
		data->game.buf[i] = (int *)malloc(sizeof(int) * width + 1);
	i = -1;
	while (++i < 8)
		data->game.texture[i] = (int *)malloc(sizeof(int) * (texHauteur
					* texLargeur));
	i = -1;
	while (++i < 8)
	{
		j = -1;
		while (++j < (texHauteur * texHauteur))
			data->game.texture[i][j] = 0;
	}
}

int	graphic_part(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		exit(EXIT_FAILURE);
	define_view_side(data);
	data->game.planex = 0.66 * data->game.diry;
	data->game.planey = 0.66 * (data->game.dirx * -1);
	data->game.re_buf = 1;
	init_malloc_graph_part(data);
	data->game.movespeed = 0.5;
	data->game.rotspeed = 0.09;
	data->win = mlx_new_window(data->mlx, width, height, "le cuvub");
	load_texture(data);
	data->game.img.img = mlx_new_image(data->mlx, width, height);
	data->game.img.dta = (int *)mlx_get_data_addr(data->game.img.img,
			&data->game.img.bpp, &data->game.img.size_l,
			&data->game.img.endian);
	main_loop(data);
	mlx_hook(data->win, 0, 1L << 0, &key_press, data);
	mlx_hook(data->win, 17, 0, &free_palestine, data);
	mlx_key_hook(data->win, &key_press, data);
	mlx_loop_hook(data->mlx, &main_loop, data);
	mlx_loop(data->mlx);
	return (0);
}
