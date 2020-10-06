

function aetherBuild()
	dofile(path.join(AETHER_DIR, "scripts/deps/aether-common-deps.lua"))
	dofile(path.join(AETHER_DIR, "scripts/libs/aether.lua"))

	local backend = _OPTIONS["backend"]
	if backend == "backend-sdl" then
		dofile(path.join(AETHER_DIR, "scripts/deps/aether-sdl-deps.lua"))
	elseif backend == "backend-allegro" then
		dofile(path.join(AETHER_DIR, "scripts/deps/aether-allegro-deps.lua"))		
	else
		print("backend not defined yet")
		os.exit(-1)
	end
end