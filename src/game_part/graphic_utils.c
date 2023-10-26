/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahouari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 22:13:02 by yahouari          #+#    #+#             */
/*   Updated: 2023/10/26 22:19:15 by yahouari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	define_side(t_data *data)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (data->game.sidedistx < data->game.sidedisty)
		{
			data->game.sidedistx += data->game.deltadistx;
			data->game.mapx += data->game.stepx;
			data->game.side = 0;
		}
		else
		{
			data->game.sidedisty += data->game.deltadisty;
			data->game.mapy += data->game.stepy;
			data->game.side = 1;
		}
		if (data->map[data->game.mapx][data->game.mapy] > '0')
			hit = 1;
	}
}

int	choose_texture(t_data *data, int texNum)
{
	if (data->game.raydirx > 0 && data->game.side == 0)
		texNum = 0;
	else if (data->game.raydirx < 0 && data->game.side == 0)
		texNum = 1;
	else if (data->game.raydiry > 0 && data->game.side == 1)
		texNum = 2;
	else
		texNum = 3;
	return (texNum);
}

void	load_image(t_data *data, int *texture, char *path, t_img *img)
{
	int	y;
	int	x;

	y = -1;
	img->img = mlx_xpm_file_to_image(data->mlx, path, &img->img_width,
			&img->img_height);
	if (!img->img)
	{
		printf("Error\nInvalid texture path\n");
		free_palestine(data);
	}
	img->dta = (int *)mlx_get_data_addr(img->img, &img->bpp, &img->size_l,
			&img->endian);
	while (++y < img->img_height)
	{
		x = -1;
		while (++x < img->img_width)
			texture[img->img_width * y + x] = img->dta[img->img_width * y + x];
	}
	mlx_destroy_image(data->mlx, img->img);
}

void	load_texture(t_data *data)
{
	load_image(data, data->game.texture[0], data->game.paths[0],
		&data->game.img);
	load_image(data, data->game.texture[1], data->game.paths[1],
		&data->game.img);
	load_image(data, data->game.texture[2], data->game.paths[2],
		&data->game.img);
	load_image(data, data->game.texture[3], data->game.paths[3],
		&data->game.img);
}
