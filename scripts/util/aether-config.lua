

function aetherConfig()

	newoption {
		trigger 	= "backend",
		value 		= "BACK",
		description = "Choose a particular backend",
		allowed = {
			{ "sdl", 		"SDL 2.0"},
			{ "allegro", 	"Allegro 5.X"},
			{ "dummy", 		"Don't do anything"}
		}
	}

	if not _OPTIONS["backend"] then
		printf("YOU MUST DEFINE A BACKEND WITH --backend")
		os.exit()
	end

end