LIBRARIES = -lglfw -lGLEW -lGLU -lGL 

all:
	gcc window.c $(LIBRARIES) -o run.out
	./run.out

clean:
	rm run.out
