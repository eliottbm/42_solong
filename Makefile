# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebengtss <ebengtss@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/13 11:16:00 by ebengtss          #+#    #+#              #
#    Updated: 2024/07/26 13:33:06 by ebengtss         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS 			+=	--no-print-directory

NAME				=	so_long
NAME_BONUS			=	so_long_bonus

LIBFT				=	libft
LIBMLX				=	libmlx

LIBFT_A				=	$(LIBFT).a
LIBMLX_A			=	$(LIBMLX).a

CC					=	cc
CFLAGS				=	-Wall -Wextra -Werror -I

LIBFT_DIR			=	libft
LIBMLX_DIR			=	minilibx-linux
SRCS_DIR			=	srcs/
OBJS_DIR			=	objs/
INCS_DIR			=	incs
SRCS_DIR_BONUS		=	srcs_bonus/
OBJS_DIR_BONUS		=	objs_bonus/
INCS_DIR_BONUS		=	incs_bonus

SRCS_FILES			=	main.c					\
						map_check.c				\
						map_make.c				\
						map_valid.c				\
						map_data.c				\
						handle_inputs.c			\
						mlx_imgs.c				\
						mlx_win.c				\
						mlx_free.c				\
						map_imgs.c				\
						handle_dirs.c			\
						so_long_utils.c

SRCS_FILES_BONUS	=	main_bonus.c			\
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

OBJS				=	$(addprefix $(OBJS_DIR), $(SRCS_FILES:.c=.o))
OBJS_BONUS			=	$(addprefix $(OBJS_DIR_BONUS), $(SRCS_FILES_BONUS:.c=.o))

