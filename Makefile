NAME		=	push_swap

SRC			=	*.c \
				libft/*.c \

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror

LIBFTDIR	=	libft/

LIBFTA		=	libft.a

all:			$(NAME)

$(NAME):		$(LIBFTA)
	@$(CC) $(CFLAGS) $(SRC) $(LIBFTA) -o $(NAME)
	@rm -f $(LIBFTA)
	@echo "$(NAME) created"

$(LIBFTA):
	@cd ./$(LIBFTDIR) && make all
	@cp ./$(LIBFTDIR)$(LIBFTA) .

clean:
	@cd ./$(LIBFTDIR) && make fclean

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
