# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtissari <mtissari@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/20 17:38:03 by mtissari          #+#    #+#              #
#    Updated: 2022/09/20 17:38:04 by mtissari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY := all re clean fclean make
CC := gcc
CFLAGS := -Wall -Wextra -Werror -c
FILES := main.c map_data.c player_data.c
O_FILES := $(FILES:.c=.o)
INCLUDES := -I includes
LIBFT := libft
NAME := mtissari.filler
S_PATH := sources/
SOURCES := $(addprefix  $(S_PATH), $(FILES))

all: $(NAME)

$(NAME):

clean:
	@rm -f $(O_FILES) debug
	@make -C $(LIBFT) clean

fclean: clean
	rm -f $(NAME)
	@make -C $(LIBFT) fclean

re: fclean all

# To launch the game with given players:
#./filler_vm -f maps/map00 -p1 players/abanlin.filler -p2 players/carli.filler
