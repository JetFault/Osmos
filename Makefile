CFLAGS=-I/filer/tmp2/contrib/include -Wall -pedantic -g
LDFLAGS=-L/filer/tmp2/contrib/lib -lsfml-system -lsfml-graphics -lsfml-window -lsfml-audio -lsndfile -lopenal
EXECCOMPILE=g++ ${CFLAGS} ${LDFLAGS}
OBJCOMPILE=g++ ${CFLAGS}

all: Hello

Hello: Hello.cpp SuperVector2f.o
	${EXECCOMPILE} -o Hello SuperVector2f.o Hello.cpp

Game: Game.cpp SuperVector2f.o
	${EXECCOMPILE} -o Game SuperVector2f.o Game.cpp

SuperVector2f.o: SuperVector2f.cpp
	${OBJCOMPILE} -c SuperVector2f.cpp
	
clean:
	rm -f Hello Game *.o
