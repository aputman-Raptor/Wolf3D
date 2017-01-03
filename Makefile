# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aputman <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/09 16:38:05 by aputman           #+#    #+#              #
#    Updated: 2017/01/03 13:41:50 by aputman          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = wolf3d

SRC =	wolf3d.c\
		mlx.c\
		keycode.c\
		getmap.c\
		color.c\
		raycast.c

OBJ = $(addprefix $(OBJDIR), $(SRC:.c=.o))

SRCDIR = ./src/
OBJDIR = ./obj/
INCDIR = ./includes/

LIB = ./libft/libft.a
LIBLINK = -L./libft -lft

CFLAGS = -Wall -Wextra -Werror -Ofast
GFLAGS = -lmlx -framework Appkit -framework OpenGL

all: obj $(NAME)

obj:
	@mkdir $(OBJDIR)

$(OBJDIR)%.o: $(SRCDIR)%.c
	@make -C libft
	@$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

$(NAME): $(OBJ)
	@$(CC) $(LIBLINK) -o $(NAME) $(OBJ) $(GFLAGS)
	@echo "Project successfully builded"

clean:
	@make clean -C libft
	@rm -rf $(OBJDIR)

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
