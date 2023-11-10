SRCS =	src/parsing/parsing.c \
		src/parsing/get_settings.c \
		src/parsing/get_settings_colors.c \
		src/parsing/check_map.c \
		src/parsing/check_settings.c \
		src/parsing/reform_map.c \
		src/parsing/get_next_line.c \
		src/parsing/get_next_line_utils.c \
		src/game_part/move.c \
		src/game_part/calcul.c \
		src/game_part/utils_calc.c \
		src/game_part/rotate.c \
		src/game_part/graphics.c \
		src/game_part/graphic_utils.c \
		src/main.c \
		src/free_palestine.c \

NAME = cub3D

INC = -Iinclude

FLAGS = -g3 -Wall -Werror -Wextra

MLX_FLAGS		=	-lm -lXext -lX11

OBJS = ${SRCS:.c=.o}

LIBFT = libft.a

${NAME} : ${OBJS} ${LIBFT}
			make -C libft/ all
			mv libft/libft.a ./
		cc $(OBJS) ${INC} mlx/libmlx.a mlx/libmlx_Linux.a -L. -lXext -L. -lX11 -lm ${FLAGS} -o $(NAME) libft.a

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