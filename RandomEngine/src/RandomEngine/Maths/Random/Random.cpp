#include "REPCH.h"

#include <glm/ext.hpp>

#include "Random.h"

namespace RandomEngine::Maths {

	Scope<ullong[]> Random::LCG(
		ullong seed,
		ullong modulus,
		ullong multiplier,
		ullong increment,
		uint count
	) {
		auto result = CreateScope<ullong[]>(count);
		auto start = seed;

		for (uint i = 0; i < count; i++) {
			start = ((multiplier * start) + increment) % modulus;
			result[i] = start;
		}

		return result;
	}

	Scope<ullong[]> Random::QCG(
		ullong seed,
		ullong modulus,
		ullong multiplier,
		ullong increment,
		uint count
	) {
		auto result = CreateScope<ullong[]>(count);
		auto start = seed;

		for (uint i = 0; i < count; i++) {
			start = ((multiplier * ((ullong)glm::pow(start, 2))) + increment) % modulus;
			result[i] = start;
		}

		return result;
	}

}
