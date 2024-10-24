
AETHER_DIR = path.getabsolute("../")
AETHER_EXTERNALS_DIR = path.getabsolute("../3rdparty")
AETHER_PLUGINS_DIR = path.getabsolute("../module")

AETHER_GENIE_PLUGINS_DIR = path.getabsolute("../scripts/libs/plugins")
AETHER_GENIE_EXTERNALS_DIR = path.getabsolute("../scripts/libs/3rdparty")

dofile(path.join(AETHER_DIR, "scripts/util/util.lua"))

aetherConfig()

solution "aether"
	location "../build"
	configurations { "debug", "release" }
	platforms { "x32", "x64" }

	aetherBuild()

	group "tests"

	print("Scanning for tests...")
	for _, file in ipairs(os.matchdirs("../examples/*")) do
		print("Found test: " .. file)
		local extracted = file:match("([^/]+)$")
		aetherProject(extracted)
			debugdir (AETHER_DIR)
			flags { "Symbols", "StaticRuntime" }
			files {
				file .. "/**.*"
			}
	end
