#include "REPCH.h"
#include "Timer.h"

#include <algorithm>
#include <thread>

#include "RandomEngine/Profiling/Instrumentor.h"

namespace RandomEngine::Profiling {

	Timer::Timer(const char* name, bool autoStart, TimerOutput output)
		: _name(name), _started(false), _stopped(false), _callback([](Result result) {}), _output(output) {
		if (autoStart) {
			_startTimepoint = std::chrono::high_resolution_clock::now();
			_started = true;
		}
	}

	Timer::Timer(const char* name, Callback callback, bool autoStart, TimerOutput output)
		: _name(name), _started(false), _stopped(false), _callback(callback), _output(output) {
		if (autoStart) {
			_startTimepoint = std::chrono::high_resolution_clock::now();
			_started = true;
		}
	}

	Timer::~Timer() {
		if (_started && !_stopped) Stop();
	}

	void Timer::Start() {
		if (_started && !_stopped) Stop();

		_startTimepoint = std::chrono::high_resolution_clock::now();
		_started = true;
		_stopped = false;
	}

	void Timer::Stop() {
		if (!_started) return;

		auto endTimepoint = std::chrono::high_resolution_clock::now();

		long long start = std::chrono::time_point_cast<std::chrono::microseconds>(_startTimepoint)
			.time_since_epoch().count();
		long long end = std::chrono::time_point_cast<std::chrono::microseconds>(endTimepoint)
			.time_since_epoch().count();

		_stopped = true;

		float duration = (end - start) * 0.001f;

		if (HAS_FLAG(_output, TimerOutput::Trace)) RE_CORE_TRACE("{0} duration: {1}ms", _name, duration);
		if (HAS_FLAG(_output, TimerOutput::Callback)) _callback({ _name, duration });
		if (HAS_FLAG(_output, TimerOutput::Instrumentor)) {
			unsigned int threadId = std::hash<std::thread::id>{}(std::this_thread::get_id());
			Instrumentor::Get().WriteProfile({ _name, start, end, threadId });
		}
	}

}
