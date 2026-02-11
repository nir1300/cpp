NAME = serializer
CFILES = main.cpp Base.cpp
OFILES = $(CFILES:.cpp=.o)
HEADER = Serializer.hpp
CFLAGS = -Wall -Werror -Wextra -std=c++98

all: $(NAME)

$(NAME): $(OFILES)
	c++ $(CFLAGS) $(OFILES) -o $(NAME)

%.o: %.cpp $(HEADER)
	c++ $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)


.PHONY: all clean fclean re
