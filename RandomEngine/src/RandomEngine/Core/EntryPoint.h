#pragma once

#include "RandomEngine/Core/Base.h"
#include "RandomEngine/Core/Application.h"

#ifdef RE_PLATFORM_WINDOWS

extern RandomEngine::Application* RandomEngine::CreateApplication();

int main(int argc, char** argv) {
	RandomEngine::Log::Init();

	auto app = RandomEngine::CreateApplication();
	app->Run();
	delete app;
}

#endif