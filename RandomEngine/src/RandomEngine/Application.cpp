#include "REPCH.h"

#include "application.h"

#include "gl/GL.h"

namespace RandomEngine {

	Application::Application() {
		_window = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application() {

	}

	void Application::Run() {
		_running = true;

		while (_running) {
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			_window->OnUpdate();
		}
	}

}