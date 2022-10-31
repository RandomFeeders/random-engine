#pragma once

#include "RandomEngine/Core/PlatformDetection.h"

#include <iostream>
#include <memory>
#include <utility>
#include <algorithm>
#include <functional>

#include <string>
#include <sstream>
#include <vector>
#include <array>
#include <unordered_map>
#include <unordered_set>

#include "RandomEngine/Core/Base.h"
#include "RandomEngine/Core/Log.h"

#ifdef RE_PLATFORM_WINDOWS
	#include <Windows.h>
#endif
