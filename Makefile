FLAGS = -Wall -Werror -g -std=c++14
FILE1 = lab3

all: $(FILE1).o 
	g++ $(FLAGS) $(FILE1).o -o $(FILE1)

$(FILE1).o: $(FILE1).cpp
	g++ -c $(FLAGS) $(FILE1).cpp -o $(FILE1).o

run: all
	./$(FILE1)

memcheck: all
	valgrind ./$(FILE1)

clean:
	rm -rf *.o $(FILE1)
