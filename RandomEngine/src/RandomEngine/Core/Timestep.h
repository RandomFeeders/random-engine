#pragma once

namespace RandomEngine {

	class Timestep {

		private:
			float _time;

		public:
			Timestep(float time = 0.0f) : _time(time) { }

			operator float() const { return _time; }

			inline float GetSeconds() const { return _time; }
			inline float GetMilliseconds() const { return _time * 1000; }
	};

}
