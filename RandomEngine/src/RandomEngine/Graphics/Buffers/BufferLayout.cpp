#include "REPCH.h"
#include "BufferLayout.h"

namespace RandomEngine::Graphics {

	BufferLayout::BufferLayout() : _stride(0) { }

	BufferLayout::BufferLayout(const InitList<BufferElement>& elements)
		: _elements(elements), _stride(0) { 
		Init();
	}

	void BufferLayout::Init() {
		_stride = 0;
		for (auto& element : _elements) {
			element.Offset = _stride;
			_stride += element.Size;
		}
	}

}
