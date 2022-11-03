#include "REPCH.h"
#include "Timer.h"

namespace RandomEngine::Profiling {

	Timer::Timer(const char* name, bool autoStart, bool trace)
		: _name(name), _started(false), _stopped(false), _callback([](Result result) {}), _trace(trace) {
		if (autoStart) {
			_startTimepoint = std::chrono::high_resolution_clock::now();
			_started = true;
		}
	}

	Timer::Timer(const char* name, Callback callback, bool autoStart, bool trace)
		: _name(name), _started(false), _stopped(false), _callback(callback), _trace(trace) {
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

		if (_trace) RE_CORE_TRACE("{0} duration: {1}ms", _name, duration);

		_callback({ _name, duration });
	}

}
