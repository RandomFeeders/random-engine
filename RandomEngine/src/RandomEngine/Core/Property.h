#pragma once

namespace RandomEngine {

	template<typename T>
	class Property {

		private:
			T _internalValue;

		public:
			T Value;

			Property(T value) : Value(value), _internalValue(value) { }

			operator T () const { return Value; }

			Property<T>& operator =(T value) {
				Value = value;
				_internalValue = value;
				return *this;
			}

			inline bool IsDirty() const { return Value != _internalValue; }
			inline void MarkAsPristine() { _internalValue = Value; }
			inline void Restore() { Value = _internalValue; }

	};

}
