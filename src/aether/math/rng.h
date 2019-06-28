#pragma once

#include <random>

namespace aether {
namespace math {

int randi(int min, int max);

int randi(int max);


size_t split(const std::string &txt, std::vector<std::string> &strs, char ch);

}
}
