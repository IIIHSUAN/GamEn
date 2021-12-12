#include "GE_pch.h"
#include "Win_Input.h"
#include <GLFW/glfw3.h>

namespace GamEn {

	bool Win_Input::_isPressKey(int key)
	{
		auto gLFWindow = static_cast<GLFWwindow*>(Manager::get().getWindow().getNativeWindow());
		int opcode = glfwGetKey(gLFWindow, key);

		return opcode == GLFW_PRESS || opcode == GLFW_REPEAT;
	}
	bool Win_Input::_isPressMouse(int botton)
	{
		auto gLFWindow = static_cast<GLFWwindow*>(Manager::get().getWindow().getNativeWindow());
		int opcode = glfwGetMouseButton(gLFWindow, botton);

		return opcode == GLFW_PRESS;
	}
	std::pair<float, float> Win_Input::_pos()
	{
		auto gLFWindow = static_cast<GLFWwindow*>(Manager::get().getWindow().getNativeWindow());
		double x, y;
		glfwGetCursorPos(gLFWindow, &x, &y);
		return { (float)x,(float)y };
	}

}