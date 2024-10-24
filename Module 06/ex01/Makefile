# C++ Flags / Variables
CPP = c++
CFLAGS = -Wall -Wextra -Werror -g -std=c++98
RM = rm -rf

# Colors
RED     = \033[1;31m
GREEN   = \033[1;32m
RESET   = \033[0m


# Project name
NAME = serialization
SRC = main.cpp \
 		Serializer.cpp \

OBJDIR = .bin
OBJ = $(addprefix $(OBJDIR)/, $(SRC:.cpp=.o))

# RULES
all: $(NAME)

$(NAME): $(OBJ)
		$(CPP) $(CFLAGS) $(OBJ) -o $(NAME)
		echo "$(GREEN)Build completed. $(RESET)" ;

$(OBJDIR)/%.o: %.cpp
		mkdir -p $(@D)
		$(CPP) $(CFLAGS) -c $< -o $@

clean:
		$(RM) $(OBJ)
		$(RM) *_shrubbery

fclean:
		$(RM) $(OBJ) $(NAME) $(OBJDIR)
		$(RM) *_shrubbery
		echo "$(RED)Cleaned project files/folders. $(RESET)" ;

re: fclean all

.SILENT:

.PHONY: all clean fclean re