DEF_COLOR			=	\033[0;39m
GREEN				=	\033[0;92m
MAGENTA				=	\033[0;35m
DEF_STYLE			=	\e[0m
BOLD_OPACITY		=	\e[1m\e[2m
RESET_LINE			=	\033[A\033[K

OBJSF				=	.objs_exists
OBJSF_BONUS			=	.objs_bonus_exists

all					:	$(NAME)
bonus				:	$(NAME_BONUS)

$(NAME)				:	$(LIBMLX_A) $(LIBFT_A) $(OBJS)
	@echo "$(RESET_LINE)$(BOLD_OPACITY)[ SO_LONG ]$(DEF_STYLE)	compiling:	$(GREEN) ✔ $(DEF_COLOR)"
	@$(CC) -o $(NAME) $(CFLAGS) $(INCS_DIR) $(OBJS) $(LIBFT_A) $(LIBMLX_A) -L. -lX11 -lXext
	@echo "$(BOLD_OPACITY)[ SO_LONG ]$(DEF_STYLE)	make:		$(GREEN) ✔ $(DEF_COLOR)"

$(NAME_BONUS)		:	$(LIBMLX_A) $(LIBFT_A) $(OBJS_BONUS)
	@echo "$(RESET_LINE)$(BOLD_OPACITY)[ SO_LONG ]$(DEF_STYLE)	compiling:	$(GREEN) ✔ $(DEF_COLOR)"
	@$(CC) -o $(NAME_BONUS) $(CFLAGS) $(INCS_DIR) $(OBJS_BONUS) $(LIBFT_A) $(LIBMLX_A) -L. -lX11 -lXext
	@echo "$(BOLD_OPACITY)[ SO_LONG ]$(DEF_STYLE)	bonus:		$(GREEN) ✔ $(DEF_COLOR)"

$(LIBMLX_A)			:
	@make -C $(LIBMLX_DIR)
	@mv $(LIBMLX_DIR)/$(LIBMLX_A) ./

$(LIBFT_A)			:
	@make -C $(LIBFT_DIR)
	@mv $(LIBFT)/$(LIBFT_A) ./

$(OBJS_DIR)%.o		:	$(SRCS_DIR)%.c | $(OBJSF)
	@$(CC) $(CFLAGS) $(INCS_DIR) -c $< -o $@
	@echo "$(RESET_LINE)$(BOLD_OPACITY)[ SO_LONG ]$(DEF_STYLE)	compiling:	$(GREEN) $< $(DEF_COLOR)"

$(OBJS_DIR_BONUS)%.o:	$(SRCS_DIR_BONUS)%.c | $(OBJSF_BONUS)
	@$(CC) $(CFLAGS) $(INCS_DIR_BONUS) -c $< -o $@
	@echo "$(RESET_LINE)$(BOLD_OPACITY)[ SO_LONG ]$(DEF_STYLE)	compiling:	$(GREEN) $< $(DEF_COLOR)"

$(OBJSF)			:
	@echo "$(BOLD_OPACITY)[ SO_LONG ]$(DEF_STYLE)	nothing to do"
	@mkdir -p $(OBJS_DIR)

$(OBJSF_BONUS)		:
	@echo "$(BOLD_OPACITY)[ SO_LONG ]$(DEF_STYLE)	nothing to do"
	@mkdir -p $(OBJS_DIR_BONUS)

clean				:
	@rm -rf $(OBJS_DIR)
	@rm -rf $(OBJS_DIR_BONUS)
	@make clean -C $(LIBMLX_DIR)
	@make clean -C $(LIBFT)
	@rm -f $(LIBFT_A) $(LIBMLX_A)
	@echo "$(BOLD_OPACITY)[ SO_LONG ]$(DEF_STYLE)	clean:		$(GREEN) ✔ $(DEF_COLOR)"

fclean				:	clean
	@rm -f $(NAME)
	@rm -f $(NAME_BONUS)
	@echo "$(BOLD_OPACITY)[ SO_LONG ]$(DEF_STYLE)	fclean:		$(GREEN) ✔ $(DEF_COLOR)"

runtest				:	all
	@echo "$(BOLD_OPACITY)[ SO_LONG ]$(DEF_STYLE)	running test ..."
	@echo "$(BOLD_OPACITY)[ SO_LONG ]$(DEF_STYLE)	$(MAGENTA)testing non existing $(DEF_COLOR)"
	-valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(NAME) maps/ceee.ber
	@echo "\n\n$(BOLD_OPACITY)[ SO_LONG ]$(DEF_STYLE)	$(MAGENTA)testing invalid border $(DEF_COLOR)"
	-valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(NAME) maps/border_err.ber
	@echo "\n\n$(BOLD_OPACITY)[ SO_LONG ]$(DEF_STYLE)	$(MAGENTA)testing cutted $(DEF_COLOR)"
	-valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(NAME) maps/cutted_err.ber
	@echo "\n\n$(BOLD_OPACITY)[ SO_LONG ]$(DEF_STYLE)	$(MAGENTA)testing empty $(DEF_COLOR)"
	-valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(NAME) maps/empty_err.ber
	@echo "\n\n$(BOLD_OPACITY)[ SO_LONG ]$(DEF_STYLE)	$(MAGENTA)testing wrong extension $(DEF_COLOR)"
	-valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(NAME) maps/extension_err.ber
	@echo "\n\n$(BOLD_OPACITY)[ SO_LONG ]$(DEF_STYLE)	$(MAGENTA)testing invalid char $(DEF_COLOR)"
	-valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(NAME) maps/invalidchar_err.ber
	@echo "\n\n$(BOLD_OPACITY)[ SO_LONG ]$(DEF_STYLE)	$(MAGENTA)testing missing char $(DEF_COLOR)"
	-valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(NAME) maps/lesschar_err.ber
	@echo "\n\n$(BOLD_OPACITY)[ SO_LONG ]$(DEF_STYLE)	$(MAGENTA)testing line lenght $(DEF_COLOR)"
	-valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(NAME) maps/line_err.ber
	@echo "\n\n$(BOLD_OPACITY)[ SO_LONG ]$(DEF_STYLE)	$(MAGENTA)testing too large $(DEF_COLOR)"
	-valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(NAME) maps/toolarge_err.ber
	@echo "\n\n$(BOLD_OPACITY)[ SO_LONG ]$(DEF_STYLE)	$(MAGENTA)testing without env $(DEF_COLOR)"
	-env -i valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(NAME) maps/classic.ber
	@echo "\n\n$(BOLD_OPACITY)[ SO_LONG ]$(DEF_STYLE)	$(MAGENTA)testing working $(DEF_COLOR)"
	-valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(NAME) maps/classic.ber
	@echo "\n"

runtestbonus		:	bonus
	@echo "$(BOLD_OPACITY)[ SO_LONG ]$(DEF_STYLE)	running bonus test ..."
	@echo "$(BOLD_OPACITY)[ SO_LONG ]$(DEF_STYLE)	$(MAGENTA)bonus testing non existing $(DEF_COLOR)"
	-valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(NAME_BONUS) maps/ceee.ber
	@echo "\n\n$(BOLD_OPACITY)[ SO_LONG ]$(DEF_STYLE)	$(MAGENTA)bonus testing invalid border $(DEF_COLOR)"
	-valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(NAME_BONUS) maps/border_err.ber
	@echo "\n\n$(BOLD_OPACITY)[ SO_LONG ]$(DEF_STYLE)	$(MAGENTA)bonus testing cutted $(DEF_COLOR)"
	-valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(NAME_BONUS) maps/cutted_err.ber
	@echo "\n\n$(BOLD_OPACITY)[ SO_LONG ]$(DEF_STYLE)	$(MAGENTA)bonus testing empty $(DEF_COLOR)"
	-valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(NAME_BONUS) maps/empty_err.ber
	@echo "\n\n$(BOLD_OPACITY)[ SO_LONG ]$(DEF_STYLE)	$(MAGENTA)bonus testing wrong extension $(DEF_COLOR)"
	-valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(NAME_BONUS) maps/extension_err.ber
	@echo "\n\n$(BOLD_OPACITY)[ SO_LONG ]$(DEF_STYLE)	$(MAGENTA)bonus testing invalid char $(DEF_COLOR)"
	-valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(NAME_BONUS) maps/invalidchar_err.ber
	@echo "\n\n$(BOLD_OPACITY)[ SO_LONG ]$(DEF_STYLE)	$(MAGENTA)bonus testing missing char $(DEF_COLOR)"
	-valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(NAME_BONUS) maps/lesschar_err.ber
	@echo "\n\n$(BOLD_OPACITY)[ SO_LONG ]$(DEF_STYLE)	$(MAGENTA)bonus testing line lenght $(DEF_COLOR)"
	-valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(NAME_BONUS) maps/line_err.ber
	@echo "\n\n$(BOLD_OPACITY)[ SO_LONG ]$(DEF_STYLE)	$(MAGENTA)bonus testing too large $(DEF_COLOR)"
	-valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(NAME_BONUS) maps/toolarge_err.ber
	@echo "\n\n$(BOLD_OPACITY)[ SO_LONG ]$(DEF_STYLE)	$(MAGENTA)bonus testing without env $(DEF_COLOR)"
	-env -i valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(NAME_BONUS) maps/classic.ber
	@echo "\n\n$(BOLD_OPACITY)[ SO_LONG ]$(DEF_STYLE)	$(MAGENTA)bonus testing working $(DEF_COLOR)"
	-valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(NAME_BONUS) maps/hard.ber

testall				:	runtest runtestbonus

re					:	fclean all

.PHONY				:	all bonus clean fclean re runtest runtestbonus testall