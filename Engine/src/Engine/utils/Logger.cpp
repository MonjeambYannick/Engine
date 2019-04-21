#include "Logger.h"

namespace Engine
{

	std::shared_ptr<spdlog::logger> Log::Core_Logger;
	std::shared_ptr<spdlog::logger> Log::Client_Logger;

	void Log::Init()
	{
		// setting log message pattern
		spdlog::set_pattern("%^[%T] %n: %v%$"); // time naem and message n color (from cherno) TODO: change to schema
		Core_Logger = spdlog::stdout_color_mt("CORE");
		Core_Logger->set_level(spdlog::level::trace);
		Client_Logger = spdlog::stdout_color_mt("CLIENT");
		Client_Logger->set_level(spdlog::level::trace);
	}

}