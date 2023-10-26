/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_settings_colors.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahouari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 20:08:38 by yahouari          #+#    #+#             */
/*   Updated: 2023/10/26 18:18:54 by yahouari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	check_colors_settings2(t_data *data, int i, int j, int k)
{
	if (!check_virgule(data->setting[i]))
		return (0);
	while (data->setting[i][j])
	{
		while (data->setting[i][j] && ft_isspace(data->setting[i][j]))
			j++;
		if (ft_isdigit(data->setting[i][j]))
		{
			k++;
			while (data->setting[i][j] && ft_isdigit(data->setting[i][j]))
				j++;
		}
		while (data->setting[i][j] && ft_isspace(data->setting[i][j]))
			j++;
		if (k < 3 && data->setting[i][j++] == ',')
			continue ;
		else if (k == 3 && data->setting[i][j] == 0)
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
	if (!fill_colors_array(ft_split(data->setting[4] + 1, ','),
			ft_split(data->setting[5] + 1, ','), data))
		return (0);
	if (!check_digit_colors(data->game.floor_colors)
		|| !check_digit_colors(data->game.ceiling_colors))
		return (0);
	return (1);
}
