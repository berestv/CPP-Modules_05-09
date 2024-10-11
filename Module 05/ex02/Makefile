# C++ Flags / Variables
CPP = c++
CFLAGS = -Wall -Wextra -Werror -g -std=c++98
RM = rm -rf

# Project name
NAME = maggots
SRC = main.cpp \
 		Bureaucrat.cpp \
 		PresidentialPardonForm.cpp \
 		RobotomyRequestForm.cpp \
 		ShrubberyCreationForm.cpp \
 		AForm.cpp \

OBJDIR = bin
OBJ = $(addprefix $(OBJDIR)/, $(SRC:.cpp=.o))

# RULES
all: $(NAME)

$(NAME): $(OBJ)
		$(CPP) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJDIR)/%.o: %.cpp
		mkdir -p $(@D)
		$(CPP) $(CFLAGS) -c $< -o $@

clean:
		$(RM) $(OBJ)

fclean:
		$(RM) $(OBJ) $(NAME) $(OBJDIR)

re: fclean all

.SILENT:

.PHONY: all clean fclean re