#pragma once

#include "ve_window.hpp"

namespace ve {
	class App {
	public:
		static constexpr int WIDTH = 800;
		static constexpr int HEIGTH = 600;

		void run();

	private:
		VeWindow veWindow{WIDTH, HEIGTH, "Hello Vulkan!"};
	};
}