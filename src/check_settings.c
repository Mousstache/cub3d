/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_settings.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motroian <motroian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 20:58:56 by motroian          #+#    #+#             */
/*   Updated: 2023/09/26 23:28:31 by motroian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	init_identifier(t_data *data)
{
	data->identifier[0] = 0;
	data->identifier[1] = 0;
	data->identifier[2] = 0;
	data->identifier[3] = 0;
	data->identifier[4] = 0;
	data->identifier[5] = 0;
}

int get_first_char_pos(char *str)
{
	int i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	return (i);
}

int	check_array_settings(t_data *data)
{
	int i;

	i = 0;
	while (i <= 5)
	{
		if (data->identifier[i] == 0)
			return (1);
		i++;
	}
	return (0);
}

int		fill_settings_array(char *str, t_data *data)
{
	int pos;

	pos = get_first_char_pos(str);
	if (str[pos] == 'N' && str[pos + 1] == 'O')
		data->identifier[0] = 1;
	else if (str[pos] == 'S' && str[pos + 1] == 'O')
		data->identifier[1] = 1;
	else if (str[pos] == 'W' && str[pos + 1] == 'E')
		data->identifier[2] = 1;
	else if (str[pos] == 'E' && str[pos + 1] == 'A')
		data->identifier[3] = 1;
	else if (str[pos] == 'F')
		data->identifier[4] = 1;
	else if (str[pos] == 'C')
		data->identifier[5] = 1;
	return (1);
}

int	check_setting(char **str, t_data *data)
{
	int	i;

	i = 0;
	init_identifier(data);
	while (str[i])
	{
		fill_settings_array(str[i], data);
		i++;
	}
	if (check_array_settings(data) == 1)
		return (1);
	return (0);
}
