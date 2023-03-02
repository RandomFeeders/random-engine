#pragma once

#include "RandomEngine/Core/Types.h"

namespace RandomEngine::IO {

	class Asset;

	using AssetRef = Ref<Asset>;
	using AssetData = Ref<byte[]>;

	class Asset {

		public:
			enum class Type : ushort {
				Unknown = 0,
				Text = 1,
				Texture2D = 2,
				Model3D = 3,
				Audio = 4,
				Video = 5
			};

		private:
			String _name;
			AssetData _data;
			ulong _size;
			Type _type;

		public:
			Asset() = default;

			inline Type GetType() const { return _type; }
			inline const AssetData& GetData() const { return _data; }
			inline ulong GetSize() const { return _size; }
			inline const String& GetName() const { return _name; }

			static AssetRef Create(const String& path, const String& name, Asset::Type type);
			static AssetRef Create(const AssetData& data, ulong size, const String& name, Asset::Type type);
	};

}
