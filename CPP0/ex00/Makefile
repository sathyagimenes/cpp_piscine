NAME = megaphone
CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98

SRCS = ./Megaphone.cpp				\


OBJS    = $(SRCS:%.cpp=%.o)

all:    $(NAME)

$(NAME):	$(OBJS)
				$(CC) $(CFLAGS) $(OBJS) -o $@

%.o:		%.c
				$(CC) $(CFLAGS) -o $@ -c $<

run:	$(NAME)
			./$(NAME) "shhhhh... I think the students are asleep..."

clean:
				rm -f $(OBJS)

fclean:		clean		clean
				rm -f $(NAME)

re:			fclean all

valgrind:	all
			valgrind ./$(NAME)

.PHONY:		all clean fclean re valgrind