#include "app.hpp"

namespace ve {

	void App::run() {

		while (!veWindow.shouldClose()) {
			glfwPollEvents(); 
		}
	}
}