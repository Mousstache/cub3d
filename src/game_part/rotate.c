/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahouari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 18:21:55 by motroian          #+#    #+#             */
/*   Updated: 2023/10/26 22:09:29 by yahouari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	rotate_left(t_data *data)
{
	double	olddirx;
	double	oldplanex;

	olddirx = data->game.dirx;
	data->game.dirx = data->game.dirx * cos(data->game.rotspeed)
		- data->game.diry * sin(data->game.rotspeed);
	data->game.diry = olddirx * sin(data->game.rotspeed) + data->game.diry
		* cos(data->game.rotspeed);
	oldplanex = data->game.planex;
	data->game.planex = data->game.planex * cos(data->game.rotspeed)
		- data->game.planey * sin(data->game.rotspeed);
	data->game.planey = oldplanex * sin(data->game.rotspeed) + data->game.planey
		* cos(data->game.rotspeed);
}

void	rotate_right(t_data *data)
{
	double	olddirx;
	double	oldplanex;

	olddirx = data->game.dirx;
	data->game.dirx = data->game.dirx * cos(-data->game.rotspeed)
		- data->game.diry * sin(-data->game.rotspeed);
	data->game.diry = olddirx * sin(-data->game.rotspeed) + data->game.diry
		* cos(-data->game.rotspeed);
	oldplanex = data->game.planex;
	data->game.planex = data->game.planex * cos(-data->game.rotspeed)
		- data->game.planey * sin(-data->game.rotspeed);
	data->game.planey = oldplanex * sin(-data->game.rotspeed)
		+ data->game.planey * cos(-data->game.rotspeed);
}
