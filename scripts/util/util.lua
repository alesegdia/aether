
AETHER_EXTERNALS_DIR = path.getabsolute("../../3rdparty")
AETHER_PLUGINS_DIR = path.getabsolute("../../module")

AETHER_GENIE_PLUGINS_DIR = path.getabsolute("../../scripts/libs/plugins")
AETHER_GENIE_EXTERNALS_DIR = path.getabsolute("../../scripts/libs/3rdparty")

dofile("aether-build.lua")
dofile("aether-config.lua")
dofile("aether-project.lua")
dofile("cmake-configure.lua")
dofile("common.lua")