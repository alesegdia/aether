
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

function baseCommonLibSetup(name, ignoreWarnings)
	project(name)
	location (path.join(AETHER_DIR, "build"))
	kind "StaticLib"
	language "C"
	configurations { "debug", "release" }
	platforms { "x32", "x64" }
	targetdir ("../build")
	commonFlags()
	if ignoreWarnings == true then
		flags(
		{
			"MinimumWarnings"
		})
	end
end

function commonLibSetup(name, ignoreWarnings)
	group "nonsortedlibs"
	baseCommonLibSetup(name, ignoreWarnings)
end

function externalCommonLibSetup(name, ignoreWarnings)
	group "external"
	baseCommonLibSetup(name, ignoreWarnings)
end

function pluginCommonLibSetup(name, ignoreWarnings)
	group "plugins"
	baseCommonLibSetup(name, ignoreWarnings)
end

function configSDL()
	configuration { "backend-sdl" }
		defines { "AETHER_USE_SDL" }
		includedirs { AETHER_SDL_INCLUDE_DIRS }
		links { AETHER_SDL_COMMON_LIBS }

	configuration { "vs20*", "backend-sdl" }
		links { AETHER_SDL_WIN_LIBS }
		--flags { "WinMain" }

end

function configGL()
	configuration { "backend-gl" }
		defines { "AETHER_USE_GL", "GLAD_GL_IMPLEMENTATION" }
		includedirs { AETHER_GL_INCLUDE_DIRS }
		links {
			AETHER_GL_COMMON_LIBS,
			"opengl32"
		}

	configuration { "vs20*", "backend-gl" }
		links { AETHER_GL_WIN_LIBS }

end

function configAllegro(magicMain)
	configuration { "backend-allegro" }
		defines { "AETHER_USE_ALLEGRO", "ALEGRO_STATICLINK", }
		if not magicMain then
			defines "ALLEGRO_NO_MAGIC_MAIN"
		end
		includedirs { AETHER_ALLEGRO_INCLUDE_DIRS }
		links { AETHER_ALLEGRO_COMMON_LIBS }

	configuration { "vs20*", "backend-allegro" }
	    links {
	    	"allegro",
	    	AETHER_ALLEGRO_WIN_LIBS,
		    "opengl32",
		    "glu32",
		}
		defines {
		    "ALLEGRO_CFG_OPENGL",
		    "ALLEGRO_CFG_OPENGL_PROGRAMMABLE_PIPELINE",
		    "ALLEGRO_CFG_SHADER_GLSL",
			"ALLEGRO_CFG_RELEASE_LOGGING",
			"DEBUGMODE",
			"ALLEGRO_STATICLINK",
		}

end


function configRaylib()
	configuration { "backend-raylib" }
		defines { "AETHER_USE_RAYLIB", "SUPPORT_CUSTOM_FRAME_CONTROL" }
		includedirs {
			path.join(AETHER_EXTERNALS_DIR, "raylib/src"),
			path.join(AETHER_EXTERNALS_DIR, "raylib/src/external/glfw/deps/mingw"),
		}
		links {
			"winmm",
		    "opengl32",
		    "glu32",
		    "raylib",
		}
end
