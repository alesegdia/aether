
#include <stdint.h>

namespace aether {
namespace core {

/// <summary>
/// Gets the time as an uint64_t in microseconds so one second is 1000000 or 1e6 in scientific notation
/// </summary>
/// <returns>The current time in microseconds</returns>
uint64_t get_time();

}
}

