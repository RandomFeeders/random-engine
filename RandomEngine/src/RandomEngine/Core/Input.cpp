#include "REPCH.h"
#include "Input.h"

#ifdef RE_PLATFORM_WINDOWS
	#include "Platform/Windows/WindowsInput.h"
#endif

namespace RandomEngine {

	Scope<Input> Input::_instance = Create();

	Scope<Input> Input::Create() {
		#ifdef RE_PLATFORM_WINDOWS
			return CreateScope<WindowsInput>();
		#else
			RE_CORE_ASSERT(false, "Unknown platform!");
			return nullptr;
		#endif
	}

}
