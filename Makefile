##
## EPITECH PROJECT, 2023
## B-PDG-300-BER-3-1-PDGD06-matthis.brocheton
## File description:
## Makefile
##

SRC		=	$(wildcard ./src/*.cpp)	\
			main.cpp

OBJ		=	$(SRC:.cpp=.o)

NAME	=	plazza

FLAGS	=	-std=c++20 -Wall -lstdc++ -I ./include -pthread

UNIT_TESTS	=	$(wildcard ./tests/*.cpp)

all: $(NAME)

$(NAME): $(OBJ)
	g++ $(FLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp
	g++ $(FLAGS) -c -o $@ $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f *.vgcore
	rm -f *.gcno
	rm -f *.gcda
	rm -f unit_tests

re: fclean all

unit_tests: $(UNIT_TESTS) $(filter-out main.cpp, $(SRC))
	g++ $(FLAGS) -o unit_tests $(UNIT_TESTS)	\
	$(filter-out main.cpp, $(SRC)) -lcriterion -coverage

tests_run: unit_tests
	./unit_tests

.PHONY: all clean fclean re unit_tests tests_run
