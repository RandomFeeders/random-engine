#pragma once

#ifdef _WIN32
	#define NEWLINE "\r\n"
	#define FONTS_DIR "%WINDIR%/fonts/"
	#ifdef _WIN64
		#define RE_PLATFORM_WINDOWS
	#else
		#error "x86 Builds are not supported!"
	#endif
#elif defined(__APPLE__) || defined(__MACH__)
	#define NEWLINE "\n"
	#define FONTS_DIR "~/Library/Fonts/"
	#include <TargetConditionals.h>
	#if TARGET_IPHONE_SIMULATOR == 1
		#error "IOS simulator is not supported!"
	#elif TARGET_OS_IPHONE == 1
		#define RE_PLATFORM_IOS
		#error "IOS is not supported!"
	#elif TARGET_OS_MAC == 1
		#define RE_PLATFORM_MACOS
		#error "MacOS is not supported!"
	#else
		#error "Unknown Apple platform!"
	#endif
#elif defined(__ANDROID__)
	#define NEWLINE "\n"
	#define FONTS_DIR "/usr/share/fonts/"
	#define RE_PLATFORM_ANDROID
	#error "Android is not supported!"
#elif defined(__linux__)
	#define NEWLINE "\n"
	#define FONTS_DIR "/usr/share/fonts/"
	#define RE_PLATFORM_LINUX
	#error "Linux is not supported!"
#else
	#error "Unknown platform!"
#endif

#ifdef RE_PLATFORM_WINDOWS
	#if RE_DYNAMIC_LINK
		#ifdef RE_BUILD_DLL
			#define RANDOM_ENGINE_API __declspec(dllexport)
		#else
			#define RANDOM_ENGINE_API __declspec(dllimport)
		#endif
	#else
		#define RANDOM_ENGINE_API
	#endif
#else
	#error Random Engine only supports Windows!
#endif
