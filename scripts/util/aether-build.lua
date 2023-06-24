

function aetherBuild()
	dofile(path.join(AETHER_DIR, "scripts/deps/aether-common-deps.lua"))
	dofile(path.join(AETHER_GENIE_PLUGINS_DIR, "aether/aether.lua"))

	local backend = _OPTIONS["backend"]
	if backend == "backend-sdl" then
		dofile(path.join(AETHER_DIR, "scripts/deps/aether-sdl-deps.lua"))
	elseif backend == "backend-allegro" then
		dofile(path.join(AETHER_DIR, "scripts/deps/aether-allegro-deps.lua"))		
	elseif backend == "backend-raylib" then
		dofile(path.join(AETHER_DIR, "scripts/deps/aether-raylib-deps.lua"))		
	elseif backend == "backend-gl" then
		dofile(path.join(AETHER_DIR, "scripts/deps/aether-gl-deps.lua"))		
	else
		print("backend not defined yet")
		os.exit(-1)
	end
end