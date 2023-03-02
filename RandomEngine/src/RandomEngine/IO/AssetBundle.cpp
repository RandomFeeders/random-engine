#include "REPCH.h"
#include "AssetBundle.h"

#include "RandomEngine/Core/Base.h"
#include "RandomEngine/IO/BinaryWriter.h"
#include "RandomEngine/IO/BinaryReader.h"

namespace RandomEngine::IO {

	Ref<AssetBundle> AssetBundle::Create(const String& path) {
		auto bundle = CreateRef<AssetBundle>();
		bundle->_path = path;
		bundle->_file = CreateScope<File>(path, File::Mode::Append, File::Access::ReadWrite);
		bundle->_file->Read();

		if (bundle->_file->GetSize() > 0) {
			bundle->Read();
		}
		
		return bundle;
	}

	void AssetBundle::ClearReadBuffers() {
		while (!_readBuffers.empty()) {
			_readBuffers.front().reset();
			_readBuffers.erase(_readBuffers.begin());
		}
	}

	void AssetBundle::Read() {
		BinaryReader br(_file->GetContent());

		auto header = br.ReadString(HEADER_SIZE);

		if (strcmp(header.c_str(), (char*)HEADER) != 0) {
			RE_CORE_ASSERT(false, "Could not read bundle '{0}'", _path);
			return;
		}

		List<AssetItem> items;
		auto tableLength = br.ReadUInt();
		auto table = br.ReadString();

		if (table.size() > 0) {
			BinaryReader brTable(table);
			for (auto i = 0; i < tableLength; i++) {
				auto index = brTable.ReadInt();
				auto name = brTable.ReadString();
				auto type = brTable.ReadUShort();
				auto size = brTable.ReadULong();

				AssetItem item(index, name, type, size);

				items.push_back(item);
			}
		}		

		ClearReadBuffers();

		for (auto& item : items) {
			AssetData data = br.ReadBytes(item.size);
			_readBuffers.push_back(data);
			auto asset = Asset::Create(data, item.size, item.name, (Asset::Type)item.type);
			Push(asset);
		}
	}

	void AssetBundle::Push(const AssetRef& asset) {
		_assets.insert({ asset->GetName(), asset});
	}

	const AssetRef& AssetBundle::Get(const String& name) {
		return _assets.at(name);
	}

	void AssetBundle::Flush() {
		BinaryWriter bw;
		
		bw.Write((byte*)HEADER, HEADER_SIZE);

		uint i = 0;
		BinaryWriter bwTable;
		for (auto& asset : _assets) {
			bwTable.Write((uint)i++);
			bwTable.Write(asset.second->GetName());
			bwTable.Write((ushort)asset.second->GetType());
			bwTable.Write((ulong)asset.second->GetSize());
		}

		bw.Write(i);
		bw.Write(bwTable.GetValue());

		for (auto& asset : _assets) {
			bw.Write(asset.second->GetData(), asset.second->GetSize());
		}

		auto content = bw.GetValue();
		if (content.size() >= MAX_SIZE) {
			RE_CORE_ASSERT(false, "Bundle '{0}' is too big", _path);
			return;
		}

		_file->Reset(_path, File::Mode::Truncate, File::Access::Write);
		_file->Reset(_path, File::Mode::Append, File::Access::ReadWrite);
		_file->Read();
		_file->Write(content);
		_file->Flush();
	}

}
