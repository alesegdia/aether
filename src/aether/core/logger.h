#pragma once

#include <string>
#include <ctime>
#include <iostream>
#include <chrono>
#include <cassert>
#include <sstream>

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
		class LogStream
		{
		public:
			LogStream(LogChannel channel) : m_channel(channel) {}
			
			template<typename T>
			LogStream& operator<<(const T& value)
			{
				m_stream << value;
				return *this;
			}

			~LogStream()
			{
				auto now = std::chrono::system_clock::now();
				auto now_time_t = std::chrono::system_clock::to_time_t(now);
				auto now_tm = *std::localtime(&now_time_t);
				std::cout << GetColorCode() << "[" << now << "] " << ChannelToString(m_channel) << ": " << m_stream.str() << std::endl;
				// std::cout << "[" << std::put_time(&now_tm, "%H:%M:%S") << "] " << ChannelToString(m_channel) << ": " << m_stream.str() << std::endl;
			}

		private:
			LogChannel m_channel;
			std::ostringstream m_stream;

			const char* GetColorCode()
			{
				switch (m_channel)
				{
				case LogChannel::Verbose: return "\033[0m"; break;
				case LogChannel::Warning: return "\033[33m"; break;
				case LogChannel::Error: return "\033[31m"; break;
				}
			}

			static std::string ChannelToString(LogChannel channel)
			{
				switch (channel)
				{
				case LogChannel::Verbose: return "ATH_MSG";
				case LogChannel::Warning: return "ATH_WARN";
				case LogChannel::Error: return "ATH_ERR";
				}
				assert(false);
				return "SHOULD NOT HAPPEN";
			}
		};

		static LogStream Log(LogChannel channel)
		{
			return LogStream(channel);
		}

		static LogStream LogMsg()
		{
			return Log(LogChannel::Verbose);
		}

		static LogStream LogError()
		{
			return Log(LogChannel::Error);
		}

		static LogStream LogWarning()
		{
			return Log(LogChannel::Warning);
		}
	};
}