# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rchmouk <rchmouk@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/22 14:19:23 by rchmouk           #+#    #+#              #
#    Updated: 2023/01/28 09:47:34 by rchmouk          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address
RM = rm -f
SRC = pipex.c ft_split.c ft_strlen.c ft_putstr.c ft_calloc.c ft_strlcpy.c ft_strjoin.c pipex_util.c \

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME): $(OBJ)
	cc $(CFLAGS) $(SRC) -o $(NAME)
	
clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
 	