/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reform_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motroian <motroian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 19:47:49 by motroian          #+#    #+#             */
/*   Updated: 2023/10/11 19:06:46 by motroian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	get_max_length(char **tab)
{
	int tmp;
	int i;

	tmp = 0;
	i = 0;
	while (tab[i])
	{
		if (ft_strlen(tab[i]) > (size_t)tmp)
			tmp = ft_strlen(tab[i]);
		i++;
	}
	return (tmp);
}

// void	get_settings(t_data *data)
// {
// 	int i;

// 	i = 0;
// 	while (data->setting[i])
// 	{
// 		if (data->setting[i][0] == 'C')
// 		else if (data->setting[i][0] == 'F')
// 		else
// 	}
// }

char *fill_string(char *str, int len)
{
	int i;
	int j;
	char *new;

	i = 0;
	j = 1;
	new = malloc(sizeof(char) * len + 3);
	if (!new)
		return (NULL);
	new[0] = 'V';
	while (str && str[i])
	{
		if (str[i] == ' ')
			new[j] = 'V';
		else 
			new[j] = str[i];
		i++;
		j++;
	}
	while (j <= len)
		new[j++] = 'V';
	new[j] = 'V';
	new[j + 1] = 0;
	return (new);
}

int	count_string(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

char **reform_map(char **tab)
{
	int i;
	int j;
	char **new;

	i = 0;
	j = 1;
	new = malloc(sizeof(char *) * (count_string(tab) + 3));
	if (!new)
		return (NULL);
	new[0] = fill_string(NULL, get_max_length(tab));
	while (tab[i])
	{
		new[j] = fill_string(tab[i], get_max_length(tab));
		i++;
		j++;
	}
	new[j] = fill_string(NULL, get_max_length(tab));
	new[j + 1] = NULL;
	if (tab)
		free_all(tab);
	return (new);
}
