#include <RandomEngine.h>
#include <RandomEngine/Core/EntryPoint.h>

#include "ExampleLayer.h"
#include "Simple2DLayer.h"

namespace Sandbox {

	class Program : public RandomEngine::Application {

	public:
		Program() {
			PushLayer(new Simple2DLayer());
		}

		~Program() {

		}
	};

}

RandomEngine::Application* RandomEngine::CreateApplication() {
	return new Sandbox::Program();
}
