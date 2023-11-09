/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_calc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motroian <motroian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 18:45:54 by yahouari          #+#    #+#             */
/*   Updated: 2023/11/09 20:48:43 by motroian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	draw(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			data->game.img.dta[y * WIDTH + x] = data->game.buf[y][x];
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->game.img.img, 0, 0);
}

int	set_rgb(int rgb[3])
{
	return (rgb[0] << 16 | rgb[1] << 8 | rgb[2]);
}

void	ceiling_or_floor(t_data *data, int x, int q)
{
	int	i;
	int	y;

	i = 0;
	if (q == 0)
	{
		while (i < data->game.drawstart && i < HEIGHT)
		{
			data->game.buf[i][x] = set_rgb(data->game.ceiling_colors);
			data->game.re_buf = 1;
			i++;
		}
		return ;
	}
	y = data->game.drawend;
	while (y < HEIGHT)
	{
		data->game.buf[y][x] = set_rgb(data->game.floor_colors);
		data->game.re_buf = 1;
		y++;
	}
}

void	initializebuff(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (++i < HEIGHT)
		while (++j < WIDTH)
			data->game.buf[i][j] = 0;
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
