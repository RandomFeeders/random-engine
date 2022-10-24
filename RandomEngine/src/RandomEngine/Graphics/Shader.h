#pragma once

#include <string>

namespace RandomEngine::Graphics {

	class Shader {

		private:
			unsigned int _rendererId;

		public:
			Shader(const std::string& vertexSrc, const std::string& fragmentSrc);
			~Shader();

			void Bind() const;
			void Unbind() const;

	};

}
