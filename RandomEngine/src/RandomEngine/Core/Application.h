#pragma once

#include <memory>
#include "Window.h"
#include "LayerStack.h"
#include "RandomEngine/Events/ApplicationEvent.h"
#include "RandomEngine/GUI/GuiLayer.h"
#include "RandomEngine/Graphics/Shader.h"
#include "RandomEngine/Graphics/Buffers/VertexArray.h"
#include "RandomEngine/Graphics/Cameras/OrthographicCamera.h"

namespace RandomEngine {

	class Application {
		
		private:
			static Application* _instance;

			bool _running = false;
			std::unique_ptr<Window> _window;
			LayerStack _layerStack;
			GuiLayer* _guiLayer;

			std::shared_ptr<Graphics::Shader> _shader;
			std::shared_ptr<Graphics::VertexArray> _vertexArray;

			Graphics::OrthographicCamera _camera;

			bool OnWindowClose(WindowCloseEvent& e);

		public:
			Application();
			virtual ~Application();

			void Run();
			void OnEvent(Event& e);

			void PushLayer(Layer* layer);
			void PushOverlay(Layer* overlay);

			inline Window& GetWindow() const { return *_window; }

			inline static Application& GetInstance() { return *_instance; }
	};

	Application* CreateApplication();

}
