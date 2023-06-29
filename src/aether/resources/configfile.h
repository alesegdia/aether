#pragma once

#include <fstream>

#include "inipp/inipp.h"

namespace aether
{
	namespace resources
	{

		class ConfigFile
		{
		public:
			ConfigFile()
			{
				
			}

			void Load(const char* path)
			{
				std::ifstream is(path);
				m_ini.parse(is);
			}

			template <typename T>
			bool GetValue(std::string section, std::string variable, T& outputValue)
			{
				if (m_ini.sections.count(section) == 0) return false;
				if (m_ini.sections[section].count(variable) == 0) return false;
				inipp::get_value(m_ini.sections[section], variable, outputValue);
				return true;
			}

		private:
			inipp::Ini<char> m_ini;

		};

	}
}