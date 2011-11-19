CFLAGS=-I/filer/tmp2/contrib/include -Wall -pedantic -g
LDFLAGS=-L/filer/tmp2/contrib/lib -lsfml-system -lsfml-graphics -lsfml-window -lsfml-audio -lsndfile -lopenal
COMPILE=g++ ${CFLAGS} ${LDFLAGS}

all: Hello

Hello: Hello.cpp
	${COMPILE} -o Hello Hello.cpp
clean:
	rm Hello
