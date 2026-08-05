CC = cc
CFLAGS = -Wall -Wextra -Werror 
FILES = srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c
OBJECT = $(FILES:.c=.o)

all : libft.a

libft.a : $(OBJECT)
	ar rcs $@ $^
srcs/%.o : srcs/%.c includes/ft.h
	$(CC) $(CFLAGS) -I includes -c $< -o $@
clean :
	rm -f $(OBJECT)
fclean : clean
	rm -f libft.a
re : fclean all


.PHONY: all clean fclean re
