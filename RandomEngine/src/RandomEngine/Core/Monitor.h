#pragma once

#include "RandomEngine/Core/Types.h"

namespace RandomEngine {

	struct Monitor {

		public:
			int Index;
			String Name;
			uint Width;
			uint Height;

			Monitor()
				: Index(0),
				  Name("Monitor"),
				  Width(0),
				  Height(0) { }

			Monitor(
				int index,
				String name,
				uint width,
				uint height
			) : Index(index),
				Name(name),
				Width(width),
				Height(height) { }
	};

}

