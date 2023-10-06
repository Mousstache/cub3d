/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_settings.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motroian <motroian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 21:48:23 by yahouari          #+#    #+#             */
/*   Updated: 2023/10/06 21:05:14 by motroian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

char	*reform_string(char *str, int to_pass, int pos)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = pos + to_pass;
	new = malloc(sizeof(char) * ft_strlen(str));
	while (str[j] == ' ' || str[j] == '\t')
		j++;
	while (str[j])
	{
		new[i] = str[j];
		i++;
		j++;
	}
	new[i] = 0;
	return (new);
}

int	check_only_id(char **tab)
{
	int	i;
	int	pos;

	i = 0;
	while (i < 4)
	{
		pos = get_first_char_pos(tab[i]) + 2;
		while (tab[i][pos] && tab[i][pos] != '.')
		{
			if (tab[i][pos] != ' ' && tab[i][pos] != '\t')
			{
				printf("LE ->%c", tab[i][pos]);
				return (0);
			}
			pos++;
		}
		i++;
	}
	return (1);
}

int	check_order_settings(t_data *data)
{
	int	i;
	int	pos;

	i = -1;
	if (!check_only_id(data->setting))
		return (0);
	while (++i < 6)
	{
		pos = get_first_char_pos(data->setting[i]);
		if (i == 0 && data->setting[i] && data->setting[i][pos] == 'N')
			data->game.paths[i] = reform_string(data->setting[i], 2, pos);
		else if (i == 1 && data->setting[i] && data->setting[i][pos] == 'S')
			data->game.paths[i] = reform_string(data->setting[i], 2, pos);
		else if (i == 2 && data->setting[i] && data->setting[i][pos] == 'W')
			data->game.paths[i] = reform_string(data->setting[i], 2, pos);
		else if (i == 3 && data->setting[i] && data->setting[i][pos] == 'E')
			data->game.paths[i] = reform_string(data->setting[i], 2, pos);
		else if (i == 4 && data->setting[i][pos] == 'F')
			i += 0;
		else if (i == 5 && data->setting[i][pos] == 'C')
			get_colors_settings(data);
		else
			return (0);
	}
	return (1);
}

// int	ft_isspace(char c)
// {
// 	if (c == ' ' || c == '\t')
// 		return (1);
// 	return (0);
// }


// int	check_colors_settings2(t_data *data, int i, int j, int k)
// {
// 	while (data->setting[i][j])
// 	{
// 		while (data->setting[i][j] && ft_isspace(data->setting[i][j]))
// 			j++;
// 		if (ft_isdigit(data->setting[i][j]))
// 		{
// 			k++;
// 			while (data->setting[i][j] && ft_isdigit(data->setting[i][j]))
// 				j++;
// 		}
// 		while (data->setting[i][j] && ft_isspace(data->setting[i][j]))
// 			j++;
// 		if (k < 3 && data->setting[i][j++] == ',')
// 			continue ;
// 		else if (k == 3 && data->setting[i][j] == 0)
// 		{
// 			printf("caca\n");
// 			return (1);
// 		}	
// 		else
// 			return (0);
// 	}
// 	return (1);
// }

// int	check_colors_settings(t_data *data)
// {
// 	int	i;
// 	int	j;
// 	int	k;

// 	i = 4;
// 	while (i < 6)
// 	{
// 		k = 0;
// 		j = 1;
// 		if (!check_colors_settings2(data, i, j, k))
// 			return (0);
// 		i++;
// 	}
// 	return (1);
// }

// int	fill_colors_array(char **str, char **str1, t_data *data)
// {
// 	int	i;

// 	i = 0;
// 	while (i < 3)
// 	{
// 		if (str[i])
// 			data->settings->floor_colors[i] = ft_atoi(str[i]);
// 		else
// 			return (free_all(str), free_all(str1), 0);
// 		i++;
// 	}
// 	i = 0;
// 	while (i < 3)
// 	{
// 		if (str[i])
// 			data->settings->ceiling_colors[i] = ft_atoi(str1[i]);
// 		else
// 			return (free_all(str), free_all(str1), 0);
// 		i++;
// 	}
// 	free_all(str);
// 	free_all(str1);
// 	return (1);
// }

// int	get_colors_settings(t_data *data)
// {
// 	if (!check_colors_settings(data))
// 		return (printf("cest pas bon morray"));
// 	if (!fill_colors_array(ft_split(data->setting[4] + 1, ','),
// 							ft_split(data->setting[5] + 1, ','),
// 							data))
// 		return (printf("cest pas bon pelo"));
// 	return (1);
// }
