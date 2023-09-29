/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_palestine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motroian <motroian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 19:50:27 by motroian          #+#    #+#             */
/*   Updated: 2023/09/29 20:17:45 by motroian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub.h"

int	free_palestine(t_data *data)
{
	close(data->fd);
	free_all(data->setting);
	free_all(data->map);
	free_all(data->map_jeu);
	mlx_clear_window(data->mlx, data->win);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	mlx_loop_end(data->mlx);
	free(data->mlx);
	exit(1);
	return (0);
}
void	ft_printtab(char **str)
{
	for(int i = 0; str[i]; i++)
		printf("%s\n", str[i]);
}
