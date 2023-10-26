#ifndef CUB_H
# define CUB_H

# include "../libft/libft.h"
# include "../mlx/mlx/mlx.h"
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <sys/wait.h>
# define LL_MAX 9223372036854775807UL
# define LL_MIN -9223372036854775807
# define width 1680
# define height 680
# define texLargeur 64
# define texHauteur 64

typedef struct s_img
{
	void	*img;
	int		*dta;
	int		size_l;
	int		bpp;
	int		endian;
	int		img_width;
	int		img_height;
}			t_img;

typedef struct t_game
{
	int		**buf;
	int		re_buf;
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
	int		floor_colors[3];
	int		ceiling_colors[3];
	char	*paths[4];
	int		**texture;
	double	raydirx;
	double	raydiry;
	int		mapx;
	int		mapy;
	double	sidedistx;
	double	sidedisty;
	double	deltadistx;
	double	deltadisty;
	int		stepx;
	int		stepy;
	int		lineHeight;
	double	perpWalldist;
	int		drawstart;
	int		drawend;
	int		side;
	t_img	img;
}			t_game;

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
}			t_data;

int			get_first_char_pos(char *str);
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
int			check_setting(char **str);
int			check_order_settings(t_data *data);
int			get_colors_settings(t_data *data);
int			get_first_char_pos(char *str);
int			check_space(char *str);
int			fill_settings_array(char **str, t_data *data);
int			check_perso(t_data *data);
void		calc(t_data *data);
int			key_press(int key, t_data *data);
int			graphic_part(t_data *data);
void		verline(t_data *data, int start, int end, int x, int color);
void		rotate_left(t_data *data);
void		rotate_right(t_data *data);
void		move_up(t_data *data);
void		move_down(t_data *data);
void		move_left(t_data *data);
void		move_right(t_data *data);
void		draw(t_data *data);
void		ceiling_or_floor(t_data *data, int x, int q);
int			ft_isspace(char c);
int			check_virgule(char *str);
void		check_line(t_data *data, char *str);
int			check_space(char *str);
void		draw(t_data *data);
int			set_rgb(int rgb[3]);
void		ceiling_or_floor(t_data *data, int x, int q);
void		initializebuff(t_data *data);
void		define(t_game *game);
int			choose_texture(t_data *data, int texNum);
void		load_image(t_data *data, int *texture, char *path, t_img *img);
void		load_texture(t_data *data);
void	define_side(t_data *data);

#endif