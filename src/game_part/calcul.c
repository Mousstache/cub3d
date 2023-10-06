/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motroian <motroian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 20:46:36 by motroian          #+#    #+#             */
/*   Updated: 2023/10/06 20:07:18 by motroian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

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
	int		color;

	x = 0;
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
		if (data->map[mapy][mapx] == '1')
			color = 0xFF0000;
		else
			color = 0xFFFF00;
		if (side == 1)
			color = color / 2;
		verline(data, 0, drawStart, x, 0x0Cd9F5);
		verline(data, drawEnd, width, x, 0xFFFFFF);
		verline(data, drawStart, drawEnd, x, color);
		x++;
	}
}
