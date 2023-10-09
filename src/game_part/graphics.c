/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motroian <motroian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 18:17:49 by motroian          #+#    #+#             */
/*   Updated: 2023/10/09 18:52:41 by motroian         ###   ########.fr       */
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
		exit(0);
	mlx_clear_window(data->mlx, data->win);
	main_loop(data);
	return (0);
}

void	graphic_part(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		exit(EXIT_FAILURE);
	data->game.posx = 7;
	data->game.posy = 12;
	data->game.dirx = -1;
	data->game.diry = 0;
	data->game.planex = 0;
	data->game.planey = 0.66;
	data->game.re_buf = 0;

	data->game.buf = (int **)malloc(sizeof(int *) * height);
	for (int i = 0; i < height; i++)
	{
		data->game.buf[i] = (int *)malloc(sizeof(int) * width);
	}

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			data->game.buf[i][j] = 0;
		}
	}

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < texHauteur * texLargeur; j++)
		{
			data->game.texture[i][j] = 0;
		}
	}

	for (int x = 0; x < texLargeur; x++)
	{
		for (int y = 0; y < texHauteur; y++)
		{
			int xorcolor = (x * 256 / texLargeur) ^ (y * 256 / texHauteur);
			int ycolor = y * 256 / texHauteur;
			int xycolor = y * 128 / texHauteur + x * 128 / texLargeur;
			data->game.texture[0][texLargeur * y + x] = 65536 * 254 * (x != y && x != texLargeur - y); //flat red texture with black cross
			data->game.texture[1][texLargeur * y + x] = xycolor + 256 * xycolor + 65536 * xycolor; //sloped greyscale
			data->game.texture[2][texLargeur * y + x] = 256 * xycolor + 65536 * xycolor; //sloped yellow gradient
			data->game.texture[3][texLargeur * y + x] = xorcolor + 256 * xorcolor + 65536 * xorcolor; //xor greyscale
			data->game.texture[4][texLargeur * y + x] = 256 * xorcolor; //xor green
			data->game.texture[5][texLargeur * y + x] = 65536 * 192 * (x % 16 && y % 16); //red bricks
			data->game.texture[6][texLargeur * y + x] = 65536 * ycolor; //red gradient
			data->game.texture[7][texLargeur * y + x] = 128 + 256 * 128 + 65536 * 128; //flat grey texture
		}
	}
	data->game.movespeed = 0.09;
	data->game.rotspeed = 0.09;
	data->win = mlx_new_window(data->mlx, width, height, "le cuvub");
	main_loop(data);
	data->game.img.img = mlx_new_image(data->mlx, width, height);
	data->game.img.dta = (int *)mlx_get_data_addr(data->game.img.img, &data->game.img.bpp, &data->game.img.size_l, &data->game.img.endian);
	mlx_hook(data->win, 0, 1L << 0, &key_press, data);
	mlx_hook(data->win, 17, 0, &free_palestine, data);
	mlx_key_hook(data->win, &key_press, data);
	mlx_loop_hook(data->mlx, &main_loop, data);
	mlx_loop(data->mlx);
}
