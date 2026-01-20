NAME = animal
CFILES = main.cpp Animal.cpp Cat.cpp Dog.cpp WrongAnimal.cpp WrongCat.cpp
OFILES = $(CFILES:.cpp=.o)
HEADER = Animal.hpp Cat.hpp Dog.hpp WrongAnimal.hpp WrongCat.hpp
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
