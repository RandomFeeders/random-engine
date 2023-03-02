#pragma once

#include "RandomEngine/Core/Base.h"
#include "RandomEngine/Core/Types.h"

namespace RandomEngine::IO {

	class File {

		public:
			enum class Mode : unsigned short {
				Open = 1,
				Create = 2,
				Truncate = 3,
				Append = 4
			};

			enum class Access : unsigned short {
				Read = BIT(0),
				Write = BIT(1),
				ReadWrite = Read | Write
			};

			FLAG(Access, unsigned short)

		private:
			String _path;
			Mode _mode;
			Access _access;
			ulong _size;
			String _content;

			Scope<std::fstream> _stream;

			bool Open();

		public:
			File(const String& path, Mode mode, Access access);
			~File();

			bool Read();
			void Write(const String& value);
			void Write(const Ref<byte[]>& value, ulong size);
			void Flush();
			bool Reset(const String& path, Mode mode, Access access);

			inline const String& GetContent() const { return _content; }
			inline ulong GetSize() const { return _size; }
			inline const String& GetPath() const { return _path; }
	};

}
