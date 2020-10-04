
function commonLibSetup(name)
	project(name)
		location (path.join(AETHER_DIR, "build"))
		kind "StaticLib"
		language "C++"
		configurations { "debug", "release" }
		targetdir ("../build")

		configuration {}		
			flags {
				-- "ExtraWarnings",
				-- "PedanticWarnings",
			}

		configuration {}
			flags {
				"StaticRuntime"
			}

		configuration { "debug" }
			flags {
				"Symbols",
			}

		configuration {}

end
