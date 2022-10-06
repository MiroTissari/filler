# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtissari <mtissari@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/20 17:38:03 by mtissari          #+#    #+#              #
#    Updated: 2022/10/05 17:49:29 by mtissari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY := all re clean fclean make
CC := gcc
CFLAGS := -Wall -Wextra -Werror
FILES := coordinates.c heat_map.c main.c map_data.c piece_data.c player_data.c
O_FILES := $(FILES:.c=.o)

T_FILES := coordinates_test.c heat_map_test.c main_test.c map_data_test.c piece_data_test.c player_data_test.c
TEST_OBJECT_FILES := $(T_FILES:.c=.o)

INCLUDES := -I includes/ -I libft/
LIBFT := libft/
NAME := mtissari.filler
S_PATH := sources/
SOURCES := $(addprefix  $(S_PATH), $(FILES))

TEST_SOURCES := $(addprefix  test_sources/, $(T_FILES))

# COLORS

GREEN := \033[0;32m
RED := \033[0;31m
RESET := \033[0m

all: $(NAME)

$(NAME): $(O_FILES)
	$(CC) $(CFLAGS) $(INCLUDES) $(O_FILES) -L$(LIBFT) -lft  -o $(NAME)

test: $(TEST_OBJECT_FILES)
	$(CC) $(CFLAGS) -g -I test_header/ -I libft/ $(TEST_OBJECT_FILES) -L$(LIBFT) -lft -o test_file

$(TEST_OBJECT_FILES):
	@echo "$(NAME): $(GREEN)Creating $(LIBFT) for test...$(RESET)"
	make re -sC $(LIBFT)
	@echo "$(NAME): $(GREEN)Creating Test_file...$(RESET)"
	$(CC) $(CFLAGS) -c $(TEST_SOURCES) -I test_header/ -I libft/ -L$(LIBFT) -lft

$(O_FILES):
	@echo "$(NAME): $(GREEN)Creating $(LIBFT)...$(RESET)"
	@make andclean -sC $(LIBFT)
	$(CC) $(CFLAGS) -c $(SOURCES) $(INCLUDES)  -L$(LIBFT) -lft

#libft:
#	@echo "$(NAME): $(GREEN)Creating $(LIBFT)...$(RESET)"
#	@make re -sC $(LIBFT)


clean:
	@echo "$(NAME): $(RED)deleting object files...$(RESET)"
	rm -f $(O_FILES) $(TEST_OBJECT_FILES)
	@make -sC $(LIBFT) clean
	@echo "$(NAME): $(GREEN)Object files deleted$(RESET)"

fclean: clean
	@echo "$(NAME): $(RED)Deleting the executable...$(RESET)"
	rm -f $(NAME) test_file
	@make -sC $(LIBFT) fclean
	@echo "$(NAME): $(GREEN)Executable file deleted$(RESET)"

re: fclean all

# To launch the game with given players:
#./resources/filler_vm -f resources/maps/map00 -p1 resources/players/abanlin.filler -p2 resources/players/carli.filler
