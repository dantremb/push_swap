# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dantremb <dantremb@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/02 23:33:38 by root              #+#    #+#              #
#    Updated: 2022/07/08 13:22:28 by dantremb         ###   ########.fr        #
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
	@printf "$R■$W"
	@$(CC) $(CFLAGS) -c $< -o $@
	
# Bonus Sources files
SRCS_FILES_BONUS = checker.c \
			check_list.c \
			stack_moves.c \
			stack_push.c \
			sort_stack.c \
			sort_utils.c \
			initialisation.c \
			stack_moves_bonus.c
SRCS_BONUS = $(addprefix $S, $(SRCS_FILES_BONUS))

# Bonus Objects conversion
OBJS_BONUS = $(SRCS_BONUS:$S%=$O%.o)
$O%.o: $S%
	@printf "$R■$W"
	@$(CC) $(CFLAGS) -c $< -o $@

# Main rule
all: signature init $(NAME)
	@echo "$G\n$(NAME) Compiled!$W"

# Bonus rule
bonus: signature_bonus init_bonus $(NAME_BONUS)
	@echo "$G\n$(NAME_BONUS) Compiled!$W"
	
# Initialise librairies and making objs folder
init:
	@mkdir -p $O
	@echo "$GLibrary's initialization$W"
	@$(MAKE) -s -C $(LIBFT_PATH)
	@printf "$CCreating $(NAME)\n$W"

# Initialise bonus librairies and making bonus objs folder
init_bonus:
	@mkdir -p $O
	@echo "$GLibrary's initialization$W"
	@$(MAKE) -s -C $(LIBFT_PATH)
	@printf "$CCreating $(NAME_BONUS)\n$W"

# Creating bonus executable
$(NAME_BONUS): $(OBJS_BONUS)
	@$(CC) $(CFLAGS) -o $@ $^ $(LIBFT)

# Creating  executable
$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $@ $^ $(LIBFT)

# Cleaning/
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

R = $(shell tput -Txterm setaf 1)
G = $(shell tput -Txterm setaf 2)
C = $(shell tput -Txterm setaf 6)
W = $(shell tput -Txterm setaf 7)

signature:
	@echo "\n$G+---+---+---+---+---+---+---+---+"
	@echo "$G|$C	$(NAME) by Dantremb	$G|"
	@echo "$G+---+---+---+---+---+---+---+---+"

signature_bonus:
	@echo "\n$G+---+---+---+---+---+---+---+---+"
	@echo "$G|$C	$(NAME_BONUS) by Dantremb	$G|"
	@echo "$G+---+---+---+---+---+---+---+---+"
