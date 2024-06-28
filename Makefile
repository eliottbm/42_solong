# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebengtss <ebengtss@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/13 11:16:00 by ebengtss          #+#    #+#              #
#    Updated: 2024/06/28 16:30:55 by ebengtss         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS 		+=	--no-print-directory

NAME			=	so_long

LIBFT			=	libft
LIBMLX			=	libmlx

CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror -I

LIBMLX_DIR		=	minilibx-linux
SRCS_DIR		=	srcs/
INCS_DIR		=	incs

SRCS_FILES		=	main.c			\
					map_check.c		\
					map_valid.c		\
					map_data.c		\
					handle_inputs.c

SRCS			=	$(addprefix $(SRCS_DIR), $(SRCS_FILES))

DEF_COLOR		=	\033[0;39m
MAGENTA			=	\033[0;95m
GREEN			=	\033[0;92m
DEF_WEIGHT		=	\e[0m
BOLD_WEIGHT		=	\e[1m

all				:	$(NAME)

$(NAME)			:
	@make -C $(LIBMLX_DIR)
	@mv $(LIBMLX_DIR)/$(LIBMLX).a ./
	@make -C $(LIBFT)
	@mv $(LIBFT)/$(LIBFT).a ./
	@$(CC) -o $(NAME) $(CFLAGS) $(INCS_DIR) $(SRCS) -L. -lft -L. -lmlx -lX11 -lXext
	@echo "$(BOLD_WEIGHT)[SOLONG]$(DEF_WEIGHT) make: $(GREEN)OK$(DEF_COLOR)"

clean			:
	@make clean -C $(LIBMLX_DIR)
	@make clean -C $(LIBFT)
	@rm -f $(LIBFT).a $(LIBMLX).a
	@echo "$(BOLD_WEIGHT)[SOLONG]$(DEF_WEIGHT) clean: $(GREEN)OK$(DEF_COLOR)"

fclean			:	clean
	@rm -f $(NAME)
	@echo "$(BOLD_WEIGHT)[SOLONG]$(DEF_WEIGHT) fclean: $(GREEN)OK$(DEF_COLOR)"

re				:	fclean all

.PHONY			:	all clean fclean re