#include <RandomEngine.h>

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
			PushOverlay(new RandomEngine::GuiLayer());
		}

		~Program() {

		}
};

RandomEngine::Application* RandomEngine::CreateApplication() {
	return new Program();
}