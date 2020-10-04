

function aetherBuild()
	dofile(path.join(AETHER_DIR, "scripts/aether-common-deps.lua"))
	dofile(path.join(AETHER_DIR, "scripts/libs/aether.lua"))

	local backend = _OPTIONS["backend"]
	if backend == "sdl" then
		dofile(path.join(AETHER_DIR, "scripts/aether-sdl-deps.lua"))
	elseif backend == "allegro" then
		print("in progress")
		os.exit(-1)
	else
		print("backend not defined yet")
		os.exit(-1)
	end
end