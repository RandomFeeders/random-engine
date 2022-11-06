#pragma once

#include "RandomEngine/Core/Types.h"

#include <algorithm>
#include <chrono>
#include <fstream>
#include <iomanip>
#include <thread>

namespace RandomEngine::Profiling {

	using FloatingPointMicroseconds = std::chrono::duration<double, std::micro>;

	struct ProfileResult {
		String Name;
		FloatingPointMicroseconds Start; 
		std::chrono::microseconds ElapsedTime;
		std::thread::id ThreadId;
	};

	struct InstrumentationSession {
		String Name;
	};

	class Instrumentor {

		private:
			std::mutex _mutex;
			InstrumentationSession* _currentSession;
			std::ofstream _outputStream;

			void InternalEndSession();

		public:
			Instrumentor();

			static Instrumentor& Get();

			void BeginSession(const std::string& name, const std::string& filePath = "results.json");
			void EndSession();
			void WriteProfile(const ProfileResult& result);
			void WriteHeader();
			void WriteFooter();
	};

}

