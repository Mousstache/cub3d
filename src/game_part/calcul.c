/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motroian <motroian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 20:46:36 by motroian          #+#    #+#             */
/*   Updated: 2023/10/09 22:41:08 by motroian         ###   ########.fr       */
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

void	calc(t_data *data)
{
	int		x;
	double	camerax;
	double	raydirx;
	double	raydiry;
	int		mapx;
	int		mapy;
	double	sidedistx;
	double	sidedisty;
	double	deltadistx;
	double	deltadisty;
	double	perpWalldist;
	int		stepx;
	int		stepy;
	int		lineHeight;
	int		drawStart;
	int		drawEnd;
	// int		color;

	x = 0;
	if (data->game.re_buf == 1)
	{
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				data->game.buf[i][j] = 0;
			}
		}
		// data->game.re_buf = 0;
	}
	while (x < width)
	{
		camerax = 2 * x / (double)width - 1;
		raydirx = data->game.dirx + data->game.planex * camerax;
		raydiry = data->game.diry + data->game.planey * camerax;
		mapx = (int)data->game.posx;
		mapy = (int)data->game.posy;
		//length of ray from current position to next x or y-side
		//length of ray from one x or y-side to next x or y-side
		deltadistx = fabs(1 / raydirx);
		deltadisty = fabs(1 / raydiry);
		//what direction to step in x or y-direction (either +1 or -1)
		int hit = 0; //was there a wall hit?
		int side;    //was a NS or a EW wall hit?
		if (raydirx < 0)
		{
			stepx = -1;
			sidedistx = (data->game.posx - mapx) * deltadistx;
		}
		else
		{
			stepx = 1;
			sidedistx = (mapx + 1.0 - data->game.posx) * deltadistx;
		}
		if (raydiry < 0)
		{
			stepy = -1;
			sidedisty = (data->game.posy - mapy) * deltadisty;
		}
		else
		{
			stepy = 1;
			sidedisty = (mapy + 1.0 - data->game.posy) * deltadisty;
		}
		while (hit == 0)
		{
			if (sidedistx < sidedisty)
			{
				sidedistx += deltadistx;
				mapx += stepx;
				side = 0;
			}
			else
			{
				sidedisty += deltadisty;
				mapy += stepy;
				side = 1;
			}
			if (data->map[mapx][mapy] > '0')
				hit = 1;
		}
		if (side == 0)
			perpWalldist = (mapx - data->game.posx + (1 - stepx) / 2) / raydirx;
		else
			perpWalldist = (mapy - data->game.posy + (1 - stepy) / 2) / raydiry;
		lineHeight = (int)(height / perpWalldist);
		drawStart = -lineHeight / 2 + height / 2;
		if (drawStart < 0)
			drawStart = 0;
		drawEnd = lineHeight / 2 + height / 2;
		if (drawEnd >= height)
			drawEnd = height - 1;
		int texNum = 1;

		// calculate value of wallX
		double wallX;
		if (side == 0)
			wallX = data->game.posy + perpWalldist * raydiry;
		else
			wallX = data->game.posx + perpWalldist * raydirx;
		wallX -= floor(wallX);

		// x coordinate on the texture
		int texX = (int)(wallX * (double)texLargeur);
		if (side == 0 && raydirx > 0)
			texX = texLargeur - texX - 1;
		if (side == 1 && raydiry < 0)
			texX = texLargeur - texX - 1;

		// How much to increase the texture coordinate perscreen pixel
		double step = 1.0 * texHauteur / lineHeight;
		// Starting texture coordinate
		double texPos = (drawStart - height / 2 + lineHeight / 2) * step;
		// printf("%d %f %d\n", drawStart, texPos, lineHeight);
		for (int y = drawStart; y < drawEnd; y++)
		{
			// Cast the texture coordinate to integer, and mask with (texHauteur - 1) in case of overflow
			int texY = (int)texPos & (texHauteur - 1);
			texPos += step;
			// printf("%d \n", texNum);
			// printf("%d\n", data->game.texture[texNum][texHauteur * texY + texX]);
			int color = data->game.texture[texNum][texHauteur * texY + texX];
			// make color darker for y-sides: R, G and B byte each divided through two with a "shift" and an "and"
			if (side == 1)
				color = (color >> 1) & 8355711;
			data->game.buf[y][x] = color;
			data->game.re_buf = 1;
		}
		x++;
		// if (data->map[mapx][mapy] == '1')
		// 	color = 0xFF0000;
		// else
		// 	color = 0xFFFF00;
		// if (side == 1)
		// 	color = color / 2;
		// verline(data, 0, drawStart, x, 0x0Cd9F5);
		// verline(data, drawEnd, width, x, 0xFFFFFF);
		// verline(data, drawStart, drawEnd, x, color);
		// x++;
	}
}
