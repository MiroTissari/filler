# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtissari <mtissari@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/20 17:38:03 by mtissari          #+#    #+#              #
#    Updated: 2022/10/17 16:56:13 by mtissari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY := all re clean fclean make

# COMPILING:
CC := gcc
CFLAGS := -Wall -Wextra -Werror

# SOURCES:
FILES := coordinates.c heat_map.c main.c map_data.c piece_data.c player_data.c \
		init.c
S_PATH := sources/
SOURCES := $(addprefix $(S_PATH), $(FILES))

#INCLUDES:
INCLUDES := -I includes/ -I libft/
LIBFT := libft/
LIB := libft/libft.a
LINKER := -L libft -lft

#OBJECTS:
O_FILES := $(FILES:.c=.o)
NAME := mtissari.filler

# COLORS
BLUEB :=  \033[1;34m
PURPLEB := \033[1;95m
GREEN := \033[0;32m
RED := \033[0;31m
YELLOW := \033[0;93m
YELLOWB := \033[1;93m
RESET := \033[0m

all: $(NAME)

$(NAME): $(LIB) $(O_FILES)
	@$(CC) $(CFLAGS) $(INCLUDES) $(O_FILES) $(LINKER) -o $(NAME)
	@echo "$(GREEN)The executable: $(PURPLEB)$(NAME)$(GREEN) created!$(RESET)"

$(LIB):
	@echo "$(YELLOWB)Creating $(LIB)...$(RESET)"
	@make re -sC $(LIBFT)

%.o: $(S_PATH)%.c
	@$(CC) $(CFLAGS) -c $(INCLUDES) $< -o $@
	@echo "$(GREEN)Created $(BLUEB)$(@)$(RESET)"

clean:
	@rm -f $(O_FILES)
	@make -sC $(LIBFT) clean
	@echo "$(YELLOWB)Libft$(YELLOW) cleaned$(RESET)"
	@echo "$(BLUEB)Object files$(RED) deleted$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@make -sC $(LIBFT) fclean
	@echo "$(GREEN)$(PURPLEB)$(NAME) $(RED)deleted$(RESET)"

re: fclean all
