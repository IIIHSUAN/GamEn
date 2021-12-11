#pragma once

#include "Core.h"

// This ignores all warnings raised inside External headers
#pragma warning(push, 0)
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#pragma warning(pop)

#define CC(x) { std::cout<<x<<'\n'; }

#define CC_ERR(...) ::GamEn::Log::getCoreLogger()->error(__VA_ARGS__)
#define CC_TRACE(...) ::GamEn::Log::getCoreLogger()->trace(__VA_ARGS__)
#define CC_WARN(...) ::GamEn::Log::getCoreLogger()->warn(__VA_ARGS__)
#define CC_INFO(...) ::GamEn::Log::getCoreLogger()->info(__VA_ARGS__)
#define CC_FATAL(...) ::GamEn::Log::getCoreLogger()->fatal(__VA_ARGS__)

#define LOG_ERR(...) ::GamEn::Log::getClientLogger()->error(__VA_ARGS__) 
#define LOG_TRACE(...) ::GamEn::Log::getClientLogger()->trace(__VA_ARGS__) 
#define LOG_WARN(...) ::GamEn::Log::getClientLogger()->warn(__VA_ARGS__) 
#define LOG_INFO(...) ::GamEn::Log::getClientLogger()->info(__VA_ARGS__)
#define LOG_FATAL(...) ::GamEn::Log::getClientLogger()->fatal(__VA_ARGS__)


namespace GamEn {

	class GE_API Log
	{
	private:
		static std::shared_ptr<spdlog::logger> _core_logger;
		static std::shared_ptr<spdlog::logger> _client_logger;
	public:
		static void init();
		inline static std::shared_ptr<spdlog::logger>&  getCoreLogger() { return _core_logger; }
		inline static std::shared_ptr<spdlog::logger>&  getClientLogger() { return _client_logger; }
	};
}