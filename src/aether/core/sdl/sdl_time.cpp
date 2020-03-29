
#include <cstdint>
#include <SDL.h>

namespace aether {
namespace core {


uint64_t get_time()
{
    return uint64_t(SDL_GetTicks() * 1e3);
}


}
}
