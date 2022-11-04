#include "REPCH.h"
#include "Instrumentor.h"

namespace RandomEngine::Profiling {

	Instrumentor::Instrumentor() : _currentSession(nullptr), _profileCount(0) { }

	Instrumentor& Instrumentor::Get() {
		static Instrumentor instance;
		return instance;
	}

	void Instrumentor::BeginSession(
		const std::string& name,
		const std::string& filePath
	) {
		_outputStream.open(filePath);
		WriteHeader();
		_currentSession = new InstrumentationSession{ name };
	}

	void Instrumentor::EndSession() {
		WriteFooter();
		_outputStream.close();
		delete _currentSession;
		_currentSession = nullptr;
		_profileCount = 0;
	}

	void Instrumentor::WriteProfile(const ProfileResult& result) {
		if (_profileCount++ > 0) _outputStream << ", ";

		std::string name = result.Name;
		std::replace(name.begin(), name.end(), '"', '\'');

		_outputStream << "{ ";
		_outputStream << "\"cat\": \"function\", ";
		_outputStream << "\"dur\": " << (result.End - result.Start) << ", ";
		_outputStream << "\"name\": \"" << name << "\", ";
		_outputStream << "\"ph\": \"X\", ";
		_outputStream << "\"pid\": 0,";
		_outputStream << "\"tid\": " << result.ThreadId << ", ";
		_outputStream << "\"ts\": " << result.Start;
		_outputStream << " }";

		_outputStream.flush();
	}

	void Instrumentor::WriteHeader() {
		_outputStream << "{ \"otherData\": { }, \"traceEvents\": [ ";
		_outputStream.flush();
	}

	void Instrumentor::WriteFooter() {
		_outputStream << " ] }";
		_outputStream.flush();
	}

}
