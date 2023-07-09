#include "REPCH.h"
#include "BinaryReader.h"

namespace RandomEngine::IO {

	BinaryReader::BinaryReader(const String& content)
		: _content(content), _cursor(0) { }

	ullong BinaryReader::GetCursor() {
		auto cursor = _cursor++;
		if (_cursor > _content.size()) {
			RE_CORE_ASSERT(false, "Index {0} out of contents bounds", _cursor);
			return 0;
		}
		return cursor;
	}

	void BinaryReader::Seek(uint position) {
		if (position >= _content.length()) {
			RE_CORE_ASSERT(false, "Index {0} out of contents bounds", position);
			return;
		}

		if (position >= 0) {
			_cursor = position;
			return;
		}
		
		auto pos = _content.length() - position;
		if (pos < 0) {
			RE_CORE_ASSERT(false, "Index {0} out of contents bounds", position);
			return;
		}
		
		_cursor = pos;
	}

	template<typename T>
	T BinaryReader::InternalRead(ulong count) {
		auto bytes = new byte[count];
		for (ulong i = 0; i < count; i++) {
			bytes[i] = ReadByte();
		}

		T value = *reinterpret_cast<T*>(bytes);
		delete[] bytes;

		return value;
	}

	byte BinaryReader::ReadByte() {	
		auto cursor = GetCursor();
		return _content[cursor];
	}


	Ref<byte[]> BinaryReader::ReadBytes(ulong size) {
		auto result = CreateRef<byte[]>(size);

		for (ulong i = 0; i < size; i++) {
			result[i] = ReadByte();
		}

		return result;
	}

	String BinaryReader::ReadString() {
		auto size = InternalRead<ulong>();
		return ReadString(size);
	}

	String BinaryReader::ReadString(ulong size) {
		std::stringstream ss;
		for (ulong i = 0; i < size; i++) {
			ss << ReadByte();
		}
		return ss.str();
	}

	short BinaryReader::ReadShort() {
		return InternalRead<short>();
	}

	ushort BinaryReader::ReadUShort() {
		return InternalRead<ushort>();
	}

	int BinaryReader::ReadInt() {
		return InternalRead<int>();
	}

	uint BinaryReader::ReadUInt() {
		return InternalRead<uint>();
	}

	long BinaryReader::ReadLong() {
		return InternalRead<long>();
	}

	ulong BinaryReader::ReadULong() {
		return InternalRead<ulong>();
	}


	llong BinaryReader::ReadLongLong() {
		return InternalRead<llong>();
	}

	ullong BinaryReader::ReadULongLong() {
		return InternalRead<ullong>();
	}

	float BinaryReader::ReadFloat() {
		return InternalRead<float>();
	}

	double BinaryReader::ReadDouble() {
		return InternalRead<double>();
	}
}
