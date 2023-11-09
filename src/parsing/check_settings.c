/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_settings.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahouari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 20:58:56 by motroian          #+#    #+#             */
/*   Updated: 2023/11/09 19:31:14 by yahouari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

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

int	get_first_char_pos(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	return (i);
}

int	check_array_settings(t_data *data)
{
	int	i;

	i = 0;
	while (i <= 5)
	{
		if (data->identifier[i] == 0)
			return (0);
		i++;
	}
	return (1);
}

int	fill_settings_array(t_data *data)
{
	int	pos;
	int	i;

	i = -1;
	while (data->set[++i])
	{
		pos = get_first_char_pos(data->set[i]);
		if (data->set[i][pos] == 'N' && data->set[i][pos + 1] == 'O')
			data->identifier[0] = 1;
		else if (data->set[i][pos] == 'S' && data->set[i][pos + 1] == 'O')
			data->identifier[1] = 1;
		else if (data->set[i][pos] == 'W' && data->set[i][pos
				+ 1] == 'E')
			data->identifier[2] = 1;
		else if (data->set[i][pos] == 'E' && data->set[i][pos
				+ 1] == 'A')
			data->identifier[3] = 1;
		else if (data->set[i][pos] == 'F')
			data->identifier[4] = 1;
		else if (data->set[i][pos] == 'C')
			data->identifier[5] = 1;
	}
	if (check_array_settings(data) == 0)
		return (0);
	return (1);
}
