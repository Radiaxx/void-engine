#pragma once

#include "ve_window.hpp"
#include "ve_pipeline.hpp"
#include "ve_device.hpp"
#include "ve_swap_chain.hpp"

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
		void createPipelineLayout();
		void createPipeline();
		void createCommandBuffers();
		void drawFrame();

		VeWindow veWindow{WIDTH, HEIGTH, "Hello Vulkan!"};
		VeDevice veDevice{ veWindow };
		VeSwapChain veSwapChain{ veDevice, veWindow.getExtent() };
		std::string vertFilepath = "C:/Users/danie/OneDrive/Documenti/Visual Studio 2022/Projects/void-engine/void-engine/src/shaders/simple_shader.vert.spv";
		std::string fragFilepath = "C:/Users/danie/OneDrive/Documenti/Visual Studio 2022/Projects/void-engine/void-engine/src/shaders/simple_shader.frag.spv";
		std::unique_ptr<VePipeline> vePipeline;
		VkPipelineLayout pipelineLayout;
		std::vector<VkCommandBuffer> commandBuffers;
	};
}