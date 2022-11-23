#pragma once

#include "ve_window.hpp"
#include "ve_device.hpp"
#include "ve_swap_chain.hpp"

// std
#include <memory>
#include <cassert>
#include <vector>

namespace ve {
	class VeRenderer {
	public:
		VeRenderer(VeWindow& window, VeDevice& device);
		~VeRenderer();

		VeRenderer(const VeRenderer&) = delete;
		VeRenderer& operator = (const VeRenderer&) = delete;

		VkRenderPass getSwapChainRenderPass() const { return veSwapChain->getRenderPass(); };
		bool isFrameInProgress() const { return isFrameStarted; }

		VkCommandBuffer getCurrentCommandBuffer() const { 
			assert(isFrameStarted && "Cannot get command buffer when frame not in progress");
			return commandBuffers[currentFrameIndex]; 
		}

		int getFrameIndex() const {
			assert(currentFrameIndex && "Cannot get current frame index when frame not in progress");
			return currentFrameIndex;
		}

		VkCommandBuffer beginFrame();
		void endFrame();
		void beginSwapChainRenderPass(VkCommandBuffer commandBuffer);
		void endSwapChainRenderPass(VkCommandBuffer commandBuffer);

	private:
		void createCommandBuffers();
		void freeCommandBuffers();
		void recreateSwapChain(); 

		VeWindow &veWindow;
		VeDevice &veDevice;
		std::unique_ptr<VeSwapChain> veSwapChain;
		std::vector<VkCommandBuffer> commandBuffers;

		uint32_t currentImageIndex;
		int currentFrameIndex{ 0 };
		bool isFrameStarted{ false };

	};
}