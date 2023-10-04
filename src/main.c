/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motroian <motroian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 21:15:33 by motroian          #+#    #+#             */
/*   Updated: 2023/10/04 22:13:37 by motroian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	main_loop(t_data *data)
{
	calc(data);
	return (0);
}

void	graphic_part(t_data *data)
{
	data->game.posx = 12;
	data->game.posy = 5;
	data->game.dirx = -1;
	data->game.diry = 0;
	data->game.planex = 0;
	data->game.planey = 0.66;
	data->game.movespeed = 0.05;
	data->game.rotspeed = 0.05;
	data->mlx = mlx_init();
	if (!data->mlx)
		exit(EXIT_FAILURE);
	data->win = mlx_new_window(data->mlx, width, height, "le cuvub");
	mlx_hook(data->win, 0, 1L << 0, &key_press, data);
	mlx_hook(data->win, 17, 0, &free_palestine, data);
	mlx_key_hook(data->win, &key_press, data);
	mlx_loop_hook(data->mlx, &main_loop, data);
	mlx_loop(data->mlx);
}

int main (int ac, char **av)
{
	if (ac == 2)
	{
		int	fd;
		t_data	data = {0};

		if (!check_name(av[1]))
			return (printf("Error: nom de fichier\n"), 1);
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
			return (0);
		if (parsing(&data, fd))
			return (close(fd), free_palestine(&data), 1);
		close(fd);
		data.game.dirx = -1;
		data.game.diry = 0;
		data.game.planex = 0;
		data.game.planey = 0.66;
		graphic_part(&data);
		free_palestine(&data);
		close(fd);
	}
	else
		printf("Error nb arguments\n");
}
