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
CFLAGS := -Wall -Wextra -Werror
#FILES := coordinates.c heat_map.c main.c map_data.c piece_data.c player_data.c
T_FILES := coordinates.c heat_map.c main_test.c map_data_test.c piece_data_test.c player_data_test.c
O_FILES := $(FILES:.c=.o)
TEST_O_FILES := $(T_FILES:.c=.o)
INCLUDES := -I includes/ -I libft/
LIBFT := libft/
NAME := mtissari.filler
S_PATH := sources/
SOURCES := $(addprefix  $(S_PATH), $(FILES))
TEST_SOURCES := $(addprefix  $(S_PATH), $(T_FILES))

# COLORS

GREEN := \033[0;32m
RED := \033[0;31m
RESET := \033[0m

all: $(NAME)

$(NAME): $(O_FILES)
	$(CC) $(CFLAGS) $(INCLUDES) $(O_FILES) -L$(LIBFT) -lft  -o $(NAME)

test: $(TEST_O_FILES)
	$(CC) $(CFLAGS) $(INCLUDES) $(TEST_O_FILES) -L$(LIBFT) -lft  -o test_file

$(TEST_O_FILES):
	@echo "$(NAME): $(GREEN)Creating $(LIBFT)...$(RESET)"
	make re -sC $(LIBFT)
	@echo "$(NAME): $(GREEN)Creating Test_file...$(RESET)"
	$(CC) $(CFLAGS) -c $(TEST_SOURCES) $(INCLUDES)  -L$(LIBFT) -lft

$(O_FILES):
	@echo "$(NAME): $(GREEN)Creating $(LIBFT)...$(RESET)"
	make andclean -sC $(LIBFT)
	$(CC) $(CFLAGS) -c $(SOURCES) $(INCLUDES)  -L$(LIBFT) -lft

#libft:
#	@echo "$(NAME): $(GREEN)Creating $(LIBFT)...$(RESET)"
#	@make re -sC $(LIBFT)


clean:
	@rm -f $(O_FILES) $(TEST_O_FILES) test_file
	@make -sC $(LIBFT) clean

fclean: clean
	rm -f $(NAME)
	@make -sC $(LIBFT) fclean

re: fclean all

# To launch the game with given players:
#./filler_vm -f maps/map00 -p1 players/abanlin.filler -p2 players/carli.filler
