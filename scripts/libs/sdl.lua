commonLibSetup("sdl")

	includedirs {
		path.join(AETHER_DIR, "module/sdl/include"),
		path.join(AETHER_DIR, "module/sdl/src/hidapi/hidapi"),
	}

	files {
		path.join(AETHER_DIR, "module/sdl/include/*.h"),
		path.join(AETHER_DIR, "module/sdl/src/*.c"),
		path.join(AETHER_DIR, "module/sdl/src/**.h"),	
		path.join(AETHER_DIR, "module/sdl/src/atomic/*.c"),
		path.join(AETHER_DIR, "module/sdl/src/audio/*.c"),
		path.join(AETHER_DIR, "module/sdl/src/audio/dummy/*.c"),
		path.join(AETHER_DIR, "module/sdl/src/audio/disk/*.c"),
		path.join(AETHER_DIR, "module/sdl/src/cpuinfo/*.c"),
		path.join(AETHER_DIR, "module/sdl/src/dynapi/*.c"),
		path.join(AETHER_DIR, "module/sdl/src/events/*.c"),
		path.join(AETHER_DIR, "module/sdl/src/file/*.c"),
		path.join(AETHER_DIR, "module/sdl/src/haptic/*.c"),
		path.join(AETHER_DIR, "module/sdl/src/haptic/dummy/*.c"),
		path.join(AETHER_DIR, "module/sdl/src/joystick/*.c"),
		path.join(AETHER_DIR, "module/sdl/src/joystick/hidapi/*.c"),
		path.join(AETHER_DIR, "module/sdl/src/joystick/virtual/*.c"),
		path.join(AETHER_DIR, "module/sdl/src/power/*.c"),
		path.join(AETHER_DIR, "module/sdl/src/render/*.c"),
		path.join(AETHER_DIR, "module/sdl/src/render/software/*.c"),
		path.join(AETHER_DIR, "module/sdl/src/sensor/*.c"),
		path.join(AETHER_DIR, "module/sdl/src/sensor/dummy/*.c"),
		path.join(AETHER_DIR, "module/sdl/src/stdlib/*.c"),
		path.join(AETHER_DIR, "module/sdl/src/thread/*.c"),
		path.join(AETHER_DIR, "module/sdl/src/timer/*.c"),
		path.join(AETHER_DIR, "module/sdl/src/timer/dummy/*.c"),
		path.join(AETHER_DIR, "module/sdl/src/video/*.c"),
		path.join(AETHER_DIR, "module/sdl/src/video/dummy/*.c"),
		path.join(AETHER_DIR, "module/sdl/src/video/yuv2rgb/*.c"),
		path.join(AETHER_DIR, "module/sdl/src/locale/*.c"),
	}

	configuration { "linux*" }
		files {
			path.join(AETHER_DIR, "module/config/sdl/linux/include/*.h"),
			path.join(AETHER_DIR, "module/sdl/src/audio/pulseaudio/*.c"),
			path.join(AETHER_DIR, "module/sdl/src/audio/dsp/*.c"),
			path.join(AETHER_DIR, "module/sdl/src/audio/alsa/*.c"),
			path.join(AETHER_DIR, "module/sdl/src/core/linux/*.c"),
			path.join(AETHER_DIR, "module/sdl/src/atomic/SDL_atomic.c"),
			path.join(AETHER_DIR, "module/sdl/src/atomic/SDL_spinlock.c"),
			path.join(AETHER_DIR, "module/sdl/src/haptic/linux/*.c"),
			path.join(AETHER_DIR, "module/sdl/src/joystick/linux/*.c"),
			path.join(AETHER_DIR, "module/sdl/src/joystick/steam/*.c"),
			path.join(AETHER_DIR, "module/sdl/src/power/linux/*.c"),
			path.join(AETHER_DIR, "module/sdl/src/filesystem/unix/*.c"),
			path.join(AETHER_DIR, "module/sdl/src/video/wayland/*.c"),
			path.join(AETHER_DIR, "module/sdl/src/video/x11/*.c"),
			path.join(AETHER_DIR, "module/sdl/src/render/opengl/*.c"),
			path.join(AETHER_DIR, "module/sdl/src/render/opengles/*.c"),
			path.join(AETHER_DIR, "module/sdl/src/render/opengles2/*.c"),
			path.join(AETHER_DIR, "module/sdl/src/libm/*.c"),
		}

	configuration { "vs20*" }
		files {
			path.join(AETHER_DIR, "module/sdl/src/audio/directsound/*.c"),
			path.join(AETHER_DIR, "module/sdl/src/audio/winmm/*.c"),
			path.join(AETHER_DIR, "module/sdl/src/audio/xaudio2/*.c"),
			path.join(AETHER_DIR, "module/sdl/src/audio/wasapi/*.c"),		
			path.join(AETHER_DIR, "module/sdl/src/haptic/windows/*.c"),
			path.join(AETHER_DIR, "module/sdl/src/hidapi/windows/*.c"),
			path.join(AETHER_DIR, "module/sdl/src/joystick/windows/*.c"),
			path.join(AETHER_DIR, "module/sdl/src/thread/windows/*.c"),
			path.join(AETHER_DIR, "module/sdl/src/thread/generic/SDL_syscond.c"),
			path.join(AETHER_DIR, "module/sdl/src/video/windows/*.c"),
			path.join(AETHER_DIR, "module/sdl/src/core/windows/*.c"),
			path.join(AETHER_DIR, "module/sdl/src/filesystem/windows/*.c"),
			path.join(AETHER_DIR, "module/sdl/src/loadso/windows/*.c"),
			path.join(AETHER_DIR, "module/sdl/src/power/windows/*.c"),
			path.join(AETHER_DIR, "module/sdl/src/timer/windows/*.c"),
			path.join(AETHER_DIR, "module/sdl/src/render/direct3d/*.c"),
			path.join(AETHER_DIR, "module/sdl/src/render/direct3d11/*.c"),
			path.join(AETHER_DIR, "module/sdl/src/render/opengl/*.c"),
	        path.join(AETHER_DIR, "module/sdl/src/render/opengles/*.c"),
	        path.join(AETHER_DIR, "module/sdl/src/render/opengles2/*.c"),
	        path.join(AETHER_DIR, "module/sdl/src/locale/windows/*.c"),
	        path.join(AETHER_DIR, "module/sdl/src/sensor/windows/*.c"),
			path.join(AETHER_DIR, "module/sdl/src/libm/*.c"),
			path.join(AETHER_DIR, "module/sdl/src/main/windows/*.c"),
		}
		defines {
			"SDL_VIDEO_DRIVER_DUMMY",
			"SDL_AUDIO_DRIVER_DUMMY",
		}
		defines {
			"HAVE_LIBC",
		}

	configuration { "mingw*" }
		files {
			path.join(AETHER_DIR, "module/sdl/src/audio/directsound/*.c"),
			path.join(AETHER_DIR, "module/sdl/src/audio/winmm/*.c"),
			path.join(AETHER_DIR, "module/sdl/src/audio/wasapi/*.c"),
			path.join(AETHER_DIR, "module/sdl/src/haptic/windows/*.c"),
			path.join(AETHER_DIR, "module/sdl/src/hidapi/windows/*.c"),
			path.join(AETHER_DIR, "module/sdl/src/joystick/windows/*.c"),
			path.join(AETHER_DIR, "module/sdl/src/thread/windows/*.c"),
			path.join(AETHER_DIR, "module/sdl/src/thread/generic/SDL_syscond.c"),
			path.join(AETHER_DIR, "module/sdl/src/video/windows/*.c"),
			path.join(AETHER_DIR, "module/sdl/src/core/windows/*.c"),
			path.join(AETHER_DIR, "module/sdl/src/filesystem/windows/*.c"),
			path.join(AETHER_DIR, "module/sdl/src/loadso/windows/*.c"),
			path.join(AETHER_DIR, "module/sdl/src/power/windows/*.c"),
			path.join(AETHER_DIR, "module/sdl/src/timer/windows/*.c"),
			path.join(AETHER_DIR, "module/sdl/src/render/direct3d/*.c"),
			path.join(AETHER_DIR, "module/sdl/src/render/opengl/*.c"),
	        path.join(AETHER_DIR, "module/sdl/src/render/opengles/*.c"),
	        path.join(AETHER_DIR, "module/sdl/src/render/opengles2/*.c"),		
			path.join(AETHER_DIR, "module/sdl/src/libm/*.c"),
		}

	configuration {}

