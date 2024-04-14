NAME = RPN
CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98

SRCS = ./main.cpp \
		./RPN.cpp

OBJS    = $(SRCS:%.cpp=%.o)

all:    $(NAME)

$(NAME):	$(OBJS)
				$(CC) $(CFLAGS) $(OBJS) -o $@

%.o:		%.cpp
				$(CC) $(CFLAGS) -o $@ -c $<

run:	$(NAME)
			./$(NAME) "8 9 * 9 - 9 - 9 - 4 - 1 +"

clean:
				rm -f $(OBJS)

fclean:		clean
				rm -f $(NAME)

re:			fclean all

valgrind:	all
			valgrind ./$(NAME) "8 9 * 9 - 9 - 9 - 4 - 1 +"

.PHONY:		all clean fclean re valgrind