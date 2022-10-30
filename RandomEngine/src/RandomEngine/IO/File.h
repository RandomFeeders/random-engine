#pragma once

#include "RandomEngine/Core/Types.h"

namespace RandomEngine::IO {

	class File {

		private:
			const String& _path;
			unsigned long long _size;
			String _content;

			bool Open();

		public:
			File(const String& path);

			bool Reload();

			inline const String& Read() const { return _content; }
			inline unsigned long long GetSize() const { return _size; }
			inline const String& GetPath() const { return _path; }

	};

}
