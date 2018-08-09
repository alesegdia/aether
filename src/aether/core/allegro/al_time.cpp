
#include <allegro5/allegro5.h>

namespace aether {
namespace core {


uint64_t get_time()
{
    return uint64_t(1e6 * al_get_time());
}


}
}
