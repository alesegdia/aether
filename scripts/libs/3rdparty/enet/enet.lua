dofile(path.join(AETHER_DIR, "scripts/util/common.lua"))

externalCommonLibSetup("enet", true)
    language "C++"

    configuration {}

    includedirs {
		path.join(AETHER_EXTERNALS_DIR, "enet/include/"),			
    }

    files {
		path.join(AETHER_EXTERNALS_DIR, "enet/*.c"),
    }

