#ifndef CUB_H
# define CUB_H

# include "../libft/libft.h"
# include "../mlx/mlx/mlx.h"
# include <math.h>
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
#define width 640
#define height 480


typedef struct t_game
{
	double	posx;
	double	posy;
	double	dirx;
	double	diry;
	double	planex;
	double	planey;
	void	*mlx;
	void	*win;
	double	movespeed;
	double	rotspeed;
	char	**map_jeu;
} 	t_game;

typedef struct t_data
{
	char	dir;
	int		pos[2];
	void	*mlx;
	void	*win;
	int		fd;
	int		identifier[6];
	int		sol[3];
	int		ciel[3];
	char	**map;
	char	**setting;
	int		i;
	int		line_bool;
	t_game	game;
}	t_data;

int			check_name(char *str);
char		*get_next_line(int fd, int boolean);
char		*ft_strjoin2(char *s1, char *s2);
int			ft_strlen2(char *str);
void		ft_printtab(char **str);
int			free_palestine(t_data *data);
char		**reform_map(char **tab);
int			check_map(char **map);
int			check_vide(char **map);
int			parsing(t_data *data, int fd);
int			check_setting(char **str, t_data *data);
int			check_space(char *str);
int			fill_settings_array(char *str, t_data *data);
int			check_perso(t_data *data);

void		calc(t_data *data);
int			key_press(int key, t_data *data);



#endif