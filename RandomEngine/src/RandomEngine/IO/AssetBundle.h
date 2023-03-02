#pragma once

#include "RandomEngine/Core/Types.h"
#include "RandomEngine/IO/Asset.h"
#include "RandomEngine/IO/File.h"

namespace RandomEngine::IO {

	class AssetBundle {

		private:
			static constexpr inline const char* HEADER = "REABv1";
			static constexpr inline uint HEADER_SIZE = 6;
			static constexpr inline uint MAX_SIZE = 268435456U;

			struct AssetItem {
				int index;
				String name;
				ushort type;
				ulong size;

				AssetItem(int index, const String& name, ushort type, ulong size) : index(index), name(name), type(type), size(size) { }
			};

			String _path;
			Scope<File> _file;
			Dictionary<String, AssetRef> _assets;
			List<Ref<byte[]>> _readBuffers;

			void Read();
			void ClearReadBuffers();

		public:
			AssetBundle() = default;
			AssetBundle(const AssetBundle&) = delete;
			AssetBundle& operator=(const AssetBundle&) = delete;

			void Push(const AssetRef& asset);
			const AssetRef& Get(const String& name);
			void Flush();

			static Ref<AssetBundle> Create(const String& path);
	};

}
