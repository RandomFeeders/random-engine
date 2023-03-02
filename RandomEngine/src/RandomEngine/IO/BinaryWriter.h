#pragma once

#include "RandomEngine/Core/Types.h"

namespace RandomEngine::IO {

	class BinaryWriter {

		private:
			std::stringstream _stream;

			template<typename T>
			void InternalWrite(T value, int size = sizeof(T));

		public:
			BinaryWriter() = default;

			inline String GetValue() { return _stream.str(); }

			void Write(byte value);
			void Write(Ref<byte[]> value, ulong size);
			void Write(byte* value, ulong size);
			void Write(const String& value);

			void Write(float value);
			void Write(double value);
			void Write(short value);
			void Write(ushort value);
			void Write(int value);
			void Write(uint value);
			void Write(long value);
			void Write(ulong value);
			void Write(llong value);
			void Write(ullong value);
	};

}
