#ifndef CUB_H
# define CUB_H

# include "../mlx/mlx/mlx.h"
# include "../libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
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
	char	**map;
	char	**setting;
	char	**fichier;
	int i;
	                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         
}					t_data;

char	*get_next_line(int fd);
char	*ft_strjoin2(char *s1, char *s2);
int		ft_strlen2(char *str);



#endif