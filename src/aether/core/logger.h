#pragma once

#include <string>
#include <ctime>
#include <iostream>
#include <chrono>

namespace aether
{
	enum class LogChannel
	{
		Verbose,
		Warning,
		Error
	};

	class Logger
	{
	public:

		static void Log(LogChannel channel, const std::string& message)
		{
			auto now = std::chrono::system_clock::now();
			std::cout << "[" << now << "] " << ChannelToString(channel) << ": " << message << std::endl;
		}

		static void LogMsg(const std::string& msg)
		{
			Log(LogChannel::Verbose, msg);
		}

		static void LogError(const std::string& msg)
		{
			Log(LogChannel::Error, msg);
		}

		static std::string ChannelToString(LogChannel channel)
		{
			switch (channel)
			{
			case LogChannel::Verbose: return "ATH_MSG";
			case LogChannel::Warning: return "ATH_WARN";
			case LogChannel::Error: return "ATH_ERR";
			}
		}
	};
}