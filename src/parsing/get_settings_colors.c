/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_settings_colors.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahouari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 20:08:38 by yahouari          #+#    #+#             */
/*   Updated: 2023/11/09 19:37:17 by yahouari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	check_colors_settings2(t_data *data, int i, int j, int k)
{
	if (!check_virgule(data->set[i]))
		return (0);
	while (data->set[i][j])
	{
		while (data->set[i][j] && ft_isspace(data->set[i][j]))
			j++;
		if (ft_isdigit(data->set[i][j]))
		{
			k++;
			while (data->set[i][j] && ft_isdigit(data->set[i][j]))
				j++;
		}
		while (data->set[i][j] && ft_isspace(data->set[i][j]))
			j++;
		if (k < 3 && data->set[i][j++] == ',')
			continue ;
		else if (k == 3 && data->set[i][j] == 0)
			return (1);
		else
			return (0);
	}
	return (1);
}

int	check_colors_settings(t_data *data)
{
	int	i;
	int	j;
	int	k;

	i = 4;
	while (i < 6)
	{
		k = 0;
		j = 1;
		if (!check_colors_settings2(data, i, j, k))
			return (0);
		i++;
	}
	return (1);
}

int	fill_colors_array(char **str, char **str1, t_data *data)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (str[i])
			data->game.floor_colors[i] = ft_atoi(str[i]);
		else
			return (free_all(str), free_all(str1), 0);
		i++;
	}
	i = 0;
	while (i < 3)
	{
		if (str[i])
			data->game.ceiling_colors[i] = ft_atoi(str1[i]);
		else
			return (free_all(str), free_all(str1), 0);
		i++;
	}
	free_all(str);
	free_all(str1);
	return (1);
}

int	check_digit_colors(int *tab)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (tab[i] > 255 || tab[i] < 0)
			return (0);
		i++;
	}
	return (1);
}

int	get_colors_settings(t_data *data)
{
	if (!check_colors_settings(data))
		return (0);
	if (!fill_colors_array(ft_split(data->set[4] + 1, ','),
			ft_split(data->set[5] + 1, ','), data))
		return (0);
	if (!check_digit_colors(data->game.floor_colors)
		|| !check_digit_colors(data->game.ceiling_colors))
		return (0);
	return (1);
}
