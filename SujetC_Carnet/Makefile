##
## YNOV PROJECT, 2026
## Ynov
## File description:
## Makefile
##

CXX		 = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -I include
NAME	 = carnet

SRCS	 = $(shell find -name "*.cpp")
OBJS	 = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
