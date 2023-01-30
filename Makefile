OBJS = ft_strlen.o ft_atoi.o ft_printf.o ft_putchar.o ft_puthex.o ft_putnbr.o ft_putstr.o ft_putunsigned.o

NAME = server
NAME2 = client 

CFLAGS = -Wall -Wextra -Werror 


all: $(NAME) $(NAME2)

$(NAME): $(OBJS) server.c 
	cc $(CFLAGS) $(OBJS) server.c -o $(NAME) 

$(NAME2): $(OBJS) client.c
	cc $(CFLAGS) $(OBJS) client.c -o $(NAME2)

%.o: %.c
	cc $(CFLAGS) -c $<

bonus: server_bonus client_bonus

server_bonus: $(OBJS) server_bonus.c
	cc $(CFLAGS) $(OBJS) server_bonus.c -o server_bonus

client_bonus: $(OBJS) client_bonus.c
	cc $(CFLAGS) $(OBJS) client_bonus.c -o client_bonus

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME2)
	rm -f server_bonus
	rm -f client_bonus

re: fclean all

.PHONY: all clean fclean re