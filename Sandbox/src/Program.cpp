#include <RandomEngine.h>
#include <RandomEngine/Core/EntryPoint.h>

#include "ExampleLayer.h"

namespace Sandbox {

	class Program : public RandomEngine::Application {

	public:
		Program() {
			PushLayer(new ExampleLayer());
		}

		~Program() {

		}
	};

}

RandomEngine::Application* RandomEngine::CreateApplication() {
	return new Sandbox::Program();
}
