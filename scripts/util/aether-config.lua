

function aetherConfig()

	newoption {
		trigger 	= "backend",
		value 		= "BACK",
		description = "Choose a particular backend",
		allowed = {
			{ "backend-sdl", 		"SDL 2.0"},
			{ "backend-allegro", 	"Allegro 5.X"},
			{ "backend-dummy", 		"Don't do anything"}
		}
	}

	newoption {
		trigger 	= "has-audio",
		value 		= "VALUE",
		description = "Enables or disables audio support",
		allowed = {
			{ "enable-audio", 		"Disables audio"},
			{ "disable-audio", 		"Enables audio"},
		}
	}

end