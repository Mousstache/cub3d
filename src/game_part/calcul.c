/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motroian <motroian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 20:46:36 by motroian          #+#    #+#             */
/*   Updated: 2023/10/10 20:15:24 by motroian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	draw(t_data *data)
{
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			data->game.img.dta[y * width + x] = data->game.buf[y][x];
		}
	}
	mlx_put_image_to_window(data->mlx, data->win, data->game.img.img, 0, 0);
}

void	initializebuff(t_data *data)
{
	if (data->game.re_buf == 1)
	{
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				data->game.buf[i][j] = 0;
			}
		}
	}
}

void	define(t_game *game)
{
	if (game->raydirx < 0)
	{
		game->stepx = -1;
		game->sidedistx = (game->posx - game->mapx) * game->deltadistx;
	}
	else
	{
		game->stepx = 1;
		game->sidedistx = (game->mapx + 1.0 - game->posx) * game->deltadistx;
	}
	if (game->raydiry < 0)
	{
		game->stepy = -1;
		game->sidedisty = (game->posy - game->mapy) * game->deltadisty;
	}
	else
	{
		game->stepy = 1;
		game->sidedisty = (game->mapy + 1.0 - game->posy) * game->deltadisty;
	}
}

int  choose_texture(t_data *data, int texNum)
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

void	define_side(t_data *data)
{
	int hit;
	
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

void	boucle_a_caca(t_data *data, int x, int texNum, int texX)
{
	double	step;
	double	texpos;
	int		texy;
	int		color;
	int		y;
	
	y = data->game.drawstart;
	step = 1.0 * texHauteur / data->game.lineHeight;
	texpos = (data->game.drawstart - height / 2 + data->game.lineHeight / 2) * step;
	while (y < data->game.drawend)
	{
		texy = (int)texpos & (texHauteur - 1);
		texpos += step;
		color = data->game.texture[texNum][texHauteur * texy + texX];
		if (data->game.side == 1)
			color = (color >> 1) & 8355711;
		data->game.buf[y][x] = color;
		data->game.re_buf = 1;
		y++;
	}
}

void init_values(t_data *data, int x)
{
	double	camerax;

	if (data->game.side == 0)
		data->game.perpWalldist = (data->game.mapx - data->game.posx + (1 - data->game.stepx) / 2) / data->game.raydirx;
	else
		data->game.perpWalldist = (data->game.mapy - data->game.posy + (1 - data->game.stepy) / 2) / data->game.raydiry;
	camerax = 2 * x / (double)width - 1;
	data->game.raydirx = data->game.dirx + data->game.planex * camerax;
	data->game.raydiry = data->game.diry + data->game.planey * camerax;
	data->game.mapx = (int)data->game.posx;
	data->game.mapy = (int)data->game.posy;
	data->game.deltadistx = fabs(1 / data->game.raydirx);
	data->game.deltadisty = fabs(1 / data->game.raydiry);

}

void define_draw(t_data *data)
{
	data->game.lineHeight = (int)(height / data->game.perpWalldist);
	data->game.drawstart = -data->game.lineHeight / 2 + height / 2;
	if (data->game.drawstart < 0)
		data->game.drawstart = 0;
	data->game.drawend = data->game.lineHeight / 2 + height / 2;
	if (data->game.drawend >= height)
		data->game.drawend = height - 1;
}

void	calc(t_data *data)
{
	double	wallX;
	int		x;
	int		texNum;
	int		texX;

	x = 0;
	initializebuff(data);
	while (x < width)
	{
		init_values(data, x);
		define(&data->game);
		define_side(data);
		define_draw(data);
		texNum = choose_texture(data, texNum);
		if (data->game.side == 0)
			wallX = data->game.posy + data->game.perpWalldist * data->game.raydiry;
		else
			wallX = data->game.posx + data->game.perpWalldist * data->game.raydirx;
		wallX -= floor(wallX);
		texX = (int)(wallX * (double)texLargeur);
		if (data->game.side == 0 && data->game.raydirx > 0)
			texX = texLargeur - texX - 1;
		if (data->game.side == 1 && data->game.raydiry < 0)
			texX = texLargeur - texX - 1;
		boucle_a_caca(data, x, texNum, texX);
		x++;
	}
}

		// if (data->map[mapx][mapy] == '1')
		// 	color = 0xFF0000;
		// else
		// 	color = 0xFFFF00;
		// if (side == 1)
		// 	color = color / 2;
		// verline(data, 0, data->game.drawStart, x, 0x0Cd9F5);
		// verline(data, drawEnd, width, x, 0xFFFFFF);
		// verline(data, drawStart, drawEnd, x, color);
		// x++;