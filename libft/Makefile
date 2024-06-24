# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebengtss <ebengtss@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/24 14:26:10 by ebengtss          #+#    #+#              #
#    Updated: 2024/06/24 14:30:01 by ebengtss         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS 		+=	--no-print-directory

NAME			=	libft.a

CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror -I
AR				=	ar rcs

SRCS_DIR		=	srcs/
OBJS_DIR		=	objs/
INCS_DIR		=	incs

SRCS_FILES		=	ft_isascii.c		ft_isprint.c		ft_strlen.c			\
					ft_isalnum.c		ft_bzero.c			ft_atoi.c			\
					ft_memcpy.c			ft_split.c			ft_memchr.c			\
					ft_calloc.c			ft_strmapi.c		ft_putnbr_fd.c		\
					ft_memmove.c		ft_strlcat.c		ft_toupper.c		\
					ft_memset.c		 	ft_memcmp.c			ft_strjoin.c		\
					ft_strnstr.c		ft_striteri.c		ft_strdup.c			\
					ft_putchar_fd.c		ft_tolower.c		ft_strchr.c			\
					ft_strlcpy.c		ft_itoa.c			ft_putendl_fd.c		\
					ft_strrchr.c		ft_strncmp.c		ft_substr.c			\
					ft_strtrim.c		ft_putstr_fd.c		ft_isalpha.c		\
					ft_isdigit.c		ft_lstadd_back.c	ft_lstadd_front.c	\
					ft_lstclear.c		ft_lstiter.c		ft_lstsize.c		\
					ft_lstlast.c		ft_lstmap.c			ft_lstdelone.c		\
					ft_lstnew.c			ft_printf.c			ft_putaddress.c		\
					ft_putchar_len.c	ft_puthex_len.c		ft_putnbr_len.c		\
					ft_putstr_len.c		ft_putuns_len.c		ft_isnl.c			\
					get_next_line.c

SRCS			=	$(addprefix $(SRCS_DIR), $(SRCS_FILES))
OBJS			=	$(addprefix $(OBJS_DIR), $(SRCS_FILES:.c=.o))

DEF_COLOR		=	\033[0;39m
MAGENTA			=	\033[0;95m
GREEN			=	\033[0;92m
DEF_WEIGHT		=	\e[0m
BOLD_WEIGHT		=	\e[1m

OBJSF			=	.cache_exists

all				:	$(NAME)

$(NAME)			:	$(OBJS)
	@$(AR) $@ $?
	@echo "$(BOLD_WEIGHT)[LIBFT]$(DEF_WEIGHT) make: $(GREEN)OK$(DEF_COLOR)"

$(OBJS_DIR)%.o	:	$(SRCS_DIR)%.c | $(OBJSF)
	@$(CC) $(CFLAGS) $(INCS_DIR) -c $< -o $@
	@echo "$(BOLD_WEIGHT)[LIBFT]$(DEF_WEIGHT) compiling: $(MAGENTA) $< $(DEF_COLOR)"

$(OBJSF)	:
	@mkdir -p $(OBJS_DIR)

clean			:
	@rm -rf $(OBJS_DIR)
	@echo "$(BOLD_WEIGHT)[LIBFT]$(DEF_WEIGHT) clean: $(GREEN)OK$(DEF_COLOR)"

fclean			:	clean
	@rm -f $(NAME)
	@echo "$(BOLD_WEIGHT)[LIBFT]$(DEF_WEIGHT) fclean: $(GREEN)OK$(DEF_COLOR)"

re				:	fclean all

.PHONY			:	all clean fclean re bonus
