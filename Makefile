all: main.o U.o
	g++ main.o U.o -o NBody -lsfml-graphics -lsfml-window -lsfml-system 

main.o: main.cpp
	g++ -c main.cpp -Wall -Werror -ansi -pedantic 

U.o: U.cpp U.hpp 
	g++ -c U.cpp -Wall -Werror -ansi -pedantic


clean: 
	rm *.o NBody
