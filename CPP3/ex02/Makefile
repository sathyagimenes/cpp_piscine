NAME = main
CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98

SRCS = ./main.cpp \
		./ClapTrap.cpp \
		./ScavTrap.cpp \
		./FragTrap.cpp

OBJS    = $(SRCS:%.c=%.o)

all:    $(NAME)

$(NAME):	$(OBJS)
				$(CC) $(CFLAGS) $(OBJS) -o $@

%.o:		%.c
				$(CC) $(CFLAGS) -o $@ -c $<

run:	$(NAME)
			./$(NAME)

clean:
				rm -f $(OBJS)

# fclean:		clean
fclean:
				rm -f $(NAME)

re:			fclean all