/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motroian <motroian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 18:21:55 by motroian          #+#    #+#             */
/*   Updated: 2023/10/06 18:22:14 by motroian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void rotate_left(t_data *data)
{
	double oldDirx = data->game.dirx;
	data->game.dirx = data->game.dirx * cos(data->game.rotspeed) - data->game.diry * sin(data->game.rotspeed);
	data->game.diry = oldDirx * sin(data->game.rotspeed) + data->game.diry * cos(data->game.rotspeed);
	double oldPlanex = data->game.planex;
	data->game.planex = data->game.planex * cos(data->game.rotspeed) - data->game.planey * sin(data->game.rotspeed);
	data->game.planey = oldPlanex * sin(data->game.rotspeed) + data->game.planey * cos(data->game.rotspeed);
}

void rotate_right(t_data *data)
{
	double oldDirx = data->game.dirx;
	data->game.dirx = data->game.dirx * cos(-data->game.rotspeed) - data->game.diry * sin(-data->game.rotspeed);
	data->game.diry = oldDirx * sin(-data->game.rotspeed) + data->game.diry * cos(-data->game.rotspeed);
	double oldPlanex = data->game.planex;
	data->game.planex = data->game.planex * cos(-data->game.rotspeed) - data->game.planey * sin(-data->game.rotspeed);
	data->game.planey = oldPlanex * sin(-data->game.rotspeed) + data->game.planey * cos(-data->game.rotspeed);
}
