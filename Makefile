main: main.o game.o
	g++ -o main main.o game.o && make clean

main.o: ./src/main.cpp
	g++ -Wall -c ./src/main.cpp ./include/game.h

game.o: ./src/game.cpp
	g++ -Wall -c ./src/game.cpp ./include/game.h

main.pdf: ./src/main.cpp ./include/game.h ./src/game.cpp Makefile
	a2ps -o - ./src/main.cpp ./include/game.h ./src/game.cpp Makefile \
		| ps2pdf - main.pdf

clean: 
	rm -f *.o core

mrproper: clean
	rm -f main
