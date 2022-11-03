#include "REPCH.h"
#include "File.h"

#include <fstream>
#include "RandomEngine/Core/Base.h"

namespace RandomEngine::IO {

	File::File(const String& path) : _path(path), _size(0) { Open(); }

	bool File::Open() {
		std::ifstream in(_path, std::ios::in | std::ios::binary);

		if (!in) {
			RE_CORE_ASSERT(false, "Could not open file '{0}'", _path);
			return false;
		}

		in.seekg(0, std::ios::end);
		_size = in.tellg();

		if (_size == -1) {
			RE_CORE_ASSERT(false, "Could not read file '{0}'", _path);
			return false;
		}

		_content.resize(_size);

		in.seekg(0, std::ios::beg);
		in.read(&_content[0], _size);
		in.close();

		return true;
	}

	bool File::Reload() {
		return Open();
	}

}
