#ifndef CUB_H
# define CUB_H

# include "../mlx/mlx/mlx.h"
# include "../libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <sys/wait.h>
# define LL_MAX 9223372036854775807UL
# define LL_MIN -9223372036854775807

typedef struct t_data
{
	void	*ptr;
	int		x;
	int		y;
	int		identifier[6];
	int		sol[3];
	int		ciel[3];
	char	**map;
	char	**map_jeu;
	char	**setting;
	int		i;
	int		line_bool;
	                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         
}					t_data;

int		check_name(char *str);
char	*get_next_line(int fd, int boolean);
char	*ft_strjoin2(char *s1, char *s2);
int		ft_strlen2(char *str);
void	ft_printtab(char **str);
void	free_palestine(t_data *data);
char	**reform_map(char **tab);
int		check_map(char **map);
int		check_vide(t_data *data, char **map);
int		parsing(t_data *data, int fd);
int		check_setting(char **str, t_data *data);
int		check_space(char *str);
int		fill_settings_array(char *str, t_data *data);
int		check_perso(t_data *data);



#endif