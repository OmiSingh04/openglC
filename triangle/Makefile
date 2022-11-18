CC = gcc
LIBRARIES = -lglfw -lGLEW -lGLU -lGL 
CFLAGS = -Wall -Wextra

OBJECT_FILES = window.o
C_FILES = window.c

BINARY = run.out


all: $(BINARY)
	./$(BINARY)

$(BINARY): $(OBJECT_FILES)
	$(CC) -o $@ $^ $(LIBRARIES)

$(OBJECT_FILES): $(C_FILES) 
	$(CC) -c $^ -o $@ $(CFLAGS)
	

clean:
	rm $(BINARY) $(OBJECT_FILES)
