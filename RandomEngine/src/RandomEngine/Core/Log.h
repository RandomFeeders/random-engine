#pragma once

#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/fmt/ostr.h>

#include "RandomEngine/Core/Types.h"

namespace RandomEngine {

	class Logger {

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
#define RE_CORE_INFO(...)		::RandomEngine::Logger::GetCoreLogger()->info(__VA_ARGS__)
#define RE_CORE_WARN(...)		::RandomEngine::Logger::GetCoreLogger()->warn(__VA_ARGS__)
#define RE_CORE_ERROR(...)		::RandomEngine::Logger::GetCoreLogger()->error(__VA_ARGS__)
#define RE_CORE_CRITICAL(...)	::RandomEngine::Logger::GetCoreLogger()->critical(__VA_ARGS__)
#define RE_CORE_DEBUG(...)		::RandomEngine::Logger::GetCoreLogger()->debug(__VA_ARGS__)
#define RE_CORE_TRACE(...)		::RandomEngine::Logger::GetCoreLogger()->trace(__VA_ARGS__)

// Client log macros
#define RE_INFO(...)			::RandomEngine::Logger::GetClientLogger()->info(__VA_ARGS__)
#define RE_WARN(...)			::RandomEngine::Logger::GetClientLogger()->warn(__VA_ARGS__)
#define RE_ERROR(...)			::RandomEngine::Logger::GetClientLogger()->error(__VA_ARGS__)
#define RE_CRITICAL(...)		::RandomEngine::Logger::GetClientLogger()->critical(__VA_ARGS__)
#define RE_DEBUG(...)			::RandomEngine::Logger::GetClientLogger()->debug(__VA_ARGS__)
#define RE_TRACE(...)			::RandomEngine::Logger::GetClientLogger()->trace(__VA_ARGS__)
