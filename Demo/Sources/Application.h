#pragma once
#include <GLFW/glfw3.h>

class Application
{
public:
	Application();
	void Init();
	void Render();
	void KeyCallback(GLFWwindow* window,int key, int scancode, int action, int mods);
private:
};