#pragma once

#include "ve_window.hpp"
#include "ve_pipeline.hpp"
#include "ve_device.hpp"

namespace ve {
	class App {
	public:
		static constexpr int WIDTH = 800;
		static constexpr int HEIGTH = 600;

		void run();	 

	private:
		VeWindow veWindow{WIDTH, HEIGTH, "Hello Vulkan!"};
		VeDevice veDevice{ veWindow };
		std::string a = "C:/Users/danie/OneDrive/Documenti/Visual Studio 2022/Projects/void-engine/void-engine/src/shaders/simple_shader_vert.spv";
		std::string b = "C:/Users/danie/OneDrive/Documenti/Visual Studio 2022/Projects/void-engine/void-engine/src/shaders/simple_shader_frag.spv";
		VePipeline VePipeline{veDevice, a, b, VePipeline::defaultPipelineConfigInfo(WIDTH, HEIGTH)};
	};
}