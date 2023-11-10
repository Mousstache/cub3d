/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motroian <motroian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 21:15:39 by motroian          #+#    #+#             */
/*   Updated: 2023/11/10 18:19:59 by motroian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	check_name(char *str)
{
	int	i;

	i = ft_strlen(str);
	if (str[i - 1] != 'b')
		return (0);
	if (str[i - 2] != 'u')
		return (0);
	if (str[i - 3] != 'c')
		return (0);
	if (str[i - 4] != '.')
		return (0);
	i = i - 5;
	while (str[i])
	{
		if (str[i] == '.')
			return (0);
		i--;
	}
	return (1);
}

int	check_spaceline(char **str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str && str[i])
	{
		if (check_space(str[i]))
			return (1);
		i++;
	}
	return (0);
}

void	get_map(t_data *data, int fd, char *str)
{
	int		i;
	char	*tmp;

	tmp = NULL;
	i = -1;
	while (*str)
	{
		tmp = ft_strjoin2(tmp, str);
		check_line(data, str);
		free(str);
		str = get_next_line(fd, 0);
	}
	while (tmp && tmp[++i])
	{
		if (tmp[i] == '\n' && tmp[i + 1] == '\n')
			data->line_bool = 1;
	}
	data->map = ft_split(tmp, '\n');
	free(tmp);
	get_next_line(fd, 1);
	free(str);
}

void	get_setting(t_data *data, int fd)
{
	int		i;
	char	*str;
	char	*tmp;

	tmp = NULL;
	i = 0;
	str = get_next_line(fd, 0);
	while (*str && i <= 5)
	{
		if (!check_space(str))
		{
			i++;
			tmp = ft_strjoin2(tmp, str);
		}
		free(str);
		str = get_next_line(fd, 0);
	}
	while (str && *str && check_space(str))
	{
		free(str);
		str = get_next_line(fd, 0);
	}
	data->set = ft_split(tmp, '\n');
	free(tmp);
	get_map(data, fd, str);
}

int	parsing(t_data *data, int fd)
{
	t_game	game;

	game = data->game;
	data->line_bool = 0;
	get_setting(data, fd);
	if (!data->map)
		return (printf("Error map : map vide\n"), 1);
	if (data->line_bool == 1)
		return (printf("Error map : ligne vide\n"), 1);
	if (check_spaceline(data->map))
		return (printf("Error map : ligne vide spaceline\n"), 1);
	if (!check_order_settings(data))
		return (printf("Error settings"), 1);
	if (check_map(data->map) == 1)
		return (printf("Error map : caractere inconnu\n"), 1);
	data->map = reform_map(data->map);
	if (check_vide(data->map))
		return (printf("Error map : trou dans la map\n"), 1);
	if (check_perso(data))
		return (printf("Error map : Mauvais nb de perso\n"), 1);
	return (0);
}
