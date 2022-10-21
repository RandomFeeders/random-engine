#include <RandomEngine.h>
#include <RandomEngine/Core/EntryPoint.h>

class ExampleLayer : public RandomEngine::Layer {

	public:
		ExampleLayer()
			: Layer("Example") { }

		void OnUpdate() override {

		}

		void OnEvent(RandomEngine::Event& e) override {

		}
};

class Program : public RandomEngine::Application {

	public:
		Program() {
			PushLayer(new ExampleLayer());
		}

		~Program() {

		}
};

RandomEngine::Application* RandomEngine::CreateApplication() {
	return new Program();
}
