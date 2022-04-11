#include <stdio.h>
#include <stdlib.h>
#include <GL/glew.h>

#include<GLFW/glfw3.h>
int main()
{

	if (!glfwInit()) {
		fprintf(stderr, "failed to initialize glfw\n");
		return -1;
	}

	glfwWindowHint(GLFW_SAMPLES, 4);	// 4x antialiasing
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);	// We want OpenGL 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);	// We don't want the old OpenGL 

	// Open a window and create its OpenGL context
	GLFWwindow *window;	// (In the accompanying source code, this variable is global for simplicity)
	window = glfwCreateWindow(1024, 768, "Tutorial 01", NULL, NULL);
	if (window == NULL) {
		fprintf(stderr,
			"Failed to open GLFW window.\n");
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);	// Initialize GLEW
	
	if (glewInit() != GLEW_OK) {
    		fprintf(stderr, "Failed to initialize GLEW\n");
    		return -1;
	}

	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

	do{
    		glClear( GL_COLOR_BUFFER_BIT );
    		glfwSwapBuffers(window);
    		glfwPollEvents();


	}while( glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS && glfwWindowShouldClose(window) == 0 );

}
