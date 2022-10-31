#pragma once

#include "RandomEngine/Core/Types.h"
#include "RandomEngine/Graphics/Shader/Shader.h"

namespace RandomEngine::Graphics {

	class ShaderLibrary {

		private:
			Dictionary<String, ShaderRef> _shaders;

		public:
			void Add(const ShaderRef& shader);
			ShaderRef Load(const String& filePath);
			ShaderRef Load(const String& name, const String& filePath);
			ShaderRef Load(const String& name, const String& vertexSrc, const String& fragmentSrc);

			ShaderRef Get(const String& name);
			bool Exists(const String& name) const;
	};

}
