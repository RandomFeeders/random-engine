#pragma once

#include <chrono>
#include <format>
#include "RandomEngine/Core/Types.h"

namespace RandomEngine::Profiling {

	class Timer {

		public:
			struct Result { 
				const char* Name; 
				float Duration; 

				inline String ToString() const { 
					return std::format("{:.3f}ms ", Duration) + String(Name);
				}

				friend std::ostream& operator<<(std::ostream& stream, const Result& vector) {
					stream << vector.ToString();
					return stream;
				}
			};

			using Callback = Func<void(Result)>;

		private:
			const char* _name;
			Callback _callback;
			std::chrono::time_point<std::chrono::steady_clock> _startTimepoint;
			bool _stopped, _started, _trace;

		public:
			Timer(const char* name, bool autoStart = true, bool trace = false);
			Timer(const char* name, Callback callback, bool autoStart = true, bool trace = false);
			~Timer();

			void Start();
			void Stop();

			inline void SetCallback(const Callback& callback) { _callback = callback; }
	};

}
