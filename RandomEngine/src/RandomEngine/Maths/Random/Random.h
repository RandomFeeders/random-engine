#pragma once

namespace RandomEngine::Maths {

	class Random {

		public:

			static Scope<ullong[]> LCG(
				ullong seed,
				ullong modulus,
				ullong multiplier,
				ullong increment,
				uint count
			);

			static Scope<ullong[]> QCG(
				ullong seed,
				ullong modulus,
				ullong multiplier,
				ullong increment,
				uint count
			);
	};
}
