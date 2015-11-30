#include <iostream>
#include "Application.h"
#include "Filesystem.h"

Application::Application()
{
}

void Application::Init()
{
	std::cout << Filesystem::GetFileContents(Filesystem::GetPath("Resources/Shaders/minimal.vert")) << std::endl;
	std::cout << Filesystem::GetFileContents(Filesystem::GetPath("Resources/Shaders/minimal.frag")) << std::endl;
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