#pragma once

#ifdef RE_PLATFORM_WINDOWS
	#ifndef RANDOM_ENGINE_API
		#define RANDOM_ENGINE_API
	#else
		#ifdef RE_BUILD_DLL
			#define RANDOM_ENGINE_API __declspec(dllexport)
		#else
			#define RANDOM_ENGINE_API __declspec(dllimport)
		#endif
	#endif
#else
	#error Random Engine only supports Windows!
#endif

#ifdef RE_ENABLE_ASSERTS
	#define RE_ASSERT(x, ...) { if (!x) { RE_ERROR("Assertation failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define RE_CORE_ASSERT(x, ...) { if (!x) { RE_CORE_ERROR("Assertation failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define RE_ASSERT(x, ...)
	#define RE_CORE_ASSERT(x, ...)
#endif

#define BIT(n) (1 << n)
#define HAS_FLAG(e, f) (e & f)