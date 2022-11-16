#include "ve_window.hpp"

namespace ve {

	VeWindow::VeWindow(int w, int h, std::string name) : width{ w }, heigth{ h }, windowName{ name } {
		initWindow();
	}

	VeWindow::~VeWindow() {
		glfwDestroyWindow(window);
		glfwTerminate();
	}

	void VeWindow::initWindow() {
		glfwInit();
		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
		glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

		window = glfwCreateWindow(width, heigth, windowName.c_str(), nullptr, nullptr);
	}
} // namespace ve