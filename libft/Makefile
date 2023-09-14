NAME		= libft.a

SRCS		= ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c

				
OBJS		= $(SRCS:%.c=%.o)

FLAGS		= -Wall -Wextra -Werror

$(NAME):
	gcc $(FLAGS) -c $(SRCS) -I./
	ar rc $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
