# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rzaccari <rzaccari@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/06 20:10:32 by imorina           #+#    #+#              #
#    Updated: 2023/01/17 20:28:45 by rzaccari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= libft.a

ROOT_DIR	?= $(shell pwd)
SRCS_DIR	= ${ROOT_DIR}/srcs/
SRCS		= $(addprefix ${SRCS_DIR}, ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c \
			ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c \
			ft_strncmp.c ft_strndup.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c \
			ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
			ft_lstnew.c ft_lstadd_front.c ft_lstadd_back.c ft_lstsize.c ft_lstlast.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c \
			get_next_line.c get_next_line_utils.c)			 
OBJS		= ${SRCS:.c=.o};

CC 			= gcc
CFLAGS		= -Wall -Wextra -Werror

RM			= rm -f

AR 			= ar rc

.PHONY: 	all clean fclean re

all:	${NAME}

${NAME}:${OBJS}
		${AR} ${NAME} ${OBJS}

clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}

re:		fclean all
