#include "REPCH.h"
#include "Log.h"

#include <ctime>

namespace RandomEngine {

	bool Log::_hasInit = false;
	Ref<spdlog::logger> Log::_coreLogger;
	Ref<spdlog::logger> Log::_clientLogger;

	void Log::Init() {
		time_t now = time(0);
		tm* ltm = localtime(&now);
		std::stringstream date;
		date << 1900 + ltm->tm_year << "-";
		date << std::setfill('0') << std::setw(2) << 1 + ltm->tm_mon << "-";
		date << std::setfill('0') << std::setw(2) << ltm->tm_mday << " ";
		date << std::setfill('0') << std::setw(2) << ltm->tm_hour << "-";
		date << std::setfill('0') << std::setw(2) << ltm->tm_min << "-";
		date << std::setfill('0') << std::setw(2) << ltm->tm_sec;

		String filename = "logs/" + date.str() + ".log";

		List<Ref<spdlog::sinks::sink>> logSinks;
		logSinks.emplace_back(CreateRef<spdlog::sinks::stdout_color_sink_mt>());
		logSinks.emplace_back(CreateRef<spdlog::sinks::basic_file_sink_mt>(filename, true));

		logSinks[0]->set_pattern("%^[%d/%m/%C %H:%M:%S] %n: %v%$");
		logSinks[1]->set_pattern("%^[%d/%m/%C %H:%M:%S] [%l] %n: %v%$");

		_coreLogger = CreateRef<spdlog::logger>("Random Engine", begin(logSinks), end(logSinks));
		spdlog::register_logger(_coreLogger);
		_coreLogger->set_level(spdlog::level::trace);
		_coreLogger->flush_on(spdlog::level::trace);

		_clientLogger = CreateRef<spdlog::logger>("Application", begin(logSinks), end(logSinks));
		spdlog::register_logger(_clientLogger);
		_clientLogger->set_level(spdlog::level::trace);
		_clientLogger->flush_on(spdlog::level::trace);

		_hasInit = true;
	}

}
