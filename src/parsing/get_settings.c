/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_settings.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahouari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 21:48:23 by yahouari          #+#    #+#             */
/*   Updated: 2023/11/09 20:13:58 by yahouari         ###   ########.fr       */
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
	if (!tab)
		return (0);
	while (i < 4)
	{
		pos = get_first_char_pos(tab[i]) + 2;
		while (tab[i][pos] && tab[i][pos] != '.')
		{
			if (tab[i][pos] != ' ' && tab[i][pos] != '\t')
				return (0);
			pos++;
		}
		i++;
	}
	return (1);
}

int	check_order_setting2(t_data *data, int i)
{
	int	pos;

	pos = get_first_char_pos(data->set[i]);
	if (data->set[i] && data->set[i][pos] == 'N')
		data->game.paths[i] = reform_string(data->set[i], 2, pos);
	else if (data->set[i] && data->set[i][pos] == 'S')
		data->game.paths[i] = reform_string(data->set[i], 2, pos);
	else if (data->set[i] && data->set[i][pos] == 'W')
		data->game.paths[i] = reform_string(data->set[i], 2, pos);
	else if (data->set[i] && data->set[i][pos] == 'E')
		data->game.paths[i] = reform_string(data->set[i], 2, pos);
	else if (data->set[i][pos] == 'F')
		i += 0;
	else if (data->set[i][pos] == 'C')
		i += 0;
	else
		return (0);
	return (1);
}

int	check_order_settings(t_data *data)
{
	int	i;

	i = -1;
	if (!check_only_id(data->set))
		return (0);
	while (++i < 6)
	{
		if (!check_order_setting2(data, i))
			return (0);
	}
	if (!get_colors_settings(data))
			return (0);
	if (!fill_settings_array(data))
		return (0);
	return (1);
}
