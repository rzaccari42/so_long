NAME = so_long

SRCS = srcs/main.c
OBJS = $(SRCS:.c=.o)

MLXFLAGS = -Lmlx -lmlx -framework OpenGL -framework Appkit

CC = gcc
OPTIONS = -c
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address

RM = rm -rf

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -Imlx $(OPTIONS) $(<) -o $(<:.c=.o)

$(NAME): $(OBJS)
	@echo objects done!!
	@$(CC) $(CFLAGS) $(MLXFLAGS) $(OBJS) $(MLX) -o $(NAME)
	@echo program done!

clean:
	$(RM) -f $(OBJS)

fclean: clean
	$(RM) -f $(CLIENT)


re: fclean all

.PHONY: re fclean clean all libft
