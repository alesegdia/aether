
#include <raylib.h>

#include <cstdint>

namespace aether {
namespace core {


uint64_t get_time()
{
    return uint64_t(1e6 * GetTime());
}


}
}
