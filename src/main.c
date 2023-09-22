/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motroian <motroian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 21:15:33 by motroian          #+#    #+#             */
/*   Updated: 2023/09/22 18:19:39 by motroian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int main (int ac, char **av)
{
	if (ac == 2)
	{
		int	fd;
		t_data	data;

		fd = open(av[1], O_RDONLY);
		if (fd == -1)
			return (0);
		if (!parsing(&data, fd))
			return (close(fd), 1);
		free_palestine(&data);
		close(fd);
	}
	else
		printf("Error nb arguments\n");
}
