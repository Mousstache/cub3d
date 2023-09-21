/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motroian <motroian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 21:15:33 by motroian          #+#    #+#             */
/*   Updated: 2023/09/21 21:22:45 by motroian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	check_zero(char **map, int x, int y)
{
	if (map[y + 1][x] == 'V')
		return (1);
	if (map[y - 1][x] == 'V')
		return (1);
	if (map[y][x + 1] == 'V')
		return (1);
	if (map[y][x - 1] == 'V')
		return (1);
	return (0);
}

int	check_vide(char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '0')
			{
				if (check_zero(map, x, y) == 1)
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
				|| (map[y][x] != 'S') || (map[y][x] != 'E') || (map[y][x] != 'W') || (map[y][x] != ' ')
				 || (map[y][x] != '\t') )
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

void	get_map(t_data *data, int fd)
{
	int		i;
	char	*str;
	char	*tmp;

	tmp = NULL;
	i = 0;
	str = get_next_line(fd);
	while (str && i <= 5)
	{
		if (check_space(str))
			i++;
		tmp = ft_strjoin(tmp, str);
		free(str);
		str = get_next_line(fd);
	}
	data->setting = ft_split(tmp, '\n');
	free(str);
	free(tmp);
	tmp = NULL;
	str = get_next_line(fd);
	while (*str)
	{
		tmp = ft_strjoin(tmp, str);
		free(str);
		str = get_next_line(fd);
	}
	check_line(data, tmp);
	data->map_jeu = ft_split(tmp, '\n');
	data->map = ft_split(tmp, '\n');
	free(tmp);
}


int	check_fin(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '1' && str[i + 1] == '1' && str[i + 2] == '1' && str[i + 3] == '1')
			return (1);
		i++;
	}
	return (0);
}

int	parsing(t_data *data, int fd)
{
	data->line_bool = 0;
	get_map(data, fd);
	if (data->line_bool == 1)
		return (printf("Error map : ligne vide\n"), 1);
	if (check_setting(data->setting))
		return (printf("Error settings"), free_palestine(data), 1);
	if (!check_map(data->map))
		return (printf("Error map : caractere inconnu\n"), free_palestine(data), 1);
	data->map = reform_map(data->map);
	ft_printtab(data->map);
	if (check_vide(data->map) == 1)
		return (printf("Error map : trou dans la map\n"), free_palestine(data), 1);
	return (0);
}

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
		// free_palestine(&data);
		// close(fd);
	}
	else
		printf("Error nb arguments\n");
}
