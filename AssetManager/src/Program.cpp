#include <RandomEngine.h>
#include <RandomEngine/Core/EntryPoint.h>

#include "MainLayer.h";

namespace RandomEngine::AssetManager {

	using namespace RandomEngine;

	class Program : public Application {

		public:
			Program() : Application(ApplicationProps("Asset Manager", 1280, 720, WindowMode::Borderless, 0)) {
				PushLayer(new MainLayer());
			}

			~Program() { }
	};

}

RandomEngine::Application* RandomEngine::CreateApplication() {
	return new AssetManager::Program();
}
