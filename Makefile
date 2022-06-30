# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dantremb <dantremb@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/02 23:33:38 by root              #+#    #+#              #
#    Updated: 2022/06/30 15:05:38 by dantremb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nom du Projet
NAME = push_swap
NAME_BONUS = checker

# Flags
AR = ar
CC = gcc
ARFLAGS = rcs
CFLAGS = -Wall -Wextra -Werror -g

# Includes
LIBFT = includes/libft/libft.a
LIBFT_PATH = includes/libft/

# Sources files
S = srcs/
SRCS_FILES = push_swap.c \
			check_list.c \
			stack_moves.c \
			stack_push.c \
			sort_stack.c \
			sort_utils.c \
			initialisation.c	
SRCS = $(addprefix $S, $(SRCS_FILES))

# Objects conversion
O = objs/
OBJS= $(SRCS:$S%=$O%.o)
$O%.o: $S%
	@printf "-"
	@$(CC) $(CFLAGS) -c $< -o $@
	
# Bonus Sources files
SRCS_FILES_BONUS = checker.c \
			check_list.c \
			stack_moves.c \
			stack_push.c \
			sort_stack.c \
			sort_utils.c \
			initialisation.c	
SRCS_BONUS = $(addprefix $S, $(SRCS_FILES_BONUS))

# Bonus Objects conversion
OBJS_BONUS = $(SRCS_BONUS:$S%=$O%.o)
$O%.o: $S%
	@printf "-"
	@$(CC) $(CFLAGS) -c $< -o $@

# Main rule
all: init $(NAME)
	@echo "> Done!."
	@echo "$(NAME) Compiled!"

# Bonus rule
bonus: init $(NAME_BONUS)
	@echo "> Done!."
	@echo "$(NAME) Compiled!"
	
# Initialise librairies and making objs folder
init:
	@mkdir -p $O
	@echo "Initialise Libft"
	@$(MAKE) -s -C $(LIBFT_PATH)
	@echo "Initialise $(NAME)"
	@printf "Compiling "

# Creating checker executable
$(NAME_BONUS): $(OBJS_BONUS)
	@$(CC) $(CFLAGS) -o $@ $^ $(LIBFT)

# Creating push_swap executable
$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $@ $^ $(LIBFT)

# Cleaning
REMOVE = rm -rf

clean:
	@$(REMOVE) $O
	@$(MAKE) -s clean -C $(LIBFT_PATH)

fclean: clean
	@$(REMOVE) $(NAME)
	@$(REMOVE) $(NAME_BONUS)
	@$(MAKE) -s fclean -C $(LIBFT_PATH)

re:	fclean all

# Utilities
COMMIT = $(shell date "+%d %B %T")
git:
	@git add .
	@git commit -m "$(COMMIT)"
	@git push
