SRC = $(wildcard *.cpp)
OBJ = $(patsubst %.cpp, %.o, $(SRC))
INC = -I "./"

all:
	g++ -c $(SRC) $(INC)
	g++ $(OBJ) -o stella
	rm -f $(OBJ)

clean:
	rm -f $(OBJ) stella
