#include "Application.h"
#include <iostream>
#include "Filesystem.h"

Application::Application()
{
}

void Application::Init()
{
	std::cout << Filesystem::GetFileContent(Filesystem::GetPath("Resources/Shaders/minimal.frag")) << std::endl;
}

void Application::Render()
{
}

void Application::KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	switch(key)
	{
		case GLFW_KEY_ESCAPE:
			glfwSetWindowShouldClose(window, GL_TRUE);
			break;
		default:
			std::cout << "Key: " << key << std::endl;
	}
}