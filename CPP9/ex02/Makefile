NAME = PmergeMe
CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98

SRCS = ./main.cpp \
		./PmergeMe.cpp

OBJS    = $(SRCS:%.cpp=%.o)

all:    $(NAME)

$(NAME):	$(OBJS)
				$(CC) $(CFLAGS) $(OBJS) -o $@

%.o:		%.cpp
				$(CC) $(CFLAGS) -o $@ -c $<

run:	$(NAME)
			./$(NAME) 10 2 3 1 5 11 9 7

clean:
				rm -f $(OBJS)

fclean:		clean
				rm -f $(NAME)

re:			fclean all

valgrind:	all
			valgrind ./$(NAME)

.PHONY:		all clean fclean re valgrind