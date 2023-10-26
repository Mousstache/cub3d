/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahouari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 20:46:36 by motroian          #+#    #+#             */
/*   Updated: 2023/10/26 22:18:26 by yahouari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	boucle_a_caca(t_data *data, int x, int texNum, int texX)
{
	double	step;
	double	texpos;
	int		texy;
	int		color;
	int		y;

	y = data->game.drawstart;
	step = 1.0 * texHauteur / data->game.lineHeight;
	texpos = (data->game.drawstart - height / 2 + data->game.lineHeight / 2)
		* step;
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

void	init_values(t_data *data, int x)
{
	double	camerax;

	if (data->game.side == 0)
		data->game.perpWalldist = (data->game.mapx - data->game.posx + (1
					- data->game.stepx) / 2) / data->game.raydirx;
	else
		data->game.perpWalldist = (data->game.mapy - data->game.posy + (1
					- data->game.stepy) / 2) / data->game.raydiry;
	camerax = 2 * x / (double)width - 1;
	data->game.raydirx = data->game.dirx + data->game.planex * camerax;
	data->game.raydiry = data->game.diry + data->game.planey * camerax;
	data->game.mapx = (int)data->game.posx;
	data->game.mapy = (int)data->game.posy;
	data->game.deltadistx = fabs(1 / data->game.raydirx);
	data->game.deltadisty = fabs(1 / data->game.raydiry);
}

void	define_draw(t_data *data)
{
	data->game.lineHeight = (int)(height / data->game.perpWalldist);
	data->game.drawstart = -data->game.lineHeight / 2 + height / 2;
	if (data->game.drawstart < 0)
		data->game.drawstart = 0;
	data->game.drawend = data->game.lineHeight / 2 + height / 2;
	if (data->game.drawend >= height || data->game.drawend < 0)
		data->game.drawend = height - 1;
}

void	define_wallx(t_data *data, double *wallx, int *texnum, int x)
{
	init_values(data, x);
	define(&data->game);
	define_side(data);
	define_draw(data);
	*texnum = choose_texture(data, *texnum);
	if (data->game.side == 0)
		*wallx = data->game.posy + data->game.perpWalldist * data->game.raydiry;
	else
		*wallx = data->game.posx + data->game.perpWalldist * data->game.raydirx;
}

void	calc(t_data *data)
{
	double	wallx;
	int		x;
	int		texnum;
	int		texx;

	x = 0;
	initializebuff(data);
	while (x < width)
	{
		define_wallx(data, &wallx, &texnum, x);
		wallx -= floor(wallx);
		texx = (int)(wallx * (double)texLargeur);
		if (data->game.side == 0 && data->game.raydirx > 0)
			texx = texLargeur - texx - 1;
		if (data->game.side == 1 && data->game.raydiry < 0)
			texx = texLargeur - texx - 1;
		boucle_a_caca(data, x, texnum, texx);
		ceiling_or_floor(data, x, 0);
		ceiling_or_floor(data, x, 1);
		x++;
	}
}
