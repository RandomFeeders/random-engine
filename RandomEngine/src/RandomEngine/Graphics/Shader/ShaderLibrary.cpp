#include "REPCH.h"
#include "ShaderLibrary.h"

namespace RandomEngine::Graphics {

	void ShaderLibrary::Add(const ShaderRef& shader) {
		auto& name = shader->GetName();
		RE_CORE_ASSERT(!Exists(name), "Shader already exists on library!");
		_shaders[name] = shader;
	}

	ShaderRef ShaderLibrary::Load(const String& filePath) {
		auto shader = Shader::Create(filePath);
		Add(shader);
		return shader;
	}

	ShaderRef ShaderLibrary::Load(const String& name, const String& filePath) {
		auto shader = Shader::Create(filePath, name);
		Add(shader);
		return shader;
	}

	ShaderRef ShaderLibrary::Load(const String& name, const String& vertexSrc, const String& fragmentSrc) {
		auto shader = Shader::Create(name, vertexSrc, fragmentSrc);
		Add(shader);
		return shader;
	}

	ShaderRef ShaderLibrary::Get(const String& name) {
		RE_CORE_ASSERT(Exists(name), "Shader not found on library!");
		return _shaders[name];
	}


	bool ShaderLibrary::Exists(const String& name) const {
		return _shaders.find(name) != _shaders.end();
	}

}
