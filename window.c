#include<stdio.h>
#include<GLFW/glfw3.h>
int main(void){


	GLFWwindow* window;

	if(!glfwInit())
		return -1;//if GLFW couldnt init, just return bro


	window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);// creates the widnow and the associated opengl context.

	if(!window){

		glfwTerminate();
		return -1;
	}


	glfwMakeContextCurrent(window);

	while(!glfwWindowShouldClose(window)){//while the window is not closed
		//clear buffers used for color writing
		glClear(GL_COLOR_BUFFER_BIT);
		//swap buffers
		glfwSwapBuffers(window);// front buffer is the one displaying, back buffer is the one we are rendering to, this is multiple-buffering
		//process event queue
		glfwPollEvents();
		
	}


	glfwTerminate();
}
