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
			String _name;

			static Dictionary PreProcessFile(const String& source, MapperFunc mapper);

		public:
			Shader() = default;
			virtual ~Shader() = default;

			virtual void Bind() const = 0;
			virtual void Unbind() const = 0;

			virtual const String& GetName() const { return _name; };

			static ShaderRef Create(const String& name, const String& vertexSrc, const String& fragmentSrc);
			static ShaderRef Create(const String& filePath, const String& name = String());
	};
}
