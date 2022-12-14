#pragma once

#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/fmt/ostr.h>
#include "RandomEngine/Core/Types.h"

namespace RandomEngine {

	class Log
	{
		private:
			static bool _hasInit;
			static Ref<spdlog::logger> _coreLogger;
			static Ref<spdlog::logger> _clientLogger;

		public:
			static void Init();

			inline static bool HasInit() { return _hasInit; }
			inline static Ref<spdlog::logger>& GetCoreLogger() { return _coreLogger; }
			inline static Ref<spdlog::logger>& GetClientLogger() { return _clientLogger; }
	};

}

// Core log macros
#define RE_CORE_INFO(...)		::RandomEngine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define RE_CORE_WARN(...)		::RandomEngine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define RE_CORE_ERROR(...)		::RandomEngine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define RE_CORE_CRITICAL(...)	::RandomEngine::Log::GetCoreLogger()->critical(__VA_ARGS__)
#define RE_CORE_DEBUG(...)		::RandomEngine::Log::GetCoreLogger()->debug(__VA_ARGS__)
#define RE_CORE_TRACE(...)		::RandomEngine::Log::GetCoreLogger()->trace(__VA_ARGS__)

// Client log macros
#define RE_INFO(...)			::RandomEngine::Log::GetClientLogger()->info(__VA_ARGS__)
#define RE_WARN(...)			::RandomEngine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define RE_ERROR(...)			::RandomEngine::Log::GetClientLogger()->error(__VA_ARGS__)
#define RE_CRITICAL(...)		::RandomEngine::Log::GetClientLogger()->critical(__VA_ARGS__)
#define RE_DEBUG(...)			::RandomEngine::Log::GetClientLogger()->debug(__VA_ARGS__)
#define RE_TRACE(...)			::RandomEngine::Log::GetClientLogger()->trace(__VA_ARGS__)
