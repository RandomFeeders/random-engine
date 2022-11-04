#pragma once

#include "RandomEngine/Core/Types.h"

#include <chrono>
#include <algorithm>
#include <fstream>
#include <thread>

namespace RandomEngine::Profiling {

	struct ProfileResult {
		String Name;
		long long Start, End;
		unsigned int ThreadId;
	};

	struct InstrumentationSession {
		String Name;
	};

	class Instrumentor {

		private:
			InstrumentationSession* _currentSession;
			std::ofstream _outputStream;
			int _profileCount;

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

