NAME = main
CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98

SRCS = ./main.cpp \
		./utils.cpp

OBJS    = $(SRCS:%.cpp=%.o)

all:    $(NAME)

$(NAME):	$(OBJS)
				$(CC) $(CFLAGS) $(OBJS) -o $@

%.o:		%.c
				$(CC) $(CFLAGS) -o $@ -c $<

run:	$(NAME)
			./$(NAME) texto "Anel" "CPP"

clean:
				rm -f $(OBJS)

fclean:		clean
				rm -f $(NAME)

re:			fclean all

valgrind:	all
			valgrind ./$(NAME) texto "Anel" "CPP"

.PHONY:		all clean fclean re valgrind