/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahouari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 21:15:33 by motroian          #+#    #+#             */
/*   Updated: 2023/10/06 22:00:40 by yahouari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int main(int ac, char **av)
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
		if (parsing(&data, fd) || !check_order_settings(&data))
		{
			printf("Error\n");
			return (close(fd), free_palestine(&data), 1);
		}
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
