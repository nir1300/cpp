NAME = sed
CFILES = main.cpp
OFILES = $(CFILES:.cpp=.o)
HEADER = sed.hpp

CFLAGS = -Wall -Werror -Wextra -std=c++98

all: $(NAME)

$(NAME): $(OFILES)
	c++ $(CFLAGS) $(OFILES) -o $(NAME) -g

%.o: %.cpp $(HEADER)
	c++ $(CFLAGS) -c $< -o $@ -g

clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)


.PHONY: all clean fclean re
