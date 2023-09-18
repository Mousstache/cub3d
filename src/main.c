/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motroian <motroian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 21:15:33 by motroian          #+#    #+#             */
/*   Updated: 2023/09/18 23:25:35 by motroian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	check_zero(char **map, int x, int y)
{
	if (map[y + 1][x] == ' ')
		return (1);
	if (map[y - 1][x] == ' ')
		return (1);
	if (map[y][x + 1] == ' ')
		return (1);
	if (map[y][x - 1] == ' ')
		return (1);
	return (0);
}

int	check_vide(char **map)
{
	int	y;
	int	x;

	x = 0;
	y = 0;
	while (map)
	{
		while (map[y][x])
		{
			if (map[y][x] == '0')
			{
				if (!check_zero(map, x, y))
					return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	check_map(char **map)
{
	int	y;
	int	x;

	x = 0;
	y = 0;

	while (map)
	{
		while (map[y][x])
		{
			if ((map[y][x] != '1') || (map[y][x] != '0') || (map[y][x] != 'N')
				|| (map[y][x] != 'S') || (map[y][x] != 'E') || (map[y][x] != 'W'))
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

int	check_space(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == ' ' || str[i] == '\t')
			return (1);
		i++;
	}
	return (0);
}

int	check_setting(char **str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str && str[i] && j <= 6)
	{
		if (!check_space(str[i]))
			j++;
		i++;
	}
	return (0);
}

void	get_map(t_data *data, int fd)
{
	int		i;
	char	*str;
	char	*tmp;

	tmp = NULL;
	i = 0;
	str = get_next_line(fd);
	while (str && str[i])
	{
		tmp = ft_strjoin(tmp, str);
		free(str);
		str = get_next_line(fd);
	}
	data->map = ft_split(tmp, '\n');
	free(tmp);
}
// void	split_map(char **map)
// {
// 	data->map = ;
// }

int	parsing(t_data *data, int fd)
{
	get_map(data, fd);
	split_map(data->map);
	if (check_setting(data->map))
		return (printf("Error settings"), free(data->map), 1);
	if (check_map(data->map))
		return (printf("Error map\n"), free(data->map), 1);
	if (check_vide(data->map))
		return (printf("Error map\n"), free(data->map), 1);
	return (0);
}

int main (int ac, char **av)
{
	if (ac == 2)
	{
		int	fd;
		t_data	*data;

		data = ft_calloc(sizeof(t_data), 1);
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
			return (0);
		if (!parsing(data, fd))
			return (printf("Error dans la map\n"));
		// printf("%p\n", data->map);
		// for(int i = 0; data->map[i]; i++)
			// printf("%s\n", data->map[i]);
	}
	else
		printf("Error nb arguments\n");
}
