#pragma once

#include <memory>
#include <vector>
#include <string>

namespace RandomEngine {

	template<typename T>
	using Scope = std::unique_ptr<T>;

	template<typename T>
	using Ref = std::shared_ptr<T>;

	template<typename T>
	using List = std::vector<T>;

	template<typename T>
	using InitList = const std::initializer_list<T>&;

	template<typename T>
	using Iterator = std::vector<T>::iterator;

	template<typename T>
	using ConstIterator = std::vector<T>::const_iterator;

	using String = std::string;

	template<typename T>
	using Func = std::function<T>;

}
