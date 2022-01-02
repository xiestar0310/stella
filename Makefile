SRC = $(wildcard *.cpp)
OBJ = $(patsubst %.cpp, %.o, $(SRC))
INC = -I "./"

all:
	g++ -std=c++17 -c $(SRC) $(INC)
	g++ -std=c++17 $(OBJ) -o stella
	rm -f $(OBJ)

clean:
	rm -f $(OBJ) stella
