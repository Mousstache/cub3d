/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motroian <motroian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 19:59:13 by motroian          #+#    #+#             */
/*   Updated: 2023/10/06 20:05:57 by motroian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"


void	move_up(t_data *data)
{
	if (data->map[(int)(data->game.posx + data->game.dirx * data->game.movespeed)][(int)(data->game.posy)])
		data->game.posx += data->game.dirx * data->game.movespeed;
	if (data->map[(int)(data->game.posx)][(int)(data->game.posy + data->game.diry * data->game.movespeed)])
		data->game.posy += data->game.diry * data->game.movespeed;
}

void move_down(t_data *data)
{
	if (data->map[(int)(data->game.posx - data->game.dirx * data->game.movespeed)][(int)(data->game.posy)])
		data->game.posx -= data->game.dirx * data->game.movespeed;
	if (data->map[(int)(data->game.posx)][(int)(data->game.posy - data->game.diry * data->game.movespeed)])
		data->game.posy -= data->game.diry * data->game.movespeed;
}

void move_left(t_data *data)
{
	if (data->map[(int)(data->game.posx - data->game.diry * data->game.movespeed)][(int)(data->game.posy)])
		data->game.posx -= data->game.diry * data->game.movespeed;
	if (data->map[(int)(data->game.posx)][(int)(data->game.posy + data->game.dirx * data->game.movespeed)])
		data->game.posy += data->game.dirx * data->game.movespeed;
}

void move_right(t_data *data)
{
	if (data->map[(int)(data->game.posx + data->game.diry * data->game.movespeed)][(int)(data->game.posy)])
		data->game.posx += data->game.diry * data->game.movespeed;
	if (data->map[(int)(data->game.posx)][(int)(data->game.posy - data->game.dirx * data->game.movespeed)])
		data->game.posy -= data->game.dirx * data->game.movespeed;
}
