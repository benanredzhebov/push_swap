# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/23 11:40:39 by beredzhe          #+#    #+#              #
#    Updated: 2024/02/23 11:40:39 by beredzhe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=		push_swap

SRC			=		calc_check.c	cost_benefit.c	create.c \
					list_check.c   list_check2.c  operations.c \
					push_swap.c		cost_helper.c	error_check.c \
					main.c libft/*.c \

CC			=		cc

CFLAGS		=		-Werror -Wextra -Wall

LIBFTDIR	=		libft/

LIBFTA		=		libft.a


all:		$(NAME)

$(NAME):	$(LIBFTA)
	@$(CC) $(CFLAGS) $(SRC) $(LIBFTA) -o $(NAME)
	@rm -f $(LIBFTA)
	@echo "$(NAME) created"

$(LIBFTA):
	@cd ./$(LIBFTDIR) && make all
	@cp libft/libft.a .

clean:
		@cd $(LIBFTDIR) && make fclean

fclean: clean
		@rm -f $(NAME)

re: fclean all