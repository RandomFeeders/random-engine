#include "REPCH.h"
#include "File.h"

#include <fstream>

namespace RandomEngine::IO {

	File::File(const String& path, Mode mode, Access access) 
		: _path(path), _mode(mode), _access(access), _size(0) {

		Open(); 
	}

	File::~File() {
		_stream->close();
	}

	bool File::Open() {
		std::ios::openmode mode = std::ios::binary;
		
		if (HAS_FLAG(_access, Access::Read)) mode = mode | std::ios::in;
		if (HAS_FLAG(_access, Access::Write)) mode = mode | std::ios::out;

		if (_mode == Mode::Open) mode = mode | std::ios::_Nocreate;
		if (_mode == Mode::Create) mode = mode | std::ios::_Noreplace;
		if (_mode == Mode::Append) mode = mode | std::ios::app;
		if (_mode == Mode::Truncate) mode = mode | std::ios::trunc;

		_stream = CreateScope<std::fstream>(_path, mode);

		if (!_stream) {
			RE_CORE_ASSERT(false, "Could not open file '{0}'", _path);
			return false;
		}

		return true;
	}

	bool File::Read() {
		_stream->seekg(0, std::ios::end);
		_size = (ulong)_stream->tellg();

		if (_size == -1) {
			RE_CORE_ASSERT(false, "Could not read file '{0}'", _path);
			return false;
		}

		_content.resize(_size);

		_stream->seekg(0, std::ios::beg);
		_stream->read(_content.data(), _size);

		return true;
	}

	bool File::Reset(const String& path, Mode mode, Access access) {
		if (mode != _mode || access != _access) {
			_mode = mode;
			_access = access;
			_path = path;
			_size = 0;
			
			_stream->close();
			_stream.reset();

			return Open();
		}

		return false;
	}

	void File::Write(const String& value) { 
		_stream->write(value.c_str(), value.length()); 
	}

	void File::Write(const Ref<byte[]>& value, ulong size) {
		_stream->write((char*)value.get(), size);
	}

	void File::Flush() {
		_stream->flush(); 
	}

}
