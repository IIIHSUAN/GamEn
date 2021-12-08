#include "Log.h"

namespace GamEn {
	std::shared_ptr<spdlog::logger> Log::_core_logger, Log::_client_logger;

	void Log::init()
	{
		spdlog::set_pattern("%^%T [%n] %v%$");
		_core_logger = spdlog::stdout_color_mt("GamEn");
		_core_logger->set_level(spdlog::level::trace);

		_client_logger = spdlog::stdout_color_mt("App");
		_client_logger->set_level(spdlog::level::trace);
	}
}