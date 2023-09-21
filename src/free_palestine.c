/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_palestine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motroian <motroian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 19:50:27 by motroian          #+#    #+#             */
/*   Updated: 2023/09/21 20:20:21 by motroian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub.h"

void	free_palestine(t_data *data)
{
	free_all(data->map);
	free_all(data->setting);
}
void	ft_printtab(char **str)
{
	for(int i = 0; str[i]; i++)
		printf("%s\n", str[i]);
}
