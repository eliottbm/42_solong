# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebengtss <ebengtss@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/13 11:16:00 by ebengtss          #+#    #+#              #
#    Updated: 2024/07/28 16:40:51 by ebengtss         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS 			+=	--no-print-directory

VALGRIND			=	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s
FILTER_OUTPUT		=	2>&1 | grep -E "Error|HEAP SUMMARY|in use at exit:|total heap usage:|ERROR SUMMARY" -A1 | grep -v '^--$$' | grep -v '^[=-]\{2\}[0-9]\+[=-]\{2\}\s*$$'

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
	@echo "$(RESET_LINE)$(BOLD_OPACITY)[ SO_LONG ]$(DEF_STYLE)	bonus compiling:$(GREEN) ✔ $(DEF_COLOR)"
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
	@echo "$(RESET_LINE)$(BOLD_OPACITY)[ SO_LONG ]$(DEF_STYLE)	bonus compiling:$(GREEN) $< $(DEF_COLOR)"

$(OBJSF)			:
	@echo "$(BOLD_OPACITY)[ SO_LONG ]$(DEF_STYLE)	nothing to do"
	@mkdir -p $(OBJS_DIR)

$(OBJSF_BONUS)		:
	@echo "$(BOLD_OPACITY)[ SO_LONG ]$(DEF_STYLE)	bonus nothing to do"
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

testmandatory		:	all
	@echo "$(BOLD_OPACITY)[ SO_LONG ]$(DEF_STYLE)	running test ..."
	@echo "$(BOLD_OPACITY)[ SO_LONG ]$(DEF_STYLE)	testing:$(MAGENTA) non existing $(DEF_COLOR)"
	-@$(VALGRIND) ./$(NAME) maps/not.ber $(FILTER_OUTPUT)
	@echo "\n\n\n$(BOLD_OPACITY)[ SO_LONG ]$(DEF_STYLE)	testing:$(MAGENTA) invalid border $(DEF_COLOR)"
	-@$(VALGRIND) ./$(NAME) maps/border_err.ber $(FILTER_OUTPUT)
	@echo "\n\n\n$(BOLD_OPACITY)[ SO_LONG ]$(DEF_STYLE)	testing:$(MAGENTA) cutted $(DEF_COLOR)"
	-@$(VALGRIND) ./$(NAME) maps/cutted_err.ber $(FILTER_OUTPUT)
	@echo "\n\n\n$(BOLD_OPACITY)[ SO_LONG ]$(DEF_STYLE)	testing:$(MAGENTA) empty $(DEF_COLOR)"
	-@$(VALGRIND) ./$(NAME) maps/empty_err.ber $(FILTER_OUTPUT)
	@echo "\n\n\n$(BOLD_OPACITY)[ SO_LONG ]$(DEF_STYLE)	testing:$(MAGENTA) wrong extension $(DEF_COLOR)"
	-@$(VALGRIND) ./$(NAME) maps/extension_err.txt $(FILTER_OUTPUT)
	@echo "\n\n\n$(BOLD_OPACITY)[ SO_LONG ]$(DEF_STYLE)	testing:$(MAGENTA) invalid char $(DEF_COLOR)"
	-@$(VALGRIND) ./$(NAME) maps/invalidchar_err.ber $(FILTER_OUTPUT)
	@echo "\n\n\n$(BOLD_OPACITY)[ SO_LONG ]$(DEF_STYLE)	testing:$(MAGENTA) line length $(DEF_COLOR)"
	-@$(VALGRIND) ./$(NAME) maps/line_err.ber $(FILTER_OUTPUT)
	@echo "\n\n\n$(BOLD_OPACITY)[ SO_LONG ]$(DEF_STYLE)	testing:$(MAGENTA) missing collectible $(DEF_COLOR)"
	-@$(VALGRIND) ./$(NAME) maps/nocol_err.ber $(FILTER_OUTPUT)
	@echo "\n\n\n$(BOLD_OPACITY)[ SO_LONG ]$(DEF_STYLE)	testing:$(MAGENTA) missing exit $(DEF_COLOR)"
	-@$(VALGRIND) ./$(NAME) maps/noexit_err.ber $(FILTER_OUTPUT)
	@echo "\n\n\n$(BOLD_OPACITY)[ SO_LONG ]$(DEF_STYLE)	testing:$(MAGENTA) missing player $(DEF_COLOR)"
	-@$(VALGRIND) ./$(NAME) maps/noplayer_err.ber $(FILTER_OUTPUT)
	@echo "\n\n\n$(BOLD_OPACITY)[ SO_LONG ]$(DEF_STYLE)	testing:$(MAGENTA) only line jump $(DEF_COLOR)"
	-@$(VALGRIND) ./$(NAME) maps/onlylinejump_err.ber $(FILTER_OUTPUT)
	@echo "\n\n\n$(BOLD_OPACITY)[ SO_LONG ]$(DEF_STYLE)	testing:$(MAGENTA) unreachable collectible $(DEF_COLOR)"
	-@$(VALGRIND) ./$(NAME) maps/reachcol_err.ber $(FILTER_OUTPUT)
	@echo "\n\n\n$(BOLD_OPACITY)[ SO_LONG ]$(DEF_STYLE)	testing:$(MAGENTA) unreachable exit $(DEF_COLOR)"
	-@$(VALGRIND) ./$(NAME) maps/reachexit_err.ber $(FILTER_OUTPUT)
	@echo "\n\n\n$(BOLD_OPACITY)[ SO_LONG ]$(DEF_STYLE)	testing:$(MAGENTA) too large height $(DEF_COLOR)"
	-@$(VALGRIND) ./$(NAME) maps/toolargeheight_err.ber $(FILTER_OUTPUT)
	@echo "\n\n\n$(BOLD_OPACITY)[ SO_LONG ]$(DEF_STYLE)	testing:$(MAGENTA) too large width $(DEF_COLOR)"
	-@$(VALGRIND) ./$(NAME) maps/toolargewidth_err.ber $(FILTER_OUTPUT)
	@echo "\n\n\n$(BOLD_OPACITY)[ SO_LONG ]$(DEF_STYLE)	testing:$(MAGENTA) too many exit $(DEF_COLOR)"
	-@$(VALGRIND) ./$(NAME) maps/toomanyexit_err.ber $(FILTER_OUTPUT)
	@echo "\n\n\n$(BOLD_OPACITY)[ SO_LONG ]$(DEF_STYLE)	testing:$(MAGENTA) too many player $(DEF_COLOR)"
	-@$(VALGRIND) ./$(NAME) maps/toomanyplayer_err.ber $(FILTER_OUTPUT)
	@echo "\n\n\n$(BOLD_OPACITY)[ SO_LONG ]$(DEF_STYLE)	testing:$(MAGENTA) without env $(DEF_COLOR)"
	-@env -i $(VALGRIND) ./$(NAME) maps/working.ber $(FILTER_OUTPUT)
	@echo "\n\n\n$(BOLD_OPACITY)[ SO_LONG ]$(DEF_STYLE)	testing:$(MAGENTA) working $(DEF_COLOR)"
	-@$(VALGRIND) ./$(NAME) maps/working.ber $(FILTER_OUTPUT)
	@echo "\n"

