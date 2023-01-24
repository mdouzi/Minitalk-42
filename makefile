SRCS = ft_strlen.c ft_atoi.c ft_printf.c ft_putchar.c ft_puthex.c ft_putnbr.c ft_putstr.c ft_putunsigned.c
NAME := client server

all: $(NAME)

$(NAME): server.c client.c $(SRCS)
	gcc server.c -o server ${SRCS}
	gcc client.c -o client ${SRCS}

clean:
	rm -f server
	rm -f client

fclean: clean

re: fclean all