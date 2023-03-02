#include "REPCH.h"
#include "Asset.h"

#include "RandomEngine/IO/File.h"

namespace RandomEngine::IO {

	AssetRef Asset::Create(const String& path, const String& name, Asset::Type type) {
		File file(path, File::Mode::Open, File::Access::Read);

		if (!file.Read() || file.GetSize() <= 0) {
			RE_CORE_ASSERT(false, "Could not read asset '{0}'", path);
			return nullptr;
		}

		auto content = file.GetContent();
		AssetRef asset = CreateRef<Asset>();
		asset->_type = type;
		asset->_data = CreateRef<byte[]>(content.size());		
		for (ulong i = 0; i < file.GetContent().size(); i++) {
			asset->_data[i] = content[i];
		}
		asset->_size = file.GetSize();
		asset->_name = name;

		return asset;
	}

	AssetRef Asset::Create(const AssetData& data, ulong size, const String& name, Asset::Type type) {
		auto asset = CreateRef<Asset>();
		asset->_type = type;
		asset->_data = data;
		asset->_name = name;
		asset->_size = size;
		return asset;
	}

}
