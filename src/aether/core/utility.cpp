
#include <string>

#include "aether/core/utility.h"

namespace aether::core
{
    void split_string_by_delimiter(std::string str, const std::string& delimiter, std::vector<std::string>& out)
    {
        out.clear();
        size_t pos = 0;
        std::string token;
        while ((pos = str.find(delimiter)) != std::string::npos) {
            token = str.substr(0, pos);
            out.push_back(token);
            str.erase(0, pos + delimiter.length());
        }
    }

    void split_string_by_delimiter(std::string str, const std::string& delimiter, std::stack<std::string>& out)
    {
        size_t pos = 0;
        std::string token;
        while ((pos = str.find(delimiter)) != std::string::npos) {
            token = str.substr(0, pos);
            out.push(token);
            str.erase(0, pos + delimiter.length());
        }
    }


    std::string to_lower(std::string str)
    {
		std::transform(str.begin(), str.end(), str.begin(), ::tolower);
		return str;
    }
}