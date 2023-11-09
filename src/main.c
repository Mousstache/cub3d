/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahouari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 21:15:33 by motroian          #+#    #+#             */
/*   Updated: 2023/11/09 19:40:46 by yahouari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	check_space(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

void	check_line(t_data *data, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n' && str[i + 1] == '\n')
			data->line_bool = 1;
		i++;
	}
}

int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

int	check_virgule(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == ',')
			count++;
		i++;
	}
	if (count > 2)
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	int				fd;
	static t_data	data = {0};

	if (ac == 2)
	{
		if (!check_name(av[1]))
			return (printf("Error: nom de fichier\n"), 1);
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
			return (printf("Erreur lors de l'ouverture de la map\n"), 0);
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
		return (printf("Error nb arguments\n"), 2);
	return (0);
}
