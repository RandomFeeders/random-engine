#pragma once

#include "RandomEngine/Core/Types.h"

namespace RandomEngine::Graphics {

	template<typename T>
	class Buffer {

		protected:
			T* _data;
			unsigned int _count;

		public:
			Buffer(T* data, unsigned int count) : _data(data), _count(count) { }
			virtual ~Buffer() = default;

			virtual void Bind() const = 0;
			virtual void Unbind() const = 0;

			virtual inline unsigned int GetCount() const { return _count; }
			virtual inline unsigned int GetSize() const { return _count * sizeof(T); }
	};

}
