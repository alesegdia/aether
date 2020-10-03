#pragma once

#include "platform.h"

#include "audio/sample.h"
#include "audio/stream.h"

#include "core/time.h"
#include "core/resourcemanager.h"
#include "core/iscreen.h"

#include "graphics/color.h"
#include "graphics/font.h"
#include "graphics/graphics.h"
#include "graphics/spritesheet.h"
#include "graphics/texture.h"
#include "graphics/animation.h"
#include "graphics/asepriteanimloader.h"

#ifdef AETHER_USE_CAMERA
#include "graphics/camera.h"
#endif

#include "math/matrix.h"
#include "math/vec.h"
#include "math/rect.h"
#include "math/rng.h"

#ifdef AETHER_USE_MAP
#include "map/collisiontilemap.h"
#include "map/tilemap.h"
#endif

#include "scene/scene.h"
#include "scene/texturenode.h"
#include "scene/animationnode.h"
#include "scene/gridnode.h"

#include "json11.hpp"
