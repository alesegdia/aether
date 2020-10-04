
function commonFlags()
	configuration {}
		flags {
			"StaticRuntime"
		}

	configuration { "debug" }
		flags {
			"Symbols"
		}

	configuration { "release" }
		flags {
			"Optimize",
			"OptimizeSize",
			"OptimizeSpeed"
		}

	configuration {}
end

function commonLibSetup(name)
	project(name)
		location (path.join(AETHER_DIR, "build"))
		kind "StaticLib"
		language "C++"
		configurations { "debug", "release" }
		platforms { "x32", "x64" }
		
		targetdir ("../build")

		configuration {}		
			flags {
				-- "ExtraWarnings",
				-- "PedanticWarnings",
			}

		commonFlags()
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

