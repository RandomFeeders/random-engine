#pragma once

#include "REPCH.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "imgui.h"

#include "RandomEngine/Application.h"
#include "RandomEngine/Layer.h"
#include "RandomEngine/Events/Event.h"
#include "RandomEngine/Events/ApplicationEvent.h"
#include "RandomEngine/Events/KeyEvent.h"
#include "RandomEngine/Events/MouseEvent.h"

namespace RandomEngine {

	class GuiLayer : public Layer {

		private:
			float _time = 0.0f;

			bool OnMouseButtonPressed(MouseButtonPressedEvent& e);
			bool OnMouseButtonReleased(MouseButtonReleasedEvent& e);
			bool OnMouseMove(MouseMovedEvent& e);
			bool OnMouseScrolled(MouseScrolledEvent& e);

			bool OnKeyPressed(KeyPressedEvent& e);
			bool OnKeyReleased(KeyReleasedEvent& e);
			bool OnKeyTyped(KeyTypedEvent& e);

			bool OnWindowResize(WindowResizeEvent& e);

		public:
			GuiLayer();
			~GuiLayer();

			void OnAttach() override;
			void OnDetach() override;
			void OnUpdate() override;
			void OnEvent(Event& event) override;
	};

}