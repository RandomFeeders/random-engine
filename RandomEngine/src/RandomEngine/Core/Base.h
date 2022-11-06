#pragma once

#include "RandomEngine/Core/PlatformDetection.h"
#include "RandomEngine/Core/Log.h"

#ifdef RE_ENV_DEBUG
	#define RE_ENABLE_ASSERTS
	#define RE_PROFILE 1
#endif

#ifdef RE_ENV_RELEASE
	#define RE_PROFILE 0
#endif

#ifdef RE_ENABLE_ASSERTS
	#define RE_ASSERT(x, ...) { if (!(x)) { RE_ERROR("Assertation failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define RE_CORE_ASSERT(x, ...) { if (!(x)) { RE_CORE_ERROR("Assertation failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define RE_ASSERT(x, ...)
	#define RE_CORE_ASSERT(x, ...)
#endif

#define BIT(n) (1 << n)
#define HAS_FLAG(e, f) ((e & f) == f)

#if RE_PROFILE
	#include "RandomEngine/Profiling/Timer.h"
	#include "RandomEngine/Profiling/TimerOutput.h"
	#include "RandomEngine/Profiling/Instrumentor.h"

	#define RE_PROFILE_BEGIN_SESSION(name, filepath) ::RandomEngine::Profiling::Instrumentor::Get().BeginSession(name, filepath)
	#define RE_PROFILE_END_SESSION() ::RandomEngine::Profiling::Instrumentor::Get().EndSession()
	#define RE_PROFILE_SCOPE(name, output) ::RandomEngine::Profiling::Timer timer##__LINE__(name, true, output)
	#define RE_PROFILE_SCOPE_FUNC(output) ::RandomEngine::Profiling::Timer timer##__LINE__(__FUNCSIG__, true, output)
	#define RE_PROFILE_SCOPE_CALLBACK(name, func, output) ::RandomEngine::Profiling::Timer timer##__LINE__(name, func, true, output)
	#define RE_PROFILE_SCOPE_CALLBACK_FUNC(func, output) ::RandomEngine::Profiling::Timer timer##__LINE__(__FUNCSIG__, func, true, output)
#else
	#define RE_PROFILE_BEGIN_SESSION(name, filepath)
	#define RE_PROFILE_END_SESSION()
	#define RE_PROFILE_SCOPE(name, output)
	#define RE_PROFILE_SCOPE_FUNC(output)
	#define RE_PROFILE_SCOPE_CALLBACK(name, func, output)
	#define RE_PROFILE_SCOPE_CALLBACK_FUNC(func, output)
#endif
