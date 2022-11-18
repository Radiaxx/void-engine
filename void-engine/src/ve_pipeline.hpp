#pragma once

#include "ve_device.hpp"

// std
#include <string>
#include <vector>

namespace ve {

	struct PipelineConfigInfo {};

	class VePipeline {
	public:
		VePipeline(
			VeDevice& device,
			const std::string& vertFilepath, 
			const std::string& fragFilepath, 
			const PipelineConfigInfo& configInfo);

		~VePipeline() {}

		VePipeline(const VePipeline&) = delete;
		void operator = (const VePipeline&) = delete;

		static PipelineConfigInfo defaultPipelineConfigInfo(uint32_t width, uint32_t heigth);

	private:
		static std::vector<char> readFile(const std::string& filepath);

		void createGraphicsPipeline(
			const std::string& vertFilepath, 
			const std::string& fragFilepath,
			const PipelineConfigInfo& configInfo);

		void createShaderModule(const std::vector<char>& code, VkShaderModule* shaderModule);

		VeDevice& veDevice;
		VkPipeline graphicsPipeline;
		VkShaderModule vertShaderModule;
		VkShaderModule fragShaderModule;
	};
}