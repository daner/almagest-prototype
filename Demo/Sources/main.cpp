#include <iostream>
#include <memory>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Application.h"


void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) 
{
	static_cast<Application*>(glfwGetWindowUserPointer(window))->KeyCallback(window, key, scancode, action, mods);
}

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
	
	auto app = std::make_unique<Application>();

	glfwSetWindowUserPointer(window, app.get());
	glfwSetKeyCallback(window, &keyCallback);

	app->Init();


	while (!glfwWindowShouldClose(window))
	{
		app->Render();
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return EXIT_SUCCESS;
} 