testbonus			:	bonus
	@echo "$(BOLD_OPACITY)[ SO_LONG ]$(DEF_STYLE)	running bonus test ..."
	@echo "$(BOLD_OPACITY)[ SO_LONG ]$(DEF_STYLE)	bonus testing:$(MAGENTA) non existing $(DEF_COLOR)"
	-@$(VALGRIND) ./$(NAME_BONUS) maps/not.ber $(FILTER_OUTPUT)
	@echo "\n\n\n$(BOLD_OPACITY)[ SO_LONG ]$(DEF_STYLE)	bonus testing:$(MAGENTA) invalid border $(DEF_COLOR)"
	-@$(VALGRIND) ./$(NAME_BONUS) maps/border_err.ber $(FILTER_OUTPUT)
	@echo "\n\n\n$(BOLD_OPACITY)[ SO_LONG ]$(DEF_STYLE)	bonus testing:$(MAGENTA) cutted $(DEF_COLOR)"
	-@$(VALGRIND) ./$(NAME_BONUS) maps/cutted_err.ber $(FILTER_OUTPUT)
	@echo "\n\n\n$(BOLD_OPACITY)[ SO_LONG ]$(DEF_STYLE)	bonus testing:$(MAGENTA) empty $(DEF_COLOR)"
	-@$(VALGRIND) ./$(NAME_BONUS) maps/empty_err.ber $(FILTER_OUTPUT)
	@echo "\n\n\n$(BOLD_OPACITY)[ SO_LONG ]$(DEF_STYLE)	bonus testing:$(MAGENTA) wrong extension $(DEF_COLOR)"
	-@$(VALGRIND) ./$(NAME_BONUS) maps/extension_err.txt $(FILTER_OUTPUT)
	@echo "\n\n\n$(BOLD_OPACITY)[ SO_LONG ]$(DEF_STYLE)	bonus testing:$(MAGENTA) invalid char $(DEF_COLOR)"
	-@$(VALGRIND) ./$(NAME_BONUS) maps/invalidchar_err.ber $(FILTER_OUTPUT)
	@echo "\n\n\n$(BOLD_OPACITY)[ SO_LONG ]$(DEF_STYLE)	bonus testing:$(MAGENTA) line length $(DEF_COLOR)"
	-@$(VALGRIND) ./$(NAME_BONUS) maps/line_err.ber $(FILTER_OUTPUT)
	@echo "\n\n\n$(BOLD_OPACITY)[ SO_LONG ]$(DEF_STYLE)	bonus testing:$(MAGENTA) missing collectible $(DEF_COLOR)"
	-@$(VALGRIND) ./$(NAME_BONUS) maps/nocol_err.ber $(FILTER_OUTPUT)
	@echo "\n\n\n$(BOLD_OPACITY)[ SO_LONG ]$(DEF_STYLE)	bonus testing:$(MAGENTA) missing exit $(DEF_COLOR)"
	-@$(VALGRIND) ./$(NAME_BONUS) maps/noexit_err.ber $(FILTER_OUTPUT)
	@echo "\n\n\n$(BOLD_OPACITY)[ SO_LONG ]$(DEF_STYLE)	bonus testing:$(MAGENTA) missing player $(DEF_COLOR)"
	-@$(VALGRIND) ./$(NAME_BONUS) maps/noplayer_err.ber $(FILTER_OUTPUT)
	@echo "\n\n\n$(BOLD_OPACITY)[ SO_LONG ]$(DEF_STYLE)	bonus testing:$(MAGENTA) only line jump $(DEF_COLOR)"
	-@$(VALGRIND) ./$(NAME_BONUS) maps/onlylinejump_err.ber $(FILTER_OUTPUT)
	@echo "\n\n\n$(BOLD_OPACITY)[ SO_LONG ]$(DEF_STYLE)	bonus testing:$(MAGENTA) unreachable collectible $(DEF_COLOR)"
	-@$(VALGRIND) ./$(NAME_BONUS) maps/reachcol_err.ber $(FILTER_OUTPUT)
	@echo "\n\n\n$(BOLD_OPACITY)[ SO_LONG ]$(DEF_STYLE)	bonus testing:$(MAGENTA) unreachable exit $(DEF_COLOR)"
	-@$(VALGRIND) ./$(NAME_BONUS) maps/reachexit_err.ber $(FILTER_OUTPUT)
	@echo "\n\n\n$(BOLD_OPACITY)[ SO_LONG ]$(DEF_STYLE)	bonus testing:$(MAGENTA) too large height $(DEF_COLOR)"
	-@$(VALGRIND) ./$(NAME_BONUS) maps/toolargeheight_err.ber $(FILTER_OUTPUT)
	@echo "\n\n\n$(BOLD_OPACITY)[ SO_LONG ]$(DEF_STYLE)	bonus testing:$(MAGENTA) too large width $(DEF_COLOR)"
	-@$(VALGRIND) ./$(NAME_BONUS) maps/toolargewidth_err.ber $(FILTER_OUTPUT)
	@echo "\n\n\n$(BOLD_OPACITY)[ SO_LONG ]$(DEF_STYLE)	bonus testing:$(MAGENTA) too many exit $(DEF_COLOR)"
	-@$(VALGRIND) ./$(NAME_BONUS) maps/toomanyexit_err.ber $(FILTER_OUTPUT)
	@echo "\n\n\n$(BOLD_OPACITY)[ SO_LONG ]$(DEF_STYLE)	bonus testing:$(MAGENTA) too many player $(DEF_COLOR)"
	-@$(VALGRIND) ./$(NAME_BONUS) maps/toomanyplayer_err.ber $(FILTER_OUTPUT)
	@echo "\n\n\n$(BOLD_OPACITY)[ SO_LONG ]$(DEF_STYLE)	bonus testing:$(MAGENTA) without env $(DEF_COLOR)"
	-@env -i $(VALGRIND) ./$(NAME_BONUS) maps/working.ber $(FILTER_OUTPUT)
	@echo "\n\n\n$(BOLD_OPACITY)[ SO_LONG ]$(DEF_STYLE)	bonus testing:$(MAGENTA) working $(DEF_COLOR)"
	-@$(VALGRIND) ./$(NAME_BONUS) maps/working_bonus.ber $(FILTER_OUTPUT)

runtest				:	testmandatory testbonus

re					:	fclean all

.PHONY				:	all bonus clean fclean re runtest runtestbonus testall