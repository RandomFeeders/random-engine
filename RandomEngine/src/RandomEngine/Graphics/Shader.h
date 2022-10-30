#pragma once

#include "RandomEngine/Core/Types.h"

namespace RandomEngine::Graphics {

	class Shader;

	using ShaderRef = Ref<Shader>;

	class Shader {

		protected:
			using MapperFunc = Func<unsigned int(const String&)>;
			using Dictionary = Dictionary<unsigned int, String>;

		private:
			static Dictionary PreProcessFile(const String& source, MapperFunc mapper);

		public:
			Shader() = default;
			virtual ~Shader() = default;

			virtual void Bind() const = 0;
			virtual void Unbind() const = 0;

			static ShaderRef Create(const String& vertexSrc, const String& fragmentSrc);
			static ShaderRef Create(const String& filePath);
	};
}
