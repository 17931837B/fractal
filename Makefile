NAME	=	fractol
SRCS	=	main.c utils.c check_julia.c param_utils.c \
	mlx_hook.c draw_fractol.c color_utils.c
OBJS	=	$(SRCS:.c=.o)
CC		=	cc
MLXDIR	= ./minilibx-linux
LIB_MLX	= $(MLXDIR)/libmlx.a
LIBX_FLAGS = $(LIB_MLX) -lXext -lX11 -lm -L/usr/lib -L$(MLXDIR)/obj 

all:		$(NAME)

$(NAME):	$(OBJS)
			$(MAKE) -C minilibx-linux
			$(CC) $(OBJS) $(LIBX_FLAGS) -o $(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

git:
			git clone git@github.com:42Paris/minilibx-linux.git minilibx-linux

re:			fclean all

.PHONY:		all clean fclean re


