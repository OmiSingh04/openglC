PROJECT_NAME = a
SOURCE = *.c
CFLAG = -Wall -g -pedantic
CC = gcc
LIBS = -lGL -lGLEW -lglfw

clean:
	rm ${PROJECT_NAME}

run:
	${CC} -o ${PROJECT_NAME} ${SOURCE} ${CFLAGS} ${LIBS}

