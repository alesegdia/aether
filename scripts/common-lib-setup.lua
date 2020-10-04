
function commonLibSetup(name)
	project(name)
		location "../build"
		kind "StaticLib"
		language "C++"
		configurations { "debug", "release" }
end
