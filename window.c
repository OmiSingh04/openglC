#define GLEW_STATIC
#include<stdio.h>
#include<stdbool.h>
#include<GL/glew.h>
#include<GL/gl.h>
#include<GLFW/glfw3.h>

GLuint compile_shader(GLuint type, const char* source){//compile shader from source and return it

	GLuint id = glCreateShader(type);
	glShaderSource(id, 1, &source, NULL);
	glCompileShader(id);//this is where the magic happens!
	
	//debug info
	GLuint compile_status;
	glGetShaderiv(id, GL_COMPILE_STATUS, &compile_status);
	
	
	
	if(compile_status == GL_FALSE){
		if(id == GL_VERTEX_SHADER)
			fprintf(stderr, "Failed while compiling Vertex Shader");
		else
			fprintf(stderr, "Failed while compiling Fragment Shader");
		
		glDeleteShader(id);
		id = 0;//just hoping 0 is an invalid 
	}
	else
			fprintf(stderr, "Compiled Fragment Shader");

	char log[1024] = {0};
	GLsizei log_length;
	glGetShaderInfoLog(id, 1024, &log_length, log); 
	printf("%s\n\n", log);
	return id;
}
	

GLuint load_shaders(const char* vertex, const char* fragment){//returns the program containing the shaders


	GLuint program = glCreateProgram();
	GLuint vertex_shader = compile_shader(GL_VERTEX_SHADER, vertex);
	GLuint fragment_shader = compile_shader(GL_FRAGMENT_SHADER, fragment);	

	glAttachShader(program, vertex_shader);
	glAttachShader(program, fragment_shader);

	glLinkProgram(program);
	glValidateProgram(program);
	

	GLuint validate_status;
	glGetProgramiv(program, GL_VALIDATE_STATUS, &validate_status);

	if(validate_status == GL_FALSE)
		fprintf(stderr, "Failed to validate program!");

	glDeleteShader(vertex_shader);
	glDeleteShader(fragment_shader);

	return program;
}



int main(void){
	
	glewExperimental = true;
	if(!glfwInit())
		return -1;//if GLFW couldnt init, just return bro

	GLFWwindow* window;
	window = glfwCreateWindow(1000, 840, "Hello World", NULL, NULL);// creates the widnow and the associated opengl context.

	if(!window){
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	//after successfully creating an OpenGL rendering context, i can now initialize glew, according to the official site
	if(glewInit() != GLEW_OK){
		fprintf(stderr, "GLEW INIT FAILLLLEDDD!!!!");
		return -1;
	}

	
	GLfloat positions[6] = {
	        0.5f, -0.5f,
	        0.0f, 0.5f,
	       -0.5f, -0.5f
	};
	

	GLuint buffer;//id of the buffer
	glGenBuffers(1, &buffer);
	glBindBuffer(GL_ARRAY_BUFFER, buffer); //important function, cause this is how opengl knows that this buffer contains the vertex attributes


	glBufferData(GL_ARRAY_BUFFER, sizeof(positions), positions, GL_STATIC_DRAW);
	
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), 0);

	char vertex_shader[] = 
		"#version 330 core\n"
		"\n"
		"layout(location = 0) in vec4 position;\n"
		"\n"
		"void main()\n"
		"{\n"
		"	gl_Position = position;\n"
		"}\n";



	
	char fragment_shader[] = 
		"#version 330 core\n"
		"\n"
		"layout(location = 0) out vec4 color;\n"
		"\n"
		"void main()\n"
		"{\n"
		"	color = vec4(1.0, 0.0, 0.0, 1.0);\n"
		"}\n";


	GLuint shader = load_shaders(vertex_shader, fragment_shader);
	glUseProgram(shader);
 

	

	while(!glfwWindowShouldClose(window)){
		glClear(GL_COLOR_BUFFER_BIT);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glfwSwapBuffers(window);// front buffer is the one displaying, back buffer is the one we are rendering to, this is multiple-buffering
		glfwPollEvents();
	}

	glfwTerminate();
}
