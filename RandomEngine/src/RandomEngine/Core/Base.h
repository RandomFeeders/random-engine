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
#define FLAG(f, t) constexpr friend f operator|(f left, f right) { return static_cast<f>(static_cast<t>(left) | static_cast<t>(right)); }\
                   constexpr friend f operator&(f left, f right) { return static_cast<f>(static_cast<t>(left) & static_cast<t>(right)); }
