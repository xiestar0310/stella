SRC = $(wildcard *.cpp)
OBJ = $(patsubst %.cpp, %.o, $(SRC))
INC = -I "./"

all:
	g++ -std=c++17 -Ofast -ffast-math -c $(SRC) $(INC)
	g++ -std=c++17 -Ofast -ffast-math $(OBJ) -o stella
	rm -f $(OBJ)

clean:
	rm -f $(OBJ) stella
