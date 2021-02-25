CC = clang

NAME = Cub3D

FLAGS = -Wall -Werror -Wextra -lm -lbsd -lX11 -lXext -fsanitize=address

INCLUDE = -I cub3d.h

LIB =  minilibx-linux/libmlx_Linux.a

SRCS =	game/main.c game/heart.c game/bmp.c game/exit.c\
		utils/ft_atoi.c utils/ft_bzero.c utils/ft_calloc.c utils/mmalloc.c utils/ft_isspace.c utils/ft_memmove.c utils/ft_putchar.c\
		utils/ft_putstr.c utils/ft_strdup.c utils/ft_strlen.c utils/ft_split.c\
		utils/get_next_line_utils.c utils/get_next_line.c\
		parsing/parse_info.c parsing/create_map.c parsing/parse_map.c parsing/parse_textures_res.c parsing/colors.c parsing/parse_sprite.c\
		raycast/raycasting.c raycast/move.c raycast/draw.c raycast/textures.c raycast/sprite.c raycast/sort_sprite.c

OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS) 
			@$(MAKE) -C ./minilibx-linux
			@rm -rf Cub3D
			@clang -o $(NAME) $(INCLUDE) $(OBJS) $(LIB) $(FLAGS)
	
all : $(NAME)

clean :
		rm -f $(OBJS)
		$(MAKE) clean -C ./minilibx-linux
		
fclean : clean
		rm -f $(NAME)
		
re : fclean all
