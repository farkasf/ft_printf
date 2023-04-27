NAME = libftprintf.a
SRC = ./sources/ft_printf.c \
	./sources/ft_cs.c \
	./sources/ft_dix.c \
	./sources/ft_up.c
LIBFT = libft/libft.a
OBJS = $(SRC:.c=.o)
CFLAGS = -Wall -Wextra -Werror
CC = cc
INCL = ./includes
RLIB = ranlib
CLIB = ar rc
R = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	make -C ./libft
	cp $(LIBFT) ${NAME}
	$(CLIB) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCL)

clean:
	${MAKE} clean -C ./libft
	$(R) $(OBJS)

fclean:	clean
	$(R) $(NAME)
	${MAKE} fclean -C ./libft

re: fclean all
