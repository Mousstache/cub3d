/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motroian <motroian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 19:59:13 by motroian          #+#    #+#             */
/*   Updated: 2023/10/04 22:10:50 by motroian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	key_press(int key, t_data *data)
{
	printf("keypres\n");
	if (key == 'w')
	{
		if (!data->game.map_jeu[(int)(data->game.posx + data->game.dirx * data->game.movespeed)][(int)(data->game.posy)])
			data->game.posx += data->game.dirx * data->game.movespeed;
		if (!data->game.map_jeu[(int)(data->game.posx)][(int)(data->game.posy + data->game.diry * data->game.movespeed)])
			data->game.posy += data->game.diry * data->game.movespeed;
	}
	//move backwards if no wall behind you
	if (key == 's')
	{
		if (!data->game.map_jeu[(int)(data->game.posx + data->game.dirx * data->game.movespeed)][(int)(data->game.posy)])
			data->game.posx -= data->game.dirx * data->game.movespeed;
		if (!data->game.map_jeu[(int)(data->game.posx)][(int)(data->game.posy + data->game.diry * data->game.movespeed)])
			data->game.posy -= data->game.diry * data->game.movespeed;
	}
	if (key == 'a')
	{
		if (!data->game.map_jeu[(int)(data->game.posx - data->game.dirx * data->game.movespeed)][(int)(data->game.posy)])
			data->game.posx -= data->game.diry * data->game.movespeed;
		if (!data->game.map_jeu[(int)(data->game.posx)][(int)(data->game.posy + data->game.dirx * data->game.movespeed)])
			data->game.posy += data->game.dirx * data->game.movespeed;
	}
	if (key == 'd')
	{
		if (!data->game.map_jeu[(int)(data->game.posx + data->game.diry * data->game.movespeed)][(int)(data->game.posy)])
			data->game.posx += data->game.diry * data->game.movespeed;
		if (!data->game.map_jeu[(int)(data->game.posx)][(int)(data->game.posy - data->game.dirx * data->game.movespeed)])
			data->game.posy -= data->game.dirx * data->game.movespeed;
	}
	//rotate to the right
	if (key == 65363)
	{
		//both camera direction and camera plane must be rotated
		double oldDirx = data->game.dirx;
		data->game.dirx = data->game.dirx * cos(-data->game.rotspeed) - data->game.diry * sin(-data->game.rotspeed);
		data->game.diry = oldDirx * sin(-data->game.rotspeed) + data->game.diry * cos(-data->game.rotspeed);
		double oldPlanex = data->game.planex;
		data->game.planex = data->game.planex * cos(-data->game.rotspeed) - data->game.planey * sin(-data->game.rotspeed);
		data->game.planey = oldPlanex * sin(-data->game.rotspeed) + data->game.planey * cos(-data->game.rotspeed);
	}
	//rotate to the left
	if (key == 65361)
	{
		//both camera direction and camera plane must be rotated
		double oldDirx = data->game.dirx;
		data->game.dirx = data->game.dirx * cos(data->game.rotspeed) - data->game.diry * sin(data->game.rotspeed);
		data->game.diry = oldDirx * sin(data->game.rotspeed) + data->game.diry * cos(data->game.rotspeed);
		double oldPlanex = data->game.planex;
		data->game.planex = data->game.planex * cos(data->game.rotspeed) - data->game.planey * sin(data->game.rotspeed);
		data->game.planey = oldPlanex * sin(data->game.rotspeed) + data->game.planey * cos(data->game.rotspeed);
	}
	if (key == 65307 || key == 113)
		exit(1);
	return (0);
}