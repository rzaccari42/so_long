NAME = so_long

SRCS = srcs/main.c
OBJS = $(SRCS:.c=.o)

PATH_MLX = includes/mlx/
MLX = mlx.a
MLXFLAGS = -I $(PATH_MLX) -L $(PATH_MLX) -lmlx -Ilmlx -lXext -lX11

CC = gcc
OPTIONS = -c
CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -Imlx $(OPTIONS) $(<) -o $(<:.c=.o)

$(NAME): $(OBJS)
	@echo objects done!!
	@make -C $(PATH_MLX)
	@$(CC) $(CFLAGS) $(MLXFLAGS) $(PATH_SRC)so_long.c $(OBJS) $(MLX) -o so_long
	@echo program done!

clean:
	$(RM) -f $(OBJS)

fclean: clean
	$(RM) -f $(CLIENT)


re: fclean all

.PHONY: re fclean clean all libft
