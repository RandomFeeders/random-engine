#pragma once

#include <memory>
#include <vector>
#include <string>

namespace RandomEngine {

	template<typename T>
	using Scope = std::unique_ptr<T>;

	template<typename T, typename ... Args>
	constexpr Scope<T> CreateScope(Args&& ... args) {
		return std::make_unique<T>(std::forward<Args>(args)...);
	}
	
	template<typename T>
	using Ref = std::shared_ptr<T>;

	template<typename T, typename ... Args>
	constexpr Ref<T> CreateRef(Args&& ... args) {
		return std::make_shared<T>(std::forward<Args>(args)...);
	}

	template<typename T, size_t s>
	using Array = std::array<T, s>;

	template<typename T>
	using List = std::vector<T>;

	template<typename T>
	using InitList = const std::initializer_list<T>&;

	template<typename T>
	using Iterator = std::vector<T>::iterator;

	template<typename T>
	using ConstIterator = std::vector<T>::const_iterator;

	template<typename T>
	using ReverseIterator = std::vector<T>::reverse_iterator;

	template<typename T>
	using ConstReverseIterator = std::vector<T>::const_reverse_iterator;

	using String = std::string;

	template<typename TKey, typename TValue>
	using Dictionary = std::unordered_map<TKey, TValue>;

	template<typename T>
	using Func = std::function<T>;

}
