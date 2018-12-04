#pragma once

#include <vector>
#include <algorithm>


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


}
}
