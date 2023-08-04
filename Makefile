CXX = clang++ -Wall -Wextra -Werror

SRC = ./src/*.cpp

SFML_HEADERS = -I /opt/homebrew/Cellar/sfml/2.6.0/include
SFML_LIB = -L /opt/homebrew/Cellar/sfml/2.6.0/lib -lsfml-graphics -lsfml-window -lsfml-system

all:
	$(CXX) $(SRC) $(SFML_HEADERS) $(SFML_LIB) -o out/game