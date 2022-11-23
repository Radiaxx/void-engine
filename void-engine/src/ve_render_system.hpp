#pragma once

#include "ve_device.hpp"
#include "ve_pipeline.hpp"
#include "ve_game_object.hpp"

// libs
#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm.hpp>
#include <gtc/constants.hpp>

// std
#include <memory>
#include <vector>

namespace ve {
	class RenderSystem {
	public:
		RenderSystem(VeDevice& device, VkRenderPass renderPass);
		~RenderSystem();

		RenderSystem(const RenderSystem&) = delete;
		RenderSystem& operator = (const RenderSystem&) = delete;

		void renderGameObjects(VkCommandBuffer commandBuffer, std::vector<VeGameObject>& gameObjects);

	private:
		void createPipelineLayout();
		void createPipeline(VkRenderPass renderPass);
		
		VeDevice& veDevice;

		std::unique_ptr<VePipeline> vePipeline;
		VkPipelineLayout pipelineLayout;

		std::string vertFilepath = "C:/Users/danie/OneDrive/Documenti/Visual Studio 2022/Projects/void-engine/void-engine/src/shaders/simple_shader.vert.spv";
		std::string fragFilepath = "C:/Users/danie/OneDrive/Documenti/Visual Studio 2022/Projects/void-engine/void-engine/src/shaders/simple_shader.frag.spv";
	};
}