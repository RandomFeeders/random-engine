#pragma once

#include "RandomEngine/Core/Types.h"
#include "RandomEngine/Graphics/Shader/ShaderDataType.h"

namespace RandomEngine::Graphics {

	struct BufferElement {
		String Name;
		ShaderDataType Type;
		unsigned int Offset;
		unsigned int Size;
		unsigned int ComponentCount;
		bool Normalized;

		BufferElement()
			: Name("_element"), Type(ShaderDataType::None), Size(0),
			  Offset(0), ComponentCount(0), Normalized(false) { }

		BufferElement(const String& name, ShaderDataType type, bool normalized = false)
			: Name(name), Type(type), Size(GetShaderDataTypeSize(type)),
			Offset(0), ComponentCount(GetShaderDataTypeCount(type)),
			Normalized(normalized) { }
	};

	class BufferLayout {

		private:
			List<BufferElement> _elements;
			unsigned int _stride;

			void Init();

		public:
			BufferLayout();
			BufferLayout(const InitList<BufferElement>& elements);

			inline const List<BufferElement>& GetElements() const { return _elements; }
			inline const unsigned int GetStride() const { return _stride; }

			Iterator<BufferElement> begin() { return _elements.begin(); }
			Iterator<BufferElement> end() { return _elements.end(); }
			ConstIterator<BufferElement> begin() const { return _elements.begin(); }
			ConstIterator<BufferElement> end() const { return _elements.end(); }
	};

}
