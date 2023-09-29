/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motroian <motroian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 21:15:33 by motroian          #+#    #+#             */
/*   Updated: 2023/09/29 20:19:30 by motroian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	graphic_part(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		exit(EXIT_FAILURE);
	data->win = mlx_new_window(data->mlx, 1200, 800, "le cuvub");
	mlx_hook(data->win, 17, 0, &free_palestine, data);
	mlx_loop(data->mlx);
}

int main (int ac, char **av)
{
	if (ac == 2)
	{
		int	fd;
		t_data	data;

		if (!check_name(av[1]))
			return (printf("Error: nom de fichier\n"), 1);
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
			return (0);
		if (parsing(&data, fd))
			return (close(fd), free_palestine(&data), 1);
		close(fd);
		graphic_part(&data);
		free_palestine(&data);
		close(fd);
	}
	else
		printf("Error nb arguments\n");
}
