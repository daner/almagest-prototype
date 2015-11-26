#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

int main(int arc, char* argv[])
{
	if(!glfwInit())
	{
		std::cout << "glfwInit failed, aborting." << std::endl;
		return EXIT_FAILURE;
	}

	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);

	auto window = glfwCreateWindow(1280, 720, "Hello World", nullptr, nullptr);
	glfwMakeContextCurrent(window);

	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
	{
		std::cout << "glewInit failed, aborting." << std::endl;
		glfwTerminate();
		return EXIT_FAILURE;
	}
	

	while (!glfwWindowShouldClose(window))
	{
		//TODO: Render here


		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return EXIT_SUCCESS;
} 