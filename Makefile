CFLAGS=-I/filer/tmp2/contrib/include -Wall -pedantic -g
LDFLAGS=-L/filer/tmp2/contrib/lib -lsfml-system -lsfml-graphics -lsfml-window -lsfml-audio -lsndfile -lopenal
COMPILE=g++ ${CFLAGS} ${LDFLAGS}

all: Hello graphics-shape

go:
	./graphics-shape

Hello: Hello.cpp
	${COMPILE} -o Hello Hello.cpp
graphics-shape: graphics-shape.cpp
	${COMPILE} -o graphics-shape graphics-shape.cpp
clean:
	rm Hello graphics-shape
