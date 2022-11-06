#pragma once

#include "RandomEngine/Core/Base.h"

namespace RandomEngine::Profiling {

	enum class TimerOutput : short {
		None = 0,
		Trace = BIT(0),
		Instrumentor = BIT(1),
		Callback = BIT(2),
		All = Trace | Instrumentor | Callback
	};

	inline TimerOutput operator|(TimerOutput a, TimerOutput b) {
		return static_cast<TimerOutput>(static_cast<short>(a) | static_cast<short>(b));
	}

	inline TimerOutput operator&(TimerOutput a, TimerOutput b) {
		return static_cast<TimerOutput>(static_cast<short>(a) & static_cast<short>(b));
	}

}
