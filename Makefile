CFLAGS=-I/filer/tmp2/contrib/include -Wall -pedantic -g
LDFLAGS=-L/filer/tmp2/contrib/lib -lsfml-system -lsfml-graphics -lsfml-window -lsfml-audio -lsndfile -lopenal
COMPILE=g++ ${CFLAGS} ${LDFLAGS}

all: Hello Game

go:
	./Game

Hello: Hello.cpp
	${COMPILE} -o Hello Hello.cpp
Game: Game.cpp
	${COMPILE} -o Game Game.cpp
clean:
	rm -f Hello Game
