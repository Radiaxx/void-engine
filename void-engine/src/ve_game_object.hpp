#pragma once

#include "ve_model.hpp"

// libs
#include <gtc/matrix_transform.hpp>

// std
#include <memory>

namespace ve {
	struct TransformComponent {
		glm::vec3 translation{};	// Position offset
		glm::vec3 scale{ 1.f, 1.f, 1.f };
		glm::vec3 rotation{};

		glm::mat4 mat4() {
			auto transform = glm::translate(glm::mat4{1.f}, translation);

			transform = glm::rotate(transform, rotation.y, { 0.f, 1.f, 0.f });
			transform = glm::rotate(transform, rotation.x, { 1.f, 0.f, 0.f });
			transform = glm::rotate(transform, rotation.x, { 0.f, 0.f, 1.f });	

			transform = glm::scale(transform, scale);
			return transform;
		}
	};

	class VeGameObject {
	public:
		using id_t = unsigned int;

		static VeGameObject	createGameObject() {
			static id_t currentId = 0;
			return VeGameObject{ currentId++ };
		}

		VeGameObject(const VeGameObject&) = delete;
		VeGameObject& operator = (const VeGameObject&) = delete;
		VeGameObject(VeGameObject&&) = default;
		VeGameObject& operator = (VeGameObject&&) = default;

		const id_t getId() { return id; }

		std::shared_ptr<VeModel> model{};
		glm::vec3 color{};
		TransformComponent transform{};

	private:
		VeGameObject(id_t objId) : id{objId} {}

		id_t id;
	};
}