#include "REPCH.h"
#include "BinaryWriter.h"

namespace RandomEngine::IO {

	template<typename T>
	void BinaryWriter::InternalWrite(T value, int size) {
		byte* ptr = reinterpret_cast<byte*>(&value);
		for (int i = 0; i < size; i++) {
			_stream << ptr[i];
		}
	}

	void BinaryWriter::Write(byte value) { 
		_stream << value; 
	}

	void BinaryWriter::Write(Ref<byte[]> value, ulong size) {
		for (ulong i = 0; i < size; i++) {
			_stream << value[i];
		}
	}

	void BinaryWriter::Write(byte* value, ulong size) {
		for (ulong i = 0; i < size; i++) {
			_stream << value[i];
		}
	}

	void BinaryWriter::Write(const String& value) {
		InternalWrite(value.size());
		_stream << value;
	}

	void BinaryWriter::Write(float value) {
		InternalWrite(value);
	}

	void BinaryWriter::Write(double value) {
		InternalWrite(value);
	}

	void BinaryWriter::Write(short value) {
		InternalWrite(value);
	}

	void BinaryWriter::Write(ushort value) {
		InternalWrite(value);
	}

	void BinaryWriter::Write(int value) {
		InternalWrite(value);
	}

	void BinaryWriter::Write(uint value) {
		InternalWrite(value);
	}

	void BinaryWriter::Write(long value) {
		InternalWrite(value);
	}

	void BinaryWriter::Write(ulong value) {
		InternalWrite(value);
	}

	void BinaryWriter::Write(llong value) {
		InternalWrite(value);
	}

	void BinaryWriter::Write(ullong value) {
		InternalWrite(value);
	}
}
