/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motroian <motroian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 19:59:13 by motroian          #+#    #+#             */
/*   Updated: 2023/10/16 19:09:44 by motroian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	move_up(t_data *data)
{
	char	pos_x;
	char	pos_y;
	int		x;
	int		y;

	x = (int)(data->game.posx + data->game.dirx * data->game.movespeed);
	y = (int)(data->game.posy + data->game.diry * data->game.movespeed);
	pos_x = data->map[x][(int)(data->game.posy)];
	pos_y = data->map[(int)(data->game.posx)][y];
	if (pos_x == '1' || pos_y == '1')
		return (1);
	if (pos_x == '0')
		data->game.posx += data->game.dirx * data->game.movespeed;
	if (pos_y == '0')
		data->game.posy += data->game.diry * data->game.movespeed;
	return (0);
}

void move_down(t_data *data)
{
	if (data->map[(int)(data->game.posx - data->game.dirx * data->game.movespeed)][(int)(data->game.posy)] == '0')
		data->game.posx -= data->game.dirx * data->game.movespeed;
	if (data->map[(int)(data->game.posx)][(int)(data->game.posy - data->game.diry * data->game.movespeed)] == '0')
		data->game.posy -= data->game.diry * data->game.movespeed;
}


void move_left(t_data *data)
{
	if (data->map[(int)(data->game.posx - data->game.diry * data->game.movespeed)][(int)(data->game.posy)] == '0')
		data->game.posx -= data->game.diry * data->game.movespeed;
	if (data->map[(int)(data->game.posx)][(int)(data->game.posy + data->game.dirx * data->game.movespeed)] == '0')
		data->game.posy += data->game.dirx * data->game.movespeed;
}

void move_right(t_data *data)
{
	if (data->map[(int)(data->game.posx + data->game.diry * data->game.movespeed)][(int)(data->game.posy)] == '0')
		data->game.posx += data->game.diry * data->game.movespeed;
	if (data->map[(int)(data->game.posx)][(int)(data->game.posy - data->game.dirx * data->game.movespeed)] == '0')
		data->game.posy -= data->game.dirx * data->game.movespeed;
}
