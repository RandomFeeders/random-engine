#include "REPCH.h"
#include "Instrumentor.h"

namespace RandomEngine::Profiling {

	Instrumentor::Instrumentor() : _currentSession(nullptr) { }

	Instrumentor& Instrumentor::Get() {
		static Instrumentor instance;
		return instance;
	}

	void Instrumentor::BeginSession(
		const std::string& name,
		const std::string& filePath
	) {
		std::lock_guard lock(_mutex);

		if (_currentSession) {
			if (Logger::HasInit()) {
				RE_CORE_ERROR(
					"Instrumentor::BeginSession('{0}') when session '{1}' already open.", 
					name, 
					_currentSession->Name
				);
			}

			InternalEndSession();
		}

		_outputStream.open(filePath);
		if (_outputStream.is_open()) {
			_currentSession = new InstrumentationSession{ name };
			WriteHeader();
		} else if (Logger::HasInit()) {
			RE_CORE_ERROR("Instrumentor could not open results file '{0}'.", filePath);
		}		
	}

	void Instrumentor::EndSession() {
		std::lock_guard lock(_mutex);
		InternalEndSession();		
	}

	void Instrumentor::InternalEndSession() {
		if (_currentSession) {
			WriteFooter();
			_outputStream.close();
			delete _currentSession;
			_currentSession = nullptr;
		}
	}

	void Instrumentor::WriteProfile(const ProfileResult& result) {
		std::stringstream json;

		std::string name = result.Name;
		std::replace(name.begin(), name.end(), '"', '\'');

		json << std::setprecision(3) << std::fixed;
		json << ", { ";
		json << "\"cat\": \"function\", ";
		json << "\"dur\": " << (result.ElapsedTime.count()) << ", ";
		json << "\"name\": \"" << name << "\", ";
		json << "\"ph\": \"X\", ";
		json << "\"pid\": 0,";
		json << "\"tid\": " << result.ThreadId << ", ";
		json << "\"ts\": " << result.Start.count();
		json << " }";

		std::lock_guard lock(_mutex);
		if (_currentSession) {
			_outputStream << json.str();
			_outputStream.flush();
		}
	}

	void Instrumentor::WriteHeader() {
		_outputStream << "{ \"otherData\": { }, \"traceEvents\": [ { }";
		_outputStream.flush();
	}

	void Instrumentor::WriteFooter() {
		_outputStream << " ] }";
		_outputStream.flush();
	}

}
