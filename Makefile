CFLAGS=-I/filer/tmp2/contrib/include -Wall -pedantic -g
LDFLAGS=-L/filer/tmp2/contrib/lib -lsfml-system -lsfml-graphics -lsfml-window -lsfml-audio -lsndfile -lopenal
COMPILE=g++ ${CFLAGS} ${LDFLAGS}

all: Hello Game

go:
	./Game


Planet.o: Planet.cpp Planet.hpp
	${COMPILE} -c Planet.cpp

Hello: Hello.cpp SuperVector2f.o
	${COMPILE} -o Hello SuperVector2f.o Hello.cpp

Game: Game.cpp SuperVector2f.o
	${COMPILE} -o Game SuperVector2f.o Game.cpp

SuperVector2f.o: SuperVector2f.cpp
	${COMPILE} -c SuperVector2f.cpp
	
clean:
	rm -f Hello Game *.o
