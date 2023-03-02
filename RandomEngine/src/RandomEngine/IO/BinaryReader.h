#pragma once

#include "RandomEngine/Core/Types.h"

namespace RandomEngine::IO {

	class BinaryReader {

		private:
			String _content;
			ulong _cursor;

			template<typename T>
			T InternalRead(ulong count = sizeof(T));

			ulong GetCursor();

		public:
			BinaryReader(const String& content);

			void Seek(uint position);

			byte ReadByte();
			Ref<byte[]> ReadBytes(ulong size);
			String ReadString();
			String ReadString(ulong size);

			short ReadShort();
			ushort ReadUShort();
			int ReadInt();
			uint ReadUInt();
			long ReadLong();
			ulong ReadULong();
			llong ReadLongLong();
			ullong ReadULongLong();
			float ReadFloat();
			double ReadDouble();
	};

}
