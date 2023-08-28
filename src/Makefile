CC:=g++
CFLAGS := -Wall -Werror -Wextra

all : clean build

build :
	${CC} ${CFLAGS} main.cpp Circle.cpp Ellipse.cpp Helix3D.cpp -o main.out
	./main.out

clean :
	rm -f main.out
