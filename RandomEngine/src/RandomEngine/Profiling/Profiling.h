#pragma once

#include "RandomEngine/Core/Base.h"

#if RE_PROFILE
	#include "RandomEngine/Profiling/Timer.h"
	#include "RandomEngine/Profiling/TimerOutput.h"
	#include "RandomEngine/Profiling/Instrumentor.h"

	#if defined(__GNUC__) || (defined(__MWERKS__) && (__MWERKS__ >= 0x3000)) || (defined(__ICC) && (__ICC >= 600)) || defined(__ghs__)
		#define RE_FUNC_SIG __PRETTY_FUNCTION__
	#elif defined(__DMC__) && (__DMC__ >= 0x810)
		#define RE_FUNC_SIG __PRETTY_FUNCTION__
	#elif defined(__FUNCSIG__)
		#define RE_FUNC_SIG __FUNCSIG__
	#elif (defined(__INTEL_COMPILER) && (__INTEL_COMPILER >= 600)) || (defined(__IBMCPP__) && (__IBMCPP__ >= 500))
		#define RE_FUNC_SIG __FUNCTION__
	#elif defined(__BORLANDC__) && (__BORLANDC__ >= 0x550)
		#define RE_FUNC_SIG __FUNC__
	#elif defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 199901)
		#define RE_FUNC_SIG __func__
	#elif defined(__cplusplus) && (__cplusplus >= 201103)
		#define RE_FUNC_SIG __func__
	#else
		#define RE_FUNC_SIG "HZ_FUNC_SIG unknown!"
	#endif

	#define RE_PROFILE_BEGIN_SESSION(name, filepath) ::RandomEngine::Profiling::Instrumentor::Get().BeginSession(name, filepath)
	#define RE_PROFILE_END_SESSION() ::RandomEngine::Profiling::Instrumentor::Get().EndSession()
	#define RE_PROFILE_SCOPE(name, output) ::RandomEngine::Profiling::Timer timer##__LINE__(name, true, output)
	#define RE_PROFILE_SCOPE_FUNC(output) ::RandomEngine::Profiling::Timer timer##__LINE__(RE_FUNC_SIG, true, output)
	#define RE_PROFILE_SCOPE_CALLBACK(name, func, output) ::RandomEngine::Profiling::Timer timer##__LINE__(name, func, true, output)
	#define RE_PROFILE_SCOPE_CALLBACK_FUNC(func, output) ::RandomEngine::Profiling::Timer timer##__LINE__(RE_FUNC_SIG, func, true, output)
#else
	#define RE_PROFILE_BEGIN_SESSION(name, filepath)
	#define RE_PROFILE_END_SESSION()
	#define RE_PROFILE_SCOPE(name, output)
	#define RE_PROFILE_SCOPE_FUNC(output)
	#define RE_PROFILE_SCOPE_CALLBACK(name, func, output)
	#define RE_PROFILE_SCOPE_CALLBACK_FUNC(func, output)
#endif
