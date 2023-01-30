OBJS = ft_strlen.o ft_atoi.o ft_printf.o ft_putchar.o ft_puthex.o ft_putnbr.o ft_putstr.o ft_putunsigned.o

NAME2 = client 
NAME = server
FLAGS = -Wall -Wextra -Werror 

all: $(NAME) $(NAME2)

$(NAME): $(OBJS) server.c 
	cc ${FLAGS} $(OBJS) server.c -o server 
	

$(NAME2): $(OBJS) client.c
	cc ${FLAGS} $(OBJS) client.c -o client 

%.o : %.c
	cc ${FLAGS} $< -c

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f server
	rm -f client

re: fclean all

.PHONY: all clean fclean re