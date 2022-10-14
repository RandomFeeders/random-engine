#include <RandomEngine.h>

class Program : public RandomEngine::Application {
	public:
		Program() {

		}

		~Program() {

		}
};

RandomEngine::Application* RandomEngine::CreateApplication() {
	return new Program();
}