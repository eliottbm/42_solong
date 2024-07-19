# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebengtss <ebengtss@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/13 11:16:00 by ebengtss          #+#    #+#              #
#    Updated: 2024/07/19 12:49:55 by ebengtss         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS 		+=	--no-print-directory

NAME			=	so_long

LIBFT			=	libft
LIBMLX			=	libmlx

LIBFT_A			=	$(LIBFT).a
LIBMLX_A		=	$(LIBMLX).a

CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror -I

LIBFT_DIR		=	libft
LIBMLX_DIR		=	minilibx-linux
SRCS_DIR		=	srcs/
OBJS_DIR		=	objs/
INCS_DIR		=	incs
SBONUS_DIR		=	srcs_bonus/
OBONUS_DIR		=	objs_bonus/
IBONUS_DIR		=	incs_bonus

SRCS_FILES		=	main.c			\
					map_check.c		\
					map_make.c		\
					map_valid.c		\
					map_data.c		\
					handle_inputs.c	\
					mlx_imgs.c		\
					mlx_win.c		\
					mlx_free.c		\
					map_imgs.c		\
					handle_dirs.c	\
					so_long_utils.c

SBONUS_FILES	=	main_bonus.c			\
					map_check_bonus.c		\
					map_make_bonus.c		\
					map_valid_bonus.c		\
					map_data_bonus.c		\
					handle_inputs_bonus.c	\
					mlx_imgs_bonus.c		\
					mlx_win_bonus.c			\
					mlx_free_bonus.c		\
					map_imgs_bonus.c		\
					handle_dirs_bonus.c		\
					so_long_utils_bonus.c

SRCS			=	$(addprefix $(SRCS_DIR), $(SRCS_FILES))
OBJS			=	$(addprefix $(OBJS_DIR), $(SRCS_FILES:.c=.o))
SBONUS			=	$(addprefix $(SBONUS_DIR), $(SBONUS_FILES))
OBONUS			=	$(addprefix $(OBONUS_DIR), $(SBONUS_FILES:.c=.o))

DEF_COLOR		=	\033[0;39m
MAGENTA			=	\033[0;95m
GREEN			=	\033[0;92m
DEF_WEIGHT		=	\e[0m
BOLD_WEIGHT		=	\e[1m

OBJSF			=	.objs_exists
OBJSF_BONUS		=	.objs_bonus_exists

all				:	$(NAME)

$(NAME)			:	$(OBJS) $(LIBMLX_A) $(LIBFT_A)
	@$(CC) -o $(NAME) $(CFLAGS) $(INCS_DIR) $(OBJS) -L. -lft -L. -lmlx -lX11 -lXext
	@echo "$(BOLD_WEIGHT)[SOLONG]$(DEF_WEIGHT) make: $(GREEN)OK$(DEF_COLOR)"

bonus		:	fclean $(OBONUS) $(LIBMLX_A) $(LIBFT_A)
	@$(CC) -o $(NAME) $(CFLAGS) $(INCS_DIR) $(OBONUS) -L. -lft -L. -lmlx -lX11 -lXext
	@echo "$(BOLD_WEIGHT)[SOLONG]$(DEF_WEIGHT) make bonus: $(GREEN)OK$(DEF_COLOR)"

$(LIBMLX_A)	:
	@make -C $(LIBMLX_DIR)
	@mv $(LIBMLX_DIR)/$(LIBMLX_A) ./

$(LIBFT_A)	:
	@make -C $(LIBFT_DIR)
	@mv $(LIBFT)/$(LIBFT_A) ./

$(OBJS_DIR)%.o	:	$(SRCS_DIR)%.c | $(OBJSF)
	@$(CC) $(CFLAGS) $(INCS_DIR) -c $< -o $@
	@echo "$(BOLD_WEIGHT)[SOLONG]$(DEF_WEIGHT) compiling: $(MAGENTA) $< $(DEF_COLOR)"

$(OBONUS_DIR)%.o	:	$(SBONUS_DIR)%.c | $(OBJSF_BONUS)
	@$(CC) $(CFLAGS) $(IBONUS_DIR) -c $< -o $@
	@echo "$(BOLD_WEIGHT)[SOLONG]$(DEF_WEIGHT) compiling: $(MAGENTA) $< $(DEF_COLOR)"

$(OBJSF)	:
	@mkdir -p $(OBJS_DIR)

$(OBJSF_BONUS)	:
	@mkdir -p $(OBONUS_DIR)

clean			:
	@rm -rf $(OBJS_DIR)
	@rm -rf $(OBONUS_DIR)
	@make clean -C $(LIBMLX_DIR)
	@make clean -C $(LIBFT)
	@rm -f $(LIBFT_A) $(LIBMLX_A)
	@echo "$(BOLD_WEIGHT)[SOLONG]$(DEF_WEIGHT) clean: $(GREEN)OK$(DEF_COLOR)"

fclean			:	clean
	@rm -f $(NAME)
	@echo "$(BOLD_WEIGHT)[SOLONG]$(DEF_WEIGHT) fclean: $(GREEN)OK$(DEF_COLOR)"

re				:	fclean all

.PHONY			:	all bonus clean fclean re