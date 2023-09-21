/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motroian <motroian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 19:47:49 by motroian          #+#    #+#             */
/*   Updated: 2023/09/21 21:32:56 by motroian         ###   ########.fr       */
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

char *fill_string(char *str, int len)
{
	int i;
	int j;
	char *new;

	i = 0;
	j = 0;
	new = malloc(sizeof(char) * len + 1);
	if (!new)
		return (NULL);
	while (str[i])
	{
		if (str[i] == ' ')
			new[j] = 'V';
		else 
			new[j] = str[i];
		i++;
		j++;
	}
	while (j < len)
		new[j++] = 'V';
	new[j] = 0;
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
	j = 0;
	new = malloc(sizeof(char *) * (count_string(tab) + 1));
	if (!new)
		return (NULL);
	while (tab[i])
	{
		new[j] = fill_string(tab[i], get_max_length(tab));
		i++;
		j++;
	}
	new[j] = NULL;
	if (tab)
		free_alll(tab);
	return (new);
}
