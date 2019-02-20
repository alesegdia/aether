#pragma once

namespace aether {
namespace math {


template <typename T, typename Callable>
void tween(T* value, T from, T to, Callable* callable);


template <typename T, typename Callable>
void tween(T* value, T to, Callable* callable);


}
}
