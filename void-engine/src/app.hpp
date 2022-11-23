#pragma once

#include "ve_window.hpp"
#include "ve_device.hpp"
#include "ve_renderer.hpp"
#include "ve_game_object.hpp"

// std
#include <memory>
#include <vector>

namespace ve {
	class App {
	public:
		static constexpr int WIDTH = 800;
		static constexpr int HEIGTH = 600;

		App();
		~App();

		App(const App&) = delete;
		App& operator = (const App&) = delete;

		void run();	 

	private:
		void loadGameObjects();

		VeWindow veWindow{WIDTH, HEIGTH, "Hello Vulkan!"};
		VeDevice veDevice{ veWindow };
		VeRenderer veRenderer{ veWindow, veDevice };

		std::vector<VeGameObject> gameObjects;

		std::string vertFilepath = "C:/Users/danie/OneDrive/Documenti/Visual Studio 2022/Projects/void-engine/void-engine/src/shaders/simple_shader.vert.spv";
		std::string fragFilepath = "C:/Users/danie/OneDrive/Documenti/Visual Studio 2022/Projects/void-engine/void-engine/src/shaders/simple_shader.frag.spv";
	};
}