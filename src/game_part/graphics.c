/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motroian <motroian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 18:17:49 by motroian          #+#    #+#             */
/*   Updated: 2023/10/09 22:50:27 by motroian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	verline(t_data *data, int start, int end, int x, int color)
{
	while (start <= end)
		mlx_pixel_put(data->mlx, data->win, x, start++, color);
}

void	load_image(t_data *data, int *texture, char *path, t_img *img)
{
	img->img = mlx_xpm_file_to_image(data->mlx, path, &img->img_width, &img->img_height);
	img->dta = (int *)mlx_get_data_addr(img->img, &img->bpp, &img->size_l, &img->endian);
	for (int y = 0; y < img->img_height; y++)
	{
		for (int x = 0; x < img->img_width; x++)
		{
			texture[img->img_width * y + x] = img->dta[img->img_width * y + x];
		}
	}
	mlx_destroy_image(data->mlx, img->img);
}

void	load_texture(t_data *data)
{
	t_img	img;

	load_image(data, data->game.texture[0], "textures/eagle.xpm", &img);
	load_image(data, data->game.texture[1], "textures/redbrick.xpm", &img);
	load_image(data, data->game.texture[2], "textures/purplestone.xpm", &img);
	load_image(data, data->game.texture[3], "textures/greystone.xpm", &img);
	load_image(data, data->game.texture[4], "textures/bluestone.xpm", &img);
	load_image(data, data->game.texture[5], "textures/mossy.xpm", &img);
	load_image(data, data->game.texture[6], "textures/wood.xpm", &img);
	load_image(data, data->game.texture[7], "textures/colorstone.xpm", &img);
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

int	graphic_part(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		exit(EXIT_FAILURE);
	data->game.posx = 22.0;
	data->game.posy = 11.5;
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

	if (!(data->game.texture = (int **)malloc(sizeof(int *) * 8)))
		return (-1);
	for (int i = 0; i < 8; i++)
	{
		if (!(data->game.texture[i] = (int *)malloc(sizeof(int) * (texHauteur * texLargeur))))
			return (-1);
	}
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < texHauteur * texLargeur; j++)
		{
			data->game.texture[i][j] = 0;
		}
	}
	data->game.movespeed = 0.09;
	data->game.rotspeed = 0.09;
	data->win = mlx_new_window(data->mlx, width, height, "le cuvub");
	load_texture(data);
	data->game.img.img = mlx_new_image(data->mlx, width, height);
	data->game.img.dta = (int *)mlx_get_data_addr(data->game.img.img, &data->game.img.bpp, &data->game.img.size_l, &data->game.img.endian);
	main_loop(data);
	mlx_hook(data->win, 0, 1L << 0, &key_press, data);
	mlx_hook(data->win, 17, 0, &free_palestine, data);
	mlx_key_hook(data->win, &key_press, data);
	mlx_loop_hook(data->mlx, &main_loop, data);
	mlx_loop(data->mlx);
	return (0);
}
