PROJECT_NAME = a
SOURCE = *.c
CFLAG = -Wall -g
CC = gcc
LIBS = -lGL -lGLEW -lglfw

build:
	${CC} -o ${PROJECT_NAME} ${SOURCE} ${CFLAGS} ${LIBS}

clean:
	rm ${PROJECT_NAME}
