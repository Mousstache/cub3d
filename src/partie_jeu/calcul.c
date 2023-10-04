/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motroian <motroian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 20:46:36 by motroian          #+#    #+#             */
/*   Updated: 2023/10/04 21:58:32 by motroian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	verline(t_data *data, int start, int end, int x, int color)
{
	// printf("[%d %d %d]\n", start,end,x);
	while (start <= end)
	{
		mlx_pixel_put(data->mlx, data->win, x, start++, color);
		// printf("%d\n", w);
	}

}

void	calc(t_data *data)
{
	int	x;

	x = 0;
	while (x < width)
	{
		// printf("%f\n", data->game.dirx);
		double camerax = 2 * x / (double)width - 1;
		double raydirx = data->game.dirx + data->game.planex * camerax;
		double raydiry = data->game.diry + data->game.planey * camerax;
		
		int mapx = (int)data->game.posx;
		int mapy = (int)data->game.posy;

		// printf("%d\n", data->game.posx);
		//length of ray from current position to next x or y-side
		double sidedistx;
		double sidedisty;
		
		 //length of ray from one x or y-side to next x or y-side
		double deltadistx = fabs(1 / raydirx);
		double deltadisty = fabs(1 / raydiry);
		double perpWalldist;
		
		//what direction to step in x or y-direction (either +1 or -1)
		int stepx;
		int stepy;
		
		int hit = 0; //was there a wall hit?
		int side; //was a NS or a EW wall hit?

		// printf("%f\n", raydirx);
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
			//jump to next map square, OR in x-direction, OR in y-direction
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
			//Check if ray has hit a wall
			if (data->map[mapx][mapy] > '0')
				hit = 1;
		}
		if (side == 0)
			perpWalldist = (mapx - data->game.posx + (1 - stepx) / 2) / raydirx;
		else
			perpWalldist = (mapy - data->game.posy + (1 - stepy) / 2) / raydiry;
		// printf("%f %i %f %i %f\n", perpWalldist, mapy, data->game.posy, stepy, raydiry);
		//Calculate height of line to draw on screen
		int lineHeight = (int)(height / perpWalldist);
		//calculate lowest and highest pixel to fill in current stripe
		int drawStart = -lineHeight / 2 + height / 2;
		// printf("%d\n", lineHeight);
		if(drawStart < 0)
			drawStart = 0;
		int drawEnd = lineHeight / 2 + height / 2;
		if(drawEnd >= height)
			drawEnd = height - 1;
		int	color;
		if (data->map[mapy][mapx] == '1')
			color = 0xFF0000;
		else
			color = 0xFFFF00;
		
		if (side == 1)
			color = color / 2;
		// int w = 0;
		// w++;
		verline(data, 0, drawStart, x, 0x0Cd9F5);
		verline(data, drawEnd, width, x, 0xFFFFFF);
		verline(data, drawStart, drawEnd, x, color);
		x++;
	}
}
