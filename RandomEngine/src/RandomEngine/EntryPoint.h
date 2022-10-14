#pragma once

#include "REPCH.h"

#ifdef RE_PLATFORM_WINDOWS

extern RandomEngine::Application* RandomEngine::CreateApplication();

int main(int argc, char** argv) {
	RandomEngine::Log::Init();

	RE_CORE_INFO("Info");
	RE_CORE_WARN("Warn");
	RE_CORE_ERROR("Error");
	RE_CORE_CRITICAL("Critical");
	RE_CORE_DEBUG("Debug");
	RE_CORE_TRACE("Trace");

	auto app = RandomEngine::CreateApplication();
	app->Run();
	delete app;
}

#endif