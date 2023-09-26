SRCS = $(addprefix src/, main.c get_next_line.c  get_next_line_utils.c  check_map.c  free_palestine.c  check_settings.c  reform_map.c  parsing.c)\

NAME = cub3d

INC = -Iinclude

FLAGS = -g3 -Wall -Werror -Wextra

MLX_FLAGS		=	-lm -lXext -lX11

OBJS = ${SRCS:.c=.o}

LIBFT = libft.a

${NAME} : ${OBJS} ${LIBFT}
			make -C libft/ all
			mv libft/libft.a ./
		cc $(OBJS) ${INC} mlx/libmlx.a mlx/libmlx_Linux.a -L. -lXext -L. -lX11 ${FLAGS} -o $(NAME) libft.a

${LIBFT}:
	make -C libft/ all
	mv libft/libft.a ./

all : ${NAME}

%.o:%.c
		cc ${FLAGS} ${INC}  -c $< -o $@

leaks: $(NAME)
	valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes   ./cub3d map.cub

clean :
		make -C ./libft/ clean
		rm -rf ${OBJS}

fclean : clean
		rm -rf ${NAME} ${LIBFT}
		make -C ./libft/ fclean

re : fclean all

.PHONY : all  clean fclean re libft NAME 