NAME = main
CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98

SRCS = ./main.cpp \
		./AForm.cpp \
		./Bureaucrat.cpp \
		./RobotomyRequestForm.cpp \
		./ShrubberyCreationForm.cpp \
		./PresidentialPardonForm.cpp

OBJS    = $(SRCS:%.cpp=%.o)

all:    $(NAME)

$(NAME):	$(OBJS)
				$(CC) $(CFLAGS) $(OBJS) -o $@

%.o:		%.c
				$(CC) $(CFLAGS) -o $@ -c $<

run:	$(NAME)
			./$(NAME)

clean:
				rm -f $(OBJS)

fclean:		clean
				rm -f $(NAME)

re:			fclean all

valgrind:	all
			valgrind ./$(NAME)

.PHONY:		all clean fclean re valgrind