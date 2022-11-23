#include "app.hpp"

#include "ve_render_system.hpp"

// libs
#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm.hpp>
#include <gtc/constants.hpp>

// std
#include <stdexcept>
#include <cassert>	
#include <array>

namespace ve {

	App::App() {
		loadGameObjects();
	}

	App::~App() {}

	void App::run() {
		RenderSystem renderSystem{veDevice, veRenderer.getSwapChainRenderPass()};

		while (!veWindow.shouldClose()) {
			glfwPollEvents();		

			if (auto commandBuffer = veRenderer.beginFrame()) {
				veRenderer.beginSwapChainRenderPass(commandBuffer);
				renderSystem.renderGameObjects(commandBuffer, gameObjects);
				veRenderer.endSwapChainRenderPass(commandBuffer);
				veRenderer.endFrame();
			}
		}

		// Wait until all GPU operations are completed
		vkDeviceWaitIdle(veDevice.device());	
	}

	void App::loadGameObjects() {
		std::vector<VeModel::Vertex> vertices{
			{{0.0f, -0.5f}, {1.0f, 0, 0}},
			{{0.5f, 0.5f}, {0, 1.0f, 0}},
			{{-0.5f, 0.5f}, {0, 0, 1.0f}}
		};

		auto veModel = std::make_shared<VeModel>(veDevice, vertices);

		auto triangle = VeGameObject::createGameObject();
		triangle.model = veModel;
		triangle.color = { .1f, .8f, .1f };
		triangle.transform2d.translation.x = .2f;	
		triangle.transform2d.scale = { 1.f, 0.5f };
		triangle.transform2d.rotation = .25f * glm::two_pi<float>();

		gameObjects.push_back(std::move(triangle)); 
	}
}