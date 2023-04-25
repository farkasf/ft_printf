NAME = libftprintf.a
SRC = ft_printf.c \
	ft_cs.c \
	ft_dix.c \
	ft_up.c
LIBFT = libft/libft.a
OBJS = $(SRC:.c=.o)
CFLAGS = -Wall -Wextra -Werror
CC = cc
INCL = .
RLIB = ranlib
CLIB = ar rc
R = rm -f

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -c $(SRC) -I $(INCL)
	make -C ./libft
	cp $(LIBFT) ${NAME}
	$(CLIB) $(NAME) $(OBJS)

clean:
	${MAKE} clean -C ./libft
	$(R) $(OBJS)

fclean:	clean
	$(R) $(NAME)
	${MAKE} fclean -C ./libft

re: fclean all
