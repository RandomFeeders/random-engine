#pragma once

#include <string>
#include <vector>

#include "RandomEngine/Graphics/ShaderDataType.h"

namespace RandomEngine::Graphics {

	struct BufferElement {
		std::string Name;
		ShaderDataType Type;
		unsigned int Offset;
		unsigned int Size;
		unsigned int ComponentCount;
		bool Normalized;

		BufferElement()
			: Name("_element"), Type(ShaderDataType::None), Size(0),
			  Offset(0), ComponentCount(0), Normalized(false) { }

		BufferElement(const std::string& name, ShaderDataType type, bool normalized = false)
			: Name(name), Type(type), Size(GetShaderDataTypeSize(type)),
			Offset(0), ComponentCount(GetShaderDataTypeCount(type)),
			Normalized(normalized) { }
	};

	class BufferLayout {

		private:
			std::vector<BufferElement> _elements;
			unsigned int _stride;

			void Init();

		public:
			BufferLayout();
			BufferLayout(const std::initializer_list<BufferElement>& elements);

			inline const std::vector<BufferElement>& GetElements() const { return _elements; }
			inline const unsigned int GetStride() const { return _stride; }

			std::vector<BufferElement>::iterator begin() { return _elements.begin(); }
			std::vector<BufferElement>::iterator end() { return _elements.end(); }
			std::vector<BufferElement>::const_iterator begin() const { return _elements.begin(); }
			std::vector<BufferElement>::const_iterator end() const { return _elements.end(); }

			static BufferLayout& Default();
	};

}
