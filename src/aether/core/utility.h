#pragma once

#include <vector>
#include <stack>
#include <algorithm>
#include <string>


namespace aether {
namespace core {


template< typename T, typename Pred >
typename std::vector<T>::iterator
    insert_sorted( std::vector<T> & vec, T const& item, Pred pred )
{
    return vec.insert
        (
           std::upper_bound( vec.begin(), vec.end(), item, pred ),
           item
        );
}


template <typename T>
void remove_by_value(std::vector<T>& v, const T& t)
{
    v.erase(std::remove(v.begin(), v.end(), t), v.end());
}

void split_string_by_delimiter(std::string str, const std::string& delimiter, std::vector<std::string>& out);
void split_string_by_delimiter(std::string str, const std::string& delimiter, std::stack<std::string>& out);

std::string to_lower(std::string str);

}
}
